#include "Display.h"

uint8_t aData[2] = {0};
uint32_t displayCount; // содержит число отображаемое на дисплее

void DisplaySendData(uint8_t reg, uint8_t data);

/**
 * Первичная инициализация драйвера MAX7219
 */
void DisplayInit(void)
{
    DisplaySendData(OP_DISPLAYTEST, 0);   //выключаем тестирование дисплея что бы не светился по чём зря.
    DisplaySendData(OP_SHUTDOWN, 1);  //выводим из ждущего режима
    DisplaySendData(OP_INTENSITY, INTENSITY_HIGH);    //устанавливаем интенсивность свечения
    DisplaySendData(OP_SCANLIMIT, SCANLIMIT);    //указываем нужное количество дисплеев, которые будут работать.
    DisplaySendData(OP_DECODEMODE,
                    DECODEMODE);    //включаем режим декодирования т.к. работаем не с матрицой светодиодов, а с 7-сегментным дисплеем
    DisplaySendData(OP_DIGIT0, 1);   //
    DisplaySendData(OP_DIGIT1, 2);   //
    DisplaySendData(OP_DIGIT2, 3 + DP);   //
    DisplaySendData(OP_DIGIT3, 4 + DP);   //устанавливаем первоначальные значения на дсплеях
    DisplaySendData(OP_DIGIT4, 5 + DP);   //все нули и точки зажигаем
    DisplaySendData(OP_DIGIT5, 6 + DP);   //
    DisplaySendData(OP_DIGIT6, 7 + DP);   //
    DisplaySendData(OP_DIGIT7, 8 + DP);   //
}

/**
 * Разделает целое число по сегментам дисплея
 * @param number Число которое нужно вывести на дисплей
 */
void DisplayNumber(volatile uint32_t number)
{
    DisplaySendData(8, number / 10000000);
    DisplaySendData(7, (number / 1000000) % 10);
    DisplaySendData(6, (number / 100000) % 10);
    DisplaySendData(5, (number / 10000) % 10);
    DisplaySendData(4, (number / 1000) % 10);
    DisplaySendData(3, (number / 100) % 10);
    DisplaySendData(2, (number / 10) % 10);
    DisplaySendData(1, number % 10);
}

/**
 * Отправляет данные на дисплей
 * @param reg Адрес регитра
 * @param data Данные
 */
void DisplaySendData(uint8_t reg, uint8_t data)
{
    Cs_SPI1(GPIO_PIN_RESET);
    aData[0] = reg;
    HAL_SPI_Transmit(&hspi1, (uint8_t*)aData, 1, 0xFFFFFFFF);
    aData[0] = data;
    HAL_SPI_Transmit(&hspi1, (uint8_t*)aData, 1, 0xFFFFFFFF);
    Cs_SPI1(GPIO_PIN_SET);
}
