/******************************************************************************
 *    FILENAME    : uds_serv10.c
 *    DESCRIPTION : Header file for UDS service - Diagnostic Session Control.
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki        28/08/2018		   Initial version
 ******************************************************************************
*/ 

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "iso14229_serv10.h"

#include "fee_conf.h"
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  @summary :- timer variable */
uint32_t Session_capture_time_u32 = 0;



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

static void UDS_Default_Diag_Init(void);
static void UDS_Programming_Session_Init(void);
static void UDS_Extended_Diag_Init(void);
static void UDS_Engineering_Diag_Init(void);
//static void UDS_Safety_System_Diag_Init();

/**
*  @Function: void UDS_Default_Diag_Init()
*  @Summary: This Function is used to initialize default diagnostic session, all flags
            are reset and all variables are re-initialized
*  @Params: None
*  @Return: None
**/
static void UDS_Default_Diag_Init(void)
{
    current_active_session_u8 = DEFAULT_SESSION_SUB_ID_E;
    //TODO: other init operations need to be done here reset the security flag (graphine req) 
	//NWMngmnt_NormalCommMsg_Adapt(TRUE, TRUE);		/* Rx Enable, Tx Enable */
    UDS_serv27_reset();
	return;
}

/**
*  @Function: void UDS_Programming_Session_Init()
*  @Summary: This Function is used to initialize Programming session, all flags
            are reset and all variables are re-initialized
*  @Params: None
*  @Return: None
**/
static void UDS_Programming_Session_Init(void)
{
    current_active_session_u8 = PROGRAMMING_SESSION_SUB_ID_E;
    //TODO: other init operations need to be done here
	//NWMngmnt_NormalCommMsg_Adapt(TRUE, TRUE);		/* Rx Enable, Tx Enable */
    UDS_serv27_reset();
	return;
}

/**
*  @Function: void UDS_Extended_Diag_Init()
*  @Summary: This Function is used to initialize extended diagnostic session, all flags
            are reset and all variables are re-initialized
*  @Params: None
*  @Return: None
**/
static void UDS_Extended_Diag_Init(void)
{
    current_active_session_u8 = EXTENDED_DIAG_SESSION_SUB_ID_E;
    //TODO: other init operations need to be done here
    UDS_serv27_reset();
	//ClearRoutineResult();
	return;
}

/**
*  @Function: void UDS_Safety_System_Diag_Init()
*  @Summary: This Function is used to initialize safety system diagnostic session, all flags
            are reset and all variables are re-initialized
*  @Params: None
*  @Return: None
**/
static void  UDS_Engineering_Diag_Init(void)
{
  current_active_session_u8 = ENGINEERING_DIAG_SESSION_SUB_ID_E;
  //TODO: other init operations need to be done here
  return ;
}


/**
*  @Function: void UDS_Safety_System_Diag_Init()
*  @Summary: This Function is used to initialize safety system diagnostic session, all flags
            are reset and all variables are re-initialized
*  @Params: None
*  @Return: None
**/
static void  UDS_EOL_Init(void)
{
  current_active_session_u8 = SUPPLIER_EOL_SESSION_SUB_ID_E;
  //NWMngmnt_NormalCommMsg_Adapt(TRUE, TRUE);		/* Rx Enable, Tx Enable */
 // u1_Start_EOL();
  //TODO: other init operations need to be done here
  return ;
}




/**
*  @Function: void UDS_Safety_System_Diag_Init()
*  @Summary: This Function is used to initialize safety system diagnostic session, all flags
            are reset and all variables are re-initialized
*  @Params: None
*  @Return: None
**/
//void UDS_Safety_System_Diag_Init()
//{
//    current_active_session_u8 = SAFETY_SYSTEM_DIAG_SESSION_SUB_ID_E;
//    //TODO: other init operations need to be done here
//    return;
//}


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/**
*  FUNCTION NAME : iso14229_serv10
*  FILENAME      : uds_serv10.c
*  @param        : UDS_Serv_St_t* UDS_Serv_pSt - pointer to service distributer table.
*  @brief        : This function will process the service_10 requests
*  @return       : Type of response.                  
*/
UDS_Serv_resptype_En_t iso14229_serv10(UDS_Serv_St_t*  UDS_Serv_pSt)
{
    
    uint8_t DiagSessionType_u8 = UDS_Serv_pSt->RxBuff_pu8[1];
//    uint8_t SuppressResponse_u8 = UDS_Serv_pSt->RxBuff_pu8[1] & 0x80;
    bool NoResponseFlag_b = FALSE;
    UDS_Serv_resptype_En_t Serv_resptype_En = UDS_SERV_RESP_NORESP_E;
    
    if((UDS_Serv_pSt->RxBuff_pu8[1] == 0x81) || (UDS_Serv_pSt->RxBuff_pu8[1] == 0x82) || (UDS_Serv_pSt->RxBuff_pu8[1] == 0x83))
    {
        NoResponseFlag_b 	= TRUE;
		DiagSessionType_u8 	= (UDS_Serv_pSt->RxBuff_pu8[1] & 0x7F);  
		
    }
	if(SERV_10_MAX_LEN != UDS_Serv_pSt->RxLen_u16)
    {
        /* check whether length should be valid or not */
        UDS_Serv_pSt->TxLen_u16 	= 3u;
        UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
        UDS_Serv_pSt->TxBuff_pu8[1] = SID_SESSIONCONTROL;
        UDS_Serv_pSt->TxBuff_pu8[2] = INVALID_MESSAGE_LENGTH;
        Serv_resptype_En = UDS_SERV_RESP_NEG_E;
    }
    else
    {
        switch(DiagSessionType_u8)
        { 
            case DEFAULT_SESSION_SUB_ID_E: // default session
            {
                UDS_Default_Diag_Init();
                UDS_Serv_pSt->TxLen_u16  	= 5u;
                UDS_Serv_pSt->TxBuff_pu8[1] = DiagSessionType_u8;
                UDS_Serv_pSt->TxBuff_pu8[2] = (uint8_t)DEFAULT_P2_CAN_MAX_HB;
                UDS_Serv_pSt->TxBuff_pu8[3] = (uint8_t)DEFAULT_P2_CAN_MAX;
                UDS_Serv_pSt->TxBuff_pu8[4] = (uint8_t)ENHANCED_P2_CAN_MAX_HB;
                UDS_Serv_pSt->TxBuff_pu8[5] = (uint8_t)ENHANCED_P2_CAN_MAX;
				Serv_resptype_En = UDS_SERV_RESP_POS_E;
                break;
            }
            case PROGRAMMING_SESSION_SUB_ID_E: // programming session 
            {
				if(UDS_GetCurrentSession() == EXTENDED_DIAG_SESSION_SUB_ID_E) 
				{
					
					UDS_Programming_Session_Init();
					if(NoResponseFlag_b == FALSE)
					{
				                UDS_Serv_pSt->TxLen_u16  	= 5u;
				                UDS_Serv_pSt->TxBuff_pu8[1] = DiagSessionType_u8;
				                UDS_Serv_pSt->TxBuff_pu8[2] = (uint8_t)DEFAULT_P2_CAN_MAX_HB;
				                UDS_Serv_pSt->TxBuff_pu8[3] = (uint8_t)DEFAULT_P2_CAN_MAX;
				                UDS_Serv_pSt->TxBuff_pu8[4] = (uint8_t)ENHANCED_P2_CAN_MAX_HB;
				                UDS_Serv_pSt->TxBuff_pu8[5] = (uint8_t)ENHANCED_P2_CAN_MAX;
				                Serv_resptype_En = UDS_SERV_RESP_POS_E;
				                Flash_Pattern_Write(DRIVE_VALIDATION_START_ADDRESS, BOOT_PATTERN);

					}
	    

					/* After calling this function microcontroller will get reset and 
						enters into bootloader                                      */
					//todo  harsh EnterBootMode();
				}
				else{
					UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
					UDS_Serv_pSt->TxBuff_pu8[1] = SID_SESSIONCONTROL;
					UDS_Serv_pSt->TxBuff_pu8[2] = SERVNOSUPP_IN_ACTIVE_SESS ;
					UDS_Serv_pSt->TxLen_u16     = 3;
					Serv_resptype_En = UDS_SERV_RESP_NEG_E;
				}
                break;
            }
            case EXTENDED_DIAG_SESSION_SUB_ID_E: // extended session 
            {
                UDS_Extended_Diag_Init();
                UDS_Serv_pSt->TxLen_u16  	= 5u;
                UDS_Serv_pSt->TxBuff_pu8[1] = DiagSessionType_u8;
                UDS_Serv_pSt->TxBuff_pu8[2] = (uint8_t)DEFAULT_P2_CAN_MAX_HB;
                UDS_Serv_pSt->TxBuff_pu8[3] = (uint8_t)DEFAULT_P2_CAN_MAX;
                UDS_Serv_pSt->TxBuff_pu8[4] = (uint8_t)ENHANCED_P2_CAN_MAX_HB;
                UDS_Serv_pSt->TxBuff_pu8[5] = (uint8_t)ENHANCED_P2_CAN_MAX;
                Serv_resptype_En = UDS_SERV_RESP_POS_E;
                break;                
            }
            case ENGINEERING_DIAG_SESSION_SUB_ID_E: // ENGINEERING DIAG session 
            {
                UDS_Engineering_Diag_Init();
                UDS_Serv_pSt->TxLen_u16  = 1u;
                UDS_Serv_pSt->TxBuff_pu8[1] = DiagSessionType_u8;
                Serv_resptype_En = UDS_SERV_RESP_POS_E;
                break;                
            }
			case SUPPLIER_EOL_SESSION_SUB_ID_E: // EOL DIAG session 
            {
                UDS_EOL_Init();
                UDS_Serv_pSt->TxLen_u16  	= 5u;
                UDS_Serv_pSt->TxBuff_pu8[1] = DiagSessionType_u8;
                UDS_Serv_pSt->TxBuff_pu8[2] = (uint8_t)DEFAULT_P2_CAN_MAX_HB;
                UDS_Serv_pSt->TxBuff_pu8[3] = (uint8_t)DEFAULT_P2_CAN_MAX;
                UDS_Serv_pSt->TxBuff_pu8[4] = (uint8_t)ENHANCED_P2_CAN_MAX_HB;
                UDS_Serv_pSt->TxBuff_pu8[5] = (uint8_t)ENHANCED_P2_CAN_MAX;
                Serv_resptype_En = UDS_SERV_RESP_POS_E;
                break;                
            }
            default: // sun function not supported 
            {
                UDS_Serv_pSt->TxLen_u16 = 3u;
                UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
                UDS_Serv_pSt->TxBuff_pu8[1] = SID_SESSIONCONTROL;
                UDS_Serv_pSt->TxBuff_pu8[2] = SUB_FUNC_NOT_SUPPORTED;
                Serv_resptype_En = UDS_SERV_RESP_NEG_E;
               // NoResponseFlag_b = FALSE;
                break;
            }            
        }
        if(NoResponseFlag_b == TRUE)
        {
            Serv_resptype_En = UDS_SERV_RESP_NORESP_E;
        }
    }
    return Serv_resptype_En;
}

/**
*  FUNCTION NAME : UDS_Serv10_Timeout
*  FILENAME      : uds_serv10.c
*  @param        : none
*  @brief        : This function will call default session because of timeout
*  @return       : Type of response.                  
*/

void UDS_Serv10_Timeout(void)
{    
    return;
}

uint8_t UDS_GetCurrentSession(void)
{
	return (uint8_t)current_active_session_u8;
}
/******************************************************************************
 End of File
 ******************************************************************************/
