#include "sdk_project_config.h"

#define INST_CANCOM0 (0U)

typedef struct {
    flexcan_msgbuff_id_type_t msg_id_type;  /*!< Type of message ID (standard or extended)*/
    uint32_t MSG_ID_u32;
    uint32_t MASK_u32;
    uint8_t  MB_u8;
    uint8_t  Can_Module_u8;
} CAN_ID_info_St_t;


extern status_t SendCAN0_Data(uint32_t mailbox_u32, uint32_t messageId_u32, uint8_t * DataRxP_u8, uint32_t Length_u8, uint8_t IDE);
void flexcan0_Callback(uint8_t Instance, flexcan_event_type_t eventType,
  					   flexcan_state_t *flexcanState);
