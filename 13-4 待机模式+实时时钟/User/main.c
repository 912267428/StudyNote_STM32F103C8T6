#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MyRTC.h"
#include "Key.h"

uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	MyRTC_Init();
	Key_Init();
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	
	OLED_ShowString(1, 1, "Ready");
//	OLED_ShowString(2, 1, "ALR :");
//	OLED_ShowString(3, 1, "ALRF:");
	Delay_s(1);
	
	PWR_WakeUpPinCmd(ENABLE);
	
//	uint32_t Alarm = RTC_GetCounter() + 10;
//	RTC_SetAlarm(Alarm);
//	OLED_ShowNum(2, 6, Alarm, 10);
	
	while (1)
	{
		OLED_ShowNum(1, 1, RTC_GetCounter(), 10);
		KeyNum = Key_GetNum();	
//		OLED_ShowNum(3, 6, RTC_GetFlagStatus(RTC_FLAG_ALR), 1);
		
		OLED_ShowString(2, 1, "Running");
		OLED_ShowString(3, 1, "Press a Key to");
		OLED_ShowString(4,1,"STANDBY");
		
		if (KeyNum != 0)
		{
			OLED_Clear();
			PWR_EnterSTANDBYMode();
		}
		
//		OLED_Clear();
//		PWR_EnterSTANDBYMode();
	}
}
