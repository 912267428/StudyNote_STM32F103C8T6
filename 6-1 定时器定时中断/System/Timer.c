#include "stm32f10x.h"                  // Device header


void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//开启定时器2的时钟
	
	TIM_InternalClockConfig(TIM2);		//设置Tim2的时钟为内部时钟，默认也是内部时钟
	
	//时基单元配置
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period = 10000-1;	//自动重装计数器
	TIM_TimeBaseInitStruct.TIM_Prescaler = 7200-1;	//预分频器
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct); 
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//避免刚上电立即进入中断
	//使能更新中断
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	//NVIC配置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
	//启动定时器
	TIM_Cmd(TIM2, ENABLE);
}

//void TIM2_IRQHandler()
//{
//	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
//	{
//		
//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//	}
//}
