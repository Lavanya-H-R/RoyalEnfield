################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIAG/diag_common/fee_adapt/fee_adapt.c 

OBJS += \
./src/DIAG/diag_common/fee_adapt/fee_adapt.o 

C_DEPS += \
./src/DIAG/diag_common/fee_adapt/fee_adapt.d 


# Each subdirectory must supply rules for building sources it contributes
src/DIAG/diag_common/fee_adapt/%.o: ../src/DIAG/diag_common/fee_adapt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/DIAG/diag_common/fee_adapt/fee_adapt.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


