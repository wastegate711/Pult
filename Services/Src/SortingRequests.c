#include "SortingRequests.h"

/*
         * Формат сообщений
         * [0] = [адрес ведущего 1 байт]
         * [1] = [адрес ведомого 1 байт]
         * [2] = [команда 1 байт]
         * [3] = [Номер сообщения 1 байт]
         * [4] = [длина сообщения 1 байт]
         * [5] = [данные 0-251 байт]
         * [6-7] = [CRC16-2 байта]
         */

extern uint8_t tx_usart1_data[BUF_LEN];
extern uint32_t displayCount;

/**
 * Функция производит сортировку входящих запросов.
 * @param data Массив который нужно сортировать.
 */
void IncomingRequest(const uint8_t *data)
{
    SetMessageCounter(data[3]);

    switch(data[2])
    {
        case GET_STATUS: //запрос текущего состояния
            GetStatus();
            break;
        case GET_UID: //запрос серийного номера устройства
            GetUID();
            break;
        case SET_BACKLIGHT_BUTTON_INSECT: //установка подсветки кнопки Средство от насекомых
            SetStateBacklightButtonInsect(data[5]);
            break;
        case SET_BACKLIGHT_BUTTON_FOAM: //установка подсветки кнопки Пена
            SetStateBacklightButtonFoam(data[5]);
            break;
        case SET_BACKLIGHT_BUTTON_FOAM_WATER: //установка подсветки кнопки Пена+вода
            SetStateBacklightButtonFoamWater(data[5]);
            break;
        case SET_BACKLIGHT_BUTTON_HOT_WATER: //установка подсветки кнопки Горячая вода
            SetStateBacklightButtonHotWater(data[5]);
            break;
        case SET_BACKLIGHT_BUTTON_COOL_WATER: //установка подсветки кнопки Холодная вода
            SetStateBacklightButtonCoolWater(data[5]);
            break;
        case SET_BACKLIGHT_BUTTON_VOSK: //установка подсветки кнопки Воск
            SetStateBacklightButtonVosk(data[5]);
            break;
        case SET_BACKLIGHT_BUTTON_OSMOS: //установка подсветки кнопки Осмос
            SetStateBacklightButtonOsmos(data[5]);
            break;
        case SET_BACKLIGHT_BUTTON_STOP: //установка подсветки кнопки Стоп
            SetStateBacklightButtonStop(data[5]);
            break;
        case SET_DISPLAY_NUMBER: // установка значения на дисплее
            SetDisplayNumber(data);
            break;
        case GET_SOFTWARE_VERSION: // Запрос версии программы
            GetSoftwareVersion();
            break;
        case LOCK_COIN_ACCEPTOR: // Управление блокировкой монетоприемника
            LockCoinAcceptor(data[5]);
            break;
        case GET_BACKLIGHT_BUTTON_INSECT: // Запрос состояния подсветки кнопки Средство от насекомых
            GetStateBacklightButtonInsect();
            break;
        case GET_BACKLIGHT_BUTTON_FOAM: // Запрос состояния подсветки кнопки Пена
            GetStateBacklightButtonFoam();
            break;
        case GET_BACKLIGHT_BUTTON_FOAM_WATER: // Запрос состояния подсветки кнопки Пена + Вода
            GetStateBacklightButtonFoamWater();
            break;
        case GET_BACKLIGHT_BUTTON_HOT_WATER: // Запрос состояния подсветки кнопки Горячая вода
            GetStateBacklightButtonHotWater();
            break;
        case GET_BACKLIGHT_BUTTON_COOL_WATER: // Запрос состояния подсветки кнопки Холодная вода
            GetStateBacklightButtonCoolWater();
            break;
        case GET_BACKLIGHT_BUTTON_VOSK: // Запрос состояния подсветки кнопки Воск
            GetStateBacklightButtonVosk();
            break;
        case GET_BACKLIGHT_BUTTON_OSMOS: // Запрос состояния подсветки кнопки Осмос
            GetStateBacklightButtonOsmos();
            break;
        case GET_BACKLIGHT_BUTTON_STOP: // Запрос состояния подсветки кнопки Стоп
            GetStateBacklightButtonStop();
            break;
    }
}
