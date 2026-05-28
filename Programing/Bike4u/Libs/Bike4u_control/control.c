#include "control.h"

extern uint16_t adc[2];
extern uint8_t bat_percent;


//**************Battery Measure**************
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    if(hadc->Instance == ADC1)
    {
        // Фільтр у форматі з фіксованою крапкою (множимо на 128)
        static int32_t filtered_adc_x128 = -128;

        // 1. Плавний фільтр без ділення (коефіцієнт приблизно 0.01)
        // Математика: (старе * 127 + нове * 1) / 128
        if (filtered_adc_x128 < 0) {
            filtered_adc_x128 = (int32_t)adc[0] << 7; // Ініціалізація (зсув << 7 це те саме що * 128)
        } else {
            filtered_adc_x128 = (filtered_adc_x128 * 127 + (int32_t)adc[0]);
        }

        // Повертаємо чисте відфільтроване значення АЦП (ділимо на 128 через зсув >> 7)
        uint16_t fil_adc = filtered_adc_x128 >> 7;

        // 2. Швидкий бінарний або лінійний пошук по таблиці
        if(fil_adc <= battery_lut[0]){
            bat_percent = 0;
            return;
        }
        if(fil_adc >= battery_lut[100]){
            bat_percent = 100;
            return;
        }

        for(uint8_t i = 0; i < 101; i++){
            if(fil_adc <= battery_lut[i]){
                bat_percent = i;
                break;
            }
        }
    }
}
