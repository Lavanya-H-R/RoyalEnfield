/******************************************************************************
 *    FILENAME    : uds_serv27.c                                              *          
 *    DESCRIPTION : UDS service - Security Access.            *
 ******************************************************************************
 * Revision history                                                           *         
 *                                                                            *          
 * Ver Author       Date               Description                            *  
 * 1   Sloki     1/10/2019	   Initial version                            *
 ******************************************************************************
*/  

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
#include "iso14229_serv27.h"
#include<stdlib.h>

/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*
 @summary :- array of flags decide that security access or not 
 */
bool security_Access_Gained_b[SECURITY_ACCESS_N0];
/*
 @summary :- this flag for required time delay is expired or not 
 */
static bool Req_delay_not_expire_b = FALSE;

/*
 @summary : this variable is treated as handler
 */
SA_STATE_MACHINE_En_t  Serv27_SA_handler_En = SA_NO_ACCESS_E;

 
/*
 @summary : this variable is for to reach required time delay or not 
 */
//static uint32_t Timer_delay_for_security_u32 = 0;  todo-sandeep

/*Number of attempts*/
 static uint8_t Number_of_Attempts_u8 = 0;

 /*Variable to hold the 4 byte random SEED*/
 uint32_t uint32_random_SEED;
 
 
uint8_t ltable[MAX_VAL];
uint8_t atable[MAX_VAL];
uint32_t rx_data;
uint32_t rx_key;
uint32_t final_data;
uint8_t uint8_t_CalculatedKeyBuff[4];
uint32_t uint32_KEY_Data; 
 
/* declare the variable*/
SPLIT_RAND_Un_t SPLIT_RAND_Un;


/*
 *  FUNCTION NAME : Verify_Key
 *  FILENAME      : uds_serv27.c
 *  @brief        : This function is verify that received key is matched or not with calculated key   
 *  @param        : Databuff_pu8 which is pointing to the key value buffer 
 *  @return       : bool  
 */

bool Verify_Key(uint8_t * Databuff_pu8, uint8_t SecurityLevel);

/*
 *  FUNCTION NAME : GENERATE_SEED_Frame
 *  FILENAME      : uds_serv27.c
 *  @brief        : This function is made for the seed frame  
 *  @param        : Databuff_pu8 which is storing to the data into  buffer  
 *  @return       : void    
 */

static void  GENERATE_SEED_Frame(uint8_t * Databuff_pu8);

/*
 *  FUNCTION NAME : GENERATENULLSeed
 *  FILENAME      : uds_serv27.c
 *  @brief        : This function is made for the seed frame   
 *  @param        : Databuff_pu8 -> storing into the null seed  
 *  @return       : void    
 */

static void  GENERATENULLSeed(uint8_t * Databuff_pu8);

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*
 *  FUNCTION NAME : Verify_Key
 *  FILENAME      : uds_serv27.c
 *  @brief        : This function is verify that received key is matched or not with calculated key     
 *  @param        : Databuff_pu8 which is pointing to the key value buffer
 *  @return       : bool  
 */
//uint32_t uint32_CalculatedKey;
bool Verify_Key(uint8_t *Databuff_pu8, uint8_t SecurityLevel)
{
//    uint8_t i;
    bool Response_b = TRUE;
	uint32_t uint32_SecretKey = 0x00000000;
	uint32_t uint32_CalculatedKey;

	if ((current_active_session_u8 == PROGRAMMING_SESSION_SUB_ID_E) && (SecurityLevel == SEND_KEY_PROGRAMMING))
	{
//		uint32_SecretKey  = (uint32_t)(((uint32_t)DID_Config_aSt[SAMPLE_DID_1_E].Var_ptr_pu8[0] << 24u) & 0xFF000000);
//		uint32_SecretKey |= (uint32_t)(((uint32_t)DID_Config_aSt[SAMPLE_DID_2_E].Var_ptr_pu8[1] << 16u) & 0x00FF0000);
//		uint32_SecretKey |= (uint32_t)(((uint32_t)DID_Config_aSt[SAMPLE_DID_3_E].Var_ptr_pu8[2] << 8u) & 0x0000FF00);
//		uint32_SecretKey |= (uint32_t)(((uint32_t)DID_Config_aSt[SAMPLE_DID_4_E].Var_ptr_pu8[3]) & 0x000000FF);
		
		uint32_CalculatedKey = uint32_CalculateKEY(uint32_random_SEED,uint32_SecretKey);
		uint8_t_CalculatedKeyBuff[0] = ((uint32_CalculatedKey & 0xFF000000) >> 24u);
		uint8_t_CalculatedKeyBuff[1] = ((uint32_CalculatedKey & 0x00FF0000) >> 16u);
		uint8_t_CalculatedKeyBuff[2] = ((uint32_CalculatedKey & 0x0000FF00) >> 8u);
		uint8_t_CalculatedKeyBuff[3] =  (uint32_CalculatedKey & 0x000000FF);
		if((uint8_t_CalculatedKeyBuff[0] == Databuff_pu8[0]) && \
		   (uint8_t_CalculatedKeyBuff[1] == Databuff_pu8[1]) && \
		   (uint8_t_CalculatedKeyBuff[2] == Databuff_pu8[2]) && \
		   (uint8_t_CalculatedKeyBuff[3] == Databuff_pu8[3]))
		{
			Response_b = TRUE;
		}
		else
		{
			Response_b = FALSE;
		}
	}
	else if (current_active_session_u8 == EXTENDED_DIAG_SESSION_SUB_ID_E)// todo harsh
	{
		switch(SecurityLevel)
		{
			case SEND_KEY_EXTENDED:
			{
//				uint32_SecretKey  = (uint32_t)(((uint32_t)DID_Config_aSt[EXTENDED_SECRET_KEY_E].Var_ptr_pu8[0] << 24u) & 0xFF000000);
//				uint32_SecretKey |= (uint32_t)(((uint32_t)DID_Config_aSt[EXTENDED_SECRET_KEY_E].Var_ptr_pu8[1] << 16u) & 0x00FF0000);
//				uint32_SecretKey |= (uint32_t)(((uint32_t)DID_Config_aSt[EXTENDED_SECRET_KEY_E].Var_ptr_pu8[2] << 8u) & 0x0000FF00);
//				uint32_SecretKey |= (uint32_t)(((uint32_t)DID_Config_aSt[EXTENDED_SECRET_KEY_E].Var_ptr_pu8[3]) & 0x000000FF);
//				
//				uint32_CalculatedKey = uint32_CalculateKEY(uint32_random_SEED,uint32_SecretKey);
//				uint8_t_CalculatedKeyBuff[0] = ((uint32_CalculatedKey & 0xFF000000) >> 24);
//				uint8_t_CalculatedKeyBuff[1] = ((uint32_CalculatedKey & 0x00FF0000) >> 16);
//				uint8_t_CalculatedKeyBuff[2] = ((uint32_CalculatedKey & 0x0000FF00) >> 8);
//				uint8_t_CalculatedKeyBuff[3] = (uint32_CalculatedKey & 0x000000FF);
                
               uint8_t_CalculatedKeyBuff[0] = 1;
				uint8_t_CalculatedKeyBuff[1] = 2;
				uint8_t_CalculatedKeyBuff[2] = 3;
				uint8_t_CalculatedKeyBuff[3] = 4;
              
				if((uint8_t_CalculatedKeyBuff[0] == Databuff_pu8[0]) && \
				(uint8_t_CalculatedKeyBuff[1] == Databuff_pu8[1]) && \
				(uint8_t_CalculatedKeyBuff[2] == Databuff_pu8[2]) && \
				(uint8_t_CalculatedKeyBuff[3] == Databuff_pu8[3]))
				{
					Response_b = TRUE;
				}
				else
				{
					Response_b = FALSE;
				}
				break;
			}
			case SEND_KEY_ENGINEERING:
			{
//				uint32_SecretKey  = (uint32_t)(((uint32_t)DID_Config_aSt[SAMPLE_DID_1_E].Var_ptr_pu8[0] << 24u) & 0xFF000000);
//				uint32_SecretKey |= (uint32_t)(((uint32_t)DID_Config_aSt[SAMPLE_DID_2_E].Var_ptr_pu8[1] << 16u) & 0x00FF0000);
//				uint32_SecretKey |= (uint32_t)(((uint32_t)DID_Config_aSt[SAMPLE_DID_3_E].Var_ptr_pu8[2] << 8u) & 0x0000FF00);
//				uint32_SecretKey |= (uint32_t)(((uint32_t)DID_Config_aSt[SAMPLE_DID_4_E].Var_ptr_pu8[3]) & 0x000000FF);
				
				uint32_CalculatedKey = uint32_CalculateKEY(uint32_random_SEED,uint32_SecretKey);
				uint8_t_CalculatedKeyBuff[0] = ((uint32_CalculatedKey & 0xFF000000) >> 24u);
				uint8_t_CalculatedKeyBuff[1] = ((uint32_CalculatedKey & 0x00FF0000) >> 16u);
				uint8_t_CalculatedKeyBuff[2] = ((uint32_CalculatedKey & 0x0000FF00) >> 8u);
				uint8_t_CalculatedKeyBuff[3] = (uint32_CalculatedKey & 0x000000FF);
				if((uint8_t_CalculatedKeyBuff[0] == Databuff_pu8[0]) && \
				(uint8_t_CalculatedKeyBuff[1] == Databuff_pu8[1]) && \
				(uint8_t_CalculatedKeyBuff[2] == Databuff_pu8[2]) && \
				(uint8_t_CalculatedKeyBuff[3] == Databuff_pu8[3]))
				{
					Response_b = TRUE;
				}
				else
				{
					Response_b = FALSE;
				}
				break;
			}
			default:
			{
				Response_b = FALSE;
				break;
			}
		}
	}
    else
	{
		Response_b =FALSE;
	}
    
    return Response_b;
}

/*
 *  FUNCTION NAME : GENERATE_SEED_Frame
 *  FILENAME      : uds_serv27.c
 *  @brief        : This function is made for the seed frame       
 *  @param        : Databuff_pu8 which is storing to the data into  buffer 
 *  @return       : void    
 */

static void  GENERATE_SEED_Frame(uint8_t * Databuff_pu8)
{
	uint32_t random_input_u32 =  0 ;//u32_DiagMSCnt;// todo harsh;
	uint32_t i = 0;   
   
    do
    {
      //  srand(u32_DiagMSCnt++); 
        SPLIT_RAND_Un.random_number = (uint32_t)rand(); /* generating the random number*/
        SPLIT_RAND_Un.random_number |= random_input_u32; /* generating the random number*/
    }while((SPLIT_RAND_Un.random_number == 0) || (SPLIT_RAND_Un.random_number == 0xFFFFFFFF));
    uint32_random_SEED =0;
    for(i = 0; i < SEED_KEY_SIZE ; i++)
    {
		Databuff_pu8[i] = SPLIT_RAND_Un.byte_buff[i];
    }
	uint32_random_SEED = ((uint32_t)Databuff_pu8[0] << 24) | ((uint32_t)Databuff_pu8[1] << 16) | ((uint32_t)Databuff_pu8[2] << 8) | Databuff_pu8[3];
    return;     
}


/*
 *  FUNCTION NAME : GENERATENULLSeed
 *  FILENAME      : uds_serv27.c
 *  @brief         : Databuff_pu8 which is storing to the data into  buffer 
 *  @param        : Databuff_pu8 storing into the null seed    
 *  @return       : void    
 */

static void  GENERATENULLSeed(uint8_t * Databuff_pu8)
{
    uint32_t i = 0;   
    for(i = 0; i < SEED_KEY_SIZE ; i++)
    {
       Databuff_pu8[i]= 0;
    }
    return;     
}

/*  A brief description of a section can be given directly below the section
    banner.
 */
 
 

/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
 


 /**
*  FUNCTION NAME : iso14229_serv27
*  FILENAME      : iso14229_serv27.c
*  @brief        : This function will process the service_27 requests
*  @param        : UDS_Serv_St_t* UDS_Serv_pSt - pointer to service table.
*  @return       : Type of response.                     
*/
UDS_Serv_resptype_En_t iso14229_serv27(UDS_Serv_St_t* UDS_Serv_pSt)
{   
     /*Local variable for number of bytes in request*/
    uint16_t numbytes_req_u16 = UDS_Serv_pSt->RxLen_u16;  
  
    /*security access Request message sub-function parameter */
    uint8_t Sa_type_u8 = UDS_Serv_pSt->RxBuff_pu8[1];
    //uint8_t SuppressResponse_u8 = UDS_Serv_pSt->RxBuff_pu8[1] & 0x80;
    bool NoResponseFlag_b = FALSE;
    UDS_Serv_resptype_En_t Serv_resptype_En = UDS_SERV_RESP_UNKNOWN_E;
    
    if((SEED_REQUEST_LEN == numbytes_req_u16 )||(SEND_KEY_REQ_LEN == numbytes_req_u16))
    {
    
    /*if(SuppressResponse_u8)
    {
        NoResponseFlag_b = TRUE;
    }*/		

    //Sa_type_u8 = Sa_type_u8 & 0x7F;
    if(EXTENDED_DIAG_SESSION_SUB_ID_E == UDS_GetCurrentSession())//todo harsh
	{
	  switch(Sa_type_u8)
      {
        case REQUEST_SEED_EXTENDED:
        {
            
            if(TRUE == Req_delay_not_expire_b){ /* time delay expire or not*/
                
                UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
                UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
                UDS_Serv_pSt->TxBuff_pu8[2] = REQ_TIMEDELAY_NOTEX;
                UDS_Serv_pSt->TxLen_u16 = 3;
                Serv_resptype_En = UDS_SERV_RESP_NEG_E;  
                NoResponseFlag_b = FALSE;
            }
            else if (security_Access_Gained_b[SECURITY_ACCESS_LEVEL_2]) /* to check security flag true or not */
            {
                UDS_Serv_pSt->TxBuff_pu8[1] = REQUEST_SEED_EXTENDED;
                /*send the null seed*/
                GENERATENULLSeed(&UDS_Serv_pSt->TxBuff_pu8[2]);
                 UDS_Serv_pSt->TxLen_u16 = 5;
                Serv_resptype_En = UDS_SERV_RESP_POS_E;
                Serv27_SA_handler_En = SA_ACCESS_OK_E;
            }
            else 
            {
                UDS_Serv_pSt->TxBuff_pu8[1] = REQUEST_SEED_EXTENDED;
                UDS_Serv_pSt->TxLen_u16 = 5;
                /* send the seed*/
                GENERATE_SEED_Frame(&UDS_Serv_pSt->TxBuff_pu8[2]);
                Serv_resptype_En = UDS_SERV_RESP_POS_E;
                Serv27_SA_handler_En = SA_RECEIVE_KEY_E;
                Number_of_Attempts_u8 = 0;                
            }
            break;
        }
		case REQUEST_SEED_PROGRAMMING:
        {
			
			if(TRUE == Req_delay_not_expire_b){

                UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
                UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
                UDS_Serv_pSt->TxBuff_pu8[2] = REQ_TIMEDELAY_NOTEX;
                UDS_Serv_pSt->TxLen_u16 = 3;
                Serv_resptype_En = UDS_SERV_RESP_NEG_E;
            }
            else if (security_Access_Gained_b[SECURITY_ACCESS_LEVEL_1])
            {
                UDS_Serv_pSt->TxBuff_pu8[1] = REQUEST_SEED_PROGRAMMING;
                GENERATENULLSeed(&UDS_Serv_pSt->TxBuff_pu8[2]);
                UDS_Serv_pSt->TxLen_u16 = 5;
                Serv_resptype_En = UDS_SERV_RESP_POS_E;
                Serv27_SA_handler_En = SA_ACCESS_OK_E;
            }
            else
            {
                UDS_Serv_pSt->TxBuff_pu8[1] = REQUEST_SEED_PROGRAMMING;
                UDS_Serv_pSt->TxLen_u16 = 5;
                GENERATE_SEED_Frame(&UDS_Serv_pSt->TxBuff_pu8[2]);
				Serv_resptype_En = UDS_SERV_RESP_POS_E;
				Serv27_SA_handler_En = SA_RECEIVE_KEY_E;
				Number_of_Attempts_u8 = 0;
			}
//			UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
//			UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
//			UDS_Serv_pSt->TxBuff_pu8[2] = SUBFUNC_NOSUPP_IN_ACTIVE_SESS;
//			UDS_Serv_pSt->TxLen_u16 = 3;
//			Serv_resptype_En = UDS_SERV_RESP_NEG_E;
			break;
		}
		case REQUEST_SEED_ENGINEERING:
		{
			if(TRUE == Req_delay_not_expire_b){ /* time delay expire or not*/
				UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = REQ_TIMEDELAY_NOTEX;
				UDS_Serv_pSt->TxLen_u16 = 3;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E;            
			}
			else if (security_Access_Gained_b[SECURITY_ACCESS_LEVEL_3]) /* to check security flag true or not */
			{
				UDS_Serv_pSt->TxBuff_pu8[1] = REQUEST_SEED_ENGINEERING;
				/*send the null seed*/
				GENERATENULLSeed(&UDS_Serv_pSt->TxBuff_pu8[2]);
				UDS_Serv_pSt->TxLen_u16 = 5;
				Serv_resptype_En = UDS_SERV_RESP_POS_E;
				Serv27_SA_handler_En = SA_ACCESS_OK_E;
			}
			else 
			{
				UDS_Serv_pSt->TxBuff_pu8[1] = REQUEST_SEED_ENGINEERING;
				UDS_Serv_pSt->TxLen_u16 = 5;
				/* send the seed*/
				GENERATE_SEED_Frame(&UDS_Serv_pSt->TxBuff_pu8[2]);
				Serv_resptype_En = UDS_SERV_RESP_POS_E;
				Serv27_SA_handler_En = SA_RECEIVE_KEY_E;
				Number_of_Attempts_u8 = 0;                
			}
			break;
		}
		case SEND_KEY_EXTENDED:
		{    
			if(TRUE == Req_delay_not_expire_b)
			{ /* check time delay is expired or not */   
				UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = REQ_TIMEDELAY_NOTEX;
				UDS_Serv_pSt->TxLen_u16 = 3;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E; 
				NoResponseFlag_b = FALSE;
			}
			/* else if(SA_ACCESS_OK_E == Serv27_SA_handler_En)
			{		
				UDS_Serv_pSt->TxBuff_pu8[1] = SEND_KEY_EXTENDED;
				UDS_Serv_pSt->TxLen_u16 = 1;
				Serv_resptype_En = SERV_RESP_POS_E;
				Number_of_Attempts_u8 = 0;
				Serv27_SA_handler_En = SA_ACCESS_OK_E;						
			}*/
			else if(SA_RECEIVE_KEY_E != Serv27_SA_handler_En) /* request to be in sequence or not */
			{
				UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = REQUEST_SEQUENCE_ERR;
				UDS_Serv_pSt->TxLen_u16 = 3;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E;
				NoResponseFlag_b = FALSE;
			}     
			
			else if(N0_OF_ATTEMPTS < Number_of_Attempts_u8)
			{
				/* send NRC response - attempt exceeded */
				Serv27_SA_handler_En = SA_NO_ACCESS_E;
				Number_of_Attempts_u8 = 0;
				UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = EXCEEDED_NUMBER_OF_ATTEMPTS;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E;
				NoResponseFlag_b = FALSE;
				UDS_Serv_pSt->TxLen_u16 = 3;
				//	Timer_delay_for_security_u32 = timer_ticks_1ms_u32;
				//Timer_delay_for_security_u32 = u32_DiagMSCnt; //todo harsh
				Req_delay_not_expire_b = TRUE;
			}
			
			else
			{   /* check whether key is match or not*/
				if(TRUE == Verify_Key(&UDS_Serv_pSt->RxBuff_pu8[2], Sa_type_u8))
				{
					UDS_Serv_pSt->TxBuff_pu8[1] = SEND_KEY_EXTENDED;
					Serv_resptype_En = UDS_SERV_RESP_POS_E;
					Serv27_SA_handler_En = SA_ACCESS_OK_E;
					Number_of_Attempts_u8 = 0;
					UDS_Serv_pSt->TxLen_u16 = 1;
					security_Access_Gained_b[SECURITY_ACCESS_LEVEL_2] = TRUE;
					security_Access_Gained_b[SECURITY_ACCESS_LEVEL_3] = FALSE;
				}
				else
				{   /*invalid key */
					UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
					UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
					UDS_Serv_pSt->TxBuff_pu8[2] = INVALID_KEY;
					Number_of_Attempts_u8++;
					UDS_Serv_pSt->TxLen_u16 = 3;
					Serv_resptype_En = UDS_SERV_RESP_NEG_E;
                   NoResponseFlag_b = FALSE;
				}
			}
			break;
		}
		case SEND_KEY_PROGRAMMING:
		{    

			if(TRUE == Req_delay_not_expire_b)
			{ 	UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = REQ_TIMEDELAY_NOTEX;
				UDS_Serv_pSt->TxLen_u16 = 3;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E;
			}
			else if(SA_ACCESS_OK_E == Serv27_SA_handler_En)
			{		
				UDS_Serv_pSt->TxBuff_pu8[1] = SEND_KEY_PROGRAMMING;
				UDS_Serv_pSt->TxLen_u16 = 1;
				Serv_resptype_En = UDS_SERV_RESP_POS_E;
				Number_of_Attempts_u8 = 0;
				Serv27_SA_handler_En = SA_ACCESS_OK_E;						
			}
			else if(SA_RECEIVE_KEY_E != Serv27_SA_handler_En)
			{
				UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = REQUEST_SEQUENCE_ERR;
				UDS_Serv_pSt->TxLen_u16 = 3;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E;
			}     
			else if(N0_OF_ATTEMPTS < Number_of_Attempts_u8)
			{
				Serv27_SA_handler_En = SA_NO_ACCESS_E;
				Number_of_Attempts_u8 = 0;
				UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = EXCEEDED_NUMBER_OF_ATTEMPTS;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E;
				UDS_Serv_pSt->TxLen_u16 = 3;
//				Timer_delay_for_security_u32 = u32_DiagMSCnt;
				Req_delay_not_expire_b = TRUE;
			}
			else
			{
//				if(TRUE == Verify_Key(&UDS_Serv_pSt->RxBuff_pu8[2], Sa_type_u8))
				if(FALSE == Verify_Key(&UDS_Serv_pSt->RxBuff_pu8[2], Sa_type_u8))
				{
					UDS_Serv_pSt->TxBuff_pu8[1] = SEND_KEY_PROGRAMMING;
					Serv_resptype_En = UDS_SERV_RESP_POS_E;
					Serv27_SA_handler_En = SA_ACCESS_OK_E;
					Number_of_Attempts_u8 = 0;
					UDS_Serv_pSt->TxLen_u16 = 1;
					security_Access_Gained_b[SECURITY_ACCESS_LEVEL_1]=true;
				}
				else
				{   UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
					UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
					UDS_Serv_pSt->TxBuff_pu8[2] = INVALID_KEY;
					Number_of_Attempts_u8++;
					UDS_Serv_pSt->TxLen_u16 = 3;
					Serv_resptype_En = UDS_SERV_RESP_NEG_E;
				
				}
			}
//			UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
//			UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
//			UDS_Serv_pSt->TxBuff_pu8[2] = SUBFUNC_NOSUPP_IN_ACTIVE_SESS;
//			UDS_Serv_pSt->TxLen_u16 = 3;
//			Serv_resptype_En = UDS_SERV_RESP_NEG_E;
			break;
		}
		case SEND_KEY_ENGINEERING:
		{
			if(TRUE == Req_delay_not_expire_b)
			{ /* check time delay is expired or not */   
				UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = REQ_TIMEDELAY_NOTEX;
				UDS_Serv_pSt->TxLen_u16 = 3;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E; 
			}
			/*else if(SA_ACCESS_OK_E == Serv27_SA_handler_En)
			{		
				UDS_Serv_pSt->TxBuff_pu8[1] = SEND_KEY_ENGINEERING;
				UDS_Serv_pSt->TxLen_u16 = 1;
				Serv_resptype_En = SERV_RESP_POS_E;
				Number_of_Attempts_u8 = 0;
				Serv27_SA_handler_En = SA_ACCESS_OK_E;						
			}*/
			else if(SA_RECEIVE_KEY_E != Serv27_SA_handler_En) /* request to be in sequence or not */
			{
				UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = REQUEST_SEQUENCE_ERR;
				UDS_Serv_pSt->TxLen_u16 = 3;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E;
			}     
			else if(N0_OF_ATTEMPTS < Number_of_Attempts_u8)
			{
				/* send NRC response - attempt exceeded */
				Serv27_SA_handler_En = SA_NO_ACCESS_E;
				Number_of_Attempts_u8 = 0;
				UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
				UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
				UDS_Serv_pSt->TxBuff_pu8[2] = EXCEEDED_NUMBER_OF_ATTEMPTS;
				Serv_resptype_En = UDS_SERV_RESP_NEG_E;
				UDS_Serv_pSt->TxLen_u16 = 3;
				//Timer_delay_for_security_u32 = timer_ticks_1ms_u32;
			//todo harsh	Timer_delay_for_security_u32 = u32_DiagMSCnt;
				Req_delay_not_expire_b = TRUE;
			}
			else
			{   /* check whether key is match or not*/
				if(TRUE == Verify_Key(&UDS_Serv_pSt->RxBuff_pu8[2], Sa_type_u8))
				{
					UDS_Serv_pSt->TxBuff_pu8[1] = SEND_KEY_ENGINEERING;
					Serv_resptype_En = UDS_SERV_RESP_POS_E;
					Serv27_SA_handler_En = SA_ACCESS_OK_E;
					Number_of_Attempts_u8 = 0;
					UDS_Serv_pSt->TxLen_u16 = 1;
					security_Access_Gained_b[SECURITY_ACCESS_LEVEL_2] = FALSE;
					security_Access_Gained_b[SECURITY_ACCESS_LEVEL_3] = TRUE;
				}
				else
				{   /*invalid key */
					UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
					UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
					UDS_Serv_pSt->TxBuff_pu8[2] = INVALID_KEY;
					Number_of_Attempts_u8++;
					UDS_Serv_pSt->TxLen_u16 = 3;
					Serv_resptype_En = UDS_SERV_RESP_NEG_E;
				}
			}
			break;
		}
		default:
		{ /* sub function not supported*/
			UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
			UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
			UDS_Serv_pSt->TxBuff_pu8[2] = SUB_FUNC_NOT_SUPPORTED;
			UDS_Serv_pSt->TxLen_u16 = 3;
			Serv_resptype_En = UDS_SERV_RESP_NEG_E; 
			NoResponseFlag_b = FALSE;
        }
      }
	}
	else
	{
		UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
		UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
		UDS_Serv_pSt->TxBuff_pu8[2] = SUBFUNC_NOSUPP_IN_ACTIVE_SESS;
		UDS_Serv_pSt->TxLen_u16 = 3;
		Serv_resptype_En = UDS_SERV_RESP_NEG_E;
	}
    
    if(NoResponseFlag_b == TRUE)
    {
        Serv_resptype_En = UDS_SERV_RESP_NORESP_E;
    }
    }
    
    else
    {       /* invalid message length */
            UDS_Serv_pSt->TxBuff_pu8[0] = 0x7F;
            UDS_Serv_pSt->TxBuff_pu8[1] = SID_SA;
            UDS_Serv_pSt->TxBuff_pu8[2] = INVALID_MESSAGE_LENGTH;
            UDS_Serv_pSt->TxLen_u16 = 3;
            Serv_resptype_En = UDS_SERV_RESP_NEG_E; 
        
    }
    return Serv_resptype_En;
}


/*
*  FUNCTION NAME : uint32_CalculateKEY
*  FILENAME      : uds_serv27.c
*  @brief        : function returns the calculated KEY as per the random SEED and secret KEY received.
*  @param        : u32_RandomSEED, u32_secretSEED.
*  @return       : uint32_t.                     
*/
uint32_t uint32_CalculateKEY(uint32_t u32_RandomSEED, uint32_t u32_secretSEED)
{
    uint32_KEY_Data = uint32_encrypt_data(u32_RandomSEED,u32_secretSEED);
	return uint32_KEY_Data;//uint32_encrypt_data(u32_RandomSEED,u32_secretSEED);
}

/*
 *  FUNCTION NAME : Check_SecurityClearance
 *  FILENAME      : uds_serv27.c
 *  @brief        : This function is cleck Security Clearance     
 *  @param        : nil
 *  @return       : bool  
 */
bool Check_SecurityClearance(void)
{
    bool SecurityCleared_b = FALSE;
	
	if((PROGRAMMING_SESSION_SUB_ID_E == current_active_session_u8) && (TRUE == security_Access_Gained_b[SECURITY_ACCESS_LEVEL_1]))
	{
		SecurityCleared_b = TRUE;
	}
	else if((EXTENDED_DIAG_SESSION_SUB_ID_E == current_active_session_u8) && ((TRUE == security_Access_Gained_b[SECURITY_ACCESS_LEVEL_2]) || (TRUE == security_Access_Gained_b[SECURITY_ACCESS_LEVEL_3])))
	{
		SecurityCleared_b = TRUE;
	}
	else if((SUPPLIER_EOL_SESSION_SUB_ID_E == current_active_session_u8))// && (TRUE == Check_EOL_NVM_Security()))
	{
		SecurityCleared_b = TRUE;
	}
	/*else if(DEFAULT_SESSION_SUB_ID_E == current_active_session_u8)
	{
		SecurityCleared_b = TRUE;
	}*/
	else
	{
		SecurityCleared_b = FALSE;
	}
	SecurityCleared_b = TRUE;//TODO: sandeep
	return SecurityCleared_b;
}

/**
*  FUNCTION NAME : UDS_serv27_timeout
*  FILENAME      : uds_serv27.c
*  @brief        : function resets the relevant variables/parameters when  timeout.
*  @param        : none.
*  @return       : none.                     
*/
void UDS_serv27_timeout(void)
{
    if(TRUE == Req_delay_not_expire_b){ /* check whether this flag true or not*/
       // if(TIME_DELAY <= (u32_DiagMSCnt - Timer_delay_for_security_u32 ))
        { 
            Serv27_SA_handler_En = SA_NO_ACCESS_E;
            security_Access_Gained_b[SECURITY_ACCESS_LEVEL_1] = FALSE;
            security_Access_Gained_b[SECURITY_ACCESS_LEVEL_2] = FALSE;
            security_Access_Gained_b[SECURITY_ACCESS_LEVEL_3] = FALSE;
            Req_delay_not_expire_b = FALSE;
        }
    }    
    
}

void UDS_serv27_reset(void)
{
    Serv27_SA_handler_En = SA_NO_ACCESS_E;
    security_Access_Gained_b[SECURITY_ACCESS_LEVEL_1] = FALSE;
    security_Access_Gained_b[SECURITY_ACCESS_LEVEL_2] = FALSE;
    security_Access_Gained_b[SECURITY_ACCESS_LEVEL_3] = FALSE;
}

uint32_t uint32_encrypt_data(uint32_t rxdata, uint32_t secret_key)
{
	uint8_t databyte[5];
	uint8_t encdatabyte[5];
	uint32_t return_data = 0L;
	int i;
	for (i=0;i<4;i++)
	{
		databyte[i]= (rxdata >> (8 * (3-i))) & 0xFF;
		encdatabyte[i] = (databyte[i]);
		return_data += encdatabyte[i] << (8 * (3-i));
	}
	return return_data ^ secret_key;
}



/*****************************************************************************/
