/******************************************************************************
 *    FILENAME    : crc_crc.h
 *    DESCRIPTION : The calc_crc32 function is defined here in this file.
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/ 
 
 #ifndef __CRC_CRC32_H
 #define __CRC_CRC32_H

/*
 **************************************************************************************************
 *    Defines
 **************************************************************************************************
 */
 #define TABLE_SIZE 256
  
 /*
 **************************************************************************************************
 *    Variable declaration
 **************************************************************************************************
 */
 const uint32_t CRC32_Lookup_Table_au32[TABLE_SIZE];

 /*
 **************************************************************************************************
 *    Function Prototype
 **************************************************************************************************
 */
/**---------
 *  @brief     :Function calc_crc32 calculates the crc32 for the continuous memory block of 
 *            given size.It calculates the new crc32 value based on the older crc32 value.
 *
 *  @param   Crc_Data_pu8 - The starting address of the memory block
 *           Crc_Size_u32 - size of the memory block
 *           Crc_Last_Crc_su32 - previous value of crc32
 *
 *  @return  The crc32 value calculated - It returns crc32 value calculated so far.
 *-----------
 */
 uint32_t Crc_CalculateCRC32(const uint8_t *Crc_Data_pu8, uint32_t Crc_Size_u32, uint32_t Crc_Last_Crc32_su32);
 uint8_t Crc_CalculateCRC8 (uint8_t *Crc_Data_pu8, uint32_t size);

#endif

/* *****************************************************************************
 End of File
 */

