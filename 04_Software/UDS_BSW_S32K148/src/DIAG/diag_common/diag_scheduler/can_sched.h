/******************************************************************************
 *    FILENAME    : can_sched.h
 *    DESCRIPTION : This file contains buffer for CIL layer data extraction as  and other structs defined in i15676.h
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/  
#ifndef _CAN_SCHED_H_
#define _CAN_SCHED_H

#include "diag_typedefs.h"
#include "diag_sys_conf.h"
#if(TRUE == DIAG_CONF_CANTP_SUPPORTED)
	#include "i15765.h"
#endif
#include "can_sched_conf.h"
#include "can_if.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
extern void CanSched_5ms (void);
extern void CanSched_Init (void);
#endif

/* *****************************************************************************
 End of File
 */
 
 
