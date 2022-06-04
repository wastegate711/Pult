#include "SortingRequests.h"

extern uint8_t tx_usart1_data[BUF_LEN];

/**
 * Функция производит сортировку входящих запросов.
 * @param data Массив который нужно сортировать.
 */
void IncomingRequest(const uint8_t *data)
{
    switch(data[2])
    {
        case GET_STATUS:
            GetStatus();
            break;
        //case GET_UID:
            //GetUID();
            break;
    }
}
