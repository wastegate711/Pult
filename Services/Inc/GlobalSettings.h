#ifndef PULT_GLOBALSETTINGS_H
#define PULT_GLOBALSETTINGS_H

#include "main.h"

// Адреса.
#define MASTER_ADDRESS          0x01 // Адрес ведущего.
#define CONTROL_BLOCK_ADDRESS   0x02 // Адрес блока управления.
#define PULT_BLOCK_ADDRESS      0x03 // Адрес пульта.

// Настройки.
#define RECEIV_LEN   255 //максимальная длина принимаемой посылки.

// Команды запросов
#define GET_STATUS 0x01
#define GET_UID 0x02

#endif //PULT_GLOBALSETTINGS_H
