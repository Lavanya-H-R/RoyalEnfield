/*!
** Copyright 2020 NXP
** @file main.c
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary configuration files. */
#include "sdk_project_config.h"
#include "Board_Init.h"
#include "Timer.h"
#include "com_tasksched.h"
volatile int exit_code = 0;
/* User includes */

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your code here */
	Board_init();

	while(1)
	{
		if(_5ms_TimerFlag)
		{
			_5ms_TimerFlag = false;
			Diag_TS_Proc_5ms();
		}
	}
    return 0;
}

/* END main */
/*!
** @}
*/
