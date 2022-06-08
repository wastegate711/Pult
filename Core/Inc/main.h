/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ButtonInkas_Pin GPIO_PIN_2
#define ButtonInkas_GPIO_Port GPIOE
#define ButtonInkas_EXTI_IRQn EXTI2_IRQn
#define CS_SPI1_Pin GPIO_PIN_4
#define CS_SPI1_GPIO_Port GPIOA
#define LedStop_Pin GPIO_PIN_8
#define LedStop_GPIO_Port GPIOE
#define LedOsmos_Pin GPIO_PIN_9
#define LedOsmos_GPIO_Port GPIOE
#define LedVosk_Pin GPIO_PIN_10
#define LedVosk_GPIO_Port GPIOE
#define LedInsect_Pin GPIO_PIN_11
#define LedInsect_GPIO_Port GPIOE
#define LedFoam_Pin GPIO_PIN_12
#define LedFoam_GPIO_Port GPIOE
#define LedFoamWater_Pin GPIO_PIN_13
#define LedFoamWater_GPIO_Port GPIOE
#define LedHotWater_Pin GPIO_PIN_14
#define LedHotWater_GPIO_Port GPIOE
#define LedCoolWater_Pin GPIO_PIN_15
#define LedCoolWater_GPIO_Port GPIOE
#define ButtonOsmos_Pin GPIO_PIN_9
#define ButtonOsmos_GPIO_Port GPIOD
#define ButtonOsmos_EXTI_IRQn EXTI9_5_IRQn
#define ButtonStop_Pin GPIO_PIN_10
#define ButtonStop_GPIO_Port GPIOD
#define ButtonStop_EXTI_IRQn EXTI15_10_IRQn
#define ButtonVosk_Pin GPIO_PIN_11
#define ButtonVosk_GPIO_Port GPIOD
#define ButtonVosk_EXTI_IRQn EXTI15_10_IRQn
#define ButtonInsect_Pin GPIO_PIN_13
#define ButtonInsect_GPIO_Port GPIOD
#define ButtonInsect_EXTI_IRQn EXTI15_10_IRQn
#define ButtonFoam_Pin GPIO_PIN_14
#define ButtonFoam_GPIO_Port GPIOD
#define ButtonFoam_EXTI_IRQn EXTI15_10_IRQn
#define ButtonFoamWater_Pin GPIO_PIN_15
#define ButtonFoamWater_GPIO_Port GPIOD
#define ButtonFoamWater_EXTI_IRQn EXTI15_10_IRQn
#define ButtonCoolWater_Pin GPIO_PIN_6
#define ButtonCoolWater_GPIO_Port GPIOC
#define ButtonCoolWater_EXTI_IRQn EXTI9_5_IRQn
#define ButtonHotWater_Pin GPIO_PIN_7
#define ButtonHotWater_GPIO_Port GPIOC
#define ButtonHotWater_EXTI_IRQn EXTI9_5_IRQn
#define Usart1_CS_RS485_Pin GPIO_PIN_11
#define Usart1_CS_RS485_GPIO_Port GPIOA
#define TokenAcceptorChanel_3_Pin GPIO_PIN_8
#define TokenAcceptorChanel_3_GPIO_Port GPIOB
#define TokenAcceptorChanel_2_Pin GPIO_PIN_9
#define TokenAcceptorChanel_2_GPIO_Port GPIOB
#define TokenAcceptorChanel_1_Pin GPIO_PIN_0
#define TokenAcceptorChanel_1_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
