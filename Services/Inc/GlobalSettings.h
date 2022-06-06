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
#define GET_STATUS                      0x01 // запрос текущего состояния
#define GET_UID                         0x02 // запрос серийного номера устройства
#define SET_BACKLIGHT_BUTTON_INSECT     0x03 // включение/выключение подсветки кнопки Средство от насекомых
#define SET_BACKLIGHT_BUTTON_FOAM       0x04 // включение/выключение подсветки кнопки Пена
#define SET_BACKLIGHT_BUTTON_FOAM_WATER 0x05 // включение/выключение подсветки кнопки Пена + вода
#define SET_BACKLIGHT_BUTTON_HOT_WATER  0x06 // включение/выключение подсветки кнопки Горячая вода
#define SET_BACKLIGHT_BUTTON_COOL_WATER 0x07 // включение/выключение подсветки кнопки Холодная вода
#define SET_BACKLIGHT_BUTTON_VOSK       0x08 // включение/выключение подсветки кнопки Воск
#define SET_BACKLIGHT_BUTTON_OSMOS      0x09 // включение/выключение подсветки кнопки Осмос
#define SET_BACKLIGHT_BUTTON_STOP       0x0A // включение/выключение подсветки кнопки Стоп
#define PUSH_BUTTON_FUNCTIONS           0x0B // Нажата кнопка выбора программы (воск, осмос, пена и др.)
#define PUSH_BUTTON_COLLECTION          0x0C // Нажата кнопка Инкассация

#endif //PULT_GLOBALSETTINGS_H
