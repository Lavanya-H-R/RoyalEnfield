/*
 * HAL_Link.h
 *
 *  Created on: Nov 12, 2020
 *      Author: sandeepky
 */

#ifndef DIAG_DIAG_COMMON_DIAG_CIL_HAL_LINK_H_
#define DIAG_DIAG_COMMON_DIAG_CIL_HAL_LINK_H_

#include "diag_typedefs.h"

typedef void (*hal2cil_fptr_t)(uint8_t, uint8_t, uint8_t, uint32_t, uint8_t*);
extern void DRV_HAL2CIL_CallBack(uint8_t IDE_u8,uint8_t DLC_u8, uint8_t CAN_Module_u8, uint32_t CAN_ID_u32,uint8_t *DataBytes_au8);
extern void DRV_CAN_Reg_CilCallBack(hal2cil_fptr_t);


#endif /* DIAG_DIAG_COMMON_DIAG_CIL_HAL_LINK_H_ */
