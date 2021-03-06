/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include <stdbool.h>
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
void Cs_Rs485_Usart1(GPIO_PinState state);
void SetBacklightButtonInsect(GPIO_PinState state);
void SetBacklightButtonFoam(GPIO_PinState state);
void SetBacklightButtonFoamWater(GPIO_PinState state);
void SetBacklightButtonHotWater(GPIO_PinState state);
void SetBacklightCoolWater(GPIO_PinState state);
void SetBacklightButtonVosk(GPIO_PinState state);
void SetBacklightButtonOsmos(GPIO_PinState state);
void SetBacklightButtonStop(GPIO_PinState state);
void Cs_SPI1(GPIO_PinState state);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

