################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/DIAG/diag_common/fee_adapt/conf/subdir.mk
-include src/DIAG/diag_common/fee_adapt/subdir.mk
-include src/DIAG/diag_common/diag_utils/subdir.mk
-include src/DIAG/diag_common/diag_scheduler/conf/subdir.mk
-include src/DIAG/diag_common/diag_scheduler/subdir.mk
-include src/DIAG/diag_common/diag_cil/conf/subdir.mk
-include src/DIAG/diag_common/diag_cil/subdir.mk
-include src/DIAG/diag_can_uds/uds_session/subdir.mk
-include src/DIAG/diag_can_uds/uds_serv27/subdir.mk
-include src/DIAG/diag_can_uds/uds_serv11/subdir.mk
-include src/DIAG/diag_can_uds/uds_serv10/subdir.mk
-include src/DIAG/diag_can_uds/conf/subdir.mk
-include src/DIAG/diag_can_tp/dcan_tp/subdir.mk
-include src/DIAG/diag_can_tp/conf/subdir.mk
-include src/DIAG/diag_appl_test/subdir.mk
-include src/subdir.mk
-include board/subdir.mk
-include SDK/rtos/osif/subdir.mk
-include SDK/platform/drivers/src/pins/subdir.mk
-include SDK/platform/drivers/src/lptmr/subdir.mk
-include SDK/platform/drivers/src/interrupt/subdir.mk
-include SDK/platform/drivers/src/flexcan/subdir.mk
-include SDK/platform/drivers/src/flash/subdir.mk
-include SDK/platform/drivers/src/edma/subdir.mk
-include SDK/platform/drivers/src/clock/S32K1xx/subdir.mk
-include SDK/S32K116_SDK_4.0.1/platform/devices/S32K116/startup/subdir.mk
-include SDK/S32K116_SDK_4.0.1/platform/devices/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
UDS_ASW_S32K116.siz \


# All Target
all: UDS_ASW_S32K116.elf secondary-outputs

# Tool invocations
UDS_ASW_S32K116.elf: $(OBJS) D:/Projects/ROYAL_ENFIELD/FW_Code/UDS_ASW_S32K116/Project_Settings/Linker_Files/S32K116_17_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "UDS_ASW_S32K116.elf" "@UDS_ASW_S32K116.args"  $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UDS_ASW_S32K116.siz: UDS_ASW_S32K116.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley UDS_ASW_S32K116.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
