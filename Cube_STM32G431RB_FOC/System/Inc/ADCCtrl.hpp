/*
 * ADCCtrl.hpp
 *
 *  Created on: 2020/05/23
 *      Author: watashi
 */

#ifndef SYSTEM_INC_ADCCTRL_HPP_
#define SYSTEM_INC_ADCCTRL_HPP_

#include "adc.h"
#include "stm32g4xx_hal.h"

#include <functional>
#include "InterruptHandler.hpp"

class ADCCtrl final {
private:
	ADCCtrl() = default;
	~ADCCtrl() = default;



public:
	ADCCtrl(const ADCCtrl&) = delete;
	ADCCtrl& operator=(const ADCCtrl&) = delete;
	ADCCtrl(ADCCtrl&&) = delete;
	ADCCtrl& operator=(ADCCtrl&&) = delete;

	static ADCCtrl& GetInstance() {
		static ADCCtrl instance;
		return instance;
	}

private:

public:

	inline void InitADC() {
		MX_ADC1_Init();
		MX_ADC2_Init();

		HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
		HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);

		HAL_ADCEx_InjectedStart_IT(&hadc1);
	};

	inline void DeInitADC() {
		HAL_ADCEx_InjectedStop_IT(&hadc1);
		HAL_ADC_DeInit(&hadc2);
		HAL_ADC_DeInit(&hadc1);
	};

	inline int GetUphaseADCVal() {
		volatile int adcval = ADC1 -> JDR1;
		return adcval;
	};

	inline int GetVphaseADCVal() {
		volatile int adcval = ADC1 -> JDR2;
		return adcval;
	};

	inline int GetWphaseADCVal() {
		volatile int adcval = ADC1 -> JDR3;
		return adcval;
	};

	inline int StartUserInputADC(void) {
		HAL_ADC_Start(&hadc1);
		return  HAL_ADC_GetValue(&hadc1);
	};

	inline int StartDCLinkADC(void) {
		HAL_ADC_Start(&hadc2);
		return  HAL_ADC_GetValue(&hadc2);
	};

};


#endif /* SYSTEM_INC_ADCCTRL_HPP_ */
