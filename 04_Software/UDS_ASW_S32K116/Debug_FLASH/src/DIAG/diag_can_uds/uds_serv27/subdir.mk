################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIAG/diag_can_uds/uds_serv27/iso14229_serv27.c 

OBJS += \
./src/DIAG/diag_can_uds/uds_serv27/iso14229_serv27.o 

C_DEPS += \
./src/DIAG/diag_can_uds/uds_serv27/iso14229_serv27.d 


# Each subdirectory must supply rules for building sources it contributes
src/DIAG/diag_can_uds/uds_serv27/%.o: ../src/DIAG/diag_can_uds/uds_serv27/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/DIAG/diag_can_uds/uds_serv27/iso14229_serv27.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


