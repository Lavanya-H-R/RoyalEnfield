/******************************************************************************
 *    FILENAME    : cil_can_conf.c
 *    DESCRIPTION : File contains the common declarations related to CIL layers.
 ******************************************************************************
 * Revision history
 *  
 * Ver   Author       Date               Description
 * 1     Sushil      27/10/2018		     Initial version
 ******************************************************************************
*/ 

/* Section: Included Files                                       */
#include "cil_can_conf.h"
#include "diag_appl_test.h"
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/*
 * @summary:- can structure message buffer  
 */
CanSchedMsg_St_t CanSB_St [CIL_DCAN_TOTAL_RX_E] = {0};


const CIL_CAN_Conf_St_t CIL_CAN_Conf_aSt[CIL_DCAN_END_E] =
{
#if(TRUE == DIAG_CONF_UDS_SUPPORTED && TRUE == DIAG_CONF_CANTP_SUPPORTED)
  { {0x7F0,  0x7FF, CAN1_E, 0x10,    STD_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX_}  , CIL_CANTP_REQ_TESTER_RX_E   , CanSched_RxCallBackInt    , &CanSB_St[CIL_CANTP_REQ_TESTER_RX_E].msg  }  ,//@
#endif
//  { { 0x1827FF81,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_1_RX_E,    CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_1_RX_E].msg  },
//  { { 0x1038FF50,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_2_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_2_RX_E].msg  },
//  { { 0x18305040,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_3_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_3_RX_E].msg  },
//  { { 0x10281050,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_4_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_4_RX_E].msg  },
//  { { 0x18FF0360,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_5_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_5_RX_E].msg  },
//  { { 0x142EFF90,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_6_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_6_RX_E].msg  },
//  { { 0x1826FF81,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_7_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_7_RX_E].msg  },
//  { { 0X18265040,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_8_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_8_RX_E].msg  },
//  { { 0X18FF0060,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_9_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_9_RX_E].msg  },
//  { { 0X18FF0D5A,0x7FFFFFFF, CAN1_E, 0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_PER_10_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_PER_10_RX_E].msg  },
//  { { 0x7EA,0x7FF, CAN1_E, 0x10,    STD_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_RX}, CIL_HMI_CONF_RX_E,   	CanSched_RxCallBackInt, &CanSB_St[CIL_HMI_CONF_RX_E].msg  },
#if(TRUE == DIAG_CONF_UDS_SUPPORTED && TRUE == DIAG_CONF_CANTP_SUPPORTED)
	{ {0x7F1,  0U, CAN1_E,  0x10,    STD_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_TX_}  , CIL_CANTP_RESP_TESTER_TX_E  , NULL                  	, NULL  }  ,
#endif
  { { 0x600,  0U, CAN1_E,  0x10,    EXT_CAN_E,    DATA_FRAME_E,   FALSE,    FALSE,    CAN_TX_}, CIL_TEST3_TX_E, NULL, NULL},

};



/* *****************************************************************************
 End of File
 */

