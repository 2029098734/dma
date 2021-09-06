#include"sys.h"
#include"irqn.h"
#include"uart.h"
#include"bpu.h"
#include"irqn.h"
#include"dma.h"


int main(void)
{
	uint32_t scr[10], dst[10];	
	SCB->VTOR = 0x01001000;
	SYSCTRL->CG_CTRL2 |= 1 << 29;
	UART_Init(UART0);
	DMA->ChEnReg_L = 0x00001100; 
	DMA->ChEnReg_L = 0x00000000;
	DMA->ClearTfr_L = 0X00000001;
	DMA->ClearBlock_L = 0X00000001;
	DMA->ClearSrcTran_L = 0X00000001;
	DMA->ClearDstTran_L = 0X00000001;
	DMA->ClearErr_L = 0X00000001;
	DMA_Channel_0->SAR_L = (uint32_t)scr;
	DMA_Channel_0->DAR_L = (uint32_t)dst;
	DMA_Channel_0->CTL_L = 0x00000024;
	DMA_Channel_0->CTL_H = 0x0000000A;
	DMA_Channel_0->CFG_L = 0xC0000C00;
	DMA_Channel_0->CFG_H = 0x00000004;
	UART0->OFFSET_0.THR = 0x1;
	while(((UART0->USR) & 0x1)){}
	while(1)
	{
		
		if((UART0->LSR) & 0x1)
		{
			if(UART0->OFFSET_0.RBR == 0x31)
			{
				UART0->OFFSET_0.THR = 0x22;
				while(((UART0->USR) & 0x1)){}
				for(int i = 0; i < 10; i++)
				{
					scr[i] = i;
				}
				DMA->DmaCfgReg_L =0x1;
				DMA->ChEnReg_L = 0x00000101; 
				UART0->OFFSET_0.THR = 0x33;
				while(((UART0->USR) & 0x1)){}
				while(!(DMA->RawBlock_L & 0x1)){}
				for(int i = 0; i < 10; i++)
				{
					UART0->OFFSET_0.THR = (dst[i] & 0xFF);
					while(((UART0->USR) & 0x1)){}
				}
			}
			if(UART0->OFFSET_0.RBR == 0x32)
			{
				UART0->OFFSET_0.THR = 0x22;
				while(((UART0->USR) & 0x1)){}
				for(int i = 0; i < 10; i++)
				{
					scr[i] = 0xFF;
				}
				DMA->DmaCfgReg_L =0x1;
				DMA->ChEnReg_L = 0x00000101; 
				UART0->OFFSET_0.THR = 0x33;
				while(((UART0->USR) & 0x1)){}
				while(!(DMA->RawBlock_L & 0x1)){}
				for(int i = 0; i < 10; i++)
				{
					UART0->OFFSET_0.THR = (dst[i] & 0xFF);
					while(((UART0->USR) & 0x1)){}
				}
			}
			if(UART0->OFFSET_0.RBR == 0x33)
			{
				for(int i = 0; i < 10; i++)
				{
					scr[i] = 0xCC;
				}
				for(int i = 0; i < 10; i++)
				{
					UART0->OFFSET_0.THR = (dst[i] & 0xFF);
					while(((UART0->USR) & 0x1)){}
				}
			}
			
			UART0->OFFSET_0.THR = UART0->OFFSET_0.RBR;
			while(((UART0->USR) & 0x1)){}
		}
	}
}