/*
 * MotorCtrlMain.cpp
 *
 *  Created on: 2020/05/23
 *      Author: watashi
 */

#include "MotorCtrlMain.hpp"

#include <array>

#include "ADCCtrl.hpp"
#include "TIMCtrl.hpp"
#include "InterruptHandler.hpp"

MotorCtrlMain::MotorCtrlMain() {
}

MotorCtrlMain::~MotorCtrlMain() {
	TIMCtrl::DeInitPWM();
}



void MotorCtrlMain::MotorCtrlInit() {
	TIMCtrl::InitPWM();
	ADCCtrl::InitADC();
};

#include <stdio.h>
#include "usart.h"



void MotorCtrlMain::MotorCtrl() {

	volatile int adc1 = ADCCtrl::GetUphaseADCVal();
	volatile int adc2 = ADCCtrl::GetVphaseADCVal();
	volatile int adc3 = ADCCtrl::GetWphaseADCVal();

	std::array<float,3> Iuvw;
	float VBus = 12;

	std::array<float,3> Vuvw;

	float input=0;
	Vuvw = mMotorController.Calculate(VBus,Iuvw,input);

	float Uduty = Vuvw[0];
	float Vduty = Vuvw[1];
	float Wduty = Vuvw[2];

	TIMCtrl::SetUphaseDuty(Uduty);
	TIMCtrl::SetVphaseDuty(Vduty);
	TIMCtrl::SetWphaseDuty(Wduty);

//		TIMCtrl::SetUphaseDuty(0.25);
//		TIMCtrl::SetVphaseDuty(0.5);
//		TIMCtrl::SetWphaseDuty(0.75);
//		TIMCtrl::SetADCTRGDuty(0.99);
//
//	  char buf[] = "■ADC interrupt\r\n";
//	  HAL_UART_Transmit(&hlpuart1, (uint8_t*)buf, sizeof(buf), 1000);
//
//
//	  char str[100] = {0};
//
//	  sprintf(str,"adc1：%d, adc2:%d, adc3:%d\r\n",adc1,adc2,adc3);
//	  HAL_UART_Transmit(&hlpuart1, (uint8_t*)str, sizeof(str), 1000);


};
