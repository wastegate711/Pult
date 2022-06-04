#ifndef PULT_CRC16_H
#define PULT_CRC16_H

#include "main.h"

uint16_t GetCrc16(uint8_t *data, int length);
uint8_t CompareCrc16(uint8_t *Buf);//функция сравнения CRC

#endif //PULT_CRC16_H
