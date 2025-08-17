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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include <string.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

typedef enum{
	sMainMenu = 0,
	sLedEffect,
	sT_RhMenu,
}state_t;

typedef struct{
	uint8_t payload[10];
	uint32_t len;
}command_t;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define SHT3_ADDRESS_WRITE  (0x70 << 1) // 1110 0000
#define SHT3_ADDRESS_READ 	(0x70 << 1) | 1 // 1110 0001
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c2;

UART_HandleTypeDef huart1;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */
xTaskHandle handle_menu_task;
xTaskHandle handle_led_task;
xTaskHandle handle_cmd_task;
xTaskHandle handle_print_task;
xTaskHandle handle_tempRH_task;

QueueHandle_t q_data;
QueueHandle_t q_print;

TimerHandle_t handle_led_timer[3];
uint8_t printBuffer[32];
volatile uint8_t user_data;
state_t curr_state = sMainMenu;
const char *msg_inv = "/**Invalid option **/\n";

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_I2C2_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */
void handler_menu_task (void * param);
void handler_led_task (void * param);
void handler_cmd_task (void * param);
void handler_print_task(void * param);
void handler_TempRH_task(void * param);
void led_effect_stop (void);
void led_effect (int n);
void led_effect_callback (TimerHandle_t xTimer);
void humidity ();
void temperature ();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint8_t temp;
	if (huart->Instance == USART1){
		if(! xQueueIsQueueFullFromISR(q_data)){
			xQueueSendFromISR(q_data, (void *)&user_data, NULL);
		}
		else {
			if (user_data == '\n' || user_data == '\r'){
				xQueueReceiveFromISR(q_data, (void *)&temp, NULL);
				xQueueSendFromISR(q_data, (void*)&user_data, NULL);
			}
		}

		HAL_UART_Transmit(&huart1, (uint8_t*)&user_data, 1, 10);

		if(user_data == '\r' || user_data == '\n'){
			xTaskNotifyFromISR(handle_cmd_task, 0, eNoAction, NULL);
		}

		HAL_UART_Receive_IT(&huart1, (uint8_t*)&user_data, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
	}
}



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
  MX_USART1_UART_Init();
  MX_I2C2_Init();
  /* USER CODE BEGIN 2 */
  BaseType_t status;

  status = xTaskCreate(handler_menu_task, "menu_task", 256, NULL, 2, &handle_menu_task);
  configASSERT(status == pdPASS);

  status = xTaskCreate(handler_led_task, "led_task", 256, NULL, 2, &handle_led_task);
  configASSERT(status == pdPASS);

  status = xTaskCreate(handler_cmd_task, "cmd_task", 256, NULL, 2, &handle_cmd_task);
  configASSERT(status == pdPASS);

  status = xTaskCreate(handler_TempRH_task, "tempRH_task", 256, NULL, 2, &handle_tempRH_task);
  configASSERT(status == pdPASS);

  status = xTaskCreate (handler_print_task, "print_task", 256, NULL, 2, &handle_print_task);
  configASSERT(status == pdPASS);

  q_data = xQueueCreate(10, sizeof(char));
  configASSERT( q_data != NULL);

  q_print =xQueueCreate(10, sizeof(char *));
  configASSERT(q_print != NULL);

  for(int i = 0; i < 3; i++){
	  handle_led_timer[i] = xTimerCreate("led_timer", pdMS_TO_TICKS(500), pdTRUE, (void*)(i+1), led_effect_callback);
   }

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
  HAL_UART_Transmit(&huart1, (uint8_t*)"Enter a number 0-3\r\n", strlen("Enter a number 0-3\r\n"), 100);
  HAL_UART_Receive_IT(&huart1, (uint8_t*)&user_data, 1);

  vTaskStartScheduler();
  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */


  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x00503D58;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_SET);

  /*Configure GPIO pins : PB1 PB2 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void handler_cmd_task (void * param)
{
	BaseType_t ret;
	command_t cmd;
	BaseType_t status;
	uint8_t item;

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);

	while(1){
		ret = xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
		if(ret == pdTRUE){
			status = uxQueueMessagesWaiting(q_data);
				if(status){
					uint8_t i = 0;
					do{
						status = xQueueReceive(q_data, &item, 0);
						if(status == pdTRUE){
							if (i < sizeof(cmd.payload) - 1)
								cmd.payload[i++] = item;
						}
					}while(item != '\r' && item != '\n');

					cmd.payload[i-1] = '\0';
					cmd.len = i-1;

					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);

					switch (curr_state){

					case sMainMenu:
						xTaskNotify(handle_menu_task, (uint32_t)&cmd, eSetValueWithOverwrite);
						break;
					case sLedEffect:
						xTaskNotify(handle_led_task, (uint32_t)&cmd, eSetValueWithOverwrite);
						break;
					case sT_RhMenu:
						xTaskNotify(handle_tempRH_task, (uint32_t)&cmd, eSetValueWithOverwrite);
						break;
					default:
						HAL_UART_Transmit(&huart1, (uint8_t*)"Invalid Input\r\n", strlen("Invalid Input\r\n"), 100);
						break;
					}
				}
		}
	}
}

void handler_menu_task(void * param){
	const char * msg_menu = "***************\r\n"
							"|    Menu     |\r\n"
							"***************\r\n"
							"Led Effect  ->0\r\n"
							"Temp_Humid  ->1\r\n"
							"Exit        ->2\r\n"
							"Enter your choice:";
	uint32_t cmd_addr;
	command_t *cmd;
	int option;

	while (1){
		xQueueSend (q_print, &msg_menu, portMAX_DELAY);

		xTaskNotifyWait(0, 0, &cmd_addr, portMAX_DELAY);
		cmd = (command_t *)cmd_addr;

		if(cmd->len == 1){
			option = cmd->payload[0] - '0';

			switch (option){
			case 0:
				curr_state = sLedEffect;
				xTaskNotify(handle_led_task, 0, eNoAction);
				break;
			case 1:
				curr_state = sT_RhMenu;
				xTaskNotify(handle_tempRH_task, 0, eNoAction);
				break;
			case 2:
				break;
			default:
				xQueueSend(q_print, &msg_inv, portMAX_DELAY);
				continue;
			}
		}else{
			xQueueSend(q_print, &msg_inv, portMAX_DELAY);
			continue;
		}
	}
		xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
}

void handler_led_task(void * param)
{
	uint32_t cmd_addr;
	command_t *cmd;

	const char * msg_led = "*************\r\n"
						   "  Led Effect \r\n"
							"*************\r\n"
							"none, p1, p2, p3\r\n"
							"Enter your choice:";

	while(1){
		xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
		xQueueSend(q_print, &msg_led, portMAX_DELAY);

		xTaskNotifyWait(0,  0, &cmd_addr, portMAX_DELAY);
		cmd = (command_t *)(cmd_addr);

		if(cmd->len <= 4){
			if(!strcmp((char*)cmd->payload, "none")){
				led_effect_stop();
			}
			else if(! strcmp((char*)cmd->payload, "p1")){
				led_effect(1);
			}
			else if (! strcmp((char*)cmd->payload, "p2")){
				led_effect(2);
			}
			else if (!strcmp((char*)cmd->payload, "p3")){
				led_effect(3);
			}
			else{
				xQueueSend(q_print, &msg_inv, portMAX_DELAY);
			}
		}
		else {
			xQueueSend(q_print, &msg_inv, portMAX_DELAY);
		}
		curr_state = sMainMenu;
		xTaskNotify(handle_menu_task, 0, eNoAction);
	}
}

void led_effect_stop(void){

	for(int i = 0; i < 3; i++){
		xTimerStop(handle_led_timer[i], portMAX_DELAY);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
	}
}

void led_effect (int n)
{
	led_effect_stop();
	xTimerStart(handle_led_timer[n-1], portMAX_DELAY);
}

void led_effect_callback(TimerHandle_t xTimer){

	int id;

	id = (uint32_t)pvTimerGetTimerID(xTimer);

	switch(id){

	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
		break;

	case 2:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
		break;

	case 3:
		static int flag = 1;
		flag ^= 1;
		if (flag){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
		}
		else {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
		}

		break;
	}
}

void handler_TempRH_task(void * param){


	uint32_t cmd_addr;
	command_t *cmd;
	int option;

	const char * msg_TempRH = "**************\r\n"
							  "|   TempRH   |\r\n"
							  "**************\r\n"
							  "Temperature->0\r\n"
							  "rHumidity  ->1\r\n"
							  "Enter your choice:";


	while(1){
		xTaskNotifyWait(0,  0, NULL, portMAX_DELAY);
		xQueueSend(q_print, &msg_TempRH, portMAX_DELAY);

		xTaskNotifyWait(0, 0, &cmd_addr, portMAX_DELAY);
		cmd = (command_t *)cmd_addr;

		if (cmd->len == 1){
			option = cmd->payload[0] - '0';
		}
		switch (option){
		case 0: temperature();
		break;
		case 1: humidity();
		break;
		default : xQueueSend(q_print, &msg_inv, portMAX_DELAY);
		break;
		}
		curr_state = sMainMenu;
		xTaskNotify(handle_menu_task, 0, eNoAction);
	}
	xTaskNotifyWait(0,  0, NULL, portMAX_DELAY);

}

void temperature (){
	uint8_t rxBuff[2];
	uint16_t rawTemp = 0;
	uint8_t regTemp[2];
	uint16_t Temp = 0;
	char *p = (char *)printBuffer;

		if(HAL_OK == HAL_I2C_IsDeviceReady(&hi2c2, SHT3_ADDRESS_WRITE, 1, 100)){
			HAL_UART_Transmit(&huart1, (uint8_t *) "Device ready \r\n", sizeof("Device ready \r\n"), 100);
			regTemp[0] = 0x7C;  //8-bit MSB Address of Relative Humidity in SHT3
			regTemp[1] = 0xA2;  //8-bit LSB Address of Relative Humidity in SHT3
		}
		//Transmitting address of Temperature sensor through I2C Master Tx
		HAL_I2C_Master_Transmit(&hi2c2, SHT3_ADDRESS_WRITE, regTemp, 2, 100);
		vTaskDelay(pdMS_TO_TICKS(100));

		//Receiving Raw Temperature data from SHT3 through I2C Master Rx
		HAL_I2C_Master_Receive(&hi2c2, SHT3_ADDRESS_READ, rxBuff, 2, 100);

		//Restructuring the Big Endian data to Little Endian
		rawTemp = ((rxBuff[0]<<8) | (rxBuff[1]));

		//Clearing PrintBuffer before UART Tx
		memset(printBuffer, 0, sizeof(printBuffer));

		//Storing Raw Temperature value and Tx through UART
		sprintf((char *)printBuffer, "Raw Temp : %u\r\n", rawTemp);

		xQueueSend(q_print, &p, portMAX_DELAY);

		//Calculating the Temperature from Raw data
		Temp = (-45) + ((175 * rawTemp) / 65535);

		vTaskDelay(pdMS_TO_TICKS(100));

		memset(printBuffer,0,sizeof(printBuffer)); //clearing printbuffer

		//Storing and Tx Temperature through UART
		sprintf((char *)printBuffer,"Temperature : %u Celcius\r\n", Temp);
		xQueueSend(q_print, &p, portMAX_DELAY);

		vTaskDelay(pdMS_TO_TICKS(1000));
}

void humidity (){
	uint8_t rxBuff[2];
	uint16_t rawHumd = 0;
	uint8_t regRH[2];
	uint16_t rHumidity = 0;
	char *p = (char *)printBuffer;

		if (HAL_OK == HAL_I2C_IsDeviceReady(&hi2c2, SHT3_ADDRESS_WRITE, 1, 100)){
			HAL_UART_Transmit(&huart1, (uint8_t *) "Device status ok \r\n", sizeof("Device status ok \r\n"), 100);
			regRH[0] = 0x5C;
			regRH[1] = 0x24;
		}
		HAL_I2C_Master_Transmit(&hi2c2, SHT3_ADDRESS_WRITE, regRH, 2, 100);
		vTaskDelay(pdMS_TO_TICKS(100));

		HAL_I2C_Master_Receive(&hi2c2, SHT3_ADDRESS_READ, rxBuff, 2, 100);
		rawHumd = ((rxBuff[0] << 8 ) | (rxBuff[1]));

		//Calculating the Relative Humidity from Raw data
		rHumidity = (100 * rawHumd) / 65535;

		memset(printBuffer, 0, sizeof(printBuffer));

		sprintf((char *)printBuffer, "Relative Humidity : %u%% RH \r\n", rHumidity);
		xQueueSend(q_print, &p, portMAX_DELAY);

		vTaskDelay(pdMS_TO_TICKS(1000));
}

void handler_print_task(void * param){
	uint32_t *msg;

	// Debug heap usage
	size_t free_heap = xPortGetFreeHeapSize();
	char heap_msg[32];
	snprintf(heap_msg, sizeof(heap_msg), "\r\nFree heap: %u bytes\r\n", free_heap);
	HAL_UART_Transmit(&huart1, (uint8_t*)heap_msg, strlen(heap_msg), 500);

	while(1){
		xQueueReceive(q_print, &msg, portMAX_DELAY);
		HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen((char*)msg), 500);

	}
}

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName) {
    (void)pxTask;
    HAL_UART_Transmit(&huart1, (uint8_t*)"Stack overflow in ", 17, 100);
    HAL_UART_Transmit(&huart1, (uint8_t*)pcTaskName, strlen(pcTaskName), 100);
    HAL_UART_Transmit(&huart1, (uint8_t*)"\r\n", 2, 100);
    taskDISABLE_INTERRUPTS();
    for(;;);
}

void vApplicationMallocFailedHook(void) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"Heap allocation failed\r\n", 23, 100);
    taskDISABLE_INTERRUPTS();
    for(;;);
}

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
#ifdef USE_FULL_ASSERT
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
