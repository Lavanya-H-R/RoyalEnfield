
/******************************************************************************
 *    FILENAME    : cil_can.c
 *    DESCRIPTION : description 
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Jithesh     18/01/2017		   Initial version
 ******************************************************************************
*/ 



/* Section: Included Files                                                   */
#include "diag_sys_conf.h"
#if(TRUE == DIAG_CONF_CAN_IF)
//	#include "can_driver.h"
#endif
#include "cil_can_conf.h"
#include "can_callback.h"
#include "can_if.h"
#include "sdk_project_config.h"
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */



// assign number of signals array 
static uint32_t CIL_CAN_ConfCANIDs_u32[NUM_CAN_SIGNALS];




uint8_t CIL_CAN_ClaimedECUAddr_pu8 = 0u;



/**
 *  @function name : void CIL_CAN_Init(void)
 *  @brief           Function is working as
 *  @param           None
 *  @return          None
 *
 */
void CIL_CAN_Init(void)
{
    //DRV-CIL Interface
   uint8_t i = 0;
    
   for(i = 0 ; i < CIL_DCAN_END_E; i++)   //todo harsh
    {
        CIL_CAN_ConfCANIDs_u32[i] = CIL_CAN_Conf_aSt[i].HAL_CAN_MsgConf_St.ID_u32;
    }

    /*Register callback functions*/
    DRV_CAN_Reg_CilCallBack(CIL_CAN_HAL2CIL_IntCallBck);
    
    return;
}  


/**
 *  @function name : void CIL_CAN_HAL2CIL_IntCallBck(uint8_t IDE_u8,uint8_t DLC_u8,uint32_t CAN_ID_u32,uint8_t *DataBytes_au8).
 *  @brief           Function is working as
 *  @param           uint8_t IDE_u8,uint8_t DLC_u8,uint32_t CAN_ID_u32,uint8_t *DataBytes_au8.
 *  @return          None
 *
 */

void CIL_CAN_HAL2CIL_IntCallBck(uint8_t IDE_u8,uint8_t DLC_u8,uint8_t CAN_Module_u8,uint32_t CAN_ID_u32,uint8_t *DataBytes_au8)
{
	uint16_t CIL_CANSig_En = 0;
    uint8_t  i = 0;       //Loop count
    uint8_t  j = 0;       //Loop count
    CAN_MessageFrame_St_t Can_Applidata_St;    //structure that holds CAN application data

	
    //copy the ID from CAN message structure
//    ID_u32 = CAN_ID_u32;
    
    //this condition is  required to check whether the id is present in the table or not
    for (i = CIL_CAN_START_E; i < CIL_DCAN_TOTAL_RX_E ; i++)
    {                     
       if (CIL_CAN_ConfCANIDs_u32[i] == (CAN_ID_u32 & CIL_CAN_Conf_aSt[i].HAL_CAN_MsgConf_St.ID_MASK_u32) )
        {
			break;
        }
    } 

    if(i < CIL_DCAN_END_E && CAN_Module_u8 == CIL_CAN_Conf_aSt[i].HAL_CAN_MsgConf_St.Can_Module_En)
    {
        Can_Applidata_St.ID_u32 = CAN_ID_u32;
        Can_Applidata_St.DataLength_u8 = DLC_u8;

        //copy the data from CAN message structure
        for (j = 0; j < DLC_u8; j++)
        {
            Can_Applidata_St.DataBytes_au8[j] = DataBytes_au8[j];
        }

        //if the user has configured the call back function then call that call back function
        //or else it will be null no data will be sent
        if (NULL != CIL_CAN_Conf_aSt[i].CAN_FnPtr)
        {
            CIL_CANSig_En = (uint16_t)(i + CIL_CAN_START_E);
            CIL_CAN_Conf_aSt[i].CAN_FnPtr (CIL_CANSig_En, Can_Applidata_St);
        }
    }
    return;
}

//can_frame_St_t boot_can_frame_St;
/**
*  @brief  Function CIL_CAN_Tx_Ack_Msg will copy the data from application and keep
*  @brief  it in a local structure and will send to  HAL_CAN_Txack_TransmitMessage
*  @brief  function which is present in HAL_CAN_tx.c.This function will check
*  @brief  for acknowledgemnt after transmitting CAN data frame and return failure if 
*  @brief  it did not receive acknowledgement in time specified and returns success if 
*  @brief  it receives acknowledgement in time specified.
*
*  @param   SignalName
*
*  @param   Can_Message_St_t Can_Applidata_St - CAN Application Data Structure
*
*  @return CAN_SUCCESS_E          - If the transmission is success
*  @return CAN_FAILED_E           - If the function won't execute any statement
*
*
*/
flexcan_msgbuff_t CAN_TxMessage_St;
CAN_RESP_En_t CIL_CAN_Tx_AckMsg (uint16_t SignalName_u16, CAN_MessageFrame_St_t Can_Applidata_St)
{
	status_t status;
	uint8_t ide_u8 = 0;
	CAN_RESP_En_t eCanRetCode = CAN_FAILED_E; // To hold the return value of the function
	PARAM_NOTUSED(SignalName_u16);

#if(TRUE == DIAG_CONF_CAN_IF)
	CAN_TxMessage_St.dataLen = Can_Applidata_St.DataLength_u8;
	CAN_TxMessage_St.msgId = Can_Applidata_St.ID_u32;

	for (uint32_t i = 0; i < Can_Applidata_St.DataLength_u8; i++)
	{
		CAN_TxMessage_St.data[i] = Can_Applidata_St.DataBytes_au8[i];
	}

	for (uint8_t id_index = 0; id_index < CIL_DCAN_END_E; id_index++)
	{
		if (CAN_TxMessage_St.msgId == CIL_CAN_Conf_aSt[id_index].HAL_CAN_MsgConf_St.ID_u32)
		{
			ide_u8 = CIL_CAN_Conf_aSt[id_index].HAL_CAN_MsgConf_St.IDE_u8;
		}
	}
	status = SendCAN0_Data(0, CAN_TxMessage_St.msgId, CAN_TxMessage_St.data, CAN_TxMessage_St.dataLen, ide_u8);
	if (STATUS_SUCCESS == status)
	{
		eCanRetCode = CAN_SUCCESS_E;
	}

#endif
	return eCanRetCode;
}

/**
 *  @brief Function CIL_CAN_Tx_DynamicMsg will copy the data from application and keep
 *  @brief it in a local structure and will send to  HAL_CAN_Tx_TransmitMessage
 *  @brief function which is present in HAL_CAN_tx.c.This function takes ID from 
 *  @brief the structure passed as parameter to this function instead of taking from 
 *  @brief configuration table.
 *
 *  @param   SignalName
 *
 *  @param   Can_Message_St_t Can_Applidata_St - CAN Application Data Structure
 *
 *  @return CANRC_SUCCESS_E    - If the transmission is success
 *  @return CANRC_FAILED_E     - If the function won't execute any statement
 *  @return CANRC_INVALID_MODULE_E    - If the CAN module is not valid
 *  @return CANRC_NULL_E       - If the Can_Message_pSt points to null pointer
 *
 */
 
CAN_RESP_En_t CIL_CAN_Tx_DynamicMsg (uint16_t SignalName_u16, CAN_MessageFrame_St_t Can_Applidata_St)
{
	CAN_RESP_En_t  eCanRetCode = CAN_FAILED_E;    // To hold the return value of the function
    PARAM_NOTUSED (SignalName_u16);
    
#if(TRUE == DIAG_CONF_CAN_IF)
	Tx_MsgBuf_Processing(1,Can_Applidata_St.DataLength_u8,&Can_Applidata_St.DataBytes_au8[0]);
//    uint32_t i = 0;
////    status_t status = STATUS_BUSY;
//    flexcan_msgbuff_t HAL_CAN_TxMessage_St;
//    static uint8_t MB_u8 = 10;
//    if(MB_u8 == 12)
//    {
//    	MB_u8 = 10;
//    }
//    else
//    {
//    	MB_u8++;
//    }

//    HAL_CAN_TxMessage_St.dataLen = Can_Applidata_St.DataLength_u8;
//    HAL_CAN_TxMessage_St.msgId = Can_Applidata_St.ID_u32;

////    HAL_CAN_TxMessage_St.IDE_u8 = (flexcan_msgbuff_id_type_t)Can_Applidata_St.MessageType_u8;//Can_Applidata_St.//CIL_CAN_Conf_aSt[SignalName_u16].HAL_CAN_MsgConf_St.IDE_u8;
////	    HAL_CAN_TxMessage_St.RTR_u8 = DATA_FRAME_E;//CIL_CAN_Conf_aSt[SignalName_u16].HAL_CAN_MsgConf_St.RTR_u8;
//    for (i=0; i<Can_Applidata_St.DataLength_u8; i++)
//    {
//        HAL_CAN_TxMessage_St.data[i] = Can_Applidata_St.DataBytes_au8[i];
//    }
//    flexcan_data_info_t dataInfo1 =
//    {
//    		.data_length = HAL_CAN_TxMessage_St.dataLen,
//            .msg_id_type = (flexcan_msgbuff_id_type_t)Can_Applidata_St.MessageType_u8,
//            .enable_brs  = false,
//            .fd_enable   = false,
//            .fd_padding  = 0U,
//			.is_remote   = false
//    };

////    HAL_CAN_TxMessage_St.IsOnShotTx = (BOOL)FALSE;//CIL_CAN_Conf_aSt[SignalName_u16].HAL_CAN_MsgConf_St.IsOnShotTx;
////    HAL_CAN_TxMessage_St.Label_u16 = 0x10U;//CIL_CAN_Conf_aSt[SignalName_u16].HAL_CAN_MsgConf_St.Label_u16;
////    HAL_CAN_TxMessage_St.IsTxHistEn = (BOOL)FALSE;//CIL_CAN_Conf_aSt[SignalName_u16].HAL_CAN_MsgConf_St.IsTxHistEn;

////    eCanRetCode = HAL_CAN_SendCANMsg((HAL_CAN_BufferId_En_t)TX_BUFFER_ID, &HAL_CAN_TxMessage_St);
//    FLEXCAN_DRV_ConfigTxMb(CIL_CAN_Conf_aSt[SignalName_u16].HAL_CAN_MsgConf_St.Can_Module_En, MB_u8, &dataInfo1, HAL_CAN_TxMessage_St.msgId);
//    /*
//    DRV-CIL Interface
//    */
//    /* Execute send data */
//    FLEXCAN_DRV_Send(CIL_CAN_Conf_aSt[SignalName_u16].HAL_CAN_MsgConf_St.Can_Module_En, MB_u8, &dataInfo1, HAL_CAN_TxMessage_St.msgId, HAL_CAN_TxMessage_St.data);
////    if(status != STATUS_SUCCESS)
////    {
////    	  PINS_DRV_SetPins(PTD, 1 << 16);
////    }

////    HAL_CAN_Send_Dynamic(SignalName_u16,Can_Applidata_St);
    eCanRetCode = CAN_SUCCESS_E;
#endif
    return eCanRetCode;

}     

/**
*  @brief  Function to set claimed address.
*  @param   Address : Address of variable holding a claimed address.
*  @return  none
*/
void CIL_CAN_SetClaimedAddr(UINT8 Address)
{
    CIL_CAN_ClaimedECUAddr_pu8 = Address;
}


/* *****************************************************************************
 End of File
 */
