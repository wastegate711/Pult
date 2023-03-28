#ifndef PULT_GLOBALSETTINGS_H
#define PULT_GLOBALSETTINGS_H

#include "main.h"

// Адреса.
#define MASTER_ADDRESS          0x01 // Адрес ведущего.
#define CONTROL_BLOCK_ADDRESS   0x02 // Адрес блока управления.
#define PULT_BLOCK_ADDRESS      0x03 // Адрес пульта.

// Настройки.
#define RECEIV_LEN   255 //максимальная длина принимаемой посылки.
#define UID_BASE_ADDRESS        0x1FFF7A10 //Начальный адрес UID
#define SOFTWARE_VERSION_MAJOR  0x00 // Версия программы старший байт до точки (*.1)
#define SOFTWARE_VERSION_MINOR  0x01 // Версия программы младший байт после точки (1.*)

// Команды
#define GET_STATUS                      0x01 // запрос текущего состояния
#define GET_UID                         0x02 // запрос серийного номера устройства
#define SET_BACKLIGHT_BUTTON_INSECT     0x16 // включение/выключение подсветки кнопки Средство от насекомых
#define SET_BACKLIGHT_BUTTON_FOAM       0x17 // включение/выключение подсветки кнопки Пена
#define SET_BACKLIGHT_BUTTON_FOAM_WATER 0x18 // включение/выключение подсветки кнопки Пена + вода
#define SET_BACKLIGHT_BUTTON_HOT_WATER  0x19 // включение/выключение подсветки кнопки Горячая вода
#define SET_BACKLIGHT_BUTTON_COOL_WATER 0x1A // включение/выключение подсветки кнопки Холодная вода
#define SET_BACKLIGHT_BUTTON_VOSK       0x1B // включение/выключение подсветки кнопки Воск
#define SET_BACKLIGHT_BUTTON_OSMOS      0x1C // включение/выключение подсветки кнопки Осмос
#define SET_BACKLIGHT_BUTTON_STOP       0x1D // включение/выключение подсветки кнопки Стоп
#define PUSH_BUTTON_INSECT              0x1E // Нажата кнопка Средство от насекомых
#define PUSH_BUTTON_COLLECTION          0x1F // Нажата кнопка Инкассация
#define SET_DISPLAY_NUMBER              0x20 // Установка значения на дисплее
#define PUSH_JETTON_CHANNEL_1           0x21 // Принят жетон по первому каналу
#define PUSH_JETTON_CHANNEL_2           0x22 // Принят жетон по 2 каналу
#define PUSH_JETTON_CHANNEL_3           0x23 // Принят жетон по 3 каналу
#define PUSH_BUTTON_FOAM                0x24 // Нажата кнопка Пена
#define PUSH_BUTTON_FOAM_WATER          0x25 // Нажата кнопка Пена + вода
#define PUSH_BUTTON_HOT_WATER           0x26 // Нажата кнопка Горячая вода
#define PUSH_BUTTON_COOL_WATER          0x27 // Нажата кнопка Холодная вода
#define PUSH_BUTTON_VOSK                0x28 // Нажата кнопка Воск
#define PUSH_BUTTON_OSMOS               0x29 // Нажата кнопка Осмос
#define PUSH_BUTTON_STOP                0x2A // Нажата кнопка Стоп
#define GET_SOFTWARE_VERSION            0x2B // Запрос версии программы
#define UID_FLAG_RESET                  0x2C // UID не запрашивался ведущим
#define SOFTWARE_FLAG_RESET             0x2D // Версия программы не запрашивалась
#define LOCK_COIN_ACCEPTOR              0x2E // Управление блокировкой монетоприемника
#define GET_BACKLIGHT_BUTTON_INSECT     0x2F // Запрос состояния подсветки кнопки Средство от насекомых
#define GET_BACKLIGHT_BUTTON_FOAM       0x30 // Запрос состояния подсветки кнопки Пена
#define GET_BACKLIGHT_BUTTON_FOAM_WATER 0x31 // Запрос состояния подсветки кнопки Пена + вода
#define GET_BACKLIGHT_BUTTON_HOT_WATER  0x32 // Запрос состояния подсветки кнопки Горячая вода
#define GET_BACKLIGHT_BUTTON_COOL_WATER 0x33 // Запрос состояния подсветки кнопки Холодная вода
#define GET_BACKLIGHT_BUTTON_VOSK       0x34 // Запрос состояния подсветки кнопки Воск
#define GET_BACKLIGHT_BUTTON_OSMOS      0x35 // Запрос состояния подсветки кнопки Осмос
#define GET_BACKLIGHT_BUTTON_STOP       0x36 // Запрос состояния подсветки кнопки Стоп

#endif //PULT_GLOBALSETTINGS_H
