/******************************************************************************
 *    FILENAME    : uds_serv10.h
 *    DESCRIPTION : Header file for UDS service - Diagnostic Session Control.
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki        28/08/2018		   Initial version
 ******************************************************************************
*/ 

#ifndef _UDS_SERV10_H_
#define	_UDS_SERV10_H_

#ifdef	__cplusplus
 "C" {
#endif

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.*/
#include "uds_conf.h"
#include "iso14229_serv27.h"
  
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Constants                                                         */
/* ************************************************************************** */
/* ************************************************************************** */

// /* @summary: length size must be 2 */
 #define DEFAULT_P2_CAN_MAX                                      50u  /* P2  Server Max = 50ms   */
 #define DEFAULT_P2_CAN_MAX_HB                                   0u
 #define ENHANCED_P2_CAN_MAX                                     5000u  /* P2* Server Max = 5000ms */
 #define ENHANCED_P2_CAN_MAX_HB                                  0x0Bu
  
// /* @summary:- this is a CRC Address */
// #define DRIVE_CRC_START_ADDRESS                                 (0x9D000000 + 0x010000)    
// #define DRIVE_VALIDATION_START_ADDRESS                          (DRIVE_CRC_START_ADDRESS)

// /* @summary:- This verification data we have to write into the CRC address so that we can jump into the Bootloader */
// #define BOOTLOADER_VERIFY_PIN                                   0x00000000 

/* @summary: length size must be 2 */
#define SERV_10_MAX_LEN                                         0x02u

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Data Types                                                        */
/* ************************************************************************** */
/* ************************************************************************** */



/* @summary :- timer variable */
 extern uint32_t Session_capture_time_u32;

/* @summary:- we can use this variable into any services for checking that services should be supported or not */
// uint8_t current_active_session_u8;

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/**
*  FUNCTION NAME : UDS_Serv10
*  FILENAME      : iso14229_serv10.c
*  @param        : UDS_Serv_St_t* UDS_Serv_pSt - pointer to service distributer table.
*  @brief        : This function will process the service_10 requests
*  @return       : Type of response.                  
**/
 extern UDS_Serv_resptype_En_t iso14229_serv10(UDS_Serv_St_t* );

/*
*  FUNCTION NAME : UDS_Serv10_Timeout
*  FILENAME      : uds_serv10.c
*  @param        : none
*  @brief        : This function will call default session because of timeout
*  @return       : Type of response.                  
**/
 extern void UDS_Serv10_Timeout(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ISO14229_SER10_H */
