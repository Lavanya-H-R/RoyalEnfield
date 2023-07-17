################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIAG/diag_common/diag_scheduler/can_sched.c \
../src/DIAG/diag_common/diag_scheduler/com_tasksched.c 

OBJS += \
./src/DIAG/diag_common/diag_scheduler/can_sched.o \
./src/DIAG/diag_common/diag_scheduler/com_tasksched.o 

C_DEPS += \
./src/DIAG/diag_common/diag_scheduler/can_sched.d \
./src/DIAG/diag_common/diag_scheduler/com_tasksched.d 


# Each subdirectory must supply rules for building sources it contributes
src/DIAG/diag_common/diag_scheduler/%.o: ../src/DIAG/diag_common/diag_scheduler/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/DIAG/diag_common/diag_scheduler/can_sched.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


