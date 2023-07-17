/******************************************************************************
 *    FILENAME    : can_sched_conf.h
 *    DESCRIPTION : This file contains buffer for CIL layer data extraction as  and other structs defined in i15676.h
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/  

#ifndef _CAN_SCHED_CONF_H_
#define _CAN_SCHED_CONF_H_

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "can_if.h"
#include "diag_typedefs.h"
#include "diag_sys_conf.h"
#if(TRUE == DIAG_CONF_CANTP_SUPPORTED)
	#include "i15765.h"
#endif

/* This section lists the other files that are included in this file.
 */

#define    	PERIODICITY_MS(x)  					((x)/(5))
#define    	NO_TIMEOUT   						0

/*Reception*/

typedef void (*CANSCHED_CB_Fptr_t)( uint16_t sig,  CAN_MessageFrame_St_t* msg_rf );
typedef BOOL (*CAN_SIGALC_MSGA_Fptr_t)(uint32_t  Bitpos);
typedef void (*CANSCHED_TCB_Fptr_t)(void);
  

/*
 ******************************************************************************
 *    CAN SCHEDULER configuration structure
 ******************************************************************************
*/ 
typedef struct
{
    uint32_t                    CIL_CAN_SigName_En;     /* CIL CAN */
    uint32_t                    Timeoutms_u32;          /* Timeout value in ms */
    CANSCHED_CB_Fptr_t          CANSCHED_CB_Fptr;       /* Receive callback function  */
    CANSCHED_TCB_Fptr_t         CANSCHED_TCB_Fptr;      /* Timeout callback function  */
}CANSCHED_RX_Conf_St_t;

 
typedef struct
{  
    uint32_t                    CIL_CAN_SigName_En;     /* CIL CAN */
    const uint16_t              Cycle_Time_u16;         /* Pointer to constant which contains the cylce time in ms */
    const uint16_t		        Offset_Time_u16; 		/* Offset time in ms */
    CANSCHED_TCB_Fptr_t         CANSCHED_CB_Fptr;       /* Tx callback function  */
}CANSCHED_TX_Conf_St_t;


#define CAN_SCHED_CONF_TOTAL_RX_MSG         1//12
extern  const CANSCHED_RX_Conf_St_t   CANSCHED_RX_Conf_aSt[CAN_SCHED_CONF_TOTAL_RX_MSG];

#define CAN_SCHED_CONF_TOTAL_TX_MSG         1 
extern  const CANSCHED_TX_Conf_St_t   CANSCHED_TX_Conf_aSt[CAN_SCHED_CONF_TOTAL_TX_MSG];


//extern void CanSched_5ms (void);

#endif

/* *****************************************************************************
 End of File
 */
 
 
