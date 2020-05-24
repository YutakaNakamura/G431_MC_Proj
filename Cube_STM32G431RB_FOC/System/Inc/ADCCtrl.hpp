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

namespace ADCCtrl {

	static inline void InitADC() {
		MX_ADC1_Init();
		MX_ADC2_Init();

		HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
		HAL_ADCEx_Calibration_Start(&hadc2, ADC_SINGLE_ENDED);

		HAL_ADCEx_InjectedStart_IT(&hadc1);
	};

	static inline void DeInitADC() {
		HAL_ADCEx_InjectedStop_IT(&hadc1);
		HAL_ADC_DeInit(&hadc2);
		HAL_ADC_DeInit(&hadc1);
	};

	static inline int GetUphaseADCVal() {
		volatile int adcval = ADC1 -> JDR1;
		return adcval;
	};

	static inline int GetVphaseADCVal() {
		volatile int adcval = ADC1 -> JDR2;
		return adcval;
	};

	static inline int GetWphaseADCVal() {
		volatile int adcval = ADC1 -> JDR3;
		return adcval;
	};

	//TODO:regular channel
	static inline void StartDCLinkAndUserInputADC() {
		HAL_ADC_Start(&hadc1);
		return;
	};

	static inline int GetDCLinkADCVal() {
		return HAL_ADC_GetValue(&hadc1);
	};

	static inline int GetUserInputADCVal() {
		return HAL_ADC_GetValue(&hadc1);
	};

	static inline void StartTempADC() {
		HAL_ADC_Start(&hadc2);
		return;
	};

	static inline int GetTempADCVal() {
		return HAL_ADC_GetValue(&hadc2);
	};

};


#endif /* SYSTEM_INC_ADCCTRL_HPP_ */
