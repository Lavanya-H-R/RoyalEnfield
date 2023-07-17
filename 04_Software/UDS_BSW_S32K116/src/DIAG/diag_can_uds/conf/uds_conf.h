/******************************************************************************
 *    FILENAME    : uds_conf.h
 *    DESCRIPTION : This file contains configuration data for UDS services.
 ******************************************************************************
 * Revision history
 *
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/

#ifndef _UDS_CONF_H_
#define _UDS_CONF_H_
/*
 **************************************************************************************************
 *    Includes
 **************************************************************************************************
 */

//#include <stdint.h>
#include "str_util.h"

//#include "uds_serv19.h"
#include "uds_session.h"
#include "diag_appl_test.h"
#include "diag_typedefs.h"
#include "diag_sys_conf.h"
#if(TRUE == DIAG_CONF_CANTP_SUPPORTED)
	#include "i15765.h"
#endif

 /*
  **************************************************************************************************
  *    Defines
  **************************************************************************************************
  */
  // Index for SID starting place in the received data buffer
//#define SID_INDEX  0
// Index for PID starting place in the received data buffer
//#define PID_INDEX  SID_INDEX+1
//
//#define RESPCODE_INDEX 0

/* Session modes */

#define UDS_SESS_DEFAULT	        0x01u
#define UDS_SESS_PROG		        0x02u
#define UDS_SESS_EXTENDED	        0x04u
#define UDS_SESS_ENGG		        0x08u	//(optional)
#define UDS_SESS_SUPPL_EOL	        0x10u   //(optional)


/*UDS SID LIST*/
#define SID_LINK_CONTROL		    	0x87
#define SID_TESTERPRESENT	        	0x3E
#define SID_SESSIONCONTROL	        	0x10
#define SID_RDBDID			        	0x22
#define SID_WDBDID			        	0x2E
#define SID_IOCBDID		            	0x2F
#define SID_SA				        	0x27
#define SID_RMBA			        	0x23
#define SID_WMBA		            	0x3D
#define SID_CDTC                      	0x14
#define SID_RDTC                      	0x19
#define SID_COMMUNICATIONCONTROL      	0x28
#define SID_ROUTINECONTROL      	    0x31
#define SID_CONTROLDTC      		    0x85
#define SID_ECURESET                   	0x11
#define SID_DDID                      	0x2C
#define SID_PDID                        0x2A


/*UDS NRC LIST*/
#define SERVICE_NOT_SUPPORTED           0x11
#define SUB_FUNC_NOT_SUPPORTED          0x12
#define INVALID_MESSAGE_LENGTH          0x13
#define RESP_LEN_EXCEEDED               0x14
#define CONDITION_NOT_CORRECT           0x22
#define REQUEST_SEQUENCE_ERR            0x24
#define REQUEST_OUT_OF_RANGE            0x31
#define SECURITY_ACCESS_DENIED          0x33
#define INVALID_KEY                     0x35
#define EXCEEDED_NUMBER_OF_ATTEMPTS     0x36    
#define REQ_TIMEDELAY_NOTEX             0x37
#define TRANSFER_DATA_SUSPENDED         0x71
#define GEN_PROG_FAILURE                0x72  
#define WRONG_BLOCK_SEQUENCE_CNTR       0x73
#define ERROR_REQ_OK_RESP_PENDING       0x78
#define SUBFUNC_NOSUPP_IN_ACTIVE_SESS   0x7E
#define SERVNOSUPP_IN_ACTIVE_SESS       0x7F
#define VOLTAGE_TOO_HIGH                0x92
#define VOLTAGE_TOO_LOW                 0x93

#define NEGATIVE_RESP                  	0x7F

/*number of services defined in the service distributor table*/
#define ServDist_UDS_NumEntries_u32 	3

/*Service 0x19*/
#define SERV19_NUMOF_SUB_FUNCTIONS      13u
#define SERV19_RECORDNUMBER_SUPPORTED   0x10u

/*Service 0x14*/
#define NUMBER_OF_GROUP_DTC_IDs		0x01u
#define SERV31_MIN_LEN         		0x03u


#define TOTAL_DDID                      0x14
#define DDID_BUFFER_SIZE                0x32


/*
 **************************************************************************************************
 *    Defines
 **************************************************************************************************
 */

 /* @summary: 2D array row and column size */
#define MEM_ARRAY_ROW_SIZE     		0x05u    /* this is used by 0x23 and 0x3D*/
#define MEM_ARRAY_COL_SIZE     		0x02u    /* this is used by 0x23 and 0x3D*/

#define SERV22_MIN_LEN        		0x02u    /* Minimum Length for Read Data Identifier*/
#define SERV22_MAX_LEN        		0x64u    /* Maximum Length for Read Data Identifier*/
			
#define SERV2E_MIN_LEN        		0x04u    /* Minimum Length for Write Data Identifier*/
#define SERV2E_MAX_LEN        		0x64u    /* Maximum Length for Write Data Identifier*/



/*****Packeted*****/
#define SERV_RECORD1                    0x462A
#define SERV_RECORD2                    0x462B
#define SERV_RECORD3                    0x462C
#define SERV_RECORD4                    0x462D
#define SERV_RECORD5                    0x462E
#define PARK_BRAKE_WARN_VHCLE_SPEED     0x4630

/******* State Encoded********/
#define CNTRL_MODULE_CONFIG_TYPE        0x7203 
#define COMMUNICATION_STATUS            0x7211
#define VEHICLE_MODE                    0x7212

#define DTC_MASKING_IDENTIFIER          0x722D

/*******Numeric******/
#define GLOBAL_RT_CLEAR_DTC             0x7213
#define DTC_SET_DUE_TO_DIAG_ROUTINE     0x7214
#define AFE_BIASING                     0x466B

/********BitMapped*****/
#define WELCOME_STRATEGY                0x4640
#define OAT_CONFIG                      0x4663
#define TCU_BUZZER_REQ                  0x466D
#define DEBUG_FRAME                     0x4701

    
/********ASCII**********/
#define SUPPLIER_PART_NUM               0xF187
#define VEHICLE_MFG_ECU_SOFT_NUM        0xF188
#define VIN_1                           0xF190
#define DIAG_VERSION                    0x7400
#define VCN                             0x7235
#define ECU_PARAM_SW_NUM                0x7244 
#define CONFIG_VERSION			0x7201


/***********Hex**********/
#define READ_MASK_DTCs                  0x7231

/*Updated DID list for X0*/
#define POWER_TRAIN_TYPE          	0x4662
#define ECU_ASSEMBLY_NUMBER		0x7234
#define ECU_CONFIG_SW_NUMBER		0x7243
#define DRIVER_SBR_TONE_COUNT		0x470B
#define ECU_INSTALLATION_DATE 		0xF19D
#define ECO_SPORT_CITY_WARN		0x4700

/*EOL DID */
#define EOL_SESSION			0xFD00

/*Additional DID */
    
#define ECU_SBL_SW_NUM			0x723F
#define SYSTEM_SUPPLIER			0xF18A

/* Global Snapshots */
#define GLOBAL_REAL_TIME                0xA000
#define TOTAL_DISTANCE_TRAVELLED        0xA001
#define ECU_SUPPLY_VOLTAGE              0xA002
#define ENGINE_SPEED                    0xA007
#define VEHICLE_SPEED                   0xA008
#define ENGINE_COOLANT_TEMP             0xA009
#define THROTTLE_POSITION               0xA00A
#define VIN_M                           0xA00B

/*************BOOTLOADER SPECIFIC DIDs*******/
#define BOOT_SOFT_IDEN                  0xF180
#define BOOT_FP_DATA                    0xF183
#define ECU_SERIAL_NUMBER               0xF18C
#define APP_SOFT_FP_DATA                0xF184

#define DTC_MASKING_IDENTIFIER_DID_722D				DID_Config_aSt[DTC_MASKING_IDENTIFIER_E].Var_ptr_pu8
#define DTC_MASKING_CODE							(U4)(((U4)DTC_MASKING_IDENTIFIER_DID_722D[0] << 16) | (DTC_MASKING_IDENTIFIER_DID_722D[1] << 8) | DTC_MASKING_IDENTIFIER_DID_722D[2])
#define DTC_MASKING_ENABLE        					(U1)(DTC_MASKING_IDENTIFIER_DID_722D[3] & BIT0)
/*************Periodic IDs**************/


/**************************************************/
/****************IO_CONTROL_DEFAULT****************/
/**************************************************/

/*****Packeted*****/
#define DEFAULT_APP_SOFT_IDEN           0x00u

#define MAX_DIDREQ_SIZE                 25u


/*************Sample DIDs**************/

#define SAMPLE_DID_1                    0xA200
#define SAMPLE_DID_2                    0xA201
#define SAMPLE_DID_3                    0xA202
#define SAMPLE_DID_4                    0xA203
#define SAMPLE_DID_5                    0xA204
#define SAMPLE_DID_6                    0xA205
#define SAMPLE_DID_7                    0xA206
#define SAMPLE_DID_8                    0xA207
#define SAMPLE_DID_9                    0xA208
#define SAMPLE_DID_10                   0xA209




/*
 **************************************************************************************************
 *    Enum
 **************************************************************************************************
 */

typedef enum
{
	UDS_SERV_STAT_UNKNOWN_E = 0,
	UDS_SERV_STAT_REQUEST_DOWNLOAD_E,
	UDS_SERV_STAT_REQUEST_UPLOAD_E
}UDS_Serv_Stat_En_t;


typedef enum
{
    DID_LIST_START_E = 0u,
	SAMPLE_DID_1_E = DID_LIST_START_E,
	SAMPLE_DID_2_E,
	SAMPLE_DID_3_E,
	SAMPLE_DID_4_E,
	SAMPLE_DID_5_E,
	SAMPLE_DID_6_E,
	SAMPLE_DID_7_E,
	SAMPLE_DID_8_E,
    SAMPLE_DID_9_E,
    SAMPLE_DID_10_E,
//
//
//	BOOT_SOFT_IDEN_E,
//	BOOT_FP_DATA_E,
//	APP_SOFT_FP_DATA_E,
//	APP_SW_DATA_DATE_E,
//	APP_SW_DATA_TST_SER_NO_E,
//	APP_SW_DATA_REPAIR_SHOP_E,
//	APP_SW_DATA_REPROG_SEQ_E,
//	CONFIGURATION_FINGERPRINT_DATA_E,
//	CONFIG_DATA_DATE_E,
//	CONFIG_DATA_TST_SER_NO_E,
//	CONFIG_DATA_REPAIR_SHOP_E,
//	CONFIG_DATA_REPROG_SEQ_E,
//	ECU_SERIAL_NUMBER_E,
//	REPROGM_SVN_E,
//	ACTIVE_DIAGNOSTIC_SESS_E,
//	ECU_MFG_DATE_E,
//	APP_SOFT_STATUS_E,
//	CALIBRATION_SOFT_STATUS_E,
//	CONFIG_SOFT_STATUS_E,
//	ACTIVE_SOFTWARE_COMPONENT_E,
//	ECU_HW_NUM_E,
//	ECU_SW_NUM_E,
//	SYSTEM_NAME_E,
//	PROGRAM_SECRET_KEY_E,
//	EXTENDED_SECRET_KEY_E,
//	END_OF_LINE_SECRET_KEY_E,
//	SERV_RECORD1_E,
//	SERV_RECORD2_E,
//	SERV_RECORD3_E,
//	SERV_RECORD4_E,
//	SERV_RECORD5_E,
//	PBL_RESERVED_E,
//	APP_SOFT_IDEN_E,
//	SUPPLIER_PART_NUM_E,
//	ECU_PBL_SW_NUM_E,
//	ECU_APP_SW_NUM_E,
//	ECU_CONFIG_SW_NUMBER_E,
//	ECU_ASSEMBLY_NUMBER_E,
	DTC_MASKING_IDENTIFIER_E,
//	SBL_VER_NUM_E,
//	ECU_SPECIFIC_E,
//	ENGINE_WARN_INDICATOR_E,
//	SEAT_BELT_WARN_CHIME_E,
//	SEAT_BELT_WARN_INDICATOR_E,
//	GEAR_MODE_INDICATOR_E,
//	METER_DISPLAY_E,
//	AFE_IFE_DISPLAY_E,
//	REV_GEAR_AUDIO_DISPLAY_E,
//	SERV_INTERVAL_DISTANCE_E,
//	DISTANCE_SINCE_LAST_SERV_E,
//	PARK_BRAKE_WARN_VHCLE_SPEED_E,
//	AMT_WARN_INDICATOR_E,
//	WIF_WARN_INDICATOR_E,
//	FUEL_LEVEL_E,
//	CLK_DISPLAY_SETTING_E,
//	SET_SWITCHES_E,
//	GLOW_PLUG_WARNING_E,
//	MIN_DISTANCE_INST_FUEL_E,
//	AVG_FUEL_TIME_E,
//	OAT_CONDITION_TIME_E,
//	TIRE_SIZE_E,
//	FUEL_TANK_SIZE_E,
//	IC_REPLACEMENT_E,
//	SEASON_ODOMETER_E,
//	SPEED_LIMIT_E,
//	ABS_FAC_E,
//	ILLUMINATION_FINE_TUNN_E,
//	CNTRL_MODULE_CONFIG_TYPE_E,
//	COMMUNICATION_STATUS_E,
//	VEHICLE_MODE_E,
//	ILL_DIMMING_LEV_OUTPUT_E,
//	GLOBAL_RT_CLEAR_DTC_E,
//	DTC_SET_DUE_TO_DIAG_ROUTINE_E,
//	GLOBAL_REAL_TIME_E,
//	TOTAL_DISTANCE_TRAVELLED_E,
//	ECU_SUPPLY_VOLTAGE_E,
//	VEHICLE_INTERIOR_TEMP_E,
//	ABIENT_AIR_TEMP_E,
//	VEHICLE_POWER_MODE_E,
//	ENGINE_SPEED_E,
//	VEHICLE_SPEED_E,
//	ENGINE_COOLANT_TEMP_E,
//	THROTTLE_POSITION_E,
//	VIN_M_E,
//	AFE_BIASING_E,
//	DIAG_GATEWAY_STATE_E,
//	NW_TOPOLOGY_CONFIG_E,
//	PARK_LAMP_IN_E,
//	IGN_IN_E,
//	TURN_WARN_INDICATOR_E,
//	HAZARD_WARN_INDICATOR_E,
//	ABS_WARN_INDICATOR_E,
//	EPAS_PSC_WARN_INDICATOR_E,
//	HIGH_COOLANT_TEMP_WARN_E,
//	BATTERY_CHARGE_WARN_INDICATOR_E,
//	BRAKE_FLUIDE_WARN_INDICATOR_E,
//	PARK_BRAKE_WARN_INDICATOR_E,
//	KEY_IN_OUT_E,
//	SPEED_LIMIT_WARN_INDICATOR_E,
//	GLOW_PLUG_WARN_INDICATOR_E,
//	TX_FAULT_INDICATOR_E,
//	DRL_INDICATOR_E,
//	WELCOME_STRATEGY_E,
//	OAT_CONFIG_E,
//	TCU_BUZZER_REQ_E,
//	DEBUG_FRAME_E,
//	VEHICLE_MFG_ECU_SOFT_NUM_E,
//	VIN_1_E,
//	DIAG_VERSION_E,
//	VCN_E,
//	ECU_PARAM_SW_NUM_E,
//	CONFIG_VERSION_E,
//	READ_MASK_DTCs_E,
//	POWER_TRAIN_TYPE_E,
//	DRIVER_SBR_TONE_COUNT_E,
//	ECU_INSTALLATION_DATE_E,
//	ECO_SPORT_CITY_WARN_E,
//	EOL_SESSION_E,
//	ECU_SBL_SW_NUM_E,
//	SYSTEM_SUPPLIER_E,
//	ELECTRICAL_POWER_E,
//	ECU_STATUS_SIG_E,
//	VEH_MANF_ECU_HW_NUM_E,
//	FRONTFOG_WARN_INDI_E,

#if (TRUE == DIAG_TEST_DEMO_CODE)
    TEST_FAULT_DID_1_E,
    TEST_FAULT_DID_2_E,
    TEST_FAULT_DID_3_E,
    TEST_FAULT_DID_4_E,
    TEST_FAULT_DID_5_E,
    TEST_FAULT_DID_6_E,
    TEST_FAULT_DID_7_E,
    TEST_FAULT_DID_8_E,
    TEST_FAULT_DID_9_E,
    TEST_FAULT_DID_10_E,
#endif
    
	//PDID_1_E,
	//PDID_2_E,
    
	DID_TOTAL_E  
}ISO14229_DidList_En_t;    /* DID Lists are in Exist*/

typedef enum
{
	ILL_DIMMING_LEV_OUTPUT_IO_E,
	BATTERY_CHARGE_WARN_INDICATOR_IO_E,
	BRAKE_FLUIDE_WARN_INDICATOR_IO_E,
	PARK_BRAKE_WARN_INDICATOR_IO_E,
	SPEED_LIMIT_WARN_INDICATOR_IO_E,
	GLOW_PLUG_WARN_INDICATOR_IO_E,
	TURN_WARN_INDICATOR_IO_E,
	ABS_WARN_INDICATOR_IO_E,
	EPAS_PSC_WARN_INDICATOR_IO_E,
	DRL_WARN_INDICATOR_IO_E,
	TX_FAULT_INDICATOR_IO_E,
	ENGINE_WARN_INDICATOR_IO_E,
	SEAT_BELT_WARN_INDICATOR_IO_E,
	CLK_DISPLAY_SETTING_IO_E,
	SET_SWITCHES_IO_E,
	SEAT_BELT_WARN_CHIME_IO_E,
	KEY_IN_OUT_IO_E,
	IO_TOTAL_E
}ISO14229_IOList_En_t;

typedef enum
{
	READ_ONLY_E = 1u,        /* READ_ONLY Access Type for DID*/
	WRITE_ONLY_E,            /* WRITE_ONLY Access Type for DID*/
	READ_WRITE_E,            /* READ_WRITE_ONLY Access Type for DID*/
	IO_CONTROL_E
}DID_aceess_type_En_t;

/* @Summary : - sessions which is going to be supported in this service */
typedef enum
{
	DEFAULT_SESSION_SUB_ID_E = 1u,
	PROGRAMMING_SESSION_SUB_ID_E,
	EXTENDED_DIAG_SESSION_SUB_ID_E,
	ENGINEERING_DIAG_SESSION_SUB_ID_E = 0x5Fu,		/* OEM EOL (optional) */
	SUPPLIER_EOL_SESSION_SUB_ID_E = 0x65u,			/* SUPPLIER EOL (optional) */
	TOTAL_SESS_E = 5u
}SESSION_SUBID_En_t;

typedef enum
{
	ASCII_E = 0u,            /* Used for STRING/Character Type*/
	INT_E,                   /* Used for Numerical Type*/
	HEX_E,
	NUMERIC_E,
	STATE_ENCODED_E,
	PACKETED_E,
	BIT_MAPPED_E
}DID_Value_Status_En_t;

/*Routine control*/
typedef enum {
	SERV31_SERVICE_INFO_RESET_E,
	SERV31_DISP_ALL_WARNING_TXT_E,
	SERV31_SET_GAUGE_MAX_E,
	SERV31_SET_GAUGE_MIN_E,
	SERV31_SET_WARN_LAMP_OFF_E,
	SERV31_SET_WARN_LAMP_ON_E,
	SERV31_AUTOLEARNING_E,
	SERV31_ODO_RESET_E,
	TOTAL_ROUTINES_E
}Serv31_RoutineList_En_t;

typedef enum {
	SERV31_SERVICE_INFO_RESET = 0x3F00,
	SERV31_DISP_ALL_WARNING_TXT = 0x3F01,
	SERV31_SET_GAUGE_MAX = 0x3F02,
	SERV31_SET_GAUGE_MIN = 0x3F03,
	SERV31_SET_WARN_LAMP_OFF = 0x3F04,
	SERV31_SET_WARN_LAMP_ON = 0x3F05,
	SERV31_AUTOLEARNING = 0x3F06,
	SERV31_ODO_RESET = 0x3F07,
}ServID_Ser31_En_t;

typedef struct {
	ServID_Ser31_En_t 		SERVICE_ID;
	void (*ServID_Fptr_t) (void);
}ServID_Ser31_St_t;



typedef union
{
	uint32_t 				Permission_u8;

}DID_Permission_Un_t;	/* Union used for DID session Check  */



typedef struct
{
	uint32_t 		driveFlashStartAddress_u32;       // drive start address 
	uint32_t 		driveFlashEndAddress_u32;         // drive end address 
	uint32_t 		clientTotalTransferDataSize_u32;  // total size of data/payload in bytes for flash programming
	uint32_t 		serverBlockLengthCntr_u32;        // total size of data/payload in bytes written to flash
	uint32_t 		serverFlashWriteAddress_u32;      // contains current flash address while programming
	uint16_t 		serverBlockLength_u16;            // block length supported by server for programming
	uint8_t  		serverBlkSqnCntr_u8;              //  
	UDS_Serv_Stat_En_t  	Serv_stat_En;
}UDS_Service_St_t;


/*
 **************************************************************************************************
 *    Structures
 **************************************************************************************************
 */

 /**
 Prototype for structure passed to the services
 */

 /* Generic Function Pointer for 0x22  0x2E & 2F */
 //typedef bool (*CALLBCK_Fptr_t)(uint8_t *dataframe, uint32_t size, uint8_t Access_Type);/* Generic Function Pointer for 0x22  0x2E & 2F */
typedef bool (*CALLBCK_Fptr_t)(uint8_t* dataframe, uint32_t size, uint8_t Access_Type, uint8_t* Var_Ptr_u8, DID_Value_Status_En_t DID_categary_En);

/*********************IO_CONTROL********/
typedef struct
{
	bool    		mode_b; /*mode true or false*/
	void* 			fv_vp;  /*void pointer to the respective forcevalues*/
	uint8_t* 		Default_Val_pu8; /*pointer to the respective Defaultvalues*/
}STM_st_t;

typedef enum
{
	SLOW_RATE_E = 1,
	MEDIUM_RATE_E = 2,
	FAST_RATE_E = 3,
	STOP_PERIODIC_TX_E = 4,
	UN_INIT_E
}Transmition_Modes_En_t;

typedef struct
{
	ISO14229_DidList_En_t 	DID_Name_En;                          /* DID name As mentioned in Enum Table*/
	uint16_t 		DID_Num;                                             /* DID Number As mentioned in MACRO Table*/
	CALLBCK_Fptr_t 		CALLBCK_Fptr;                                /* Generic Function Pointer for READ DATA BY ID(0x22) and for WRITE DATA BY ID(0x2E)*/
	uint8_t 		DID_Val_Size;                                         /* DID size in bytes*/
	DID_Value_Status_En_t 	Type_En;                              /* Type of data used in Operation*/
	DID_Permission_Un_t 	DID_Permission_Un[TOTAL_SESS_E];		/* Session Operation for each DID */
	uint8_t* 		Var_ptr_pu8;											/* Pointer used for hold the DID Global Var Array*/
	STM_st_t* 		STM_st;                                           /* IO_CONTROL Stimulu*/
	uint8_t* 		Real_Time_Val_u8;                                    /* Pointer used for hold the Real Time Value */
	Transmition_Modes_En_t 	Transmition_Mode_En;
	bool 			Transmit_Status_b;
	uint32_t 		Periodic_Timer_Ms_u32;
}ISO14229_DID_config_St_t;                                      /* Structure declaration used by RDBDID(0x22) & WDBDID(0x2E)*/

/**
	service Dist table
*/
typedef struct
{
	uint16_t 		DDID_Num_u16;
	uint16_t 		DDID_DID_Count_u16;
	uint16_t 		Req_DID_Table[MAX_DIDREQ_SIZE];
	uint8_t 		Req_DIDSize[MAX_DIDREQ_SIZE];
}DDID_St_t;             /* Structure for Dynamically define ddata Identifiers */

typedef enum
{
	SERV19_NUMBER_OF_DTC_BY_STATUS_MASK_E      = 0x01 ,                       
	SERV19_DTC_BY_STATUS_MASK_E                       ,
	SERV19_DTC_SNAPSHOT_IDENTIFICATION_E              ,              
	SERV19_DTC_SNAPSHOT_RECORD_BY_DTC_NUMBER_E        ,           
	SERV19_DTC_STORED_RECORD_BY_RECORD_NUMBER_E     ,          
	SERV19_DTC_EXTENDED_DATA_RECORD_BY_DTC_NUMBER_E   ,           
	SERV19_NUMBER_OF_DTC_BY_SEVERITY_MASK_RECORD_E    ,         
	SERV19_DTC_BY_SEVERITY_MASK_RECORD_E              ,         
	SERV19_SEVERITY_INFORMATION_OF_DTC_E              ,       
	SERV19_SUPPORTED_DTC_E                            ,     
	SERV19_FIRST_TEST_FAILED_E                        ,      
	SERV19_FIRST_CONFIRMED_E                          ,      
	SERV19_MOST_RECENT_TEST_FAILED_E                  ,  
	SERV19_MOST_RECENT_CONFIRMED_E                    ,
	SERV19_MIRROR_MEMORY_DTC_BY_STATUS_MASK_E         ,   
	SERV19_MIRROR_MEMORY_EXTENDED_DATA_RECORD_BY_DTC_NUMBER_E,   
	SERV19_NUMBER_OF_MIRROR_MEMORY_BY_DTC_E              ,   
	SERV19_NUMBER_OF_EMISSION_RELATED_OBD_DTC_BY_STATUS_MASK_E,
	SERV19_EMISSION_RELATED_OBD_DTC_BY_STATUS_MASK_E   ,
	SERV19_DTC_FAULT_DETECTION_COUNTER_E               ,
	SERV19_DTC_WITH_PERMANENT_STATUS_E                 ,
	SERV19_DTC_EXTENDED_DATA_RECORD_BY_RECORD_NUMBER_E ,
	SERV19_USER_DEFINE_MEMORY_DTC_BY_STATUS_MASK_E     ,
	SERV19_USER_DEFINE_MEMORY_DTC_SNAPSHOT_RECORD_BY_DTC_NUMBER_E,
	SERV19_USER_DEFINE_MEMORY_DTC_EXTENDED_DATA_RECORD_BY_DTC_NUMBER_E,  
	SERV19_WWH_OBD_DTC_BY_MASK_RECORD_E        =  0x42 ,
	SERV19_WWH_OBD_DTC_WITH_PERMANENT_STATUS_E =  0x55 ,
}SubFunctionSer19_En_t;
/*
 ****************************************************************************************
 *    Structure Definition 
 ****************************************************************************************
*/
//todo harsh
typedef struct
{
    SubFunctionSer19_En_t 	SUB_FUNCTION_ID ;
    uint16_t 			(*Subfun_Fptr_t) (uint8_t*);
    uint8_t 			DTC_SubFun_Valide_Length_u8;
}SubFunctionSer19_St_t;


extern DDID_St_t DDID_ast[TOTAL_DDID];
/*
 **************************************************************************************************
 *    Export Variables
 **************************************************************************************************
 */

 /* @summary: this 2D array for flash memory blocks */
extern const uint32_t MemoryArray_config[MEM_ARRAY_ROW_SIZE][MEM_ARRAY_COL_SIZE]; /* this is used by 0x23 and 0x3D*/
extern const ServiceDistUDS_St_t UDSServDist_apt[ServDist_UDS_NumEntries_u32];
extern uint8_t current_active_session_u8;
extern UDS_Service_St_t UDS_Server_St;
extern ISO14229_DidList_En_t Current_DID_Index_u16;
extern const SubFunctionSer19_St_t Service19_SubFunctionsaSt[SERV19_NUMOF_SUB_FUNCTIONS];

//extern ISO14229_DID_config_St_t DID_Config_aSt[DID_TOTAL_E];  /* This Structure Array DID_Config_aSt[] is used by both 0x22(RDBDID) and 0x2E(WDBDID) Services*/
extern uint8_t* Var_Ptr_pu8;

extern const uint32_t GroupOfDTCIDs_au32[NUMBER_OF_GROUP_DTC_IDs];

//extern void Update_DiagTBL_2_Conf_aSt(void);
//extern void Update_Conf_aSt_2_DiagTBL(void);


typedef struct
{
	uint8_t		Masking_Byte_pos;		/* Byte position		*/
	uint8_t	    Masking_Data;           /* Min Data Value		*/
}ST_DID_MASK;

//extern UDS_Serv_St_t*  UDS_Serv_pSt;
extern const ST_DID_MASK DID_MASK_TBL[DID_TOTAL_E];


extern uint8_t UDS_GetCurrentSession(void);


#endif

/* *****************************************************************************
 End of File
 ******************************************************************************/
