#include "crc.h"

/**
 * @brief Initialize hardware CRC peripheral.
 */
void CRC32_Init(void)
{
    // Enable CRC clock on AHB
    RCC->AHBENR |= RCC_AHBENR_CRCEN;

    // Reset CRC data register and internal state
    CRC->CR = CRC_CR_RESET;
}

/**
 * @brief Calculate CRC32 for a buffer (word-aligned).
 */
uint32_t CRC32_Calculate(uint32_t *data, uint32_t length)
{
    CRC32_Init();

    for (uint32_t i = 0; i < length; i++)
    {
        CRC->DR = data[i];
    }

    return CRC->DR;
}

/**
 * @brief Calculate CRC32 for a memory range (e.g., flash).
 */
uint32_t CRC32_MemoryRange(uint32_t startAddr, uint32_t length)
{
    CRC32_Init();

    // Process 32-bit words
    uint32_t endAddr = startAddr + length;
    for (uint32_t addr = startAddr; addr < endAddr; addr += 4)
    {
        uint32_t data = *(uint32_t *)addr;
        CRC->DR = data;
    }

    return CRC->DR;
}
