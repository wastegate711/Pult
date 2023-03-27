#include "AnswersToQuestion.h"

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

uint8_t GetStatePeripheral(void);

extern uint8_t tx_usart1_data[BUF_LEN];
//флаги состояния Устройства
bool getUidFlag = false; // запрашивался UID или нет
bool getSoftwareFlag = false; // запрашивалась версия программы или нет
//флаги монетоприемника
extern bool lockCoinAcceptorFlag;
extern bool jettonChanel_1;
extern bool jettonChanel_2;
extern bool jettonChanel_3;
//флаги нажатий кнопок
extern bool buttonInsectFlag;
extern bool buttonFoamFlag;
extern bool buttonFoamWaterFlag;
extern bool buttonHotWaterFlag;
extern bool buttonCoolWaterFlag;
extern bool buttonVoskFlag;
extern bool buttonOsmosFlag;
extern bool buttonStopFlag;
extern bool buttonInkasFlag;
extern uint8_t messageCounter;
uint16_t crc;

/*
 * Формат ответа
 * [0] = Адрес ведущего
 * [1] = Адрес ведомого
 * [2] = Команда
 * [3] = Номер сообщения
 * [4] = Длинна посылки (включая CRC16)
 * [5] = Данные
 * [^2] = CRC16
 * [^1] = CRC16
 */

/**
 * Устанавливает в счетчик номера сообщений.
 * @param number Номер сообщения.
 */
void SetMessageCounter(uint8_t number)
{
    messageCounter = number;
}

/**
 * Получает номер последнего входящего сообщения.
 * @return Номер сообщения.
 */
uint8_t GetMessageCounter()
{
    return messageCounter;
}

/**
 * Отправляет ведущему текущее состояние
 */
void GetStatus(void)
{
    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = PULT_BLOCK_ADDRESS;
    tx_usart1_data[2] = GetStatePeripheral();
    tx_usart1_data[3] = GetMessageCounter();
    tx_usart1_data[4] = 0x09;
    tx_usart1_data[5] = 0x00;
    tx_usart1_data[6] = 0x00;
    crc = GetCrc16(tx_usart1_data, tx_usart1_data[4] - 2);
    tx_usart1_data[7] = crc >> 8;
    tx_usart1_data[8] = crc;

    SendDataUsart1(tx_usart1_data, tx_usart1_data[4]);
}

/**
 * Отправляет ведущему серийный номер устройства
 */
void GetUID(void)
{
    getUidFlag = true;
    uint32_t serialNumberPart1 = ReadFlash(UID_BASE_ADDRESS);
    uint32_t serialNumberPart2 = ReadFlash(UID_BASE_ADDRESS + 4);
    uint32_t serialNumberPart3 = ReadFlash(UID_BASE_ADDRESS + 8);

    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = PULT_BLOCK_ADDRESS;
    tx_usart1_data[2] = GET_UID;
    tx_usart1_data[3] = GetMessageCounter();
    tx_usart1_data[4] = 0x13;
    tx_usart1_data[5] = serialNumberPart1 >> 24;
    tx_usart1_data[6] = serialNumberPart1 >> 16;
    tx_usart1_data[7] = serialNumberPart1 >> 8;
    tx_usart1_data[8] = serialNumberPart1;
    tx_usart1_data[9] = serialNumberPart2 >> 24;
    tx_usart1_data[10] = serialNumberPart2 >> 16;
    tx_usart1_data[11] = serialNumberPart2 >> 8;
    tx_usart1_data[12] = serialNumberPart2;
    tx_usart1_data[13] = serialNumberPart3 >> 24;
    tx_usart1_data[14] = serialNumberPart3 >> 16;
    tx_usart1_data[15] = serialNumberPart3 >> 8;
    tx_usart1_data[16] = serialNumberPart3;
    crc = GetCrc16(tx_usart1_data, tx_usart1_data[4] - 2);
    tx_usart1_data[17] = crc >> 8;
    tx_usart1_data[18] = crc;

    SendDataUsart1(tx_usart1_data, tx_usart1_data[4]);
}

/**
 * Управляет подсветкой кнопки Средство от насекомых
 * @param state 1-включено/0-выключено
 */
void SetStateBacklightButtonInsect(uint8_t state)
{
    if(state == 0x01)
        SetBacklightButtonInsect(GPIO_PIN_SET);
    else if(state == 0x00)
        SetBacklightButtonInsect(GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Пена
 * @param state 1-включено/0-выключено
 */
void SetStateBacklightButtonFoam(uint8_t state)
{
    if(state == 0x01)
        SetBacklightButtonFoam(GPIO_PIN_SET);
    else if(state == 0x00)
        SetBacklightButtonFoam(GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Пена+Вода
 * @param state 1-включено/0-выключено
 */
void SetStateBacklightButtonFoamWater(uint8_t state)
{
    if(state == 0x01)
        SetBacklightButtonFoamWater(GPIO_PIN_SET);
    else if(state == 0x00)
        SetBacklightButtonFoamWater(GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Горячая Вода
 * @param state 1-включено/0-выключено
 */
void SetStateBacklightButtonHotWater(uint8_t state)
{
    if(state == 0x01)
        SetBacklightButtonHotWater(GPIO_PIN_SET);
    else if(state == 0x00)
        SetBacklightButtonHotWater(GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Холодная Вода
 * @param state 1-включено/0-выключено
 */
void SetStateBacklightButtonCoolWater(uint8_t state)
{
    if(state == 0x01)
        SetBacklightCoolWater(GPIO_PIN_SET);
    else if(state == 0x00)
        SetBacklightCoolWater(GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Воск
 * @param state 1-включено/0-выключено
 */
void SetStateBacklightButtonVosk(uint8_t state)
{
    if(state == 0x01)
        SetBacklightButtonVosk(GPIO_PIN_SET);
    else if(state == 0x00)
        SetBacklightButtonVosk(GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Осмос
 * @param state 1-включено/0-выключено
 */
void SetStateBacklightButtonOsmos(uint8_t state)
{
    if(state == 0x01)
        SetBacklightButtonOsmos(GPIO_PIN_SET);
    else if(state == 0x00)
        SetBacklightButtonOsmos(GPIO_PIN_RESET);
}

/**
 * Управляет подсветкой кнопки Стоп
 * @param state 1-включено/0-выключено
 */
void SetStateBacklightButtonStop(uint8_t state)
{
    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = PULT_BLOCK_ADDRESS;
    tx_usart1_data[2] = SET_BACKLIGHT_BUTTON_STOP;
    tx_usart1_data[3] = GetMessageCounter();
    tx_usart1_data[4] = 0x08;
    tx_usart1_data[5] = state;
    crc = GetCrc16(tx_usart1_data, tx_usart1_data[4] - 2);
    tx_usart1_data[6] = crc >> 8;
    tx_usart1_data[7] = crc;

    if(state == 0x01)
        SetBacklightButtonStop(GPIO_PIN_SET);
    else if(state == 0x00)
        SetBacklightButtonStop(GPIO_PIN_RESET);

    SendDataUsart1(tx_usart1_data, tx_usart1_data[4]);
}

/**
 * Принимает от ведищего данные и устанавливает значение на дисплее.
 * @param pData
 */
void SetDisplayNumber(const uint8_t *pData)
{
    uint32_t number = pData[5];
    (uint32_t)number << 8;
    number = pData[6];

    DisplayNumber(ConvertDigits(pData));
}

/**
 * Проверяет установленые флаги и вернет код команды для отправки ведущему
 * @return Код команды
 */
uint8_t GetStatePeripheral(void)
{
    // проверка флагов состояния
    if(!getUidFlag) // если флаг сброшен значит еще не запрашивался серийный номер
    {
        return UID_FLAG_RESET;
    } else if(!getSoftwareFlag) // если флаг сброшен значит еще не запрашивалась версия программы
    {
        return SOFTWARE_FLAG_RESET;
    }
    // Проверка в какой канал жетоноприемка был проброшен жетон
    if(jettonChanel_1)
    {
        jettonChanel_1 = false;
        return PUSH_JETTON_CHANNEL_1;
    } else if(jettonChanel_2)
    {
        jettonChanel_2 = false;
        return PUSH_JETTON_CHANNEL_2;
    } else if(jettonChanel_3)
    {
        jettonChanel_3 = false;
        return PUSH_JETTON_CHANNEL_3;
    }

    // Проверка какая кнопка была нажата
    if(buttonInsectFlag)
    {
        buttonInsectFlag = false;
        return PUSH_BUTTON_INSECT;
    } else if(buttonFoamFlag)
    {
        buttonFoamFlag = false;
        return PUSH_BUTTON_FOAM;
    } else if(buttonFoamWaterFlag)
    {
        buttonFoamWaterFlag = false;
        return PUSH_BUTTON_FOAM_WATER;
    } else if(buttonHotWaterFlag)
    {
        buttonHotWaterFlag = false;
        return PUSH_BUTTON_HOT_WATER;
    } else if(buttonCoolWaterFlag)
    {
        buttonCoolWaterFlag = false;
        return PUSH_BUTTON_COOL_WATER;
    } else if(buttonVoskFlag)
    {
        buttonVoskFlag = false;
        return PUSH_BUTTON_VOSK;
    } else if(buttonOsmosFlag)
    {
        buttonOsmosFlag = false;
        return PUSH_BUTTON_OSMOS;
    } else if(buttonStopFlag)
    {
        buttonStopFlag = false;
        return PUSH_BUTTON_STOP;
    }

    return GET_STATUS;
}

/**
 * Возвращает версию программы.
 */
void GetSoftwareVersion(void)
{
    getSoftwareFlag = true;
    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = PULT_BLOCK_ADDRESS;
    tx_usart1_data[2] = GET_SOFTWARE_VERSION;
    tx_usart1_data[3] = GetMessageCounter();
    tx_usart1_data[4] = 0x09;
    tx_usart1_data[5] = SOFTWARE_VERSION_MAJOR;
    tx_usart1_data[6] = SOFTWARE_VERSION_MINOR;
    crc = GetCrc16(tx_usart1_data, tx_usart1_data[4] - 2);
    tx_usart1_data[7] = crc >> 8;
    tx_usart1_data[8] = crc;

    SendDataUsart1(tx_usart1_data, tx_usart1_data[4]);
}

/**
 * Упраление блокировкой монетоприемника.
 * @param state Если 1-монетоприемник заблокирован, 0-разблокирован.
 */
void LockCoinAcceptor(uint8_t state)
{
    if(state == 1)
        lockCoinAcceptorFlag = true;
    else if(state == 0)
        lockCoinAcceptorFlag = false;
}