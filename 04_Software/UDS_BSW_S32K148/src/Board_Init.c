#include "Board_Init.h"
#include "com_tasksched.h"

void Board_init(void)
{
	status_t status;

	status = CLOCK_DRV_Init(&clockMan1_InitConfig0);
	DEV_ASSERT(status == STATUS_SUCCESS);

	/* Pin-muxing + GPIO pin direction and initial value settings. */
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

	/*Initializes CAN*/
	FlexCAN_init();
	LPTMR_init_();

	Flash_EEE_Partition_init();
	Diag_TS_Init();
}






