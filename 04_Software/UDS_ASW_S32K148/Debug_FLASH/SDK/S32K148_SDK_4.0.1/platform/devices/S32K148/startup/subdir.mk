################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/S32K148_SDK_4.0.1/platform/devices/S32K148/startup/system_S32K148.c 

OBJS += \
./SDK/S32K148_SDK_4.0.1/platform/devices/S32K148/startup/system_S32K148.o 

C_DEPS += \
./SDK/S32K148_SDK_4.0.1/platform/devices/S32K148/startup/system_S32K148.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/S32K148_SDK_4.0.1/platform/devices/S32K148/startup/%.o: ../SDK/S32K148_SDK_4.0.1/platform/devices/S32K148/startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/S32K148_SDK_4.0.1/platform/devices/S32K148/startup/system_S32K148.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


