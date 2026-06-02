################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Libraries/NRF24.c \
../Core/Src/Libraries/st7789v3.c 

OBJS += \
./Core/Src/Libraries/NRF24.o \
./Core/Src/Libraries/st7789v3.o 

C_DEPS += \
./Core/Src/Libraries/NRF24.d \
./Core/Src/Libraries/st7789v3.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Libraries/%.o Core/Src/Libraries/%.su Core/Src/Libraries/%.cyclo: ../Core/Src/Libraries/%.c Core/Src/Libraries/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L010x8 -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Libraries

clean-Core-2f-Src-2f-Libraries:
	-$(RM) ./Core/Src/Libraries/NRF24.cyclo ./Core/Src/Libraries/NRF24.d ./Core/Src/Libraries/NRF24.o ./Core/Src/Libraries/NRF24.su ./Core/Src/Libraries/st7789v3.cyclo ./Core/Src/Libraries/st7789v3.d ./Core/Src/Libraries/st7789v3.o ./Core/Src/Libraries/st7789v3.su

.PHONY: clean-Core-2f-Src-2f-Libraries

