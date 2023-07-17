/******************************************************************************
 *    FILENAME    : uds_serv27.h                                              *
 *    DESCRIPTION : Header file for UDS service - Security Access.            *
 ******************************************************************************
 * Revision history 
 *  
 * Ver Author       Date               Description
 * 1   Sloki     1/10/2019		   Initial version
 ******************************************************************************
*/  

#ifndef _UDS_SERV27_H_
#define _UDS_SERV27_H_

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
#include "uds_conf.h"

/* ************************************************************************** */
/* ************************************************************************** */



#ifdef	__cplusplus
 "C" {
#endif

 /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */
#define REQUEST_SEED_PROGRAMMING   	0x01u
#define REQUEST_SEED_EXTENDED      	0x03u /*EXTENDED IS ALSO CALLED AS ENHANCED SESSION*/
#define REQUEST_SEED_ENGINEERING   	0x07u /*TML EOL IS ALSO CALLED AS ENGINEERING SESSION*/

#define SEND_KEY_PROGRAMMING       	0x02u
#define SEND_KEY_EXTENDED          	0x04u /*EXTENDED IS ALSO CALLED AS ENHANCED SESSION*/
#define SEND_KEY_ENGINEERING       	0x08u /*TML EOL IS ALSO CALLED AS ENGINEERING SESSION*/


#define SEED_REQUEST_LEN         	0x02u
#define SEND_KEY_REQ_LEN         	0x06u   
#define SEED_KEY_SIZE            	0x04u
#define N0_OF_ATTEMPTS           	0x03u   
#define TIME_DELAY               	6000
#define SECURITY_ACCESS_N0        	3u 
#define SECURITY_ACCESS_LEVEL_1   	0u                      
#define SECURITY_ACCESS_LEVEL_2   	1u                      
#define SECURITY_ACCESS_LEVEL_3   	2u                      
#define MAX_VAL   					256u


#if 0
/*Secret KEY*/                      
#define PROG_SECRET_KEY   			0xFAD8136Du                      
#define EXT_SECRET_KEY   			0xFCDA13EDu                
#define ENGG_SECRET_KEY   			0xF0DE13ADu        /*Also called as enhanced session in requirement*/                   
#endif

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************    

     /*  A brief description of a section can be given directly below the section
        banner.
     */
    
/*
 @summary :- this flag decide that security access or not 
*/
extern bool security_Access_Gained_b[SECURITY_ACCESS_N0];
    
          


 /*
 **************************************************************************************************
 *    Union
 **************************************************************************************************
 */   
/*
    @Summary: for split the  variable into byte 
*/
    
typedef union
{
    uint32_t random_number;
    uint8_t byte_buff[3];
}SPLIT_RAND_Un_t;

/*
 **************************************************************************************************
 *    Enum
 **************************************************************************************************
 */    
/*
    @summary: this enum is define for state machine cycle
*/
    
typedef enum
{
        SA_NO_ACCESS_E=0,               
                SA_RECEIVE_KEY_E,
                SA_ACCESS_OK_E                
}SA_STATE_MACHINE_En_t;


    
    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************


 /**
*  FUNCTION NAME : iso14229_serv27
*  FILENAME      : iso14229_serv27.h
*  @param        : UDS_Serv_St_t* UDS_Serv_pSt - pointer to service table.
*  @brief        : This function will process the service_27 requests
*  @return       : Type of response.                     
*/
    
extern  UDS_Serv_resptype_En_t iso14229_serv27 (UDS_Serv_St_t *UDS_Serv_pSt);
/*
*  FUNCTION NAME : serv27_timeout
*  FILENAME      : uds_serv27.c
*  @param        : none.
*  @brief        : function resets the relevant variables/parameters when session timesout.
*  @return       : none.                     
*/

extern void UDS_serv27_timeout(void);
/*
*  FUNCTION NAME : serv27_reset
*  FILENAME      : uds_serv27.c
*  @param        : none.
*  @brief        : function resets the relevant variables/parameters during session entry.
*  @return       : none.                     
*/
extern void UDS_serv27_reset(void);

/*
*  FUNCTION NAME : uint32_CalculateKEY
*  FILENAME      : uds_serv27.c
*  @brief        : function returns the calculated KEY as per the random SEED and secret KEY received.
*  @param        : u32_RandomSEED, u32_secretSEED.
*  @return       : uint32_t.                     
*/
extern uint32_t uint32_CalculateKEY(uint32_t, uint32_t);

/*
 *  FUNCTION NAME : Check_SecurityClearance
 *  FILENAME      : uds_serv27.c
 *  @brief        : This function is cleck Security Clearance     
 *  @param        : nil
 *  @return       : bool  
 */
extern bool Check_SecurityClearance(void);




extern uint32_t uint32_encrypt_data(uint32_t , uint32_t );
extern uint8_t uint8_t_s_box(uint8_t);
extern uint8_t uint8_t_mul_inverse(uint8_t);
extern void vd_generate_tables(void);


/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif
#endif



