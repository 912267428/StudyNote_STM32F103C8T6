#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"
#include "Key.h"

uint16_t Prescaler = 720-1;
uint16_t ARR = 50;
uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	Key_Init();
	OLED_ShowString(1,1,"Freq:0000HZ");
	OLED_ShowString(2,1,"Duty:000%");
	PWM_Init();
	PWM_SetPrescaler(Prescaler);
	PWM_SetCompare1(ARR);
	
	IC_Init();
			
	while(1)
	{	
		KeyNum = Key_GetNum();
		if (KeyNum == 1)
		{
			Prescaler+=100;
			PWM_SetPrescaler(Prescaler);
		}
		if (KeyNum == 2)
		{
			ARR+=10;
			if(ARR >= 100) ARR=0;
			PWM_SetCompare1(ARR);
		}
		OLED_ShowNum(1,6,IC_GetFreq(),4);
		OLED_ShowNum(2,6,IC_GetDuty(),4);
	}
}
