/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define SAMPLE_BUFFER_SIZE          500

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
	 float heart_rate_buffer[10];  // Last 10 HR readings
	 float spo2_buffer[10];        // Last 10 SpO2 readings
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
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
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

#define MIN_SAMPLES_FOR_HR          200   // Increased for better accuracy
#define MIN_SAMPLES_FOR_SPO2        300   // Increased for better accuracy
#define STABILITY_THRESHOLD         5     // Require 5 consecutive stable readings
#define MAX_HR_VARIATION           15     // Max BPM variation for stability
#define MAX_SPO2_VARIATION         3      // Max SpO2% variation for stability
#define OUTPUT_DELAY_MS            3000   // 3 second delay before first output
#define UPDATE_INTERVAL_MS         2000   // Update every 2 seconds after stabilization
#define SIGNAL_QUALITY_THRESHOLD   30    // Minimum signal quality required
 #define MOVING_AVERAGE_SIZE         4
 #define DC_REMOVAL_ALPHA            0.95f
 #define BUTTERWORTH_CUTOFF_HZ       3.0f
 #define SAMPLING_RATE_HZ            100.0f

 /* Calibration Constants for SpO2 */
 #define SPO2_A                      -45.060f
 #define SPO2_B                      30.354f
 #define SPO2_C                      94.845f
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
SensorData_t sensor_data = {0};
VitalSigns_t vital_signs = {0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
void MAX30102_Init(void);
void MAX30102_ReadFIFO(void);
void ProcessSignals(void);
float CalculateHeartRateEnhanced(void);
float CalculateSpO2Enhanced(void);
void ApplyDCRemoval(float *signal, float *dc_value, float alpha, uint16_t length);
void ApplyButterworthFilter(float *signal, float *prev_filtered, uint16_t length);
uint8_t DetectFingerPresenceEnhanced(void);
void BlinkLED(void);
void ProcessVitalSigns(void);
uint8_t AddReadingAndCheckStability(float hr, float spo2);
uint8_t AssessSignalQuality(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* Enable Timer interrupt */
  HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);

  MAX30102_Init();
  HAL_Delay(1000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if (sensor_data.count >= MIN_SAMPLES_FOR_HR) {
	      ProcessSignals();
	      ProcessVitalSigns();
	      BlinkLED();
	  }
	  HAL_Delay(50);	       }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLL1_SOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 250;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1_VCIRANGE_1;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1_VCORANGE_WIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK3;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the programming delay
  */
  __HAL_FLASH_SET_PROGRAM_DELAY(FLASH_PROGRAMMING_DELAY_2);
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x60808CD3;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 24999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 99;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PF4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : RMII_MDC_Pin RMII_RXD0_Pin RMII_RXD1_Pin */
  GPIO_InitStruct.Pin = RMII_MDC_Pin|RMII_RXD0_Pin|RMII_RXD1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : RMII_REF_CLK_Pin RMII_MDIO_Pin RMII_CRS_DV_Pin */
  GPIO_InitStruct.Pin = RMII_REF_CLK_Pin|RMII_MDIO_Pin|RMII_CRS_DV_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : VBUS_SENSE_Pin */
  GPIO_InitStruct.Pin = VBUS_SENSE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(VBUS_SENSE_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PB0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : UCPD_CC1_Pin UCPD_CC2_Pin */
  GPIO_InitStruct.Pin = UCPD_CC1_Pin|UCPD_CC2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : RMII_TXD1_Pin */
  GPIO_InitStruct.Pin = RMII_TXD1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(RMII_TXD1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD9 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PG4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pin : UCPD_FLT_Pin */
  GPIO_InitStruct.Pin = UCPD_FLT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(UCPD_FLT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : USB_FS_N_Pin USB_FS_P_Pin */
  GPIO_InitStruct.Pin = USB_FS_N_Pin|USB_FS_P_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF10_USB;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : RMII_TXT_EN_Pin RMI_TXD0_Pin */
  GPIO_InitStruct.Pin = RMII_TXT_EN_Pin|RMI_TXD0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF11_ETH;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : ARD_D1_TX_Pin ARD_D0_RX_Pin */
  GPIO_InitStruct.Pin = ARD_D1_TX_Pin|ARD_D0_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF8_LPUART1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
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

 /* Enhanced signal quality assessment */
 uint8_t AssessSignalQuality(void) {
     float red_snr, ir_snr;
     float red_ac = 0, red_dc_avg = 0;
     float ir_ac = 0, ir_dc_avg = 0;
     uint16_t i;
     uint8_t quality_score = 0;

     if (sensor_data.count < MIN_SAMPLES_FOR_HR) return 0;

     // Calculate DC components
     for (i = 0; i < sensor_data.count; i++) {
         red_dc_avg += (float)sensor_data.red[i];
         ir_dc_avg += (float)sensor_data.ir[i];
     }
     red_dc_avg /= sensor_data.count;
     ir_dc_avg /= sensor_data.count;

     // Calculate AC RMS
     for (i = 0; i < sensor_data.count; i++) {
         float red_diff = (float)sensor_data.red[i] - red_dc_avg;
         float ir_diff = (float)sensor_data.ir[i] - ir_dc_avg;
         red_ac += red_diff * red_diff;
         ir_ac += ir_diff * ir_diff;
     }
     red_ac = sqrtf(red_ac / sensor_data.count);
     ir_ac = sqrtf(ir_ac / sensor_data.count);

     // Calculate SNR
     if (red_dc_avg > 0 && ir_dc_avg > 0) {
         red_snr = red_ac / red_dc_avg;
         ir_snr = ir_ac / ir_dc_avg;

         // Quality based on signal strength and SNR
         if (red_dc_avg > 80000 && ir_dc_avg > 80000) quality_score += 30;
         else if (red_dc_avg > 50000 && ir_dc_avg > 50000) quality_score += 20;
         else if (red_dc_avg > 30000 && ir_dc_avg > 30000) quality_score += 10;

         // Quality based on AC component (perfusion)
         if (red_snr > 0.02 && ir_snr > 0.02) quality_score += 40;
         else if (red_snr > 0.01 && ir_snr > 0.01) quality_score += 20;

         // Quality based on signal stability (check for motion artifacts)
         float red_variance = 0, ir_variance = 0;
         for (i = 1; i < sensor_data.count; i++) {
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

 // Improved ProcessSignals function to handle circular buffer correctly
 void ProcessSignals(void) {
     uint16_t i;

     // Copy data maintaining chronological order
     if (sensor_data.count < SAMPLE_BUFFER_SIZE) {
         // Buffer not full yet, copy from beginning
         for (i = 0; i < sensor_data.count; i++) {
             sensor_data.red_filtered[i] = (float)sensor_data.red[i];
             sensor_data.ir_filtered[i] = (float)sensor_data.ir[i];
         }
     } else {
         // Buffer is full, copy in chronological order
         for (i = 0; i < SAMPLE_BUFFER_SIZE; i++) {
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
     uint16_t i;
     for (i = 0; i < length; i++) {
         *dc_value = alpha * (*dc_value) + (1.0f - alpha) * signal[i];
         signal[i] = signal[i] - *dc_value;
     }
 }

 /* Butterworth Low-pass Filter */
 void ApplyButterworthFilter(float *signal, float *prev_filtered, uint16_t length) {
     float RC = 1.0f / (2.0f * M_PI * BUTTERWORTH_CUTOFF_HZ);
     float dt = 1.0f / SAMPLING_RATE_HZ;
     float alpha = dt / (RC + dt);

     uint16_t i;
     for (i = 0; i < length; i++) {
         if (i == 0) {
             signal[i] = alpha * signal[i] + (1.0f - alpha) * (*prev_filtered);
         } else {
             signal[i] = alpha * signal[i] + (1.0f - alpha) * signal[i-1];
         }
     }
     *prev_filtered = signal[length-1];
 }

 /* Enhanced heart rate calculation with better peak detection */
 float CalculateHeartRateEnhanced(void) {
     uint16_t i;
     float peaks[50];
     uint16_t peak_indices[50];
     uint16_t peak_count = 0;
     float max_val = -999999.0f, min_val = 999999.0f;
     float mean_val = 0;
     uint32_t peak_intervals[49];
     uint8_t interval_count = 0;

     // Calculate statistics
     for (i = 0; i < sensor_data.count; i++) {
         mean_val += sensor_data.red_filtered[i];
         if (sensor_data.red_filtered[i] > max_val) max_val = sensor_data.red_filtered[i];
         if (sensor_data.red_filtered[i] < min_val) min_val = sensor_data.red_filtered[i];
     }
     mean_val /= sensor_data.count;

     // Dynamic threshold based on signal characteristics
     float signal_range = max_val - min_val;
     float threshold = mean_val + signal_range * 0.3f;

     // Minimum distance between peaks (prevent double counting)
     uint16_t min_peak_distance = (uint16_t)(SAMPLING_RATE_HZ * 0.4f); // 400ms minimum

     // Enhanced peak detection with slope analysis
     for (i = 3; i < sensor_data.count - 3; i++) {
         if (sensor_data.red_filtered[i] > threshold &&
             sensor_data.red_filtered[i] > sensor_data.red_filtered[i-1] &&
             sensor_data.red_filtered[i] > sensor_data.red_filtered[i+1] &&
             sensor_data.red_filtered[i] > sensor_data.red_filtered[i-2] &&
             sensor_data.red_filtered[i] > sensor_data.red_filtered[i+2] &&
             sensor_data.red_filtered[i] > sensor_data.red_filtered[i-3] &&
             sensor_data.red_filtered[i] > sensor_data.red_filtered[i+3]) {

             // Check if minimum distance from last peak
             if (peak_count == 0 || (i - peak_indices[peak_count-1]) > min_peak_distance) {
                 peaks[peak_count] = sensor_data.red_filtered[i];
                 peak_indices[peak_count] = i;
                 peak_count++;

                 if (peak_count >= 50) break; // Prevent overflow
             }
         }
     }

     if (peak_count < 3) return 0.0f;

     // Calculate intervals between consecutive peaks
     for (i = 1; i < peak_count && interval_count < 49; i++) {
         uint32_t interval = peak_indices[i] - peak_indices[i-1];

         // Filter out unrealistic intervals
         float bpm = (SAMPLING_RATE_HZ * 60.0f) / (float)interval;
         if (bpm >= 40 && bpm <= 200) {
             peak_intervals[interval_count++] = interval;
         }
     }

     if (interval_count < 2) return 0.0f;

     // Calculate median interval for stability
     for (i = 0; i < interval_count - 1; i++) {
         for (uint8_t j = 0; j < interval_count - i - 1; j++) {
             if (peak_intervals[j] > peak_intervals[j + 1]) {
                 uint32_t temp = peak_intervals[j];
                 peak_intervals[j] = peak_intervals[j + 1];
                 peak_intervals[j + 1] = temp;
             }
         }
     }

     uint32_t median_interval = peak_intervals[interval_count / 2];

     // Also calculate mean for comparison
     uint32_t sum_intervals = 0;
     for (i = 0; i < interval_count; i++) {
         sum_intervals += peak_intervals[i];
     }
     uint32_t mean_interval = sum_intervals / interval_count;

     // Use median if it's close to mean (more stable), otherwise use mean
     uint32_t final_interval = (abs((int32_t)median_interval - (int32_t)mean_interval) < mean_interval * 0.1f) ?
                               median_interval : mean_interval;

     float heart_rate = (SAMPLING_RATE_HZ * 60.0f) / (float)final_interval;

     // Validate range
     if (heart_rate < 40 || heart_rate > 200) {
         return 0.0f;
     }

     return heart_rate;
 }

 /* Enhanced SpO2 calculation with better calibration */
 float CalculateSpO2Enhanced(void) {
     float red_ac = 0, red_dc_avg = 0;
     float ir_ac = 0, ir_dc_avg = 0;
     uint16_t i;

     // Use more samples for better accuracy
     uint16_t samples_to_use = (sensor_data.count > 200) ? 200 : sensor_data.count;
     uint16_t start_idx = sensor_data.count - samples_to_use;

     // Calculate DC components from recent samples
     for (i = start_idx; i < sensor_data.count; i++) {
         red_dc_avg += (float)sensor_data.red[i];
         ir_dc_avg += (float)sensor_data.ir[i];
     }
     red_dc_avg /= samples_to_use;
     ir_dc_avg /= samples_to_use;

     // Calculate AC RMS from filtered signal
     for (i = start_idx; i < sensor_data.count; i++) {
         red_ac += sensor_data.red_filtered[i] * sensor_data.red_filtered[i];
         ir_ac += sensor_data.ir_filtered[i] * sensor_data.ir_filtered[i];
     }
     red_ac = sqrtf(red_ac / samples_to_use);
     ir_ac = sqrtf(ir_ac / samples_to_use);

     if (red_dc_avg == 0 || ir_dc_avg == 0 || ir_ac == 0) {
         return 0.0f;
     }

     // Calculate R value
     float ratio_of_ratios = (red_ac / red_dc_avg) / (ir_ac / ir_dc_avg);

     // Improved calibration formula (may need adjustment for your sensor)
     float spo2;
     if (ratio_of_ratios < 0.5f) {
         spo2 = 100.0f;
     } else if (ratio_of_ratios < 3.4f) {
         spo2 = 104.0f - 17.0f * ratio_of_ratios;
     } else {
         spo2 = 70.0f;
     }

     // Validate range
     if (spo2 < 70 || spo2 > 100) {
         return 0.0f;
     }

     return spo2;
 }

 /* Add reading to buffer and check stability */
 uint8_t AddReadingAndCheckStability(float hr, float spo2) {
     static uint8_t initialized = 0;

     if (!initialized) {
         memset(vital_signs.heart_rate_buffer, 0, sizeof(vital_signs.heart_rate_buffer));
         memset(vital_signs.spo2_buffer, 0, sizeof(vital_signs.spo2_buffer));
         vital_signs.hr_buffer_index = 0;
         vital_signs.spo2_buffer_index = 0;
         vital_signs.hr_valid_count = 0;
         vital_signs.spo2_valid_count = 0;
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
         return 0; // Not enough readings
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

     // Check if readings are stable
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

 /* Enhanced finger detection */
 uint8_t DetectFingerPresenceEnhanced(void) {
     uint32_t avg_red = 0, avg_ir = 0;
     uint16_t samples_to_check = (sensor_data.count > 50) ? 50 : sensor_data.count;
     uint16_t i;

     if (samples_to_check < 10) return 0;

     // Check recent samples
     for (i = sensor_data.count - samples_to_check; i < sensor_data.count; i++) {
         avg_red += sensor_data.red[i];
         avg_ir += sensor_data.ir[i];
     }
     avg_red /= samples_to_check;
     avg_ir /= samples_to_check;

     // Multiple criteria for finger detection
     uint8_t finger_present = 0;

     // Signal strength check
     if (avg_ir > 30000 && avg_red > 30000) finger_present++;

     // Signal quality check
     if (sensor_data.signal_quality > SIGNAL_QUALITY_THRESHOLD) finger_present++;

     // AC component check (perfusion indicator)
     float ir_variance = 0;
     for (i = sensor_data.count - samples_to_check; i < sensor_data.count - 1; i++) {
         float diff = (float)sensor_data.ir[i+1] - (float)sensor_data.ir[i];
         ir_variance += diff * diff;
     }
     ir_variance /= (samples_to_check - 1);

     if (ir_variance > 1000 && ir_variance < 100000000) finger_present++;

     return (finger_present >= 2) ? 1 : 0;
 }

 /* Main processing function with delayed output */
 void ProcessVitalSigns(void) {
     static uint32_t last_output_time = 0;
     static uint8_t first_output_done = 0;
     uint32_t current_time = HAL_GetTick();

     // Assess signal quality first
     sensor_data.signal_quality = AssessSignalQuality();

     // Check finger presence
     vital_signs.finger_detected = DetectFingerPresenceEnhanced();

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
     float current_hr = CalculateHeartRateEnhanced();
     float current_spo2 = CalculateSpO2Enhanced();

     if (current_hr > 0 && current_spo2 > 0) {
         uint8_t stable = AddReadingAndCheckStability(current_hr, current_spo2);

         // Only output after initial delay and then at specified intervals
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
             // Regular updates after stabilization
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

 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
     if (htim->Instance == TIM2) {
         MAX30102_ReadFIFO();  // Read sensor data at 100Hz
     }
 }

 /* Blink LED to indicate data reading */
 void BlinkLED(void) {
     static uint32_t last_blink = 0;
     uint32_t current_time = HAL_GetTick();

     if (current_time - last_blink > 100) {  // Blink every 100ms
         HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);  // Use configured output pin
         last_blink = current_time;
     }
 }




/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
