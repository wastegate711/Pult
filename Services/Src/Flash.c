#include "Flash.h"

/**
 * Читает данные из указанной области памяти
 * @param address Адрес памяти
 * @return Вернет содержимое адреса
 */
uint32_t ReadFlash(uint32_t address)
{
    return *(uint32_t*)address;
}