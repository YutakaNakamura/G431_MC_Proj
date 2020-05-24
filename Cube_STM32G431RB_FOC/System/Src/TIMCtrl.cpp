///*
// * TIMCtrl.cpp
// *
// *  Created on: 2020/05/23
// *      Author: watashi
// */
//
//#include "TIMCtrl.hpp"
//
//using namespace TIMCtrl;
//
//	void TIMCtrl::InitPWM() {
//		MX_TIM1_Init();
//
//		SetUphaseDuty(0.5);
//		SetVphaseDuty(0.5);
//		SetWphaseDuty(0.5);
//		SetADCTRGDuty(0.99);
//
//		if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1) != HAL_OK)
//		{
//		Error_Handler();
//		}
//		if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2) != HAL_OK)
//		{
//		Error_Handler();
//		}
//		if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3) != HAL_OK)
//		{
//		Error_Handler();
//		}
//
//		//disableにすれば出力されない
//		if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4) != HAL_OK)
//		{
//		Error_Handler();
//		}
//
//	};

//	void DeInitPWM() {
//		TIMCtrl::SetUphaseDuty(0.5);
//		TIMCtrl::SetVphaseDuty(0.5);
//		TIMCtrl::SetWphaseDuty(0.5);
//		HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
//		HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
//		HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_3);
//		HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_4);
//		HAL_TIM_PWM_DeInit(&htim1);
//	};

