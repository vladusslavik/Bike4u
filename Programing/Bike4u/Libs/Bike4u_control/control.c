#include "control.h"

extern uint16_t adc[2];
extern uint8_t bat_percent;


//**************Battery Measure**************
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    if(hadc->Instance == ADC1)
    {
        // Накопичувач фільтра (експоненційне середнє з фіксованою крапкою)
        static int32_t filter_reg = -1;

        // 1. Цифровий EMA фільтр на зсувах
        if (filter_reg < 0) {
            filter_reg = (int32_t)adc[0] << 7; // Перша ініціалізація
        } else {
            // Формула рівноваги: Y = Y + X - (Y / 128)
            filter_reg = filter_reg + (int32_t)adc[0] - (filter_reg >> 7);
        }

        // Отримуємо чисте значення АЦП без дробової частини
        uint32_t adc_filtered = filter_reg >> 7;

        // 2. Визначення відсотка по таблиці значень АЦП
        if(adc_filtered <= battery_lut[0]){
            bat_percent = 0;
            return;
        }
        if(adc_filtered >= battery_lut[100]){
            bat_percent = 100;
            return;
        }

        for(uint8_t i = 0; i < 101; i++){
            if(adc_filtered <= battery_lut[i]){
                bat_percent = i;
                break;
            }
        }
    }
}
