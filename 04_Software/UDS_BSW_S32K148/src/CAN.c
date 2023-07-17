#include "CAN.h"

#define Num_IDs    1
CAN_ID_info_St_t CAN_ID_info_t[Num_IDs] =
{
	{FLEXCAN_MSG_ID_STD,	0x7F0,		0x7FF,	0, INST_CANCOM0},
};
flexcan_msgbuff_t RecvBuff1_St;

void FlexCAN_init(void)
{
	/*Initializes CAN 0*/
	PINS_DRV_ClearPins(PTA, (1 << 21));//Stand by pin for CAN0

	FLEXCAN_DRV_Init(INST_CANCOM0, &flexcanState0, &flexcanInitConfig0);
	FLEXCAN_DRV_SetRxMaskType(INST_CANCOM0, FLEXCAN_RX_MASK_INDIVIDUAL);

	flexcan_data_info_t dataInfo =
	{
		.data_length = 8U,
		.msg_id_type = FLEXCAN_MSG_ID_STD,
		.enable_brs  = false,
		.fd_enable   = false,
		.fd_padding  = 0U
	};

	for(uint8_t id_index = 0; id_index < Num_IDs; id_index++)
	{
		if(INST_CANCOM0 == CAN_ID_info_t[id_index].Can_Module_u8)
	    {
			dataInfo.msg_id_type = CAN_ID_info_t[id_index].msg_id_type;

			FLEXCAN_DRV_SetRxIndividualMask(INST_CANCOM0, CAN_ID_info_t[id_index].msg_id_type, CAN_ID_info_t[id_index].MB_u8, CAN_ID_info_t[id_index].MASK_u32);
			FLEXCAN_DRV_ConfigRxMb(INST_CANCOM0, CAN_ID_info_t[id_index].MB_u8 , &dataInfo, CAN_ID_info_t[id_index].MSG_ID_u32);
			FLEXCAN_DRV_Receive(INST_CANCOM0, CAN_ID_info_t[id_index].MB_u8, &RecvBuff1_St);
			/* This is for Global Mask*/
			//FLEXCAN_DRV_SetRxMbGlobalMask(INST_CANCOM0, FLEXCAN_MSG_ID_STD, 0);
	    }
	}
	FLEXCAN_DRV_InstallEventCallback(INST_CANCOM0, (void*) flexcan0_Callback, NULL);
}

void flexcan0_Callback(uint8_t Instance, flexcan_event_type_t eventType,flexcan_state_t *flexcanState)
{
   	(void)flexcanState->errorCallbackParam;
   	uint8_t i = 0;
   	switch(eventType)
   	{
   	case FLEXCAN_EVENT_RX_COMPLETE:
   		{
   		   for(i = 0; i<(sizeof(CAN_ID_info_t)/sizeof(CAN_ID_info_t[0])); i++)
   		   {
   			   if(INST_CANCOM0 == CAN_ID_info_t[i].Can_Module_u8)
   			   {
				   /* enable receiving data in RX_MAILBOX again */
				   if(STATUS_SUCCESS == FLEXCAN_DRV_Receive(INST_CANCOM0, CAN_ID_info_t[i].MB_u8, &RecvBuff1_St))
				   {
					   DRV_HAL2CIL_CallBack(0, RecvBuff1_St.dataLen, Instance, RecvBuff1_St.msgId, RecvBuff1_St.data);
					   break;
				   }
   			   }
   		   }

   		}
   		break;
   	case FLEXCAN_EVENT_RXFIFO_COMPLETE:
   		{
   			/* enable receiving data in RX FIFO again */
   			//FLEXCAN_DRV_RxFifo(INST_CANCOM1,&RecvBuff2_St);
   		}
   		break;
   	case FLEXCAN_EVENT_TX_COMPLETE:
   		{
   		}
  		break;
    default:
   		break;
   	}
}

status_t SendCAN0_Data(uint32_t mailbox_u32, uint32_t messageId_u32, uint8_t *DataRxP_u8, uint32_t Length_u8, uint8_t IDE)
{
	status_t status;
	flexcan_data_info_t dataInfo =
		{
			.data_length = Length_u8,
			.msg_id_type = IDE,
			.enable_brs = false,
			.fd_enable = false,
			.fd_padding = 0U};
	/* Configure TX message buffer with index TX_MSG_ID and TX_MAILBOX*/
	FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0, mailbox_u32, &dataInfo, messageId_u32);

	/* Execute send data */
	status = FLEXCAN_DRV_Send(INST_CANCOM0, mailbox_u32, &dataInfo, messageId_u32, DataRxP_u8);
	return status;
}
