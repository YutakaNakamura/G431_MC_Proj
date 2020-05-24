/*
 * TIMCtrl.h
 *
 *  Created on: 2020/05/23
 *      Author: watashi
 */

#ifndef SYSTEM_INC_TIMCTRL_HPP_
#define SYSTEM_INC_TIMCTRL_HPP_

#include "tim.h"
#include "stm32g4xx_hal.h"
#include "MotorCtrlDefPack.hpp"

namespace TIMCtrl {

	static inline void SetPrescaler(int pPrescalerVal) {
		TIM1 -> PSC = pPrescalerVal;
		return;
	};

	static inline void SetCountPeriod(int pCountPeriod) {
		TIM1 -> ARR = pCountPeriod;
		return;
	};

	template<typename T>
	static inline void SetUphaseDuty(T pDutyCycle) {
		volatile int CountPeriod = TIM1 -> ARR;
		volatile int CountVal = (int)(pDutyCycle * (T)CountPeriod);
		TIM1 -> CCR1 = CountVal;
		return;
	};

	template<typename T>
	static inline void SetVphaseDuty(T pDutyCycle) {
		volatile int CountPeriod = TIM1 -> ARR;
		volatile int CountVal = (int)(pDutyCycle * (T)CountPeriod);
		TIM1 -> CCR2 = CountVal;
		return;
	};

	template<typename T>
	static inline void SetWphaseDuty(T pDutyCycle) {
		volatile int CountPeriod = TIM1 -> ARR;
		volatile int CountVal = (int)(pDutyCycle * (T)CountPeriod);
		TIM1 -> CCR3 = CountVal;
		return;
	};

	template<typename T>
	static inline void SetADCTRGDuty(T pDutyCycle) {
		volatile int CountPeriod = TIM1 -> ARR;
		volatile int CountVal = (int)(pDutyCycle * (T)CountPeriod);
		TIM1 -> CCR4 = CountVal;
		return;
	};

	static void InitPWM() {
		MX_TIM1_Init();

		SetPrescaler(0);
		SetCountPeriod(PWMCounter);

		SetUphaseDuty(0.5);
		SetVphaseDuty(0.5);
		SetWphaseDuty(0.5);
		SetADCTRGDuty(0.99);

		if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1) != HAL_OK)
		{
		Error_Handler();
		}
		if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2) != HAL_OK)
		{
		Error_Handler();
		}
		if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3) != HAL_OK)
		{
		Error_Handler();
		}

		//disableにすれば出力されない
		if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4) != HAL_OK)
		{
		Error_Handler();
		}

	};

	static void DeInitPWM() {
		TIMCtrl::SetUphaseDuty(0.5);
		TIMCtrl::SetVphaseDuty(0.5);
		TIMCtrl::SetWphaseDuty(0.5);
		HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
		HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
		HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
		HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_4);
		HAL_TIM_PWM_DeInit(&htim1);
	};

};

#endif /* SYSTEM_INC_TIMCTRL_HPP_ */
