################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/App.c \
../Src/RCC.c \
../Src/cortex.c \
../Src/it.c \
../Src/led.c \
../Src/main.c \
../Src/scheduler.c \
../Src/sysTick.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/App.o \
./Src/RCC.o \
./Src/cortex.o \
./Src/it.o \
./Src/led.o \
./Src/main.o \
./Src/scheduler.o \
./Src/sysTick.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/App.d \
./Src/RCC.d \
./Src/cortex.d \
./Src/it.d \
./Src/led.d \
./Src/main.d \
./Src/scheduler.d \
./Src/sysTick.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F0 -DSTM32F030C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/App.d ./Src/App.o ./Src/App.su ./Src/RCC.d ./Src/RCC.o ./Src/RCC.su ./Src/cortex.d ./Src/cortex.o ./Src/cortex.su ./Src/it.d ./Src/it.o ./Src/it.su ./Src/led.d ./Src/led.o ./Src/led.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/scheduler.d ./Src/scheduler.o ./Src/scheduler.su ./Src/sysTick.d ./Src/sysTick.o ./Src/sysTick.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

