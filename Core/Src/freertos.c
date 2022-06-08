/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "usart.h"
#include "GlobalSettings.h"
#include "Crc16.h"
#include "SortingRequests.h"
#include "Display.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern uint8_t tx_usart1_data[BUF_LEN];
extern uint8_t rx_usart1_data[BUF_LEN];
bool jettonChanel_1 = false;
bool jettonChanel_2 = false;
bool jettonChanel_3 = false;
/* USER CODE END Variables */
/* Definitions for MainTask */
osThreadId_t MainTaskHandle;
const osThreadAttr_t MainTask_attributes = {
  .name = "MainTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for JettonAcceptor */
osThreadId_t JettonAcceptorHandle;
const osThreadAttr_t JettonAcceptor_attributes = {
  .name = "JettonAcceptor",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartTask02(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
    HAL_UART_Receive_IT(&huart1, rx_usart1_data, RECEIV_LEN);
    DisplayInit();
  /* USER CODE END Init */

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
  /* creation of MainTask */
  MainTaskHandle = osThreadNew(StartDefaultTask, NULL, &MainTask_attributes);

  /* creation of JettonAcceptor */
  JettonAcceptorHandle = osThreadNew(StartTask02, NULL, &JettonAcceptor_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
    /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */

    /* Infinite loop */
    for(;;)
    {
        if(RECEIV_LEN - huart1.RxXferCount != 0)
        {
            if(rx_usart1_data[0] == MASTER_ADDRESS &&
               rx_usart1_data[1] == PULT_BLOCK_ADDRESS &&
               rx_usart1_data[3] == RECEIV_LEN - huart1.RxXferCount)
            {
                if(CompareCrc16(rx_usart1_data) == 1)
                {
                    IncomingRequest(rx_usart1_data);
                }

                memset(rx_usart1_data, 0, sizeof(rx_usart1_data)); // очистка массива
                HAL_UART_AbortReceive(&huart1); //отключение прерываний для входящих данных
                HAL_UART_Receive_IT(&huart1, rx_usart1_data, RECEIV_LEN); //включение прерываний для входящих данных
            } else
            {
                memset(rx_usart1_data, 0, sizeof(rx_usart1_data)); // очистка массива
                HAL_UART_AbortReceive(&huart1); //отключение прерываний для входящих данных
                HAL_UART_Receive_IT(&huart1, rx_usart1_data, RECEIV_LEN); //включение прерываний для входящих данных
            }
        }

        osDelay(30);
    }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the JetonAcceptor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void *argument)
{
  /* USER CODE BEGIN StartTask02 */
    /* Infinite loop */
    for(;;)
    {
        if(HAL_GPIO_ReadPin(TokenAcceptorChanel_1_GPIO_Port, TokenAcceptorChanel_1_Pin) == GPIO_PIN_SET)
            jettonChanel_1 = true;
        if(HAL_GPIO_ReadPin(TokenAcceptorChanel_2_GPIO_Port, TokenAcceptorChanel_2_Pin) == GPIO_PIN_SET)
            jettonChanel_2 = true;
        if(HAL_GPIO_ReadPin(TokenAcceptorChanel_3_GPIO_Port, TokenAcceptorChanel_3_Pin) == GPIO_PIN_SET)
            jettonChanel_3 = true;

        osDelay(10);
    }
  /* USER CODE END StartTask02 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

