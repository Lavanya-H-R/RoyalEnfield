################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIAG/diag_can_uds/uds_serv11/iso14229_serv11.c 

OBJS += \
./src/DIAG/diag_can_uds/uds_serv11/iso14229_serv11.o 

C_DEPS += \
./src/DIAG/diag_can_uds/uds_serv11/iso14229_serv11.d 


# Each subdirectory must supply rules for building sources it contributes
src/DIAG/diag_can_uds/uds_serv11/%.o: ../src/DIAG/diag_can_uds/uds_serv11/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/DIAG/diag_can_uds/uds_serv11/iso14229_serv11.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


