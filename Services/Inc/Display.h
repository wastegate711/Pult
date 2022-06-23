#ifndef PULT_DISPLAY_H
#define PULT_DISPLAY_H

#include "main.h"
#include "spi.h"
#include "gpio.h"
#include "cmsis_os2.h"

//OPTIONS
#define SCANLIMIT_3 0x03
#define INTENSITY_HIGH 12
#define INTENSITY_MED 7
#define INTENSITY_LOW 3
#define DP 0x80
#define MINUS 0x0a
#define BLANK 0x0f
#define DECODEMODE 0xff

//OPCODES
#define OP_NOOP   0
#define OP_DIGIT0 1
#define OP_DIGIT1 2
#define OP_DIGIT2 3
#define OP_DIGIT3 4
#define OP_DIGIT4 5
#define OP_DIGIT5 6
#define OP_DIGIT6 7
#define OP_DIGIT7 8
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15

void DisplayInit(void);
void DisplayNumber(volatile uint32_t number);
uint32_t ConvertDigits(const uint8_t *pDAta);

#endif //PULT_DISPLAY_H
