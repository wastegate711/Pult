#include "SortingRequests.h"

extern uint8_t tx_usart1_data[BUF_LEN];
extern uint32_t displayCount;

/**
 * Функция производит сортировку входящих запросов.
 * @param data Массив который нужно сортировать.
 */
void IncomingRequest(const uint8_t *data)
{
    switch(data[2])
    {
        case GET_STATUS: //запрос текущего состояния
            GetStatus();
            break;
        case GET_UID: //запрос серийного номера устройства
            GetUID();
            break;
        case SET_BACKLIGHT_BUTTON_INSECT: //установка подсветки кнопки Средство от насекомых
            SetStateBacklightButtonInsect(data[4]);
            break;
        case SET_BACKLIGHT_BUTTON_FOAM: //установка подсветки кнопки Пена
            SetStateBacklightButtonFoam(data[4]);
            break;
        case SET_BACKLIGHT_BUTTON_FOAM_WATER: //установка подсветки кнопки Пена+вода
            SetStateBacklightButtonFoamWater(data[4]);
            break;
        case SET_BACKLIGHT_BUTTON_HOT_WATER: //установка подсветки кнопки Горячая вода
            SetStateBacklightButtonHotWater(data[4]);
            break;
        case SET_BACKLIGHT_BUTTON_COOL_WATER: //установка подсветки кнопки Холодная вода
            SetStateBacklightButtonCoolWater(data[4]);
            break;
        case SET_BACKLIGHT_BUTTON_VOSK: //установка подсветки кнопки Воск
            SetStateBacklightButtonVosk(data[4]);
            break;
        case SET_BACKLIGHT_BUTTON_OSMOS: //установка подсветки кнопки Осмос
            SetStateBacklightButtonOsmos(data[4]);
            break;
        case SET_BACKLIGHT_BUTTON_STOP: //установка подсветки кнопки Стоп
            SetStateBacklightButtonStop(data[4]);
            break;
        case SET_DISPLAY_NUMBER: // установка значения на дисплее
            SetDisplayNumber(data);
            break;
        case GET_SOFTWARE_VERSION: // Запрос версии программы
            GetSoftwareVersion();
            break;
        case LOCK_COIN_ACCEPTOR: // Управление блокировкой монетоприемника
            LockCoinAcceptor(data[4]);
            break;
    }
}
