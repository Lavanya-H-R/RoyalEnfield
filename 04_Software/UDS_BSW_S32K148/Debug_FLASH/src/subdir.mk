################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Board_Init.c \
../src/CAN.c \
../src/Flash_EEPROM.c \
../src/Timer.c \
../src/main.c 

OBJS += \
./src/Board_Init.o \
./src/CAN.o \
./src/Flash_EEPROM.o \
./src/Timer.o \
./src/main.o 

C_DEPS += \
./src/Board_Init.d \
./src/CAN.d \
./src/Flash_EEPROM.d \
./src/Timer.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/Board_Init.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


