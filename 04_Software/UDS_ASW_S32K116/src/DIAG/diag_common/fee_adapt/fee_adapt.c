/***********************************************************************************************************************
* File Name    : fee_adapt.c
* Version      : 01
* Description  : 
* Created By   : Sloki
* Creation Date: 10/01/2019
***********************************************************************************************************************/


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "fee_adapt.h"
#include "fee_conf.h"
#include "diag_adapt.h"
#include "diag_appl_test.h"
#include "diag_sys_conf.h"
#if(TRUE == DIAG_CONF_EEPROM)
	#include "eeprom.h"				//include the eeprom related files
#endif

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/



/***********************************************************************************************************************
* Function Name: Flash_Pattern_Write
* Description  : 
* Arguments    : uint32_t address,uint32_t data
* Return Value : bool
***********************************************************************************************************************/
uint8_t data_buff_au8[8] = {0};
//fsp_err_t Erase_status, FlashWrite_status;
bool Flash_Pattern_Write(uint32_t address,uint32_t data)
{
//    flash_result_t blank_check_result;
//    uint8_t Buff_index = 0;
//    for (Buff_index = 0; Buff_index < 4U; Buff_index++)
//    {
//        data_buff_au8[Buff_index] = (uint8_t) ((data >> (Buff_index * 8)) & 0xFF);
//    }
//    __disable_irq ();
//    Erase_status = R_FLASH_HP_Erase (&g_flash0_ctrl, (uint32_t) address, 1);
//    __enable_irq ();
//    if (FSP_SUCCESS != Erase_status)
//    {
//        return false;
//    }
//
//    __disable_irq ();
//    FlashWrite_status = R_FLASH_HP_Write (&g_flash0_ctrl, (uint32_t) (&data_buff_au8[0]), (uint32_t) address, 4);
//    __enable_irq ();
//    if (FSP_SUCCESS != FlashWrite_status)
//    {
//        return false;
//    }
//    return FlashWrite_status;
}

/********************************************************EOF***********************************************************/
