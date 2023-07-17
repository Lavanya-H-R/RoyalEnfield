/******************************************************************************
 *    FILENAME    : uds_conf.c
 *    DESCRIPTION : This file contains configuration data for UDS services.
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************/
// Sloki
/*
 **************************************************************************************************
 *    Includes
 **************************************************************************************************
 */

#include "uds_conf.h"
//#include "uds_stimulus.h"
//#include "iso14229_serv10.h"
//#include "iso14229_serv22.h"
//#include "iso14229_serv2E.h"
//#include "iso14229_serv3E.h"
//#include "iso14229_serv3D.h"
//#include "iso14229_serv23.h"
//#include "iso14229_serv19.h"
//#include "iso14229_serv14.h"
//#include "iso14229_serv27.h"
//#include "iso14229_serv2F.h"
//#include "iso14229_serv28.h"
//#include "iso14229_serv85.h"
//#include "uds_DID.h"
//#include "iso14229_serv11.h"
//#include"iso14229_serv87.h"
//#include "iso14229_serv2C.h"
//#include "iso14229_serv2A.h"
//#include "iso14229_serv31.h"
#include "diag_appl_test.h"
#include "diag_sys_conf.h"
 


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
/* All below Global variables are used by 0x22 and 0x2E Services*/   

/***************************************/
/****Sample IO_CONTROL REAL VALUE*******/
/***************************************/


uint8_t Rv_Sample_DID_1_Data_au8    			    [1];
uint8_t Rv_Sample_DID_2_Data_au8    			    [1];
uint8_t Rv_Sample_DID_3_Data_au8    			    [1];
uint8_t Rv_Sample_DID_4_Data_au8    			    [1];
uint8_t Rv_Sample_DID_5_Data_au8    			    [1];
uint8_t Rv_Sample_DID_6_Data_au8    			    [1];
uint8_t Rv_Sample_DID_7_Data_au8    			    [1];
uint8_t Rv_Sample_DID_8_Data_au8    			    [1];
uint8_t Rv_Sample_DID_9_Data_au8    			    [1];
uint8_t Rv_Sample_DID_10_Data_au8    			    [1];

uint8_t Rv_DTC_Mask_Iden_au8              	    [4 ];


//uint8_t *Var_Ptr_pu8; /*Global Pointer*/

ISO14229_DidList_En_t Current_DID_Index_u16;

/**
Constant service distributor table for OBD services. Duplicate the table for ISO 14229 or other diagnostic protocol
*/

const ServiceDistUDS_St_t UDSServDist_apt[ServDist_UDS_NumEntries_u32] =
{
    /*  SID     Initialization function   service implementation   */
//    {SID_SESSIONCONTROL,       	NULL,     &iso14229_serv10, 	(uint8_t )(UDS_SESS_EXTENDED | UDS_SESS_PROG | UDS_SESS_DEFAULT | UDS_SESS_SUPPL_EOL)},
//    {SID_SA,                   	NULL,     &iso14229_serv27, 	(uint8_t )(UDS_SESS_EXTENDED | UDS_SESS_PROG )},
//    {SID_ECURESET,          	NULL,     &iso14229_serv11, 	(uint8_t )(UDS_SESS_EXTENDED | UDS_SESS_PROG )}
};



/***************Structure definition********************************/
//ISO14229_DID_config_St_t DID_Config_aSt[DID_TOTAL_E] =
//{
//	/*Enum*/                 /*DID_MACRo*/  	/*Function*/         /*size*/   /*category*/       	/*DID_Session*/            		/*Global Array*/        /*For2F-shortTermAdjustment*/		/*Current real values*/
//	{SAMPLE_DID_1_E,        SAMPLE_DID_1,    	DID_Comm_Fn,   		1u,      NUMERIC_E,      	{{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_1_Data_au8,	         NULL   	,                       Rv_Sample_DID_1_Data_au8,		    UN_INIT_E,	FALSE,	0},
//    {SAMPLE_DID_2_E,        SAMPLE_DID_2,    	DID_Comm_Fn,   		1u,      ASCII_E,      	{{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_2_Data_au8,	         NULL   	,                       Rv_Sample_DID_2_Data_au8,		    UN_INIT_E,	FALSE,	0},
//	{SAMPLE_DID_3_E,       	SAMPLE_DID_3,    	DID_Comm_Fn,   		1u,      PACKETED_E,      	{{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_3_Data_au8,	         NULL   	,                       Rv_Sample_DID_3_Data_au8,		    UN_INIT_E,	FALSE,	0},
//	{SAMPLE_DID_4_E,       	SAMPLE_DID_4,    	DID_Comm_Fn,   		1u,      BIT_MAPPED_E,      	{{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_4_Data_au8,	         NULL   	,                       Rv_Sample_DID_4_Data_au8,		    UN_INIT_E,	FALSE,	0},
//	{SAMPLE_DID_5_E,       	SAMPLE_DID_5,    	DID_Comm_Fn,   		1u,      INT_E,      	{{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_5_Data_au8,	         NULL   	,                       Rv_Sample_DID_5_Data_au8,		    UN_INIT_E,	FALSE,	0},
//	{SAMPLE_DID_6_E,       	SAMPLE_DID_6,    	DID_Comm_Fn,   		1u,      STATE_ENCODED_E,      	{{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_6_Data_au8,	         NULL   	,                       Rv_Sample_DID_6_Data_au8,		    UN_INIT_E,	FALSE,	0},
//	{SAMPLE_DID_7_E,       	SAMPLE_DID_7,    	DID_Comm_Fn,   		1u,      PACKETED_E,      	{{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_7_Data_au8,	         NULL   	,                       Rv_Sample_DID_7_Data_au8,		    UN_INIT_E,	FALSE,	0},
//	{SAMPLE_DID_8_E,       	SAMPLE_DID_8,    	DID_Comm_Fn,   		1u,      ASCII_E,      	{{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_8_Data_au8,	         NULL   	,                       Rv_Sample_DID_8_Data_au8,		    UN_INIT_E,	FALSE,	0},
//	{SAMPLE_DID_9_E,       	SAMPLE_DID_9,    	DID_Comm_Fn,   		1u,      ASCII_E,      	{{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_9_Data_au8,	         NULL   	,                       Rv_Sample_DID_9_Data_au8,		    UN_INIT_E,	FALSE,	0},
//	{SAMPLE_DID_10_E,       SAMPLE_DID_10,    	DID_Comm_Fn,   		1u,      ASCII_E,      {{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  Sample_DID_10_Data_au8,	 NULL          ,                        Rv_Sample_DID_10_Data_au8,		    UN_INIT_E,	FALSE,	0},

//	{DTC_MASKING_IDENTIFIER_E,       	DTC_MASKING_IDENTIFIER,            	DID_DTCMask_Fn,		4u,     PACKETED_E,      	{{0x00}, {0x00}, {0x02}, {0x02}, {0x00}},  DTC_Mask_Iden_au8,              		NULL											,	Rv_DTC_Mask_Iden_au8,              	    UN_INIT_E,	FALSE,	0},

//#if (TRUE == DIAG_TEST_DEMO_CODE)
//    {TEST_FAULT_DID_1_E,       TEST_FAULT_DID_1,         DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x03}, {0x03}, {0x03}, {0x03}, {0x03}},  test_fault_input1_au8,          NULL           ,                        Rv_test_fault_input1_au8,           UN_INIT_E,	FALSE,	0},
//    {TEST_FAULT_DID_2_E,       TEST_FAULT_DID_2,         DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x01}, {0x03}, {0x01}, {0x03}, {0x00}},  test_fault_input2_au8,          NULL           ,                        Rv_test_fault_input2_au8,           UN_INIT_E,	FALSE,	0},
//    {TEST_FAULT_DID_3_E,       TEST_FAULT_DID_3,         DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x01}, {0x03}, {0x01}, {0x03}, {0x00}},  test_fault_input3_au8,          NULL           ,                        Rv_test_fault_input3_au8,           UN_INIT_E,	FALSE,	0},
//    {TEST_FAULT_DID_4_E,       TEST_FAULT_DID_4,         DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x01}, {0x03}, {0x01}, {0x03}, {0x00}},  test_fault_input4_au8,          NULL           ,                        Rv_test_fault_input4_au8,           UN_INIT_E,	FALSE,	0},
//    {TEST_FAULT_DID_5_E,       TEST_FAULT_DID_5,         DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x01}, {0x03}, {0x01}, {0x03}, {0x00}},  test_fault_input5_au8,          NULL           ,                        Rv_test_fault_input5_au8,           UN_INIT_E,	FALSE,	0},
//    {TEST_FAULT_DID_6_E,       TEST_FAULT_DID_6,         DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x01}, {0x03}, {0x01}, {0x03}, {0x00}},  test_fault_input6_au8,          NULL           ,                        Rv_test_fault_input6_au8,           UN_INIT_E,	FALSE,	0},
//    {TEST_FAULT_DID_7_E,       TEST_FAULT_DID_7,         DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x01}, {0x03}, {0x01}, {0x03}, {0x00}},  test_fault_input7_au8,          NULL           ,                        Rv_test_fault_input7_au8,           UN_INIT_E,	FALSE,	0},
//    {TEST_FAULT_DID_8_E,       TEST_FAULT_DID_8,         DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x01}, {0x03}, {0x01}, {0x03}, {0x00}},  test_fault_input8_au8,          NULL           ,                        Rv_test_fault_input8_au8,           UN_INIT_E,	FALSE,	0},
//    {TEST_FAULT_DID_9_E,       TEST_FAULT_DID_9,         DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x01}, {0x03}, {0x01}, {0x03}, {0x00}},  test_fault_input9_au8,          NULL           ,                        Rv_test_fault_input9_au8,           UN_INIT_E,	FALSE,	0},
//    {TEST_FAULT_DID_10_E,      TEST_FAULT_DID_10,        DID_Comm_Fn,           1u,     NUMERIC_E,              {{0x01}, {0x03}, {0x01}, {0x03}, {0x00}},  test_fault_input10_au8,         NULL           ,                        Rv_test_fault_input10_au8,          UN_INIT_E,	FALSE,	0},


//#endif
        
//};
       /* This Array of Structure Variable contains DID_name,DID_Number, FUnction Pointer for Each DID, DID_DATA_size and ACCESS Type*/
       /* This Structure Array DID_Config_aSt[DID_TOTAL_E] is used by both 0x22(RDBDID) and 0x2E(WDBDID) Services*/
       /* This Structure Array Size DID_Config_aSt[DID_TOTAL_E] can Vary while adding extra DIDs*/ 



    /* @summary: this 2D array for flash memory blocks */
    const uint32_t MemoryArray_config[MEM_ARRAY_ROW_SIZE][MEM_ARRAY_COL_SIZE] =
    {
        /*start_addr,           end_addr */
        {0x00000200,            0x000003FF},        /* Memory Block 1 */
        {0x00000400,            0x000005FF},        /* Memory Block 2 */
        {0x00000600,            0x000007FF},        /* Memory Block 3 */
        {0x00000800,            0x000009FF},        /* Memory Block 4 */
        {0x00000A00,            0x00000FFF}         /* Memory Block 5 */
    };      /* this is used by 0x23 and 0x3D*/


    /*******************************************************************************/
    /*****************Dynamically Defines By Data Identifier(0x2C)******************/
    /*******************************************************************************/



/* Structure Array contains Dynamic DID's Information */ 
DDID_St_t DDID_ast[TOTAL_DDID] = 
{
  {NULL, NULL, {NULL}, {NULL}}
};


//const SubFunctionSer19_St_t Service19_SubFunctionsaSt[SERV19_NUMOF_SUB_FUNCTIONS] = {
//    {    SERV19_NUMBER_OF_DTC_BY_STATUS_MASK_E                              ,      &GetNumOfFaultsByMask               ,   THREE    },
//    {    SERV19_DTC_BY_STATUS_MASK_E                                        ,      &GetDTCsByStatusMask                ,   THREE    },
//    {    SERV19_DTC_SNAPSHOT_IDENTIFICATION_E                               ,      &GetDTCSnapshotIdentification       ,   TWO      },
//    {    SERV19_DTC_SNAPSHOT_RECORD_BY_DTC_NUMBER_E                         ,      &GetDTCSnapshotRecordByDTCNumber    ,   SIX      },
//    {    SERV19_NUMBER_OF_DTC_BY_SEVERITY_MASK_RECORD_E                     ,      &GetNumberOfDTCBySeverityMaskRecord ,   FOUR     },
//    {    SERV19_DTC_BY_SEVERITY_MASK_RECORD_E                               ,      &GetDTCBySeverityMaskRecord         ,   FOUR     },
//    {    SERV19_SEVERITY_INFORMATION_OF_DTC_E                               ,      &SeverityInformationOfDTC           ,   FIVE     },
//    {    SERV19_SUPPORTED_DTC_E                                             ,      &SupportedDTCs                      ,   TWO      },
//    {    SERV19_FIRST_TEST_FAILED_E                                         ,      &GetFirstTestFailedDTC              ,   TWO      },
//    {    SERV19_FIRST_CONFIRMED_E                                           ,      &GetFirstConfirmedDTC               ,   TWO      },
//    {    SERV19_DTC_FAULT_DETECTION_COUNTER_E                               ,      &GetDTCFaultDetectionCounter        ,   TWO      },
//    {    SERV19_DTC_WITH_PERMANENT_STATUS_E                                 ,      &GetDTCWithPermanentStatus          ,   TWO      },
//    {    SERV19_DTC_EXTENDED_DATA_RECORD_BY_DTC_NUMBER_E                    ,      GetExtendedDataRecordByDTCNumber    ,   SIX    	}
//};

//const ServID_Ser31_St_t Service31_ServIDaSt[TOTAL_ROUTINES_E] = {
//    {    SERV31_SERVICE_INFO_RESET,      	&ServiceInfoReset_Routine		},
//    {    SERV31_DISP_ALL_WARNING_TXT,      	&DispAllWarning_TXT_Routine     },
//    {    SERV31_SET_GAUGE_MAX,      		&SetGaugeMAX_Routine            },
//    {    SERV31_SET_GAUGE_MIN,      		&SetGaugeMIN_Routine            },
//    {    SERV31_SET_WARN_LAMP_OFF,      	&SetWarningLampOFF_Routine      },
//    {    SERV31_SET_WARN_LAMP_ON,      		&SetWarningLampON_Routine       },
//    {    SERV31_AUTOLEARNING,      			&AutomaticLearning_Routine      },
//    {    SERV31_ODO_RESET,      			&OdometerReset_Routine          }
//};

/*0x14 - Clear DTC Information*/
const uint32_t GroupOfDTCIDs_au32[NUMBER_OF_GROUP_DTC_IDs] = 
{       
	0xFFFFFF
};


//void Update_DiagTBL_2_Conf_aSt(void)
//{
//	uint32_t ui32IdCounter = 0;
//	uint32_t ui32DataCounter = 0;
//	uint32_t ui32RamCounter = 0;
//
//    for(ui32IdCounter = 0; ui32IdCounter < DID_TOTAL_E; ui32IdCounter++)
//    {
//        for(ui32DataCounter = 0; ui32DataCounter < DID_Config_aSt[ui32IdCounter].DID_Val_Size  ; ui32DataCounter++)
//        {
//			DID_Config_aSt[ui32IdCounter].Var_ptr_pu8[ui32DataCounter] = u1_Diag_param_tbl[ui32RamCounter++];
//        }
//    }
//}

//void Update_Conf_aSt_2_DiagTBL(void)
//{
//	uint32_t ui32IdCounter = 0;
//	uint32_t ui32DataCounter = 0;
//	uint32_t ui32RamCounter = 0;
//
//    for(ui32IdCounter = 0; ui32IdCounter < DID_TOTAL_E; ui32IdCounter++)
//    {
//        for(ui32DataCounter = 0; ui32DataCounter < DID_Config_aSt[ui32IdCounter].DID_Val_Size  ; ui32DataCounter++)
//        {
//			u1_Diag_param_tbl[ui32RamCounter++] = DID_Config_aSt[ui32IdCounter].Var_ptr_pu8[ui32DataCounter] ;
//        }
//    }
//	vd_WriteDiag_BkupRAM();
//}




const ST_DID_MASK DID_MASK_TBL[DID_TOTAL_E] = {
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},				    /* DTC_MASKING_IDENTIFIER_E          	*/
#if (TRUE == DIAG_TEST_DEMO_CODE)
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
		{0, 0},
#endif
//	{0, 0},				    /* BOOT_SOFT_IDEN_E                		*/
//	{0, 0},				    /* BOOT_FP_DATA_E                    	*/
//	{0, 0},				    /* APP_SOFT_FP_DATA_E                	*/
//	{0, 0},				    /* APP_SW_DATA_DATE_E					*/
//	{0, 0},				    /* APP_SW_DATA_TST_SER_NO_E				*/
//	{0, 0},				    /* APP_SW_DATA_REPAIR_SHOP_E			*/
//	{0, 0},				    /* APP_SW_DATA_REPROG_SEQ_E				*/
//	{0, 0},				    /* CONFIGURATION_FINGERPRINT_DATA_E  	*/
//	{0, 0},				    /* CONFIG_DATA_DATE_E					*/
//	{0, 0},				    /* CONFIG_DATA_TST_SER_NO_E				*/
//	{0, 0},				    /* CONFIG_DATA_REPAIR_SHOP_E			*/
//	{0, 0},				    /* CONFIG_DATA_REPROG_SEQ_E				*/
//	{0, 0},				    /* ECU_SERIAL_NUMBER_E               	*/
//	{0, 0},				    /* REPROGM_SVN_E                    	*/
//	{0, 0},				    /* ACTIVE_DIAGNOSTIC_SESS_E     		*/
//	{0, 0},				    /* ECU_MFG_DATE_E                   	*/
//	{0, 0},				    /* APP_SOFT_STATUS_E            		*/
//	{0, 0},				    /* CALIBRATION_SOFT_STATUS_E    		*/
//	{0, 0},				    /* CONFIG_SOFT_STATUS_E        			*/
//	{0, 0},				    /* ACTIVE_SOFTWARE_COMPONENT_E			*/
//	{0, 0},				    /* ECU_HW_NUM_E                     	*/
//	{0, 0},				    /* ECU_SW_NUM_E                     	*/
//	{0, 0},				    /* SYSTEM_NAME_E					    */
//	{0, 0},				    /* PROGRAM_SECRET_KEY_E             	*/
//	{0, 0},				    /* EXTENDED_SECRET_KEY_E            	*/
//	{0, 0},				    /* END_OF_LINE_SECRET_KEY_E				*/
//	{0, 0},				    /* SERV_RECORD1_E                    	*/
//	{0, 0},				    /* SERV_RECORD2_E                    	*/
//	{0, 0},				    /* SERV_RECORD3_E                    	*/
//	{0, 0},				    /* SERV_RECORD4_E                    	*/
//	{0, 0},				    /* SERV_RECORD5_E                    	*/
//	{0, 0},				    /* PBL_RESERVED_E                    	*/
//	{0, 0},				    /* APP_SOFT_IDEN_E                   	*/
//	{0, 0},				    /* SUPPLIER_PART_NUM_E             		*/
//	{0, 0},				    /* ECU_PBL_SW_NUM_E                 	*/
//	{0, 0},				    /* ECU_APP_SW_NUM_E                 	*/
//	{0, 0},				    /* ECU_CONFIG_SW_NUMBER_E				*/
//	{0, 0},				    /* ECU_ASSEMBLY_NUMBER_E				*/
//	{0, 0},				    /* SBL_VER_NUM_E                     	*/
//	{0, 0},				    /* ECU_SPECIFIC_E                    	*/
//	{5, 0x1B},				/* ENGINE_WARN_INDICATOR_E           	*/
//	{1, 0x02},				/* SEAT_BELT_WARN_CHIME_E            	*/
//	{4, 0x03},				/* SEAT_BELT_WARN_INDICATOR_E        	*/
//	{0, 0},				    /* GEAR_MODE_INDICATOR_E             	*/
//	{0, 0},				    /* METER_DISPLAY_E                   	*/
//	{0, 0},				    /* AFE_IFE_DISPLAY_E                 	*/
//	{0, 0},				    /* REV_GEAR_AUDIO_DISPLAY_E          	*/
//	{0, 0},				    /* SERV_INTERVAL_DISTANCE_E          	*/
//	{0, 0},				    /* DISTANCE_SINCE_LAST_SERV_E        	*/
//	{0, 0},				    /* PARK_BRAKE_WARN_VHCLE_SPEED_E     	*/
//	{0, 0},				    /* AMT_WARN_INDICATOR_E              	*/
//	{0, 0},				    /* WIF_WARN_INDICATOR_E              	*/
//	{4, 0x40},				/* FUEL_LEVEL_E                      	*/
//	{5, 0x07},				/* CLK_DISPLAY_SETTING_E             	*/
//	{0, 0},				    /* SET_SWITCHES_E                    	*/
//	{6, 0x10},				/* GLOW_PLUG_WARNING_E               	*/
//	{5, 0x1F},				/* MIN_DISTANCE_INST_FUEL_E          	*/
//	{0, 0},				    /* AVG_FUEL_TIME_E                   	*/
//	{3, 0x07},				/* OAT_CONDITION_TIME_E              	*/
//	{6, 0x1A},				/* TIRE_SIZE_E                       	*/
//	{0, 0},				    /* FUEL_TANK_SIZE_E                  	*/
//	{0, 0},				    /* IC_REPLACEMENT_E                  	*/
//	{6, 0x01},				/* SEASON_ODOMETER_E                 	*/
//	{0, 0},				    /* SPEED_LIMIT_E                     	*/
//	{0, 0},				    /* ABS_FAC_E                         	*/
//	{0, 0},				    /* ILLUMINATION_FINE_TUNN_E				*/
//	{0, 0},				    /* CNTRL_MODULE_CONFIG_TYPE_E   		*/
//	{0, 0},				    /* COMMUNICATION_STATUS_E          		*/
//	{0, 0},				    /* VEHICLE_MODE_E                 		*/
//	{0, 0},				    /* ILL_DIMMING_LEV_OUTPUT_E				*/
//	{0, 0},				    /* GLOBAL_RT_CLEAR_DTC_E        		*/
//	{0, 0},				    /* DTC_SET_DUE_TO_DIAG_ROUTINE_E		*/
//	{0, 0},				    /* GLOBAL_REAL_TIME_E           		*/
//	{0, 0},				    /* TOTAL_DISTANCE_TRAVELLED_E   		*/
//	{0, 0},				    /* ECU_SUPPLY_VOLTAGE_E         		*/
//	{0, 0},				    /* VEHICLE_INTERIOR_TEMP_E      		*/
//	{0, 0},				    /* ABIENT_AIR_TEMP_E            		*/
//	{0, 0},				    /* VEHICLE_POWER_MODE_E            		*/
//	{0, 0},				    /* ENGINE_SPEED_E               		*/
//	{0, 0},				    /* VEHICLE_SPEED_E              		*/
//	{0, 0},				    /* ENGINE_COOLANT_TEMP_E        		*/
//	{0, 0},				    /* THROTTLE_POSITION_E                	*/
//	{0, 0},				    /* VIN_M_E                          	*/
//	{0, 0},				    /* AFE_BIASING_E					    */
//	{0, 0},				    /* DIAG_GATEWAY_STATE_E              	*/
//	{0, 0},				    /* NW_TOPOLOGY_CONFIG_E              	*/
//	{0, 0},				    /* PARK_LAMP_IN_E                    	*/
//	{0, 0},				    /* IGN_IN_E                          	*/
//	{0, 0x50},				/* TURN_WARN_INDICATOR_E             	*/
//	{0, 0x04},				/* HAZARD_WARN_INDICATOR_E           	*/
//	{0, 0x50},				/* ABS_WARN_INDICATOR_E              	*/
//	{0, 0x40},				/* EPAS_PSC_WARN_INDICATOR_E         	*/
//	{0, 0},				    /* HIGH_COOLANT_TEMP_WARN_E          	*/
//	{0, 0x30},			    /* BATTERY_CHARGE_WARN_INDICATOR_E   	*/
//	{0, 0x10},				/* BRAKE_FLUIDE_WARN_INDICATOR_E     	*/
//	{0, 0x10},				/* PARK_BRAKE_WARN_INDICATOR_E       	*/
//	{0, 0x10},				/* KEY_IN_OUT_E                      	*/
//	{0, 0x10},				/* SPEED_LIMIT_WARN_INDICATOR_E      	*/
//	{0, 0xA0},				/* GLOW_PLUG_WARN_INDICATOR_E        	*/
//	{0, 0x10},				/* TX_FAULT_INDICATOR_E              	*/
//	{0, 0x40},				/* DRL_INDICATOR_E                   	*/
//	{0, 0},				    /* WELCOME_STRATEGY_E                	*/
//	{0, 0},				    /* OAT_CONFIG_E                      	*/
//	{0, 0},				    /* TCU_BUZZER_REQ_E                  	*/
//	{0, 0},				    /* DEBUG_FRAME_E					    */
//	{0, 0},				    /* VEHICLE_MFG_ECU_SOFT_NUM_E       	*/
//	{0, 0},				    /* VIN_1_E                          	*/
//	{0, 0},				    /* DIAG_VERSION_E                   	*/
//	{0, 0},				    /* VCN_E                            	*/
//	{0, 0},				    /* ECU_PARAM_SW_NUM_E            		*/
//	{0, 0},				    /* CONFIG_VERSION_E					    */
//	{0, 0},				    /* READ_MASK_DTCs_E                  	*/
//	{0, 0},				    /* POWER_TRAIN_TYPE_E					*/
//	{0, 0},				    /* DRIVER_SBR_TONE_COUNT_E				*/
//	{0, 0},				    /* ECU_INSTALLATION_DATE_E				*/
//	{0, 0},				    /* ECO_SPORT_CITY_WARN_E              	*/
//	{0, 0},				    /* EOL_SESSION_E					    */
//	{0, 0},				    /* ECU_SBL_SW_NUM_E					    */
//	{0, 0},				    /* SYSTEM_SUPPLIER_E				    */
//	{0, 0},				    /* ELECTRICAL_POWER_E				    */
//	{0, 0},				    /* ECU_STATUS_SIG_E					    */
//	{0, 0},				    /* VEH_MANF_ECU_HW_NUM				    */
//	{0, 0},				    /* FRONTFOG_WARN_INDI				    */
};


/******************************************************************************
 End of File
 ******************************************************************************/
