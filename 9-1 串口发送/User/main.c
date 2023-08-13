#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

int main(void)
{
	OLED_Init();
	
	Serial_Init();
	
//	Serial_SendByte(0x41);
//	
//	uint8_t Array[] = {0x42, 0x43, 0x44, 0x45};
//	Serial_SendArray(Array, 4);
//	
//	Serial_SendString("\r\nHelloWorld!");
//	Serial_SendNumber(12345, 5);
//	
//	printf("Num=%d\r\n", 666);
	
	char String[100];
	sprintf(String, "Num=%d\r\n",666);
	Serial_SendString(String);
	
	Serial_Printf("Num=%d\r\n",777);
	while(1)
	{	
		
	}
}
