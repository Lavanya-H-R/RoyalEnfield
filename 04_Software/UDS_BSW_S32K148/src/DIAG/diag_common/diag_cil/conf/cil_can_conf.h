/******************************************************************************
 *    FILENAME    : cil_can_conf.h
 *    DESCRIPTION : File contains CIL_CAN_Conf.c related definitions and declarations.
 ******************************************************************************
 * Revision history
 *  
 * Ver   Author       Date               Description
 * 1     Sushil      27/10/2018		     Initial version
 ******************************************************************************
*/ 
#ifndef _CIL_CAN_CONF_H_
#define _CIL_CAN_CONF_H_
/*
 ****************************************************************************************
 *    Includes
 ****************************************************************************************
*/
#include "can_if.h"
#include "diag_sys_conf.h"

/*
 ****************************************************************************************
 *    Defines
 ****************************************************************************************
*/  
#define CIL_CAN_GetID(sig)          (CIL_CAN_Conf_aSt[sig].HAL_CAN_MsgConf_St.ID_u32)

/*
 ****************************************************************************************
 *    ENUM Definition 
 ****************************************************************************************
*/
/*
    Enum defined to sort out the type callback recieved from cil or network layer to upper layer.
*/
typedef enum
{
    CIL_NEW_REQ_Rxed_E = 1,
    CIL_Rx_ERROR_E = 2,
    CIL_TX_CONFRM_E = 3,
    CIL_TX_ERROR_E = 4,
    CIL_FF_RXED_E = 5,
}nl2tp_CbkType_En_t;


typedef enum
{
	CIL_CAN_START_E = 0,
	CIL_RX_UDS_START = CIL_CAN_START_E,
	CIL_CANTP_REQ_TESTER_RX_E =CIL_RX_UDS_START,
	CIL_RX_UDS_END,

//	CIL_RX_HMI_START_E = CIL_RX_UDS_END,
//	CIL_HMI_PER_1_RX_E = CIL_RX_HMI_START_E,
//	CIL_HMI_PER_2_RX_E,
//	CIL_HMI_PER_3_RX_E,
//	CIL_HMI_PER_4_RX_E,
//	CIL_HMI_PER_5_RX_E,
//	CIL_HMI_PER_6_RX_E,
//    	CIL_HMI_PER_7_RX_E,
//		CIL_HMI_PER_8_RX_E,
//		CIL_HMI_PER_9_RX_E,
//		CIL_HMI_PER_10_RX_E,
//		CIL_HMI_PER_11_RX_E,
//
//	CIL_HMI_CONF_RX_E,
//	CIL_HMI_RX_END_E,

	CIL_DCAN_TOTAL_RX_E = CIL_RX_UDS_END,
	CIL_TX_UDS_START = CIL_DCAN_TOTAL_RX_E,
	CIL_CANTP_RESP_TESTER_TX_E = CIL_TX_UDS_START,
	CIL_TX_UDS_END,
	CIL_TEST3_TX_E,
	CIL_DCAN_TX_E = CIL_TEST3_TX_E,
	CIL_DCAN_END_E = CIL_DCAN_TX_E,
}CIL_SigName_En_t; 

/*
 ****************************************************************************************
 *    Structure Definition 
 ****************************************************************************************
*/


/*
 ****************************************************************************************
 *    al Variables
 ****************************************************************************************
*/ 
extern const CIL_CAN_Conf_St_t CIL_CAN_Conf_aSt[];

/*
 ****************************************************************************************
 *    Function Prototypes
 ****************************************************************************************
*/

#endif

/* *****************************************************************************
 End of File
 */

