################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIAG/diag_appl_test/diag_adapt.c \
../src/DIAG/diag_appl_test/diag_appl_test.c 

OBJS += \
./src/DIAG/diag_appl_test/diag_adapt.o \
./src/DIAG/diag_appl_test/diag_appl_test.o 

C_DEPS += \
./src/DIAG/diag_appl_test/diag_adapt.d \
./src/DIAG/diag_appl_test/diag_appl_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/DIAG/diag_appl_test/%.o: ../src/DIAG/diag_appl_test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/DIAG/diag_appl_test/diag_adapt.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


