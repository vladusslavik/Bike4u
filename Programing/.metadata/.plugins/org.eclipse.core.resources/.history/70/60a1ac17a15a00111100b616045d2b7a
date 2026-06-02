#include "control.h"

extern uint16_t adc[2];
extern uint8_t bat_percent;


//**************Battery Measure**************

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    if(hadc->Instance == ADC1)
    {
    	//static float ema_cof = 0.01;
    	static float filtered = -1;


    	float vdda = VREFINT_CAL_COEF / (float)adc[1];
    	float battery = (vdda * (float)adc[0])/ 4095.0f;
    	battery *= BAT_PRESC;

    	if (filtered < 0)
			filtered = battery;
		else
			filtered = (filtered * 0.99f) + ((float) battery * 0.01f);

    	uint16_t fil_u = (float)filtered * 1000;

    	if(fil_u <= battery_lut[0]){
    		bat_percent = 0;
    		return;
    	}
    	if(fil_u >= battery_lut[100]){
    		bat_percent = 100;
    		return;
    	}

    	for(uint8_t i = 0; i < 101; i++){
    		if(fil_u < battery_lut[i]){
    			bat_percent = i;
    			break;
    		}

    	}

    }
}
