#include "stm32g030xx.h"
#include "app.h"
#include "crc32.h"
#include "gpio.h"
#include "sw_timebase.h"
//#include "timebase.h"



#define APP_START_ADDR   0x08000000
#define APP_SIZE_BYTES   (64 * 1024)   // Example: 64KB firmware
#define	delay_interval		1000


//uint8_t t1, t2;

   


void App_Setup(void){
	
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	GPIO_Init(GPIOA,4,GPIO_MODE_OUTPUT,GPIO_OTYPE_PP,GPIO_NOPULL,GPIO_SPEED_LOW);
	GPIO_Init(GPIOA,6,GPIO_MODE_OUTPUT,GPIO_OTYPE_PP,GPIO_NOPULL,GPIO_SPEED_LOW);
	GPIO_SetPin(GPIOA,4);
	GPIO_SetPin(GPIOA,6);
	sw_timebase_Init(1000);
	//Timebase_Init(1000); // ????? 1ms interrupt
	//Timebase_DownCounter_Set_Securely(0, 1); // 5 sec
	//Timebase_DownCounter_Set_Securely(1, 2); // 5 sec
	sw_timebase_counter_set_securely(0,1);
	sw_timebase_counter_set_securely(1,2);
	
}


void App_Main_Loop(void){
	
	//Timebase_Main_Loop_Executables();
	sw_timebase_main_loop_executable();
	if (sw_timebase_counter_continous_expired_event(0)){
        GPIO_TogglePin(GPIOA, 4);
				//sw_timebase_counter_set_forcefully(0,1);
				//Timebase_DownCounter_Set_Forcefully(0, 1);
		
	}

    if (sw_timebase_counter_continous_expired_event(1)){
        GPIO_TogglePin(GPIOA, 6);
				//sw_timebase_counter_set_forcefully(1,2);
				//Timebase_DownCounter_Set_Forcefully(1, 2);
			
		}
	
}







