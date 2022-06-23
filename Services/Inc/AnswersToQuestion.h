#ifndef PULT_ANSWERTOQUESTION_H
#define PULT_ANSWERTOQUESTION_H

#include "main.h"
#include "GlobalSettings.h"
#include "usart.h"
#include "Crc16.h"
#include "gpio.h"
#include "Flash.h"
#include "Display.h"

void GetStatus(void);
void GetUID(void);
void SetStateBacklightButtonStop(uint8_t state);
void SetStateBacklightButtonOsmos(uint8_t state);
void SetStateBacklightButtonVosk(uint8_t state);
void SetStateBacklightButtonCoolWater(uint8_t state);
void SetStateBacklightButtonHotWater(uint8_t state);
void SetStateBacklightButtonFoamWater(uint8_t state);
void SetStateBacklightButtonFoam(uint8_t state);
void SetStateBacklightButtonInsect(uint8_t state);
void SetDisplayNumber(const uint8_t *pData);
void GetSoftwareVersion(void);
void LockCoinAcceptor(uint8_t state);

#endif //PULT_ANSWERTOQUESTION_H
