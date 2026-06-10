#include "control.h"

extern uint16_t adc[2];
extern uint8_t bat_percent;


//**************Battery Measure**************
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	if(hadc->Instance == ADC1)
	    {
	        // Прості накопичувачі для фільтра
	        static int32_t f_bat = -1;
	        static int32_t f_vref = -1;

	        // 1. Фільтруємо батарею (adc[0])
	        if (f_bat < 0)
	        	f_bat = (int32_t)adc[0] << 7;
	        else
	        	f_bat = f_bat + (int32_t)adc[0] - (f_bat >> 7);

	        uint32_t clear_bat = f_bat >> 7;

	        // 2. Фільтруємо опорку (adc[1])
	        if (f_vref < 0)
	        	f_vref = (int32_t)adc[1] << 7;
	        else
	        	f_vref = f_vref + (int32_t)adc[1] - (f_vref >> 7);

	        uint32_t clear_vref = f_vref >> 7;

	        // Захист від ділення на 0
	        if (clear_vref == 0) return;

	        // 3. Магія компенсації
	        // Перераховуємо батарею так, ніби живлення завжди рівно 3.3В
	        // 1489 — це те, що мав би видавати adc[1], якби на платі було чітко 3.3В
	        uint32_t adc_corrected = (clear_bat * 1489) / clear_vref;

	        // 4. Шукаємо відсоток по твоїй таблиці
	        if(adc_corrected <= battery_lut[0]){
	            bat_percent = 0;
	            return;
	        }
	        if(adc_corrected >= battery_lut[100]){
	            bat_percent = 100;
	            return;
	        }

	        for(uint8_t i = 0; i < 101; i++){
	            if(adc_corrected <= battery_lut[i]){
	                bat_percent = i;
	                break;
	            }
	        }
	    }
}
