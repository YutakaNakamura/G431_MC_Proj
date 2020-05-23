/*
 * InterruptHandler.hpp
 *
 *  Created on: 2020/05/22
 *      Author: watashi
 */

#ifndef SYSTEM_INC_INTERRUPTHANDLER_HPP_
#define SYSTEM_INC_INTERRUPTHANDLER_HPP_

class InterruptHandler final{
private:
	InterruptHandler() = default;
	~InterruptHandler() = default;
public:
	InterruptHandler(const InterruptHandler&) = delete;
	InterruptHandler& operator=(const InterruptHandler&) = delete;
	InterruptHandler(InterruptHandler&&) = delete;
	InterruptHandler& operator=(InterruptHandler&&) = delete;

	static InterruptHandler& GetInstance() {
		static InterruptHandler instance;
		return instance;
	}

private:
	//Handler格納
	void (*mADCInterruptFunc)();

public:
	void SetADCCpltInterrptFunc( void(*pADCInterruptFunc)() ) {
		mADCInterruptFunc = pADCInterruptFunc;
	};

	void ADCCpltFunc() {
		mADCInterruptFunc();
	}

};

#endif /* SYSTEM_INC_INTERRUPTHANDLER_HPP_ */
