################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIAG/diag_can_tp/dcan_tp/i15765_init.c \
../src/DIAG/diag_can_tp/dcan_tp/i15765_nl.c \
../src/DIAG/diag_can_tp/dcan_tp/i15765_tp.c 

OBJS += \
./src/DIAG/diag_can_tp/dcan_tp/i15765_init.o \
./src/DIAG/diag_can_tp/dcan_tp/i15765_nl.o \
./src/DIAG/diag_can_tp/dcan_tp/i15765_tp.o 

C_DEPS += \
./src/DIAG/diag_can_tp/dcan_tp/i15765_init.d \
./src/DIAG/diag_can_tp/dcan_tp/i15765_nl.d \
./src/DIAG/diag_can_tp/dcan_tp/i15765_tp.d 


# Each subdirectory must supply rules for building sources it contributes
src/DIAG/diag_can_tp/dcan_tp/%.o: ../src/DIAG/diag_can_tp/dcan_tp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/DIAG/diag_can_tp/dcan_tp/i15765_init.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


