#include "stm32f10x.h"


void MyDMA_Init(uint32_t AddrA, uint32_t AddrB, uint16_t Size)
{
	DMA_InitTypeDef DMA_InitStruct;
	DMA_StructInit(&DMA_InitStruct);
	DMA_InitStruct.DMA_PeripheralBaseAddr = AddrA;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_MemoryBaseAddr = AddrB;
	DMA_InitStruct.DMA_MemoryDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_BufferSize = Size;
	DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStruct.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStruct.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStruct.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMA1_Channel1, &DMA_InitStruct);
	DMA_Cmd(DMA1_Channel1, ENABLE);
}
