################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIAG/diag_common/diag_utils/crc_util.c \
../src/DIAG/diag_common/diag_utils/diag_typedefs.c \
../src/DIAG/diag_common/diag_utils/math_util.c \
../src/DIAG/diag_common/diag_utils/str_util.c \
../src/DIAG/diag_common/diag_utils/utils.c 

OBJS += \
./src/DIAG/diag_common/diag_utils/crc_util.o \
./src/DIAG/diag_common/diag_utils/diag_typedefs.o \
./src/DIAG/diag_common/diag_utils/math_util.o \
./src/DIAG/diag_common/diag_utils/str_util.o \
./src/DIAG/diag_common/diag_utils/utils.o 

C_DEPS += \
./src/DIAG/diag_common/diag_utils/crc_util.d \
./src/DIAG/diag_common/diag_utils/diag_typedefs.d \
./src/DIAG/diag_common/diag_utils/math_util.d \
./src/DIAG/diag_common/diag_utils/str_util.d \
./src/DIAG/diag_common/diag_utils/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/DIAG/diag_common/diag_utils/%.o: ../src/DIAG/diag_common/diag_utils/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/DIAG/diag_common/diag_utils/crc_util.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


