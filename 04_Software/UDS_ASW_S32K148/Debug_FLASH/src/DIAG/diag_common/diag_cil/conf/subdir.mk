################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIAG/diag_common/diag_cil/conf/cil_can_conf.c 

OBJS += \
./src/DIAG/diag_common/diag_cil/conf/cil_can_conf.o 

C_DEPS += \
./src/DIAG/diag_common/diag_cil/conf/cil_can_conf.d 


# Each subdirectory must supply rules for building sources it contributes
src/DIAG/diag_common/diag_cil/conf/%.o: ../src/DIAG/diag_common/diag_cil/conf/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/DIAG/diag_common/diag_cil/conf/cil_can_conf.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


