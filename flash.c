#include "flash.h"


static void flash_unlock(void)
{
    if (FLASH->CR & FLASH_CR_LOCK)
    {
        FLASH->KEYR = FLASH_KEY1;
        FLASH->KEYR = FLASH_KEY2;
    }
}

static void flash_lock(void)
{
    FLASH->CR |= FLASH_CR_LOCK;
}

static void flash_clear_flags(void) {
    FLASH->SR |= (FLASH_SR_OPERR | FLASH_SR_PROGERR | FLASH_SR_WRPERR |
                  FLASH_SR_PGAERR | FLASH_SR_SIZERR | FLASH_SR_PGSERR |
                  FLASH_SR_MISERR | FLASH_SR_FASTERR | FLASH_SR_EOP);
}

void flash_erase_page(uint32_t page_address)
{
    while (FLASH->SR & FLASH_SR_BSY1);   // wait if busy
	
		flash_clear_flags();

    flash_unlock();

    FLASH->CR |= FLASH_CR_PER;          // enable page erase
    FLASH->CR &= ~FLASH_CR_PNB_Msk;     // clear page number bits
    FLASH->CR |= ((page_address - FLASH_BASE_ADDR) / FLASH_PAGE_SIZE) << FLASH_CR_PNB_Pos;
    FLASH->CR |= FLASH_CR_STRT;         // start erase

    while (FLASH->SR & FLASH_SR_BSY1);   // wait done

    FLASH->CR &= ~FLASH_CR_PER;         // disable page erase
    FLASH->SR |= FLASH_SR_EOP;          // clear EOP flag



    flash_lock();
}
