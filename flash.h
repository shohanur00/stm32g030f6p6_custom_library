#ifndef FLASH_H
#define FLASH_H

#include "stm32g030xx.h" // or your device header

#define FLASH_KEY1 0x45670123
#define FLASH_KEY2 0xCDEF89AB
#define FLASH_PAGE_SIZE  0x800   // 2KB
#define FLASH_BASE_ADDR  0x08000000



void flash_erase_page(uint32_t page_address);



#endif