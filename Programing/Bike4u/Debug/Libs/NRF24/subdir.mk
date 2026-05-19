################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/NRF24/NRF24.c 

OBJS += \
./Libs/NRF24/NRF24.o 

C_DEPS += \
./Libs/NRF24/NRF24.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/NRF24/%.o Libs/NRF24/%.su Libs/NRF24/%.cyclo: ../Libs/NRF24/%.c Libs/NRF24/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L010x8 -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"/Users/admin/Desktop/My Projects/Bike4u/Programing/Bike4u/Libs" -I"/Users/admin/Desktop/My Projects/Bike4u/Programing/Bike4u/Libs/NRF24" -I"/Users/admin/Desktop/My Projects/Bike4u/Programing/Bike4u/Libs/ST7789" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-NRF24

clean-Libs-2f-NRF24:
	-$(RM) ./Libs/NRF24/NRF24.cyclo ./Libs/NRF24/NRF24.d ./Libs/NRF24/NRF24.o ./Libs/NRF24/NRF24.su

.PHONY: clean-Libs-2f-NRF24

