#include "Flash_EEPROM.h"


flash_ssd_config_t  flashSSDConfig;


//void CCIF_Handler(void)
//{
//    /* Disable Flash Command Complete interrupt */
//    FTFx_FCNFG &= (~FTFx_FCNFG_CCIE_MASK);
//
//    return;
//}


void Flash_EEE_Partition_init(void)
{
	status_t status;

	/* Install interrupt for Flash Command Complete event */
//	INT_SYS_InstallHandler(FTFC_IRQn, CCIF_Handler, 0);
//	INT_SYS_EnableIRQ(FTFC_IRQn);

	/* Enable global interrupt */
//	INT_SYS_EnableIRQGlobal();

	status = FLASH_DRV_Init(&Flash_InitConfig0, &flashSSDConfig);
	DEV_ASSERT(STATUS_SUCCESS == status);

#if ((FEATURE_FLS_HAS_FLEX_NVM == 1u) & (FEATURE_FLS_HAS_FLEX_RAM == 1u))
	if (flashSSDConfig.EEESize == 0) /*check partition if not done partition will take place*/
	{
		status = FLASH_DRV_DEFlashPartition(&flashSSDConfig, EEE_SIZE, EEE_BACKUP, 0x0u, false, true); /*eeprom partition */
		DEV_ASSERT(STATUS_SUCCESS == status);
		status = FLASH_DRV_Init(&Flash_InitConfig0, &flashSSDConfig);
		DEV_ASSERT(STATUS_SUCCESS == status);
		status = FLASH_DRV_SetFlexRamFunction(&flashSSDConfig, EEE_ENABLE, 0x00u, NULL); /* flex Ram to flex NVM */
		DEV_ASSERT(STATUS_SUCCESS == status);
	}
#endif
}


status_t Flash_EEPROM_Write(uint32_t EEP_Address, uint32_t size, uint8_t *sourceBuffer)
{
	status_t status;
	/* Try to write data to EEPROM if FlexRAM is configured as EEPROM */
	if (flashSSDConfig.EEESize != 0u)
	{
//		address = flashSSDConfig.EERAMBase;
//		size = sizeof(uint32_t);
		status = FLASH_DRV_EEEWrite(&flashSSDConfig, EEP_Address, size, sourceBuffer);

		/* Verify the written data */
//		if (*((uint32_t*) sourceBuffer) != *((uint32_t*) address))
//		{
//			/* Failed to write data to EEPROM */
//
//		}
	}
	return status;
}


status_t Flash_Write(uint32_t Address, uint32_t size, uint8_t *data)
{
	status_t Flash_status;
	uint16_t data_size;
	uint8_t Rem_DataSize;
	uint8_t Rem_Databuff[8] = { 0x00 };

	data_size = (FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE * (size / FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE));

	Flash_status = FLASH_DRV_Program(&flashSSDConfig, Address, data_size, data);
	DEV_ASSERT(STATUS_SUCCESS == ret);

	data += data_size;
	Rem_DataSize  = (size % FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE);
	if(Rem_DataSize > 0)
	{
		for (uint8_t i = 0; i < 8; i++)
		{
			if(Rem_DataSize > 0)
			{
				Rem_Databuff[i] = *(uint8_t*) data;
				data++;
				Rem_DataSize--;
			}
			else
			{
				Rem_Databuff[i] = 0xFF;
			}
		}
		Flash_status = FLASH_DRV_Program(&flashSSDConfig, (Address + data_size), FEATURE_FLS_PF_BLOCK_WRITE_UNIT_SIZE, Rem_Databuff);
	}
	return Flash_status;
}

bool Flash_Read(uint32_t Flash_Start_add, uint32_t Flash_mem_size,uint8_t *data1_buff)
{
	uint32_t size_u32 = 0, PflashStartAdd_u32 = 0, PflashReadData_u32 = 0;
//	uint16_t *Flash_Read_Data = NULL;
//	Flash_Read_Data = (uint16_t*)Flash_Start_add;
//	for(uint16_t index = 0; index < Flash_mem_size; index+=2,count_ind++)
//	{
//		data1_buff[index] = Flash_Read_Data[count_ind] & 0xFF;
//		data1_buff[index+1] = (Flash_Read_Data[count_ind] >> 8 );
//	}
	size_u32 = Flash_mem_size;
	PflashStartAdd_u32 = Flash_Start_add;
	for (uint32_t i = 0; i < (size_u32 / 4); i++)
	{
		PflashReadData_u32 = *(uint32_t*) PflashStartAdd_u32;
		for (uint8_t j = 0; j < 4; j++)
		{
			data1_buff[j] = (uint8_t) (PflashReadData_u32 >> ((uint16_t) 8 * j));
		}
		PflashStartAdd_u32 += (uint32_t) 4;
	}
	return true;
}
