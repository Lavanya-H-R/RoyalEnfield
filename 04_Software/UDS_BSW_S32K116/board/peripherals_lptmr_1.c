/***********************************************************************************************************************
 * This file was generated by the S32 Configuration Tools. Any manual edits made to this file
 * will be overwritten if the respective S32 Configuration Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v11.0
processor: S32K116
package_id: S32K116_LQFP48
mcu_data: s32sdk_s32k1xx_rtm_401
processor_version: 0.0.0
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: a6d43dcb-893a-49cd-9d9d-0bb26ff0f05b
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Included files 
 ******************************************************************************/
#include "peripherals_lptmr_1.h"

/*******************************************************************************
 * lptmr_1 initialization code
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'lptmr_1'
- type: 'lptmr'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'lptmr'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPTMR_0'
- config_sets:
  - lptmr:
    - lptmrConfig:
      - 0:
        - name: 'lptmr_1_config0'
        - readOnly: 'true'
        - workMode: 'LPTMR_WORKMODE_TIMER'
        - dmaRequest: 'false'
        - interruptEnable: 'true'
        - freeRun: 'false'
        - compareValue: '1000'
        - counterUnits: 'LPTMR_COUNTER_UNITS_MICROSECONDS'
        - clockSelect: 'LPTMR_CLOCKSOURCE_SIRCDIV2'
        - prescaler: 'LPTMR_PRESCALE_2'
        - bypassPrescaler: 'false'
        - pinSelect: 'LPTMR_PINSELECT_TRGMUX'
        - pinPolarity: 'LPTMR_PINPOLARITY_RISING'
    - quick_selection: 'lptmr_default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files in application code.
 *
 */

/* LPTMR configuration structure 0 */
const lptmr_config_t  lptmr_1_config0 = {
  .workMode = LPTMR_WORKMODE_TIMER,
  .dmaRequest = false,
  .interruptEnable = true,
  .freeRun = false,
  .compareValue = 1000UL,
  .counterUnits = LPTMR_COUNTER_UNITS_MICROSECONDS,
  .clockSelect = LPTMR_CLOCKSOURCE_SIRCDIV2,
  .prescaler = LPTMR_PRESCALE_2,
  .bypassPrescaler = false,
  .pinSelect = LPTMR_PINSELECT_TRGMUX,
  .pinPolarity = LPTMR_PINPOLARITY_RISING
};


