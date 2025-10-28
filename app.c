#include "stm32g030xx.h"
#include "app.h"
#include "crc.h"
#include "gpio.h"



#define APP_START_ADDR   0x08000000
#define APP_SIZE_BYTES   (64 * 1024)   // Example: 64KB firmware
#define	delay_interval		1000


uint32_t fw_crc;






void App_Setup(void){
	

	GPIO_Init(GPIOA,5,GPIO_MODE_OUTPUT,GPIO_OTYPE_PP,GPIO_NOPULL,GPIO_SPEED_LOW);
	GPIO_Init(GPIOA,6,GPIO_MODE_OUTPUT,GPIO_OTYPE_PP,GPIO_NOPULL,GPIO_SPEED_LOW);
	GPIO_SetPin(GPIOA,5);
	
}


void App_Main_Loop(void){
	

		

}







