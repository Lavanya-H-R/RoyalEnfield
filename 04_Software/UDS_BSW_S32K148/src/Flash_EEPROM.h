#include "sdk_project_config.h"

#define EEE_SIZE  			0x02u
#define EEE_BACKUP			0x04u

//extern flash_ssd_config_t  flashSSDConfig;
extern status_t Flash_Write(uint32_t Address, uint32_t size, uint8_t *data);
status_t Flash_EEPROM_Write(uint32_t EEP_Address, uint32_t size, uint8_t *sourceBuffer);
bool Flash_Read(uint32_t Flash_Start_add, uint32_t Flash_mem_size,uint8_t *data1_buff);
