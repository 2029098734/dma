#include"sys.h"
#include"irqn.h"
#include"uart.h"
#include"bpu.h"
#include"irqn.h"
#include"dma.h"


int main(void)
{
	uint8_t scr[10], dst[10];
	for(int i = 0; i < 10; i++)
	{
		dst[i] = 0x00;
	}
	SCB->VTOR = 0x01001000;
	SYSCTRL->CG_CTRL2 |= 1 << 29;
	UART_Init(UART0);
	UART_Init(UART1);
	UART1->OFFSET_0.THR = 0x1;
	while(((UART1->USR) & 0x1)){}
	uart_dma_fifo(UART0);
	//清除所有中断
	DMA->ChEnReg_L = 0x00001100; 
	DMA->ChEnReg_L = 0x00000000;
	DMA->ClearTfr_L = 0X00000001;
	DMA->ClearBlock_L = 0X00000001;
	DMA->ClearSrcTran_L = 0X00000001;
	DMA->ClearDstTran_L = 0X00000001;
	DMA->ClearErr_L = 0X00000001;

	UART1->OFFSET_0.THR = 0x1;
	while(((UART1->USR) & 0x1)){}

	DMA_Channel_0->SAR_L = (uint32_t)&(UART0->OFFSET_0.RBR);
	DMA_Channel_0->DAR_L = (uint32_t)dst;
	SYSCTRL->DMA_CHAN = (SYSCTRL->DMA_CHAN & 0xFFFFFFE0) | 0x00000003;

	DMA_Channel_0->CTL_L = 0x00200600;
	DMA_Channel_0->CTL_H = 0x0000000A;
	DMA_Channel_0->CFG_L = 0xC0000400;
	DMA->DmaCfgReg_L =0x1;
	DMA->ChEnReg_L = 0x00000101; 
	UART1->OFFSET_0.THR = 0x1;
	while(((UART1->USR) & 0x1)){}
	while(1)
	{
		
		if((UART1->LSR) & 0x1)
		{


			if(UART1->OFFSET_0.RBR == 0x31)
			{
				//while(!(DMA->RawBlock_L & 0x1)){}
				for(int i = 0; i < 10; i++)
				{
					UART1->OFFSET_0.THR = (dst[i] & 0xFF);
					while(((UART1->USR) & 0x1)){}
				}
			}
			if(UART1->OFFSET_0.RBR == 0x32)
			{
				
			}
			if(UART1->OFFSET_0.RBR == 0x33)
			{
				for(int i = 0; i < 10; i++)
				{
					scr[i] = 0xCC;
				}
				for(int i = 0; i < 10; i++)
				{
					UART1->OFFSET_0.THR = (dst[i] & 0xFF);
					while(((UART1->USR) & 0x1)){}
				}
			}
			UART1->OFFSET_0.THR = UART1->OFFSET_0.RBR;
			while(((UART1->USR) & 0x1)){}
		}
	}
}