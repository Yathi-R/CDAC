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

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

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



/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */

xTaskHandle handle_led_task;
xTaskHandle handle_cmd_task;
xTaskHandle handle_isr_task;
QueueHandle_t q_data;
volatile uint8_t user_data;
TimerHandle_t handle_led_timer[3];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */

void handler_led_task (void * param);
void handler_cmd_task (void * param);
void led_effect_stop (void);
void led_effect (int n);
void led_effect_callback (TimerHandle_t xTimer);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	for (volatile int i = 0; i < 6000; i++);

	if (huart->Instance == USART1){
		if(! xQueueIsQueueFullFromISR(q_data)){
			xQueueSendFromISR(q_data, (void *)&user_data, NULL);
		}

		HAL_UART_Transmit(&huart1, &user_data, 1, 10);

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
  /* USER CODE BEGIN 2 */

  BaseType_t status;

  status = xTaskCreate(handler_led_task, "led_task", 128, NULL, 2, &handle_led_task);
  configASSERT(status == pdPASS);

  status = xTaskCreate(handler_cmd_task, "cmd_task", 128, NULL, 2, &handle_cmd_task);
  configASSERT(status == pdPASS);

  q_data = xQueueCreate(10, sizeof(char));
  configASSERT( q_data != NULL);

  for(int i = 0; i < 3; i++){
	  handle_led_timer[i] = xTimerCreate("led_timer", pdMS_TO_TICKS(500), pdTRUE, (void*)(i+1), led_effect_callback);
  }

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
  HAL_UART_Transmit(&huart1, (uint8_t*)"Enter a number 0-3\r\n", strlen("Enter a number 0-3\r\n"), 100);
  HAL_UART_Receive_IT(&huart1, &user_data, 1);

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
	static command_t cmd;
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

				if(cmd.len == 1 && cmd.payload[0] >= '0' && cmd.payload[0] <= '3'){
					xTaskNotify(handle_led_task, (uint32_t)&cmd, eSetValueWithOverwrite);
				}
				else {
					HAL_UART_Transmit(&huart1, (uint8_t*)"Invalid Input\r\n", strlen("Invalid Input\r\n"), 100);
				}
			}
		}
	}
}

void handler_led_task(void * param)
{
	uint32_t cmd_addr;
	command_t *cmd;
	int option;
	while(1){
		xTaskNotifyWait(0,  0, &cmd_addr, portMAX_DELAY);
		cmd = (command_t *)(cmd_addr);

		if(cmd->len == 1){
			option = cmd->payload[0] - '0';
		}

		switch(option){
		case 0:
			led_effect_stop();
			break;
		case 1:
			led_effect(1);
			break;
		case 2:
			led_effect(2);
			break;
		case 3:
			led_effect(3);
			break;
		}
	}
}

void led_effect_stop(void){

	for(int i = 0; i < 3; i++){
		xTimerStop(handle_led_timer[i], portMAX_DELAY);
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
