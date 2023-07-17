################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIAG/diag_common/diag_cil/can_callback.c \
../src/DIAG/diag_common/diag_cil/can_if.c \
../src/DIAG/diag_common/diag_cil/cil_nvm.c 

OBJS += \
./src/DIAG/diag_common/diag_cil/can_callback.o \
./src/DIAG/diag_common/diag_cil/can_if.o \
./src/DIAG/diag_common/diag_cil/cil_nvm.o 

C_DEPS += \
./src/DIAG/diag_common/diag_cil/can_callback.d \
./src/DIAG/diag_common/diag_cil/can_if.d \
./src/DIAG/diag_common/diag_cil/cil_nvm.d 


# Each subdirectory must supply rules for building sources it contributes
src/DIAG/diag_common/diag_cil/%.o: ../src/DIAG/diag_common/diag_cil/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/DIAG/diag_common/diag_cil/can_callback.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


