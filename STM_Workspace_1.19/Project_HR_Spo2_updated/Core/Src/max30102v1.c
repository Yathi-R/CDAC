/* max30102.c - MAX30102 Pulse Oximeter and Heart Rate Sensor Driver Implementation */

#include "max30102.h"

/* Global Variables */
SensorData_t sensor_data = {0};
VitalSigns_t vital_signs = {0};

/* MAX30102 Initialization */
void MAX30102_Init(void) {
    uint8_t data;

    /* Reset MAX30102 */
    data = 0x40;
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_MODE_CONFIG, 1, &data, 1, 1000);
    HAL_Delay(100);

    /* Configure FIFO */
    data = 0x4F;  // Sample averaging = 1, FIFO rollover enabled, FIFO almost full = 15
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_CONFIG, 1, &data, 1, 1000);

    /* Configure Mode - SpO2 mode */
    data = 0x03;
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_MODE_CONFIG, 1, &data, 1, 1000);

    /* Configure SpO2 settings */
    data = 0x27;  // SPO2_ADC_RGE = 4096nA, SPO2_SR = 100Hz, LED_PW = 411μs
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_SPO2_CONFIG, 1, &data, 1, 1000);

    /* Configure LED pulse amplitudes */
    data = 0x24;  // Red LED current = ~7mA
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_LED1_PA, 1, &data, 1, 1000);

    data = 0x24;  // IR LED current = ~7mA
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_LED2_PA, 1, &data, 1, 1000);

    /* Clear FIFO pointers */
    data = 0x00;
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_WR_PTR, 1, &data, 1, 1000);
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_RD_PTR, 1, &data, 1, 1000);
}

/* Read FIFO Data */
void MAX30102_ReadFIFO(void) {
    uint8_t fifo_data[6];
    uint32_t red_sample, ir_sample;

    /* Read 6 bytes (1 sample of Red + IR) */
    if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_DATA, 1, fifo_data, 6, 1000) == HAL_OK) {
        /* Extract Red LED data (18-bit) */
        red_sample = ((uint32_t)fifo_data[0] << 16) | ((uint32_t)fifo_data[1] << 8) | fifo_data[2];
        red_sample &= 0x3FFFF;  // 18-bit mask

        /* Extract IR LED data (18-bit) */
        ir_sample = ((uint32_t)fifo_data[3] << 16) | ((uint32_t)fifo_data[4] << 8) | fifo_data[5];
        ir_sample &= 0x3FFFF;   // 18-bit mask

        /* Store in circular buffer */
        sensor_data.red[sensor_data.head] = red_sample;
        sensor_data.ir[sensor_data.head] = ir_sample;

        sensor_data.head = (sensor_data.head + 1) % SAMPLE_BUFFER_SIZE;
        if (sensor_data.count < SAMPLE_BUFFER_SIZE) {
            sensor_data.count++;
        }
    }
}

/* Signal quality assessment */
uint8_t AssessSignalQuality(void) {
    if (sensor_data.count < MIN_SAMPLES_FOR_HR) return 0;

    float red_dc_avg = 0, ir_dc_avg = 0;
    float red_ac = 0, ir_ac = 0;
    uint8_t quality_score = 0;

    // Calculate DC components
    for (uint16_t i = 0; i < sensor_data.count; i++) {
        red_dc_avg += (float)sensor_data.red[i];
        ir_dc_avg += (float)sensor_data.ir[i];
    }
    red_dc_avg /= sensor_data.count;
    ir_dc_avg /= sensor_data.count;

    // Calculate AC RMS
    for (uint16_t i = 0; i < sensor_data.count; i++) {
        float red_diff = (float)sensor_data.red[i] - red_dc_avg;
        float ir_diff = (float)sensor_data.ir[i] - ir_dc_avg;
        red_ac += red_diff * red_diff;
        ir_ac += ir_diff * ir_diff;
    }
    red_ac = sqrtf(red_ac / sensor_data.count);
    ir_ac = sqrtf(ir_ac / sensor_data.count);

    // Calculate quality score
    if (red_dc_avg > 0 && ir_dc_avg > 0) {
        float red_snr = red_ac / red_dc_avg;
        float ir_snr = ir_ac / ir_dc_avg;

        // Signal strength quality
        if (red_dc_avg > 80000 && ir_dc_avg > 80000) quality_score += 30;
        else if (red_dc_avg > 50000 && ir_dc_avg > 50000) quality_score += 20;
        else if (red_dc_avg > 30000 && ir_dc_avg > 30000) quality_score += 10;

        // Perfusion quality
        if (red_snr > 0.02 && ir_snr > 0.02) quality_score += 40;
        else if (red_snr > 0.01 && ir_snr > 0.01) quality_score += 20;

        // Stability quality
        float red_variance = 0, ir_variance = 0;
        for (uint16_t i = 1; i < sensor_data.count; i++) {
            float red_diff = (float)sensor_data.red[i] - (float)sensor_data.red[i-1];
            float ir_diff = (float)sensor_data.ir[i] - (float)sensor_data.ir[i-1];
            red_variance += red_diff * red_diff;
            ir_variance += ir_diff * ir_diff;
        }
        red_variance /= (sensor_data.count - 1);
        ir_variance /= (sensor_data.count - 1);

        if (red_variance < 10000000 && ir_variance < 10000000) quality_score += 30;
        else if (red_variance < 50000000 && ir_variance < 50000000) quality_score += 15;
    }

    return (quality_score > 100) ? 100 : quality_score;
}

/* Process signals with filtering */
void ProcessSignals(void) {
    // Copy data maintaining chronological order
    if (sensor_data.count < SAMPLE_BUFFER_SIZE) {
        // Buffer not full yet, copy from beginning
        for (uint16_t i = 0; i < sensor_data.count; i++) {
            sensor_data.red_filtered[i] = (float)sensor_data.red[i];
            sensor_data.ir_filtered[i] = (float)sensor_data.ir[i];
        }
    } else {
        // Buffer is full, copy in chronological order
        for (uint16_t i = 0; i < SAMPLE_BUFFER_SIZE; i++) {
            uint16_t idx = (sensor_data.head + i) % SAMPLE_BUFFER_SIZE;
            sensor_data.red_filtered[i] = (float)sensor_data.red[idx];
            sensor_data.ir_filtered[i] = (float)sensor_data.ir[idx];
        }
    }

    /* Apply DC removal filter */
    ApplyDCRemoval(sensor_data.red_filtered, &sensor_data.red_dc, DC_REMOVAL_ALPHA, sensor_data.count);
    ApplyDCRemoval(sensor_data.ir_filtered, &sensor_data.ir_dc, DC_REMOVAL_ALPHA, sensor_data.count);

    /* Apply Butterworth low-pass filter */
    ApplyButterworthFilter(sensor_data.red_filtered, &sensor_data.red_prev_filtered, sensor_data.count);
    ApplyButterworthFilter(sensor_data.ir_filtered, &sensor_data.ir_prev_filtered, sensor_data.count);
}

/* DC Removal Filter */
void ApplyDCRemoval(float *signal, float *dc_value, float alpha, uint16_t length) {
    for (uint16_t i = 0; i < length; i++) {
        *dc_value = alpha * (*dc_value) + (1.0f - alpha) * signal[i];
        signal[i] = signal[i] - *dc_value;
    }
}

/* Butterworth Low-pass Filter */
void ApplyButterworthFilter(float *signal, float *prev_filtered, uint16_t length) {
    float RC = 1.0f / (2.0f * M_PI * BUTTERWORTH_CUTOFF_HZ);
    float dt = 1.0f / SAMPLING_RATE_HZ;
    float alpha = dt / (RC + dt);

    for (uint16_t i = 0; i < length; i++) {
        if (i == 0) {
            signal[i] = alpha * signal[i] + (1.0f - alpha) * (*prev_filtered);
        } else {
            signal[i] = alpha * signal[i] + (1.0f - alpha) * signal[i-1];
        }
    }
    *prev_filtered = signal[length-1];
}

/* Optimized heart rate calculation */
float CalculateHeartRate(void) {
    if (sensor_data.count < MIN_SAMPLES_FOR_HR) return 0.0f;

    float max_val = -999999.0f, min_val = 999999.0f;
    float mean_val = 0;

    // Calculate statistics
    for (uint16_t i = 0; i < sensor_data.count; i++) {
        mean_val += sensor_data.red_filtered[i];
        if (sensor_data.red_filtered[i] > max_val) max_val = sensor_data.red_filtered[i];
        if (sensor_data.red_filtered[i] < min_val) min_val = sensor_data.red_filtered[i];
    }
    mean_val /= sensor_data.count;

    // Dynamic threshold
    float signal_range = max_val - min_val;
    float threshold = mean_val + signal_range * 0.3f;
    uint16_t min_peak_distance = (uint16_t)(SAMPLING_RATE_HZ * 0.4f); // 400ms minimum

    // Peak detection
    uint16_t peak_indices[20];  // Reduced from 50 to 20
    uint8_t peak_count = 0;

    for (uint16_t i = 3; i < sensor_data.count - 3 && peak_count < 20; i++) {
        if (sensor_data.red_filtered[i] > threshold &&
            sensor_data.red_filtered[i] > sensor_data.red_filtered[i-1] &&
            sensor_data.red_filtered[i] > sensor_data.red_filtered[i+1] &&
            sensor_data.red_filtered[i] > sensor_data.red_filtered[i-2] &&
            sensor_data.red_filtered[i] > sensor_data.red_filtered[i+2] &&
            sensor_data.red_filtered[i] > sensor_data.red_filtered[i-3] &&
            sensor_data.red_filtered[i] > sensor_data.red_filtered[i+3]) {

            // Check minimum distance from last peak
            if (peak_count == 0 || (i - peak_indices[peak_count-1]) > min_peak_distance) {
                peak_indices[peak_count] = i;
                peak_count++;
            }
        }
    }

    if (peak_count < 3) return 0.0f;

    // Calculate intervals between consecutive peaks
    uint32_t intervals[19];  // Reduced from 49 to 19
    uint8_t interval_count = 0;

    for (uint8_t i = 1; i < peak_count && interval_count < 19; i++) {
        uint32_t interval = peak_indices[i] - peak_indices[i-1];
        float bpm = (SAMPLING_RATE_HZ * 60.0f) / (float)interval;

        if (bpm >= 40 && bpm <= 200) {
            intervals[interval_count++] = interval;
        }
    }

    if (interval_count < 2) return 0.0f;

    // Calculate mean interval
    uint32_t sum_intervals = 0;
    for (uint8_t i = 0; i < interval_count; i++) {
        sum_intervals += intervals[i];
    }
    uint32_t mean_interval = sum_intervals / interval_count;

    float heart_rate = (SAMPLING_RATE_HZ * 60.0f) / (float)mean_interval;
    return (heart_rate >= 40 && heart_rate <= 200) ? heart_rate : 0.0f;
}

/* Optimized SpO2 calculation */
float CalculateSpO2(void) {
    if (sensor_data.count < MIN_SAMPLES_FOR_SPO2) return 0.0f;

    float red_ac = 0, red_dc_avg = 0;
    float ir_ac = 0, ir_dc_avg = 0;

    uint16_t samples_to_use = (sensor_data.count > 200) ? 200 : sensor_data.count;
    uint16_t start_idx = sensor_data.count - samples_to_use;

    // Calculate DC components
    for (uint16_t i = start_idx; i < sensor_data.count; i++) {
        red_dc_avg += (float)sensor_data.red[i];
        ir_dc_avg += (float)sensor_data.ir[i];
    }
    red_dc_avg /= samples_to_use;
    ir_dc_avg /= samples_to_use;

    // Calculate AC RMS from filtered signal
    for (uint16_t i = start_idx; i < sensor_data.count; i++) {
        red_ac += sensor_data.red_filtered[i] * sensor_data.red_filtered[i];
        ir_ac += sensor_data.ir_filtered[i] * sensor_data.ir_filtered[i];
    }
    red_ac = sqrtf(red_ac / samples_to_use);
    ir_ac = sqrtf(ir_ac / samples_to_use);

    if (red_dc_avg == 0 || ir_dc_avg == 0 || ir_ac == 0) return 0.0f;

    // Calculate R value
    float ratio_of_ratios = (red_ac / red_dc_avg) / (ir_ac / ir_dc_avg);

    // Calibration formula
    float spo2;
    if (ratio_of_ratios < 0.5f) {
        spo2 = 100.0f;
    } else if (ratio_of_ratios < 3.4f) {
        spo2 = 104.0f - 17.0f * ratio_of_ratios;
    } else {
        spo2 = 70.0f;
    }

    return (spo2 >= 70 && spo2 <= 100) ? spo2 : 0.0f;
}

/* Add reading to buffer and check stability */
uint8_t AddReadingAndCheckStability(float hr, float spo2) {
    static uint8_t initialized = 0;

    if (!initialized) {
        memset(&vital_signs, 0, sizeof(vital_signs));
        initialized = 1;
    }

    // Add HR reading
    if (hr > 0) {
        vital_signs.heart_rate_buffer[vital_signs.hr_buffer_index] = hr;
        vital_signs.hr_buffer_index = (vital_signs.hr_buffer_index + 1) % 10;
        if (vital_signs.hr_valid_count < 10) vital_signs.hr_valid_count++;
    }

    // Add SpO2 reading
    if (spo2 > 0) {
        vital_signs.spo2_buffer[vital_signs.spo2_buffer_index] = spo2;
        vital_signs.spo2_buffer_index = (vital_signs.spo2_buffer_index + 1) % 10;
        if (vital_signs.spo2_valid_count < 10) vital_signs.spo2_valid_count++;
    }

    // Check stability only if we have enough readings
    if (vital_signs.hr_valid_count < 5 || vital_signs.spo2_valid_count < 5) {
        return 0;
    }

    // Calculate mean and check variation
    float hr_sum = 0, spo2_sum = 0;
    float hr_min = 999, hr_max = 0;
    float spo2_min = 999, spo2_max = 0;

    uint8_t hr_count = (vital_signs.hr_valid_count < 10) ? vital_signs.hr_valid_count : 10;
    uint8_t spo2_count = (vital_signs.spo2_valid_count < 10) ? vital_signs.spo2_valid_count : 10;

    for (uint8_t i = 0; i < hr_count; i++) {
        hr_sum += vital_signs.heart_rate_buffer[i];
        if (vital_signs.heart_rate_buffer[i] < hr_min) hr_min = vital_signs.heart_rate_buffer[i];
        if (vital_signs.heart_rate_buffer[i] > hr_max) hr_max = vital_signs.heart_rate_buffer[i];
    }

    for (uint8_t i = 0; i < spo2_count; i++) {
        spo2_sum += vital_signs.spo2_buffer[i];
        if (vital_signs.spo2_buffer[i] < spo2_min) spo2_min = vital_signs.spo2_buffer[i];
        if (vital_signs.spo2_buffer[i] > spo2_max) spo2_max = vital_signs.spo2_buffer[i];
    }

    vital_signs.stable_heart_rate = hr_sum / hr_count;
    vital_signs.stable_spo2 = spo2_sum / spo2_count;

    // Check stability
    uint8_t hr_stable = (hr_max - hr_min) <= MAX_HR_VARIATION;
    uint8_t spo2_stable = (spo2_max - spo2_min) <= MAX_SPO2_VARIATION;

    if (hr_stable && spo2_stable) {
        vital_signs.stability_counter++;
        return (vital_signs.stability_counter >= STABILITY_THRESHOLD) ? 1 : 0;
    } else {
        vital_signs.stability_counter = 0;
        return 0;
    }
}

/* Finger presence detection */
uint8_t DetectFingerPresence(void) {
    if (sensor_data.count < 10) return 0;

    uint32_t avg_red = 0, avg_ir = 0;
    uint16_t samples_to_check = (sensor_data.count > 50) ? 50 : sensor_data.count;

    // Check recent samples
    for (uint16_t i = sensor_data.count - samples_to_check; i < sensor_data.count; i++) {
        avg_red += sensor_data.red[i];
        avg_ir += sensor_data.ir[i];
    }
    avg_red /= samples_to_check;
    avg_ir /= samples_to_check;

    uint8_t finger_present = 0;

    // Signal strength check
    if (avg_ir > 30000 && avg_red > 30000) finger_present++;

    // Signal quality check
    if (sensor_data.signal_quality > SIGNAL_QUALITY_THRESHOLD) finger_present++;

    // AC component check (perfusion indicator)
    float ir_variance = 0;
    for (uint16_t i = sensor_data.count - samples_to_check; i < sensor_data.count - 1; i++) {
        float diff = (float)sensor_data.ir[i+1] - (float)sensor_data.ir[i];
        ir_variance += diff * diff;
    }
    ir_variance /= (samples_to_check - 1);

    if (ir_variance > 1000 && ir_variance < 100000000) finger_present++;

    return (finger_present >= 2) ? 1 : 0;
}

/* Main processing function */
void ProcessVitalSigns(void) {
    static uint32_t last_output_time = 0;
    static uint8_t first_output_done = 0;
    uint32_t current_time = HAL_GetTick();

    // Assess signal quality
    sensor_data.signal_quality = AssessSignalQuality();

    // Check finger presence
    vital_signs.finger_detected = DetectFingerPresence();

    if (!vital_signs.finger_detected || sensor_data.signal_quality < SIGNAL_QUALITY_THRESHOLD) {
        vital_signs.valid_reading = 0;
        vital_signs.stability_counter = 0;
        printf("Place finger properly on sensor\r\n");
        return;
    }

    if (sensor_data.count < MIN_SAMPLES_FOR_SPO2) {
        printf("Collecting data... (%d/%d)\r\n", sensor_data.count, MIN_SAMPLES_FOR_SPO2);
        return;
    }

    // Calculate readings
    float current_hr = CalculateHeartRate();
    float current_spo2 = CalculateSpO2();

    if (current_hr > 0 && current_spo2 > 0) {
        uint8_t stable = AddReadingAndCheckStability(current_hr, current_spo2);

        // Output logic
        if (!first_output_done) {
            if (current_time > OUTPUT_DELAY_MS && stable) {
                printf("HR: %.1f BPM, SpO2: %.1f%% (Quality: %d%%)\r\n",
                       vital_signs.stable_heart_rate, vital_signs.stable_spo2, sensor_data.signal_quality);
                vital_signs.valid_reading = 1;
                vital_signs.last_valid_time = current_time;
                first_output_done = 1;
                last_output_time = current_time;
            } else if (stable) {
                printf("Stabilizing... HR: %.1f, SpO2: %.1f\r\n",
                       vital_signs.stable_heart_rate, vital_signs.stable_spo2);
            }
        } else {
            if (stable && (current_time - last_output_time) >= UPDATE_INTERVAL_MS) {
                printf("HR: %.1f BPM, SpO2: %.1f%% (Quality: %d%%)\r\n",
                       vital_signs.stable_heart_rate, vital_signs.stable_spo2, sensor_data.signal_quality);
                vital_signs.valid_reading = 1;
                vital_signs.last_valid_time = current_time;
                last_output_time = current_time;
            }
        }
    }
}
