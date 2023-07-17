/******************************************************************************
 *    FILENAME    : uds_serv11.c
 *    DESCRIPTION : The ECUReset service is used by the client to request a server reset.
 ******************************************************************************
 * Revision history
 *
 *   Ver Author       Date               Description
 *   Sloki       16/1/2019            Initial version                */
/**********************************************************************************
                                includes
 **********************************************************************************/

#include "iso14229_serv11.h"
#include "uds_session.h"
#include "iso14229_serv27.h"


/*
 ****************************************************************************************
 *    functions prototype
 ****************************************************************************************
 */

/*
 ****************************************************************************************
 *    macros
 ****************************************************************************************
 */
#define SYSC_KEY_UNLOCK         0x5CACCE55

/*
 ****************************************************************************************
 *    Static functions
 ****************************************************************************************
 */

/*
 ****************************************************************************************
 *    Global Variables
 ****************************************************************************************
 */
static bool SoftReset_b = FALSE;
static bool HardReset_b = FALSE;
bool reset_b = false;
/*
 ****************************************************************************************
 *    Function Definition
 ****************************************************************************************
 */

/*
 *  FUNCTION NAME : void hardreset(void)
 *  FILENAME      : uds_serv11.c
 *  @param        : none
 *  @brief        : The function resets the MCU.
 *  @return       : none
 */
void hardreset(void)
{
    if(HardReset_b)
    {
        /* TODO: MCU specific Reset function to be implemented here */
    }
    return;
}


/*
 *  FUNCTION NAME : softreset
 *  FILENAME      : uds_serv11
 *  @param        : none
 *  @brief        : The function resets the MCU.
 *  @return       : none
 */
void softreset(void)
{
    if(SoftReset_b)
    {
        /* TODO: MCU specific Reset function to be implemented here */
    }
    return;
}


/*
 *  FUNCTION NAME :  iso14229_serv11
 *  FILENAME      :  iso14229_serv11.c
 *  @param        :  UDS_Serv_St_t* UDS_Serv_pSt
 *  @brief        : This function is verify that received key is matched or not with calculated key
 *  @return       :  serv_11_resp_En
 */
UDS_Serv_resptype_En_t iso14229_serv11 (UDS_Serv_St_t* UDS_Serv_pSt)
{
    uint16_t  	numbytes_req_u16  = UDS_Serv_pSt->RxLen_u16;  
	UDS_Serv_resptype_En_t serv_11_resp_En = UDS_SERV_RESP_UNKNOWN_E;
    uint8_t 	sub_id_u8 = 0;
    bool 		Suppress_Pos_Resp_Bit_b = FALSE;
	
    sub_id_u8 = UDS_Serv_pSt->RxBuff_pu8[1];
    
    if(sub_id_u8 & 0x80)
    {
      Suppress_Pos_Resp_Bit_b = TRUE;
    }
    
    if(SERV_11_MAX_LEN != numbytes_req_u16 )        /* NRC - INVALID_MESSAGE_LENGTH - (0x13) */
    {
        UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
        UDS_Serv_pSt->TxBuff_pu8[1] = SID_ECURESET;
        UDS_Serv_pSt->TxBuff_pu8[2] = INVALID_MESSAGE_LENGTH;  	/*NRC- 0x13*/
        UDS_Serv_pSt->TxLen_u16 = 3u;
        serv_11_resp_En = UDS_SERV_RESP_NEG_E;
    }
    else if(FALSE == Check_SecurityClearance())
	{
        UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
        UDS_Serv_pSt->TxBuff_pu8[1] = SID_ECURESET;
        UDS_Serv_pSt->TxBuff_pu8[2] = SECURITY_ACCESS_DENIED; 	/*NRC- 0x33 */
        UDS_Serv_pSt->TxLen_u16 = 3u;
        serv_11_resp_En = UDS_SERV_RESP_NEG_E;
    }
    else
    {
        sub_id_u8 = sub_id_u8 & 0x7F;
        switch(sub_id_u8)
        {
        	case SUB_ID_HARDRESET:      /* SUB_ID_HARDRESET */
        		HardReset_b = TRUE;		/* Flag checked in 10ms Routine	*/
        		UDS_Serv_pSt->TxLen_u16  	= 1u;
        		UDS_Serv_pSt->TxBuff_pu8[1] = sub_id_u8;
        		serv_11_resp_En = UDS_SERV_RESP_POS_E;
        		break;

        	case SUB_ID_KEYOFFONRESET:	/* SUB_ID_KEYOFFONRESET */
        		//KeyOffOnReset_b = TRUE;	/* Flag checked in Ignition Update Routine	*/
        		UDS_Serv_pSt->TxLen_u16 = 0x01;
        		UDS_Serv_pSt->TxBuff_pu8[1] = sub_id_u8;
        		serv_11_resp_En = UDS_SERV_RESP_POS_E;
        		break;

        	case SUB_ID_SOFTRESET:      /* SUB_ID_SOFTRESET */
        		SoftReset_b = TRUE;		/* Flag checked in 10ms Routine	*/
        		UDS_Serv_pSt->TxLen_u16 = 0x01;
        		UDS_Serv_pSt->TxBuff_pu8[1] = sub_id_u8;
        		serv_11_resp_En = UDS_SERV_RESP_POS_E;
        		reset_b = true;
//        		SystemSoftwareReset();
        		break;

        	case SUB_ID_EN_RAPID_SHUTDOWN:
        		UDS_Serv_pSt->TxLen_u16  	= 3u;
        		UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
        		UDS_Serv_pSt->TxBuff_pu8[1] = SID_ECURESET;
        		UDS_Serv_pSt->TxBuff_pu8[2] = SUB_FUNC_NOT_SUPPORTED;
        		serv_11_resp_En = UDS_SERV_RESP_NEG_E;
        		break;

        	case SUB_ID_DIS_RAPID_SHUTDOWN:
        		UDS_Serv_pSt->TxLen_u16  	= 3u;
        		UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
        		UDS_Serv_pSt->TxBuff_pu8[1] = SID_ECURESET;
        		UDS_Serv_pSt->TxBuff_pu8[2] = SUB_FUNC_NOT_SUPPORTED;
        		serv_11_resp_En = UDS_SERV_RESP_NEG_E;
        		break;

        	default:
        		UDS_Serv_pSt->TxLen_u16  	= 3u;
        		UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
        		UDS_Serv_pSt->TxBuff_pu8[1] = SID_ECURESET;
        		UDS_Serv_pSt->TxBuff_pu8[2] = SUB_FUNC_NOT_SUPPORTED;
        		serv_11_resp_En = UDS_SERV_RESP_NEG_E;
        		break;

        }       
    }
	if((Suppress_Pos_Resp_Bit_b == TRUE) && (serv_11_resp_En == UDS_SERV_RESP_POS_E))
	{
		serv_11_resp_En = UDS_SERV_RESP_NORESP_E;
	}
    return serv_11_resp_En;
}


/* *****************************************************************************
 End of File
 */
