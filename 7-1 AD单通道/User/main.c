#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t ADValue;
float V;
int main(void)
{
	OLED_Init();
	AD_init();
	OLED_ShowString(1, 1, "ADValue:");
	OLED_ShowString(2, 1, "V:0.00");
	
	while(1)
	{	
		ADValue = AD_GetValue();
		V = (float)ADValue / 4095 *3.3;
		OLED_ShowNum(1,9,ADValue,4);
		OLED_ShowNum(2,3,V,1);
		OLED_ShowNum(2,5,(uint16_t)(V*100)%100,2);
		
		Delay_ms(200);
	}
}

