
/***********************************************************************************************************************
* File Name    : fee_conf.h
* Version      : 01
* Description  : EEPROM configuration 
* Created By   : Sloki
* Creation Date: 18/01/2017	
***********************************************************************************************************************/
#ifndef _FEE_CONF_H_
#define _FEE_CONF_H_

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "diag_typedefs.h"
#include "fee_adapt.h"


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define BOOT_SUPPORTED                  TRUE
#define APP_PATTERN					0x55AA55AA
#define BOOT_PATTERN				0xAA55AA55

/* Address of  the Flash from where the application starts executing */
/* Rule: Set BOOTLOADER_FLASH_BASE_ADDRESS to _RESET_ADDR value of application linker script*/
#define APP_START_ADDRESS			        0x00010000 /*This is application  memory address*/
#define APP_SIZE					        0x00050000
#define APP_END_ADDRESS     		        (APP_START_ADDRESS + (APP_SIZE - 1))
#define BOOT_START_ADDRESS			        0x00000000 /*This application boot memory*/
#define CRC_RESET_VALUE                     0xFFFFFFFF
//#define DRIVE_VALIDATION_START_ADDRESS    APP_END_ADDRESS
#define DRIVE_VALIDATION_START_ADDRESS      (APP_START_ADDRESS - 0x2000)
//#define DRIVE_VALIDATION_END_ADDRESS      (DRIVE_CRC_END_ADDRESS)
#define DRIVE_VALIDATION_END_ADDRESS        (APP_START_ADDRESS - 0x01)

/***********************************************************************************************************************
Structures and Enums
***********************************************************************************************************************/


#endif /*_FEE_CONF_H_*/
