#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	//打开时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
	
	TIM_InternalClockConfig(TIM2);		//设置Tim2的时钟为内部时钟，默认也是内部时钟
	
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 20000-1;	//自动重装计数器 //ARR
	TIM_TimeBaseInitStruct.TIM_Prescaler = 72-1;	//预分频器		//PSC
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct); 
	
	//配置输出比较单元
	TIM_OCInitTypeDef TIM_OCInitStruct;
	TIM_OCStructInit(&TIM_OCInitStruct);
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse = 0;	//CCR   500-2500对应0.5ms-2.5ms
	TIM_OC2Init(TIM2, &TIM_OCInitStruct);
	
	//配置GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//运行控制
	TIM_Cmd(TIM2, ENABLE);
}

void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM2, Compare);
}
