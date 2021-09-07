#ifndef __DMA_H
#define __DMA_H


#include "sys.h"

#define DMA_BASE                                (0x40000800UL)               


typedef struct
{
    __IO uint32_t SAR_L;
    __IO uint32_t SAR_H;
    __IO uint32_t DAR_L;
    __IO uint32_t DAR_H;
    __IO uint32_t LLP_L;
    __IO uint32_t LLP_H;
    __IO uint32_t CTL_L;
    __IO uint32_t CTL_H;
    __IO uint32_t SSTAT_L;
    __IO uint32_t SSTAT_H;
    __IO uint32_t DSTAT_L;
    __IO uint32_t DSTAT_H;
    __IO uint32_t SSTATAR_L;
    __IO uint32_t SSTATAR_H;
    __IO uint32_t DSTATAR_L;
    __IO uint32_t DSTATAR_H;
    __IO uint32_t CFG_L;
    __IO uint32_t CFG_H;
    __IO uint32_t SGR_L;
    __IO uint32_t SGR_H;
    __IO uint32_t DSR_L;
    __IO uint32_t DSR_H;
} DMA_TypeDef;


typedef struct
{
    DMA_TypeDef DMA_Channel[8];

    __I  uint32_t RawTfr_L;
    __I  uint32_t RawTfr_H;
    __I  uint32_t RawBlock_L;
    __I  uint32_t RawBlock_H;
    __I  uint32_t RawSrcTran_L;
    __I  uint32_t RawSrcTran_H;
    __I  uint32_t RawDstTran_L;
    __I  uint32_t RawDstTran_H;
    __I  uint32_t RawErr_L;
    __I  uint32_t RawErr_H;
    
    __I  uint32_t StatusTfr_L;
    __I  uint32_t StatusTfr_H;
    __I  uint32_t StatusBlock_L;
    __I  uint32_t StatusBlock_H;
    __I  uint32_t StatusSrcTran_L;
    __I  uint32_t StatusSrcTran_H;
    __I  uint32_t StatusDstTran_L;
    __I  uint32_t StatusDstTran_H;
    __I  uint32_t StatusErr_L;
    __I  uint32_t StatusErr_H;

    __IO uint32_t MaskTfr_L;
    __IO uint32_t MaskTfr_H;
    __IO uint32_t MaskBlock_L;
    __IO uint32_t MaskBlock_H;
    __IO uint32_t MaskSrcTran_L;
    __IO uint32_t MaskSrcTran_H;
    __IO uint32_t MaskDstTran_L;
    __IO uint32_t MaskDstTran_H;
    __IO uint32_t MaskErr_L;
    __IO uint32_t MaskErr_H;
    
    __O  uint32_t ClearTfr_L;
    __O  uint32_t ClearTfr_H;
    __O  uint32_t ClearBlock_L;
    __O  uint32_t ClearBlock_H;
    __O  uint32_t ClearSrcTran_L;
    __O  uint32_t ClearSrcTran_H;
    __O  uint32_t ClearDstTran_L;
    __O  uint32_t ClearDstTran_H;
    __O  uint32_t ClearErr_L;
    __O  uint32_t ClearErr_H;
    
    __I  uint32_t StatusInt_L;
    __I  uint32_t StatusInt_H;
    
    __IO uint32_t ReqSrcReg_L;
    __IO uint32_t ReqSrcReg_H;
    __IO uint32_t ReqDstReg_L;
    __IO uint32_t ReqDstReg_H;
    __IO uint32_t SglReqSrcReg_L;
    __IO uint32_t SglReqSrcReg_H;
    __IO uint32_t SglReqDstReg_L;
    __IO uint32_t SglReqDstReg_H;
    __IO uint32_t LstSrcReg_L;
    __IO uint32_t LstSrcReg_H;
    __IO uint32_t LstDstReg_L;
    __IO uint32_t LstDstReg_H;
    
    __IO uint32_t DmaCfgReg_L;
    __IO uint32_t DmaCfgReg_H;
    __IO uint32_t ChEnReg_L;
    __IO uint32_t ChEnReg_H;
    __I  uint32_t DmaIdReg_L;
    __I  uint32_t DmaIdReg_H;
    __IO uint32_t DmaTestReg_L;
    __IO uint32_t DmaTestReg_H;
    
    __IO uint32_t RESERVED2[4];
    
    __I  uint32_t DMA_COMP_PARAMS_6_L;
    __I  uint32_t DMA_COMP_PARAMS_6_H;
    __I  uint32_t DMA_COMP_PARAMS_5_L;
    __I  uint32_t DMA_COMP_PARAMS_5_H;
    __I  uint32_t DMA_COMP_PARAMS_4_L;
    __I  uint32_t DMA_COMP_PARAMS_4_H;
    __I  uint32_t DMA_COMP_PARAMS_3_L;
    __I  uint32_t DMA_COMP_PARAMS_3_H;
    __I  uint32_t DMA_COMP_PARAMS_2_L;
    __I  uint32_t DMA_COMP_PARAMS_2_H;
    __I  uint32_t DMA_COMP_PARAMS_1_L;
    __I  uint32_t DMA_COMP_PARAMS_1_H;
    __I  uint32_t DMA_Component_ID_Register_L;
    __I  uint32_t DMA_Component_ID_Register_H;

} DMA_MODULE_TypeDef;


#define DMA_Channel_0                           ((DMA_TypeDef *)DMA_BASE)
#define DMA_Channel_1                           ((DMA_TypeDef *)(DMA_BASE + 0x58))
#define DMA_Channel_2                           ((DMA_TypeDef *)(DMA_BASE + 0x58*2))
#define DMA_Channel_3                           ((DMA_TypeDef *)(DMA_BASE + 0x58*3))
#define DMA_Channel_4                           ((DMA_TypeDef *)(DMA_BASE + 0x58*4))
#define DMA_Channel_5                           ((DMA_TypeDef *)(DMA_BASE + 0x58*5))
#define DMA_Channel_6                           ((DMA_TypeDef *)(DMA_BASE + 0x58*6))
#define DMA_Channel_7                           ((DMA_TypeDef *)(DMA_BASE + 0x58*7))
#define DMA                                     ((DMA_MODULE_TypeDef *)DMA_BASE)


#endif