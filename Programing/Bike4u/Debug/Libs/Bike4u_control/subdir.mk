################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/Bike4u_control/control.c 

OBJS += \
./Libs/Bike4u_control/control.o 

C_DEPS += \
./Libs/Bike4u_control/control.d 


# Each subdirectory must supply rules for building sources it contributes
Libs/Bike4u_control/%.o Libs/Bike4u_control/%.su Libs/Bike4u_control/%.cyclo: ../Libs/Bike4u_control/%.c Libs/Bike4u_control/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L010x8 -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"/Users/admin/Desktop/My Projects/Bike4u/Programing/Bike4u/Libs" -I"/Users/admin/Desktop/My Projects/Bike4u/Programing/Bike4u/Libs/NRF24" -I"/Users/admin/Desktop/My Projects/Bike4u/Programing/Bike4u/Libs/ST7789" -I"/Users/admin/Desktop/My Projects/Bike4u/Programing/Bike4u/Libs/Bike4u_control" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Libs-2f-Bike4u_control

clean-Libs-2f-Bike4u_control:
	-$(RM) ./Libs/Bike4u_control/control.cyclo ./Libs/Bike4u_control/control.d ./Libs/Bike4u_control/control.o ./Libs/Bike4u_control/control.su

.PHONY: clean-Libs-2f-Bike4u_control

