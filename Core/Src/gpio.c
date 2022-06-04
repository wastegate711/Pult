/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
bool buttonInsectFlag = false;
bool buttonFoamFlag = false;
bool buttonFoamWaterFlag = false;
bool buttonHotWaterFlag = false;
bool buttonCoolWaterFlag = false;
bool buttonVoskFlag = false;
bool buttonOsmosFlag = false;
bool buttonStopFlag = false;
/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOE, LedStop_Pin | LedOsmos_Pin | LedVosk_Pin | LedInsect_Pin
                             | LedFoam_Pin | LedFoamWater_Pin | LedHotWater_Pin | LedCoolWater_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(Usart1_CS_RS485_GPIO_Port, Usart1_CS_RS485_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = ButtonInkas_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(ButtonInkas_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : PEPin PEPin PEPin PEPin
                             PEPin PEPin PEPin PEPin */
    GPIO_InitStruct.Pin = LedStop_Pin | LedOsmos_Pin | LedVosk_Pin | LedInsect_Pin
                          | LedFoam_Pin | LedFoamWater_Pin | LedHotWater_Pin | LedCoolWater_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /*Configure GPIO pins : PDPin PDPin PDPin PDPin
                             PDPin PDPin */
    GPIO_InitStruct.Pin = ButtonOsmos_Pin | ButtonStop_Pin | ButtonVosk_Pin | ButtonInsect_Pin
                          | ButtonFoam_Pin | ButtonFoamWater_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Configure GPIO pins : PCPin PCPin */
    GPIO_InitStruct.Pin = ButtonCoolWater_Pin | ButtonHotWater_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = Usart1_CS_RS485_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(Usart1_CS_RS485_GPIO_Port, &GPIO_InitStruct);

    /* EXTI interrupt init*/
    HAL_NVIC_SetPriority(EXTI2_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(EXTI2_IRQn);

    HAL_NVIC_SetPriority(EXTI9_5_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */
/**
 * Управление выводом управляющим режимом работы микросхемы RS-485
 * @param state Статус SET-передача RESET-прием
 */
void Cs_Rs485_Usart1(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Usart1_CS_RS485_GPIO_Port, Usart1_CS_RS485_Pin, state);
}

/**
 * Обработчик прерываний
 * @param GPIO_Pin Номер порта на котором произошло прерывание
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    switch(GPIO_Pin)
    {
        case ButtonHotWater_Pin:
            buttonHotWaterFlag = true;
            break;
        case ButtonCoolWater_Pin:
            buttonCoolWaterFlag = true;
            break;
        case ButtonFoamWater_Pin:
            buttonFoamWaterFlag = true;
            break;
        case ButtonFoam_Pin:
            buttonFoamFlag = true;
            break;
        case ButtonInsect_Pin:
            buttonInsectFlag = true;
            break;
        case ButtonVosk_Pin:
            buttonVoskFlag = true;
            break;
        case ButtonStop_Pin:
            buttonStopFlag = true;
            break;
        case ButtonOsmos_Pin:
            buttonOsmosFlag = true;
            break;
        default:
            break;
    }
}

/**
 * Управляет подсветкой кнопки Средство от насекомых
 * @param state SET/RESET Включено/Выключено
 */
void SetBacklightButtonInsect(GPIO_PinState state)
{
    if(state == GPIO_PIN_SET)
        HAL_GPIO_WritePin(LedInsect_GPIO_Port, LedInsect_Pin, GPIO_PIN_SET);
    else if(state == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(LedInsect_GPIO_Port, LedInsect_Pin, GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Пена
 * @param state SET/RESET Включено/Выключено
 */
void SetBacklightButtonFoam(GPIO_PinState state)
{
    if(state == GPIO_PIN_SET)
        HAL_GPIO_WritePin(LedFoam_GPIO_Port, LedFoam_Pin, GPIO_PIN_SET);
    else if(state == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(LedFoam_GPIO_Port, LedFoam_Pin, GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Пена + Вода
 * @param state SET/RESET Включено/Выключено
 */
void SetBacklightButtonFoamWater(GPIO_PinState state)
{
    if(state == GPIO_PIN_SET)
        HAL_GPIO_WritePin(LedFoamWater_GPIO_Port, LedFoamWater_Pin, GPIO_PIN_SET);
    else if(state == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(LedFoamWater_GPIO_Port, LedFoamWater_Pin, GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Горячая Вода
 * @param state SET/RESET Включено/Выключено
 */
void SetBacklightButtonHotWater(GPIO_PinState state)
{
    if(state == GPIO_PIN_SET)
        HAL_GPIO_WritePin(LedHotWater_GPIO_Port, LedHotWater_Pin, GPIO_PIN_SET);
    else if(state == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(LedHotWater_GPIO_Port, LedHotWater_Pin, GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Холодная Вода
 * @param state SET/RESET Включено/Выключено
 */
void SetBacklightCoolWater(GPIO_PinState state)
{
    if(state == GPIO_PIN_SET)
        HAL_GPIO_WritePin(LedCoolWater_GPIO_Port, LedCoolWater_Pin, GPIO_PIN_SET);
    else if(state == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(LedCoolWater_GPIO_Port, LedCoolWater_Pin, GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Воск
 * @param state SET/RESET Включено/Выключено
 */
void SetBacklightButtonVosk(GPIO_PinState state)
{
    if(state == GPIO_PIN_SET)
        HAL_GPIO_WritePin(LedVosk_GPIO_Port, LedVosk_Pin, GPIO_PIN_SET);
    else if(state == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(LedVosk_GPIO_Port, LedVosk_Pin, GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Осмос
 * @param state SET/RESET Включено/Выключено
 */
void SetBacklightButtonOsmos(GPIO_PinState state)
{
    if(state == GPIO_PIN_SET)
        HAL_GPIO_WritePin(LedOsmos_GPIO_Port, LedOsmos_Pin, GPIO_PIN_SET);
    else if(state == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(LedOsmos_GPIO_Port, LedOsmos_Pin, GPIO_PIN_RESET);
}
/**
 * Управляет подсветкой кнопки Стоп
 * @param state SET/RESET Включено/Выключено
 */
void SetBacklightButtonStop(GPIO_PinState state)
{
    if(state == GPIO_PIN_SET)
        HAL_GPIO_WritePin(LedStop_GPIO_Port, LedStop_Pin, GPIO_PIN_SET);
    else if(state == GPIO_PIN_RESET)
        HAL_GPIO_WritePin(LedStop_GPIO_Port, LedStop_Pin, GPIO_PIN_RESET);
}
/* USER CODE END 2 */

















