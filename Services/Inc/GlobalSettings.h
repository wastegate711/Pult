#ifndef PULT_GLOBALSETTINGS_H
#define PULT_GLOBALSETTINGS_H

#include "main.h"

// Адреса.
#define MASTER_ADDRESS          0x01 // Адрес ведущего.
#define CONTROL_BLOCK_ADDRESS   0x02 // Адрес блока управления.
#define PULT_BLOCK_ADDRESS      0x03 // Адрес пульта.

// Настройки.
#define RECEIV_LEN   255 //максимальная длина принимаемой посылки.

// Команды
#define GET_STATUS                      0x01
#define GET_UID                         0x02
#define SET_BACKLIGHT_BUTTON_INSECT     0x03
#define SET_BACKLIGHT_BUTTON_FOAM       0x04
#define SET_BACKLIGHT_BUTTON_FOAM_WATER 0x05
#define SET_BACKLIGHT_BUTTON_HOT_WATER  0x06
#define SET_BACKLIGHT_BUTTON_COOL_WATER 0x07
#define SET_BACKLIGHT_BUTTON_VOSK       0x08
#define SET_BACKLIGHT_BUTTON_OSMOS      0x09
#define SET_BACKLIGHT_BUTTON_STOP       0x0A

#endif //PULT_GLOBALSETTINGS_H
