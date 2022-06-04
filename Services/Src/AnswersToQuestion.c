#include "AnswersToQuestion.h"

extern uint8_t tx_usart1_data[BUF_LEN];

uint16_t crc;

/*
 * Формат ответа
 * [0] = Адрес ведущего
 * [1] = Адрес ведомого
 * [2] = Команда
 * [3] = Длинна посылки (включая CRC16)
 * [4] = Данные
 * [^2] = CRC16
 * [^1] = CRC16
 */

/**
 * Отправляет ведущему текущее состояние
 */
void GetStatus(void)
{
    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = PULT_BLOCK_ADDRESS;
    tx_usart1_data[2] = GET_STATUS;
    tx_usart1_data[3] = 0x08;
    tx_usart1_data[4] = 0x00;
    tx_usart1_data[5] = 0x00;
    crc = GetCrc16(tx_usart1_data, tx_usart1_data[3] - 2);
    tx_usart1_data[6] = crc >> 8;
    tx_usart1_data[7] = crc;

    SendDataUsart1(tx_usart1_data, tx_usart1_data[3]);
}
