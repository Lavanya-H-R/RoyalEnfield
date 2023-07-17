/******************************************************************************
 *    FILENAME    : uds_session.c
 *    DESCRIPTION : Service description for UDS session
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/ 

/*
****************************************************************************
* Includes
****************************************************************************
*/
#include "str_util.h"
//#include "diag_typedefs.h"
#include "diag_typedefs.h"
#include "diag_adapt.h"
#include "uds_session.h"
#include "diag_sys_conf.h"
#include "i15765.h"
#include "uds_conf.h"
#include "uds_session.h"

//#include "fsp_common_api.h"
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

static UDS_Serv_resptype_En_t   ServDistUDS(uint16_t);
UDS_Serv_St_t               Serv_databuf_St;


/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */


/*
 **************************************************************************************************
 *    Variables
 **************************************************************************************************
 */
 
// Global variable that contains the application layer specific data
static ServiceDistUDS_St_t* ServDistUDS_pt = NULL;
uint8_t current_active_session_u8;

/**
 *  Function name  : void uds_session_proc_5ms()
 *  @brief         : Function for uds session process of 5ms.
 *                   
 *  @param         : none
 *
 *  @return        : none.

 */
void uds_session_proc_5ms(void)
{
	uint16_t canTpInstanceId_u16 = 0;
	uint32_t current_cputimer_u32 = 0;
	UDS_Serv_resptype_En_t resp_type_En = UDS_SERV_RESP_NORESP_E;    // To store the response code
    static bool     instanceSessTimeout_b = false;

#if(TRUE == DIAG_CONF_CANTP_SUPPORTED)

    static uint8_t  instanceSessTimeout_au8[DCAN_TP_INSTANCE_TOTAL_E] /*= {0, 0}*/;

	current_cputimer_u32 = GET_TIME_MS();
	//Periodic_Data_Transmit_proc();
    
    instanceSessTimeout_b = true;
    for(canTpInstanceId_u16 = DCAN_TP_INSTANCE_UDSDIAG_START_E ; canTpInstanceId_u16 < DCAN_TP_INSTANCE_UDSDIAG_END_E ; canTpInstanceId_u16++ )
    {
        //instanceSessTimeout_au8[canTpInstanceId_u16] = false;
        if(DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->sessionTimeoutTimer_u32 <= current_cputimer_u32)
        {
            if(SUPPLIER_EOL_SESSION_SUB_ID_E != current_active_session_u8)
            {
                 instanceSessTimeout_au8[canTpInstanceId_u16] = true;
                 //service_distributor_timeout();
            }
            DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->sessionTimeoutTimer_u32 = GET_TIME_MS() + ISO15765_CONF_SESSION_TIMEOUT_DELAY_MS; // todo harsh
        }
        instanceSessTimeout_b = instanceSessTimeout_b && instanceSessTimeout_au8[canTpInstanceId_u16];
    }

    if (instanceSessTimeout_b)
    {
        instanceSessTimeout_b = false;

        /* session timeout when there is no traffic any instances */
        service_distributor_timeout();

        for(canTpInstanceId_u16 = DCAN_TP_INSTANCE_UDSDIAG_START_E ; canTpInstanceId_u16 < DCAN_TP_INSTANCE_UDSDIAG_END_E ; canTpInstanceId_u16++ )
        {
            instanceSessTimeout_au8[canTpInstanceId_u16] = false;
        }
    }
    
    
    
//	*DID_Config_aSt[ACTIVE_DIAGNOSTIC_SESS_E].Var_ptr_pu8 = current_active_session_u8;// todo Sandeep
	
	for(canTpInstanceId_u16 = DCAN_TP_INSTANCE_UDSDIAG_START_E ; canTpInstanceId_u16 < DCAN_TP_INSTANCE_UDSDIAG_END_E ; canTpInstanceId_u16++ )
    {
		// Check if AL is in process_request state
		if (DCAN_TP_ST_PROC_REQ_E == DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->al_state_u8)
		{

			//if(canTpInstanceId_u16 == DCAN_TP_INSTANCE_IVN_E)  //todo-hareesha
			{
				resp_type_En = ServDistUDS(canTpInstanceId_u16);

				if(DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->databuf_pu8[SID_INDEX] != UDS_NEG_RESP_CODE)
                {
					DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->sessionTimeoutTimer_u32 = GET_TIME_MS() + ISO15765_CONF_SESSION_TIMEOUT_DELAY_MS;
                    instanceSessTimeout_au8[canTpInstanceId_u16] = false;
				}
				else
                {
					if(DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->databuf_pu8[2] != SERVICE_NOT_SUPPORTED &&
							DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->databuf_pu8[2] != SERVNOSUPP_IN_ACTIVE_SESS )
                    {
							DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->sessionTimeoutTimer_u32 = GET_TIME_MS() + ISO15765_CONF_SESSION_TIMEOUT_DELAY_MS;
                            instanceSessTimeout_au8[canTpInstanceId_u16] = false;
					}
				}
			}
			//else
            //{
				//do whatever to be done for second isntance "DCAN_TP_INSTANCE_UDSDIAG_E"

			//}

			if ((UDS_SERV_RESP_POS_E == resp_type_En) ||
				(UDS_SERV_RESP_NEG_E == resp_type_En))
			{
				clearBuffer(canTpInstanceId_u16, BUFF1_TP_E);

				if(DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->al_state_u8 != DCAN_TP_ST_TX_INPROG_E){
					DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->al_state_u8 = DCAN_TP_ST_TX_INITIATED_E;
				}
				else{
					DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->tx_prcwait_b = TRUE;
				}
			}

			if (UDS_SERV_RESP_NORESP_E == resp_type_En)
			{
				clearBuffer(canTpInstanceId_u16, BUFF1_TP_E);
			}

			FunAddessedID_flag = 0;
			current_cputimer_u32 = GET_TIME_MS();

			if ((UDS_SERV_RESP_WAITPEND_E == resp_type_En) &&
		          (FALSE == DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->flag_P2Ext_b)){

				clearBuffer(canTpInstanceId_u16, BUFF1_TP_E);

				DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->flag_P2Ext_b = TRUE;
				/* Load the P2 timer value */
				DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->P2_timings_u32 = DCAN_TPTiming_St.P3_u32;
				/* Start P2 timer */
				DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->timer_u32 = current_cputimer_u32 + DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->P2_timings_u32;

				if(DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->al_state_u8 != DCAN_TP_ST_TX_INPROG_E)
                {
					DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->al_state_u8 = DCAN_TP_ST_TX_INITIATED_E;
				}
				else
                {
					DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->tx_prcwait_b = TRUE;
				}
			}

			// Check if P2 or extended P2 timer expires
			if (DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->timer_u32 <= current_cputimer_u32)
			{
				if (TRUE == DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->flag_P2Ext_b)
				{
					if (UDS_SERV_RESP_WAITPEND_E == resp_type_En)
					{
						/* Reload extended P2 timer again */
						DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->timer_u32 = current_cputimer_u32 + DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->P2_timings_u32;
						DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->al_state_u8 = DCAN_TP_ST_IDLE_E;

						// Change AL state to transmission initiated
						DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->al_state_u8 = DCAN_TP_ST_TX_INITIATED_E;
					}
				}
				else
				{
					// Change AL state to idle state
					// DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->timer_u32 ->al_state_u8 = DCAN_TP_ST_IDLE_E;
					DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->timer_u32 = 0;
					//clearBuffer(canTpInstanceId_u16,BUFF1_TP_E);
				}
			}

		}
	}
#endif
}

/**
 *  Function name  : void setOBDServDist (ServiceDist_St_t*)
 *  @brief         : Function captures the number of entries in the Distributor .
 *                   table and the configuration structure pointer.

 *  @param         : ServiceDist_St_t* ConfigServDist_pt - pointer to service distributor
 *                                                 table.
 *  @param         : uint32_t numentries_u32 - Number of entries in configuration table.
 *
 *  @return        : none.
 *  @Code tag      : @[CODE_OBD_SERVDIST_3] @{SDD_OBD_SERVDIST_3}
 */
void setUDSServDist(const ServiceDistUDS_St_t* ConfigServDist_pt, uint32_t numentries_u32)
{
	ServDistUDS_pt = ConfigServDist_pt;         // Service distributor pointer
    //ServDistNumEntries_u32 = numentries_u32; // Number of entries in the SID table

    return;
}

/**
 *  Function name  : void servDistSetstr()
 *  @brief         : Function for service distributor setting
 *                   

 *  @param         : none
 
 *
 *  @return        : none.

 */
void servDistSetstr(void)
{
#if(TRUE == DIAG_CONF_UDS_SUPPORTED && TRUE == DIAG_CONF_CANTP_SUPPORTED)

	Serv_databuf_St.RxBuff_pu8 = DCAN_tpFrameCtrl_paSt[DCAN_TP_INSTANCE_IVN_E][BUFF1_TP_E]->databuf_pu8;
	Serv_databuf_St.TxBuff_pu8 = DCAN_tpFrameCtrl_paSt[DCAN_TP_INSTANCE_IVN_E][BUFF2_TP_E]->databuf_pu8;
	Serv_databuf_St.RxLen_u16 = 0 ;
	Serv_databuf_St.TxLen_u16 = 0 ;

#endif
		current_active_session_u8 = UDS_SESS_DEFAULT;
}

/**
 *  Function name  : void ServDistUDS_init()
 *  @brief         : Function for service distributor initialization.
 *                   

 *  @param         : none
 
 *
 *  @return        : none.

 */
void ServDistUDS_init(void)
{
	setUDSServDist((const ServiceDistUDS_St_t*) UDSServDist_apt, (sizeof(UDSServDist_apt) /sizeof(UDSServDist_apt[0])));
	servDistSetstr();
	//return;
}


/**
* Function name  : Serv_resptype_En_t ServDist_CAN ()
* @brief         : Function implements the service distributor for ISO 14229
* @param         : NULL
* @return        : Type of response
* @Code tag      : @[CODE_OBD_SERVDIST_2] @{SDD_OBD_SERVDIST_2}
*/ 
static UDS_Serv_resptype_En_t ServDistUDS(uint16_t canTpInstanceId_u16)
{
    UDS_Serv_resptype_En_t respCode_E = UDS_SERV_RESP_NORESP_E;    // Initialize the response code to no response
    static uint8_t  sid_u8 = 0;     // Variable to hold the received SID number
	static bool  call_serviceagain_b = FALSE;    // Flag to track the request is called for wait pending CVN
    bool  foundService_b = FALSE;           // flag used to trace the SID table
    uint8_t  idx_u8 = 0;             // For loop tracing index
	uint8_t  current_session_bit_u8 = 0;		
	uint8_t  session_support_u8 = 0;		
#if(TRUE == DIAG_CONF_CANTP_SUPPORTED)

    // Check if the service distributor pointer is valid.
    if (ServDistUDS_pt != NULL)
    {
        Serv_databuf_St.RxBuff_pu8 = DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->databuf_pu8;     
        Serv_databuf_St.TxBuff_pu8 = DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->databuf_pu8;     

        Serv_databuf_St.TxLen_u16 = 0;
        Serv_databuf_St.RxLen_u16 = DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF1_TP_E]->numbytes_req_u16 ;
		
		if(!call_serviceagain_b){
			sid_u8 = Serv_databuf_St.RxBuff_pu8[SID_INDEX];
		}
		
        // Search for the PID and break in case of a success
        for(idx_u8 = 0 ;(idx_u8 < ServDist_UDS_NumEntries_u32 );idx_u8++)
        {
            // If the PID is found then assert the flag to stop the search.
            if (sid_u8 == ServDistUDS_pt[idx_u8].sid_u8)
            {
				
                foundService_b = TRUE;
				break;
            }                            
        }
		
		
        if(!foundService_b && (!FunAddessedID_flag))
        {
            // fill the negative response code in the buffer
            Serv_databuf_St.TxBuff_pu8[SID_INDEX] = 0x7F;
            // Copy the SID to the second byte
            Serv_databuf_St.TxBuff_pu8[SID_INDEX+1] = sid_u8;       
            Serv_databuf_St.TxBuff_pu8[2] = SERVICE_NOT_SUPPORTED;
            Serv_databuf_St.TxLen_u16 = 3;
            respCode_E = UDS_SERV_RESP_NEG_E;
            
        }
		else if(!foundService_b)
		{
			FunAddessedID_flag = 0;
		}
        // Check for the valid index
        else 
        {
            // Valid service intrepreter exist call the function
            if (ServDistUDS_pt[idx_u8].Service_Fptr_t != NULL)
            {
                switch(current_active_session_u8) 
				{
					case DEFAULT_SESSION_SUB_ID_E:
						current_session_bit_u8 = UDS_SESS_DEFAULT;
						break;
					case PROGRAMMING_SESSION_SUB_ID_E:
						current_session_bit_u8 = UDS_SESS_PROG;
						break;
					case EXTENDED_DIAG_SESSION_SUB_ID_E:
						current_session_bit_u8 = UDS_SESS_EXTENDED;
						break;
					case ENGINEERING_DIAG_SESSION_SUB_ID_E:
						current_session_bit_u8 = UDS_SESS_ENGG;
						break;
					case SUPPLIER_EOL_SESSION_SUB_ID_E:
						current_session_bit_u8 = UDS_SESS_SUPPL_EOL;
						break;
					default :
						current_session_bit_u8 = UDS_SESS_DEFAULT;
						break;
				}
					
				session_support_u8 = ServDistUDS_pt[idx_u8].Session_subid_u8 & current_session_bit_u8;
                if(session_support_u8)
                {
                    // Call the service functions depends upon the SID.
                    respCode_E = ServDistUDS_pt[idx_u8].Service_Fptr_t(&Serv_databuf_St);
                }
                else
                {
					// fill the negative response code in the buffer
					Serv_databuf_St.TxBuff_pu8[SID_INDEX] = 0x7F;
					// Copy the SID to the second byte
					Serv_databuf_St.TxBuff_pu8[SID_INDEX+1] = sid_u8;       
					Serv_databuf_St.TxBuff_pu8[2] = SERVNOSUPP_IN_ACTIVE_SESS;
					Serv_databuf_St.TxLen_u16 = 3;
					respCode_E = UDS_SERV_RESP_NEG_E;
                }
                    
                switch (respCode_E)
                {
                    // For positive response
                    case UDS_SERV_RESP_POS_E:
                    {
                        Serv_databuf_St.TxBuff_pu8[SID_INDEX] = (uint8_t)(Serv_databuf_St.RxBuff_pu8[SID_INDEX] + 0x40);
						Serv_databuf_St.TxLen_u16 = (uint16_t)(Serv_databuf_St.TxLen_u16 + 1);
						call_serviceagain_b = FALSE;
                        break;
                    }
                    // For negative response
                    case UDS_SERV_RESP_NEG_E:
                    {
						if((Serv_databuf_St.TxBuff_pu8[2] != INVALID_MESSAGE_LENGTH) && (FunAddessedID_flag == 1))
						{
							respCode_E = UDS_SERV_RESP_NORESP_E;
						}
                        call_serviceagain_b = FALSE;
                        break;
                    }
                    // For waiting response
                    case UDS_SERV_RESP_WAITPEND_E:
                    {
                        // Fill the negative response code in the buffer
                        Serv_databuf_St.TxBuff_pu8[SID_INDEX] = 0x7F;
                        Serv_databuf_St.TxBuff_pu8[SID_INDEX +1 ] = Serv_databuf_St.RxBuff_pu8[SID_INDEX];
                        // Fill the waiting response code in the buffer
                        Serv_databuf_St.TxBuff_pu8[SID_INDEX+2] = 0x78;
                        // Add the number of response byte in the global structure
                        Serv_databuf_St.TxLen_u16 = (uint16_t)(Serv_databuf_St.TxLen_u16 + 3);
                        call_serviceagain_b = TRUE;
                        break;
                    }
                    // For no response
                    case UDS_SERV_RESP_NORESP_E:
                    default:
                    {
						call_serviceagain_b = FALSE;
                       break;
                    }
                }
            }
        }
        DCAN_tpFrameCtrl_paSt[canTpInstanceId_u16][BUFF2_TP_E]->numbytes_resp_u16 = Serv_databuf_St.TxLen_u16 ;
    }
#endif
    return respCode_E;
}

/**
* Function name  : void service_distributor_timeout(void)
* @brief         : Function is call all service timeout function 
* @param         : none
* @return        : none
*/ 
               
void service_distributor_timeout(void){  
	current_active_session_u8 = UDS_SESS_DEFAULT;
	//Serv31_Routine_Complete();
//    UDS_serv27_timeout();
//	UDS_Serv3E_Timeout();
//	UDS_Serv28_Timeout();
	//vd_Stop_EOL();
}


/* *****************************************************************************
 End of File
  ******************************************************************************/
