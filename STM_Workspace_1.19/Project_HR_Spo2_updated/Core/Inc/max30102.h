/* max30102.h - MAX30102 Pulse Oximeter and Heart Rate Sensor Driver */

#ifndef MAX30102_H
#define MAX30102_H

#include "main.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* MAX30102 Register Addresses */
#define MAX30102_I2C_ADDR           0xAE  // 0x57 << 1
#define MAX30102_INT_STATUS_1       0x00
#define MAX30102_INT_STATUS_2       0x01
#define MAX30102_INT_ENABLE_1       0x02
#define MAX30102_INT_ENABLE_2       0x03
#define MAX30102_FIFO_WR_PTR        0x04
#define MAX30102_FIFO_RD_PTR        0x06
#define MAX30102_FIFO_DATA          0x07
#define MAX30102_FIFO_CONFIG        0x08
#define MAX30102_MODE_CONFIG        0x09
#define MAX30102_SPO2_CONFIG        0x0A
#define MAX30102_LED1_PA            0x0C  // Red LED
#define MAX30102_LED2_PA            0x0D  // IR LED
#define MAX30102_PILOT_PA           0x10
#define MAX30102_MULTI_LED_CTRL1    0x11
#define MAX30102_MULTI_LED_CTRL2    0x12
#define MAX30102_TEMP_INT           0x1F
#define MAX30102_TEMP_FRAC          0x20
#define MAX30102_TEMP_CONFIG        0x21
#define MAX30102_PROX_INT_THRESH    0x30
#define MAX30102_REV_ID             0xFE
#define MAX30102_PART_ID            0xFF

/* Configuration Constants */
#define SAMPLE_BUFFER_SIZE          500
#define MIN_SAMPLES_FOR_HR          200
#define MIN_SAMPLES_FOR_SPO2        300
#define STABILITY_THRESHOLD         5
#define MAX_HR_VARIATION           15
#define MAX_SPO2_VARIATION         3
#define OUTPUT_DELAY_MS            3000
#define UPDATE_INTERVAL_MS         2000
#define SIGNAL_QUALITY_THRESHOLD   30
#define DC_REMOVAL_ALPHA            0.95f
#define BUTTERWORTH_CUTOFF_HZ       3.0f
#define SAMPLING_RATE_HZ            100.0f

/* Data Structures */
typedef struct {
    uint32_t red[SAMPLE_BUFFER_SIZE];
    uint32_t ir[SAMPLE_BUFFER_SIZE];
    float red_filtered[SAMPLE_BUFFER_SIZE];
    float ir_filtered[SAMPLE_BUFFER_SIZE];
    uint16_t head;
    uint16_t count;
    float red_dc;
    float ir_dc;
    float red_prev_filtered;
    float ir_prev_filtered;
    uint8_t signal_quality;
} SensorData_t;

typedef struct {
    float heart_rate_buffer[10];
    float spo2_buffer[10];
    uint8_t hr_buffer_index;
    uint8_t spo2_buffer_index;
    uint8_t hr_valid_count;
    uint8_t spo2_valid_count;
    float stable_heart_rate;
    float stable_spo2;
    uint8_t finger_detected;
    uint8_t valid_reading;
    uint32_t last_valid_time;
    uint8_t stability_counter;
} VitalSigns_t;

/* Global Variables */
extern SensorData_t sensor_data;
extern VitalSigns_t vital_signs;
extern I2C_HandleTypeDef hi2c1;

/* Function Prototypes */
void MAX30102_Init(void);
void MAX30102_ReadFIFO(void);
void ProcessSignals(void);
float CalculateHeartRate(void);
float CalculateSpO2(void);
void ProcessVitalSigns(void);
uint8_t DetectFingerPresence(void);
uint8_t AssessSignalQuality(void);
uint8_t AddReadingAndCheckStability(float hr, float spo2);

/* Internal Processing Functions */
void ApplyDCRemoval(float *signal, float *dc_value, float alpha, uint16_t length);
void ApplyButterworthFilter(float *signal, float *prev_filtered, uint16_t length);

#endif /* MAX30102_H */
