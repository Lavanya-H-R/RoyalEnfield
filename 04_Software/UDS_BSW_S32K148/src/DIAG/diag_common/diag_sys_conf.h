/***********************************************************************************************************************
* File Name    : diag_sys_conf.h
* Version      : 01
* Description  : This file contains version # of ISO 14229 stack software. This is an internal version # to track the 
					stack development. This version # does not refer to ver # of UDS Standard. 
* Created By   : Sloki
* Creation Date: 18/01/2017	
***********************************************************************************************************************/

#ifndef	_DIAG_SYS_CONF_H_
#define _DIAG_SYS_CONF_H_


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define 	TRUE 							1
#define 	FALSE 							0


#define	DIAG_CONF_FM_SUPPORTED			(FALSE)		//TODO Configurable Parameter
#define	DIAG_CONF_CANTP_SUPPORTED		(TRUE)		//TODO Configurable Parameter

#define	DIAG_CONF_UDS_SUPPORTED			(TRUE)		//TODO Configurable Parameter
#define	DIAG_CONF_OBD2_SUPPORTED		(FALSE)		//TODO Configurable Parameter
#define	DIAG_CONF_J1939_SUPPORTED		(FALSE)		//TODO Configurable Parameter


#define	DIAG_CONF_J1587_SUPPORTED		(FALSE)
#define	DIAG_CONF_DOIP_SUPPORTED		(FALSE)


#define DIAG_CONF_INTERRUPTS         	(FALSE)		//TODO Configurable Parameter
#define DIAG_CONF_CAN_IF         		(TRUE)		//TODO Configurable Parameter
#define DIAG_CONF_EEPROM         		(FALSE)		//TODO Configurable Parameter

#define DIAG_TEST_DEMO_CODE    			(FALSE)		//TODO Configurable Parameter
#define DIAG_TEST_FM_EEPROM_DEMO    	(FALSE)		//TODO Configurable Parameter
#define DIAG_TEST_FM_DEMO    			(FALSE)		//TODO Configurable Parameter

#define DIAG_TEST_J1939_DEMO    	    (FALSE)		//TODO Configurable Parameter


#define DIAG_CONF_CORE_LITTLE_ENDIAN 	(TRUE)		//TODO Configurable Parameter

#if(FALSE ==  DIAG_CONF_CORE_LITTLE_ENDIAN)
	#define DIAG_CONF_CORE_BIG_ENDIAN   (TRUE)
#endif

/***********************************************************************************************************************
Export Variables and Functions
***********************************************************************************************************************/


#endif /*_DIAG_SYS_CONF_H_*/
