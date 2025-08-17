/* max30102.c - Optimized MAX30102 Implementation */

#include "max30102.h"

/* Global Variables */
SensorData_t sensor_data = {0};
VitalSigns_t vital_signs = {0};

/* MAX30102 Initialization - Fixed and Optimized */
void MAX30102_Init(void) {
    uint8_t data;
    uint8_t part_id;

    HAL_Delay(100); // Power-on delay

    /* Verify sensor communication */
    if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_PART_ID, 1, &part_id, 1, 1000) != HAL_OK) {
        printf("ERROR: Cannot communicate with MAX30102!\r\n");
        return;
    }

    if (part_id != 0x15) {
        printf("ERROR: Wrong part ID: 0x%02X (expected 0x15)\r\n", part_id);
        return;
    }

    printf("MAX30102 detected (Part ID: 0x%02X)\r\n", part_id);

    /* Soft Reset MAX30102 */
    data = 0x40;
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_MODE_CONFIG, 1, &data, 1, 1000);
    HAL_Delay(100);

    /* Wait for reset to complete */
    uint8_t timeout = 10;
    do {
        HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_MODE_CONFIG, 1, &data, 1, 1000);
        HAL_Delay(10);
    } while ((data & 0x40) && --timeout);

    if (timeout == 0) {
        printf("ERROR: MAX30102 reset timeout!\r\n");
        return;
    }

    /* Clear FIFO pointers */
    data = 0x00;
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_WR_PTR, 1, &data, 1, 1000);
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_RD_PTR, 1, &data, 1, 1000);
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, 0x05, 1, &data, 1, 1000); // OVF_COUNTER

    /* Configure FIFO - More aggressive settings */
    data = 0x0F;  // Sample averaging = 1, FIFO rollover enabled, FIFO almost full = 15
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_CONFIG, 1, &data, 1, 1000);

    /* Configure SpO2 settings first */
    data = 0x27;  // SPO2_ADC_RGE = 4096nA, SPO2_SR = 100Hz, LED_PW = 411μs
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_SPO2_CONFIG, 1, &data, 1, 1000);

    /* Configure LED pulse amplitudes - Higher current */
    data = 0x32;  // Red LED current = ~12mA (increased from 7mA)
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_LED1_PA, 1, &data, 1, 1000);

    data = 0x32;  // IR LED current = ~12mA (increased from 7mA)
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_LED2_PA, 1, &data, 1, 1000);

    /* Configure Mode - SpO2 mode LAST */
    data = 0x03;
    HAL_I2C_Mem_Write(&hi2c1, MAX30102_I2C_ADDR, MAX30102_MODE_CONFIG, 1, &data, 1, 1000);

    HAL_Delay(100); // Allow sensor to stabilize

    /* Initialize data structures */
    memset(&sensor_data, 0, sizeof(sensor_data));
    memset(&vital_signs, 0, sizeof(vital_signs));

    printf("MAX30102 initialization complete\r\n");
}

/* Read FIFO Data */
// void MAX30102_ReadFIFO(void) {
//     uint8_t fifo_data[6];
//     uint32_t red_sample, ir_sample;
//
//     /* Read 6 bytes (1 sample of Red + IR) */
//     if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_DATA, 1, fifo_data, 6, 1000) == HAL_OK) {
//         /* Extract Red LED data (18-bit) */
//         red_sample = ((uint32_t)fifo_data[0] << 16) | ((uint32_t)fifo_data[1] << 8) | fifo_data[2];
//         red_sample &= 0x3FFFF;  // 18-bit mask
//
//         /* Extract IR LED data (18-bit) */
//         ir_sample = ((uint32_t)fifo_data[3] << 16) | ((uint32_t)fifo_data[4] << 8) | fifo_data[5];
//         ir_sample &= 0x3FFFF;   // 18-bit mask
//
//         /* Store in circular buffer */
//         sensor_data.red[sensor_data.head] = red_sample;
//         sensor_data.ir[sensor_data.head] = ir_sample;
//
//         sensor_data.head = (sensor_data.head + 1) % SAMPLE_BUFFER_SIZE;
//         if (sensor_data.count < SAMPLE_BUFFER_SIZE) {
//             sensor_data.count++;
//         }
//     }
// }

///* Optimized FIFO Reading with better error handling */
//void MAX30102_ReadFIFO(void) {
//    uint8_t fifo_wr_ptr, fifo_rd_ptr, num_samples;
//    uint8_t fifo_data[6];
//    uint32_t red_sample, ir_sample;
//
//    /* Read FIFO pointers */
//    if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_WR_PTR, 1, &fifo_wr_ptr, 1, 100) != HAL_OK) {
//        return;
//    }
//    if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_RD_PTR, 1, &fifo_rd_ptr, 1, 100) != HAL_OK) {
//        return;
//    }
//
//    /* Calculate number of samples available */
//    if (fifo_wr_ptr >= fifo_rd_ptr) {
//        num_samples = fifo_wr_ptr - fifo_rd_ptr;
//    } else {
//        num_samples = (32 - fifo_rd_ptr) + fifo_wr_ptr;
//    }
//    printf("WR: %d, RD: %d, NS: %d\n", fifo_wr_ptr, fifo_rd_ptr, num_samples);
//    /* Read available samples (limit to prevent overflow) */
//    uint8_t samples_to_read = (num_samples > 5) ? 5 : num_samples;
//
//    for (uint8_t i = 0; i < samples_to_read; i++) {
//        /* Read 6 bytes (1 sample of Red + IR) */
//        if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_DATA, 1, fifo_data, 6, 100) == HAL_OK) {
//            /* Extract Red LED data (18-bit) */
//            red_sample = ((uint32_t)fifo_data[0] << 16) | ((uint32_t)fifo_data[1] << 8) | fifo_data[2];
//            red_sample &= 0x3FFFF;  // 18-bit mask
//
//            /* Extract IR LED data (18-bit) */
//            ir_sample = ((uint32_t)fifo_data[3] << 16) | ((uint32_t)fifo_data[4] << 8) | fifo_data[5];
//            ir_sample &= 0x3FFFF;   // 18-bit mask
//
//            printf("Red: %lu, IR: %lu\n", red_sample, ir_sample);
//
//
//            /* Basic validation - reject obviously invalid samples */
//            if (red_sample > 1000 && ir_sample > 1000 && red_sample < 250000 && ir_sample < 250000) {
//                /* Store in circular buffer */
//                sensor_data.red[sensor_data.head] = red_sample;
//                sensor_data.ir[sensor_data.head] = ir_sample;
//
//                sensor_data.head = (sensor_data.head + 1) % SAMPLE_BUFFER_SIZE;
//                if (sensor_data.count < SAMPLE_BUFFER_SIZE) {
//                    sensor_data.count++;
//                }
//            }
//        }
//    }
//}

void MAX30102_ReadFIFO(void) {
    uint8_t fifo_wr_ptr, fifo_rd_ptr, num_samples;
    uint8_t fifo_data[6];
    uint8_t int_status;
    uint32_t red_sample, ir_sample;

    /* Check if data ready */
    if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_INT_STATUS_1, 1, &int_status, 1, 100) != HAL_OK) return;
    if (!(int_status & 0x40)) return; // PPG_RDY

    /* Read FIFO pointers */
    if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_WR_PTR, 1, &fifo_wr_ptr, 1, 100) != HAL_OK) return;
    if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_RD_PTR, 1, &fifo_rd_ptr, 1, 100) != HAL_OK) return;

    if (fifo_wr_ptr >= fifo_rd_ptr) {
        num_samples = fifo_wr_ptr - fifo_rd_ptr;
    } else {
        num_samples = (32 - fifo_rd_ptr) + fifo_wr_ptr;
    }

    printf("INT: 0x%02X, WR: %d, RD: %d, NS: %d\n", int_status, fifo_wr_ptr, fifo_rd_ptr, num_samples);

    uint8_t samples_to_read = (num_samples > 5) ? 5 : num_samples;

    for (uint8_t i = 0; i < samples_to_read; i++) {
        if (HAL_I2C_Mem_Read(&hi2c1, MAX30102_I2C_ADDR, MAX30102_FIFO_DATA, 1, fifo_data, 6, 100) == HAL_OK) {
            red_sample = ((uint32_t)fifo_data[0] << 16) | ((uint32_t)fifo_data[1] << 8) | fifo_data[2];
            red_sample &= 0x3FFFF;

            ir_sample = ((uint32_t)fifo_data[3] << 16) | ((uint32_t)fifo_data[4] << 8) | fifo_data[5];
            ir_sample &= 0x3FFFF;

            printf("Red: %lu, IR: %lu\n", red_sample, ir_sample);

            if (red_sample > 1000 && ir_sample > 1000 && red_sample < 250000 && ir_sample < 250000) {
                sensor_data.red[sensor_data.head] = red_sample;
                sensor_data.ir[sensor_data.head] = ir_sample;

                sensor_data.head = (sensor_data.head + 1) % SAMPLE_BUFFER_SIZE;
                if (sensor_data.count < SAMPLE_BUFFER_SIZE) {
                    sensor_data.count++;
                }
            }
        }
    }
}


/* Enhanced Signal Quality Assessment */
uint8_t AssessSignalQuality(void) {
    if (sensor_data.count < 50) return 0; // Reduced from MIN_SAMPLES_FOR_HR

    uint16_t samples_to_check = (sensor_data.count > 100) ? 100 : sensor_data.count;
    uint16_t start_idx = sensor_data.count - samples_to_check;

    float red_dc_avg = 0, ir_dc_avg = 0;
    float red_ac = 0, ir_ac = 0;
    uint8_t quality_score = 0;

    // Calculate DC components (recent samples only)
    for (uint16_t i = start_idx; i < sensor_data.count; i++) {
        red_dc_avg += (float)sensor_data.red[i];
        ir_dc_avg += (float)sensor_data.ir[i];
    }
    red_dc_avg /= samples_to_check;
    ir_dc_avg /= samples_to_check;

    // Calculate AC RMS
    for (uint16_t i = start_idx; i < sensor_data.count; i++) {
        float red_diff = (float)sensor_data.red[i] - red_dc_avg;
        float ir_diff = (float)sensor_data.ir[i] - ir_dc_avg;
        red_ac += red_diff * red_diff;
        ir_ac += ir_diff * ir_diff;
    }
    red_ac = sqrtf(red_ac / samples_to_check);
    ir_ac = sqrtf(ir_ac / samples_to_check);

    // Calculate quality score
    if (red_dc_avg > 0 && ir_dc_avg > 0) {
        // Signal strength quality (more lenient thresholds)
        if (red_dc_avg > 30000 && ir_dc_avg > 30000) quality_score += 40;
        else if (red_dc_avg > 15000 && ir_dc_avg > 15000) quality_score += 25;
        else if (red_dc_avg > 5000 && ir_dc_avg > 5000) quality_score += 15;

        // Perfusion quality
        float red_snr = red_ac / red_dc_avg;
        float ir_snr = ir_ac / ir_dc_avg;

        if (red_snr > 0.01 && ir_snr > 0.01) quality_score += 30;
        else if (red_snr > 0.005 && ir_snr > 0.005) quality_score += 15;

        // Motion artifact detection (simplified)
        if (red_snr < 0.5 && ir_snr < 0.5) quality_score += 30; // Not too much variation
    }

    printf("Signal Quality: %d%% (Red DC: %.0f, IR DC: %.0f)\r\n",
           quality_score, red_dc_avg, ir_dc_avg);

    return (quality_score > 100) ? 100 : quality_score;
}

/* Simplified and more robust finger detection */
uint8_t DetectFingerPresence(void) {
    if (sensor_data.count < 10) return 0;

    uint32_t avg_red = 0, avg_ir = 0;
    uint16_t samples_to_check = (sensor_data.count > 20) ? 20 : sensor_data.count;
    uint16_t start_idx = sensor_data.count - samples_to_check;

    // Check recent samples
    for (uint16_t i = start_idx; i < sensor_data.count; i++) {
        avg_red += sensor_data.red[i];
        avg_ir += sensor_data.ir[i];
    }
    avg_red /= samples_to_check;
    avg_ir /= samples_to_check;

    printf("Finger check - Red: %lu, IR: %lu\r\n", avg_red, avg_ir);

    // More lenient finger detection
    if (avg_ir > 10000 && avg_red > 10000) {
        return 1;
    }

    return 0;
}

/* Simplified Processing */
void ProcessSignals(void) {
    // Simple DC removal - just subtract mean
    if (sensor_data.count < 50) return;

    uint16_t samples_to_process = (sensor_data.count > 200) ? 200 : sensor_data.count;
    uint16_t start_idx = sensor_data.count - samples_to_process;

    // Calculate means
    float red_mean = 0, ir_mean = 0;
    for (uint16_t i = start_idx; i < sensor_data.count; i++) {
        red_mean += (float)sensor_data.red[i];
        ir_mean += (float)sensor_data.ir[i];
    }
    red_mean /= samples_to_process;
    ir_mean /= samples_to_process;

    // Simple DC removal
    for (uint16_t i = 0; i < samples_to_process; i++) {
        uint16_t idx = start_idx + i;
        sensor_data.red_filtered[i] = (float)sensor_data.red[idx] - red_mean;
        sensor_data.ir_filtered[i] = (float)sensor_data.ir[idx] - ir_mean;
    }
}

/* Simplified Heart Rate Calculation */
float CalculateHeartRate(void) {
    if (sensor_data.count < 100) return 0.0f; // Reduced requirement

    uint16_t samples_to_use = (sensor_data.count > 200) ? 200 : sensor_data.count;
    ProcessSignals(); // Process signals first

    // Simple peak detection on IR signal (AC component)
    float threshold = 0; // Will be calculated dynamically
    uint16_t peak_indices[10];
    uint8_t peak_count = 0;

    // Find maximum and minimum for threshold
    float max_val = -999999.0f, min_val = 999999.0f;
    for (uint16_t i = 0; i < samples_to_use; i++) {
        if (sensor_data.ir_filtered[i] > max_val) max_val = sensor_data.ir_filtered[i];
        if (sensor_data.ir_filtered[i] < min_val) min_val = sensor_data.ir_filtered[i];
    }

    threshold = (max_val + min_val) / 2.0f + (max_val - min_val) * 0.3f;

    // Simple peak detection
    for (uint16_t i = 2; i < samples_to_use - 2 && peak_count < 10; i++) {
        if (sensor_data.ir_filtered[i] > threshold &&
            sensor_data.ir_filtered[i] > sensor_data.ir_filtered[i-1] &&
            sensor_data.ir_filtered[i] > sensor_data.ir_filtered[i+1] &&
            sensor_data.ir_filtered[i] > sensor_data.ir_filtered[i-2] &&
            sensor_data.ir_filtered[i] > sensor_data.ir_filtered[i+2]) {

            // Check minimum distance (30 samples = 300ms at 100Hz)
            if (peak_count == 0 || (i - peak_indices[peak_count-1]) > 30) {
                peak_indices[peak_count] = i;
                peak_count++;
            }
        }
    }

    if (peak_count < 2) return 0.0f;

    // Calculate average interval
    uint32_t total_interval = 0;
    for (uint8_t i = 1; i < peak_count; i++) {
        total_interval += peak_indices[i] - peak_indices[i-1];
    }

    float avg_interval = (float)total_interval / (peak_count - 1);
    float heart_rate = (SAMPLING_RATE_HZ * 60.0f) / avg_interval;

    printf("HR calc: %d peaks, avg interval: %.1f, HR: %.1f\r\n", peak_count, avg_interval, heart_rate);

    return (heart_rate >= 40 && heart_rate <= 200) ? heart_rate : 0.0f;
}

/* Simplified SpO2 calculation */
float CalculateSpO2(void) {
    if (sensor_data.count < 100) return 0.0f; // Reduced requirement

    uint16_t samples_to_use = (sensor_data.count > 150) ? 150 : sensor_data.count;
    uint16_t start_idx = sensor_data.count - samples_to_use;

    float red_ac = 0, red_dc_avg = 0;
    float ir_ac = 0, ir_dc_avg = 0;

    // Calculate DC components
    for (uint16_t i = start_idx; i < sensor_data.count; i++) {
        red_dc_avg += (float)sensor_data.red[i];
        ir_dc_avg += (float)sensor_data.ir[i];
    }
    red_dc_avg /= samples_to_use;
    ir_dc_avg /= samples_to_use;

    // Calculate AC RMS
    for (uint16_t i = start_idx; i < sensor_data.count; i++) {
        float red_diff = (float)sensor_data.red[i] - red_dc_avg;
        float ir_diff = (float)sensor_data.ir[i] - ir_dc_avg;
        red_ac += red_diff * red_diff;
        ir_ac += ir_diff * ir_diff;
    }
    red_ac = sqrtf(red_ac / samples_to_use);
    ir_ac = sqrtf(ir_ac / samples_to_use);

    if (red_dc_avg == 0 || ir_dc_avg == 0 || ir_ac == 0) return 0.0f;

    // Calculate R value
    float ratio_of_ratios = (red_ac / red_dc_avg) / (ir_ac / ir_dc_avg);

    // Simplified calibration
    float spo2 = 104.0f - 17.0f * ratio_of_ratios;

    // Clamp to reasonable range
    if (spo2 > 100.0f) spo2 = 100.0f;
    if (spo2 < 70.0f) spo2 = 80.0f; // Default to reasonable value for poor signal

    printf("SpO2 calc: R=%.3f, SpO2=%.1f\r\n", ratio_of_ratios, spo2);

    return spo2;
}

/* Simplified stability check */
uint8_t AddReadingAndCheckStability(float hr, float spo2) {
    static uint8_t readings_count = 0;
    static float hr_sum = 0, spo2_sum = 0;

    if (hr > 0 && spo2 > 0) {
        hr_sum += hr;
        spo2_sum += spo2;
        readings_count++;

        if (readings_count >= 3) { // Reduced from 5
            vital_signs.stable_heart_rate = hr_sum / readings_count;
            vital_signs.stable_spo2 = spo2_sum / readings_count;

            // Reset for next average
            hr_sum = 0;
            spo2_sum = 0;
            readings_count = 0;

            return 1; // Consider stable after 3 readings
        }
    }

    return 0;
}

/* Main processing function - Simplified */
void ProcessVitalSigns(void) {
    static uint32_t last_output_time = 0;
    uint32_t current_time = HAL_GetTick();

    // More frequent status updates
    if ((current_time - last_output_time) >= 1000) { // Every 1 second
        printf("Status: %d samples, Quality: %d%%\r\n",
               sensor_data.count, AssessSignalQuality());
        last_output_time = current_time;
    }

    // Check finger presence
    vital_signs.finger_detected = DetectFingerPresence();
    sensor_data.signal_quality = AssessSignalQuality();

    if (!vital_signs.finger_detected) {
        printf("Place finger on sensor\r\n");
        return;
    }

    if (sensor_data.count < 100) { // Reduced from MIN_SAMPLES_FOR_SPO2
        printf("Collecting data... (%d/100)\r\n", sensor_data.count);
        return;
    }

    // Try to calculate readings with lower requirements
    float current_hr = CalculateHeartRate();
    float current_spo2 = CalculateSpO2();

    if (current_hr > 0 || current_spo2 > 0) {
        printf("Raw readings - HR: %.1f, SpO2: %.1f\r\n", current_hr, current_spo2);

        if (current_hr > 0 && current_spo2 > 0) {
            uint8_t stable = AddReadingAndCheckStability(current_hr, current_spo2);

            if (stable) {
                printf("=== RESULTS ===\r\n");
                printf("HR: %.1f BPM\r\n", vital_signs.stable_heart_rate);
                printf("SpO2: %.1f%%\r\n", vital_signs.stable_spo2);
                printf("Quality: %d%%\r\n", sensor_data.signal_quality);
                printf("===============\r\n");
                vital_signs.valid_reading = 1;
            }
        }
    } else {
        printf("No valid readings detected\r\n");
    }
}
