/******************************************************************************
 *    FILENAME    : can_sched.c
 *    DESCRIPTION : description of a can scheduler
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/ 



/* Section: Included Files                                                   */
#include "can_sched.h"
#include "can_sched_conf.h"
#include "cil_can_conf.h"
#include "math_util.h"
#include "diag_appl_test.h"
/**************************************************************************** */

/*
 * @summary:-    array of can Application structures    
 */
const CANSCHED_RX_Conf_St_t   CANSCHED_RX_Conf_aSt[CAN_SCHED_CONF_TOTAL_RX_MSG]=
{
	{CIL_CANTP_REQ_TESTER_RX_E,		PERIODICITY_MS(10),		CANSched_RxMsgCallback, 	  	NULL},
//	{CIL_HMI_PER_1_RX_E,        	PERIODICITY_MS(100),    CANSched_HMI_RxMsgCallback,		NULL},
//  	{CIL_HMI_PER_2_RX_E,      		PERIODICITY_MS(100),    CANSched_HMI_RxMsgCallback,   	NULL},
//	{CIL_HMI_PER_3_RX_E,			PERIODICITY_MS(100),	CANSched_HMI_RxMsgCallback,	  	NULL},
//	{CIL_HMI_PER_4_RX_E,			PERIODICITY_MS(100),	CANSched_HMI_RxMsgCallback,	  	NULL},
//    {CIL_HMI_PER_5_RX_E,			PERIODICITY_MS(100),	CANSched_HMI_RxMsgCallback,	  	NULL},
//    {CIL_HMI_PER_6_RX_E,			PERIODICITY_MS(100),	CANSched_HMI_RxMsgCallback,	  	NULL},
//    {CIL_HMI_PER_7_RX_E,			PERIODICITY_MS(100),	CANSched_HMI_RxMsgCallback,	  	NULL},
//	{CIL_HMI_PER_8_RX_E,			PERIODICITY_MS(100),	CANSched_HMI_RxMsgCallback,	  	NULL},
//	{CIL_HMI_PER_9_RX_E,			PERIODICITY_MS(100),	CANSched_HMI_RxMsgCallback,	  	NULL},
//	{CIL_HMI_PER_10_RX_E,			PERIODICITY_MS(100),	CANSched_HMI_RxMsgCallback,	  	NULL},
//	{CIL_HMI_CONF_RX_E,				PERIODICITY_MS(100),	CANSched_HMI_RxMsgCallback,	  	NULL},
};


const CANSCHED_TX_Conf_St_t   CANSCHED_TX_Conf_aSt[CAN_SCHED_CONF_TOTAL_TX_MSG]=
{
    // CIL Sig name,			    Cycle Time			Offset (Timeslice)	Call Back Function     
    { CIL_TEST3_TX_E,			PERIODICITY_MS(500), 		PERIODICITY_MS(10),   		NULL},

};


/* *****************************************************************************
 End of File
 */
