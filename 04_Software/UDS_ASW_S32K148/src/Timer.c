#include "Timer.h"
#include "diag_typedefs.h"

uint32_t _1ms_Timer_Counter = 0;
bool _5ms_TimerFlag = false;
void LPTMR_init_(void)
{
	LPTMR_DRV_Init(INST_LPTMR1, &lptmr_1_config0, false);

	/* Install IRQ handler for LPTMR interrupt */
	INT_SYS_InstallHandler(LPTMR0_IRQn, &lptmrISR, 0);

	/* Enable IRQ for LPTMR */
	INT_SYS_EnableIRQ(LPTMR0_IRQn);

	/* Start LPTMR counter */
	LPTMR_DRV_StartCounter(INST_LPTMR1);
}


void lptmrISR(void)
{
	_1ms_Timer_Counter++;
	INC_TIME_MS();
	if(0 == (_1ms_Timer_Counter % 5))
	{
		_5ms_TimerFlag = true;
		_1ms_Timer_Counter = 0;
	}
}
