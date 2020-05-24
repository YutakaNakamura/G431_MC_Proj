/*
 * DebugCtrl.cpp
 *
 *  Created on: Aug 8, 2019
 *      Author: watashi
 */

#include "DebugCtrl.hpp"
#include <stdio.h>
#include <string.h>
#include <math.h>



DebugCtrl::DebugCtrl() {
	// TODO Auto-generated constructor stub
	mLogcount = 0;

	SEGGER_RTT_Init();
	SEGGER_RTT_ConfigUpBuffer(1, "JScope_I4I4I4I4I4I4", &mJS_RTT_UpBuffer[0], sizeof(mJS_RTT_UpBuffer), SEGGER_RTT_MODE_NO_BLOCK_SKIP);

	//	SEGGER_RTT_ConfigUpBuffer(1, "JScope_I4I4I4I4I4I4I4I4I4", &mJS_RTT_UpBuffer[0], sizeof(mJS_RTT_UpBuffer), SEGGER_RTT_MODE_NO_BLOCK_SKIP);
//	SEGGER_RTT_ConfigUpBuffer(1, "JScope_i2", &mJS_UpBUffer1[0], sizeof(mJS_UpBUffer1), SEGGER_RTT_MODE_NO_BLOCK_SKIP);
//	SEGGER_RTT_ConfigUpBuffer(2, "JScope_i2", &mJS_UpBUffer2[0], sizeof(mJS_UpBUffer2), SEGGER_RTT_MODE_NO_BLOCK_SKIP);
//	SEGGER_RTT_ConfigUpBuffer(3, "JScope_i2", &mJS_UpBUffer3[0], sizeof(mJS_UpBUffer3), SEGGER_RTT_MODE_NO_BLOCK_SKIP);
//	SEGGER_RTT_ConfigUpBuffer(4, "JScope_i2", &mJS_UpBUffer4[0], sizeof(mJS_UpBUffer4), SEGGER_RTT_MODE_NO_BLOCK_SKIP);
//	SEGGER_RTT_ConfigUpBuffer(5, "JScope_i2", &mJS_UpBUffer5[0], sizeof(mJS_UpBUffer5), SEGGER_RTT_MODE_NO_BLOCK_SKIP);
}

DebugCtrl::~DebugCtrl() {
	// TODO Auto-generated destructor stub
}



void DebugCtrl::RTTOutput(const MotorInfo<float> &pMotorInfo) {

	//namespace karma = boost::spirit::karma;

	std::array<float,3> Iuvw = pMotorInfo.GetIuvw();

	int milIu = (int)( Iuvw.at(0) * 1000 );
	int milIv = (int)( Iuvw.at(1) * 1000 );
	int milIw = (int)( Iuvw.at(2) * 1000 );

	std::array<float,2> Vgd = pMotorInfo.GetVganmadelta();
	int milVg = (int)(  Vgd.at(0) * 1000 );
	int milVd = (int)(  Vgd.at(1) * 1000 );
	mJScopeData.mLogCnt = mLogcount;
	mJScopeData.mIu = milIu;
	mJScopeData.mIv = milIv;
	mJScopeData.mIw = milIw;
	mJScopeData.mVg = milVg;
	mJScopeData.mVd = milVd;


////	int DegArg = (int)(pMotorInfo.mgdArg/M_PI * 180 );//指令値の角度
////	int DegAxiErr =(int)( pMotorInfo.mArgErr / M_PI *180 );
//	int EstOmega =(int)( pMotorInfo.mEstOmega );
//	int EstThetaDeg =(int)( pMotorInfo.mEstTheta/M_PI * 180 );
//
//	int milIa = (int)( pMotorInfo.GetIab().at(0) * 1000 );
//	int milIb = (int)( pMotorInfo.GetIab().at(1) * 1000 );
//
//	int milIg = (int)( pMotorInfo.mIgd.at(0) * 1000 );
//	int milId = (int)( pMotorInfo.mIgd.at(1) * 1000 );
//
//	int milVg = (int)( pMotorInfo.mVgd.at(0) * 1000 );
//	int milVd = (int)( pMotorInfo.mVgd.at(1) * 1000 );
//
//	//SVMdebug
//	int milVu = (int)(pMotorInfo.mDutyuvw.at(0) * 1000 );
//	int milVv = (int)(pMotorInfo.mDutyuvw.at(1) * 1000 );
//	int milVw = (int)(pMotorInfo.mDutyuvw.at(2) * 1000 );

//	int milIgTarget = (int)(pMotorInfo.mIgdTarget.at(0)*1000);

//	int milEstEMFg = (int)(mObserver.GetEstEMFgd().at(0) * 1000);
//	int milEstEMFd = (int)(mObserver.GetEstEMFgd().at(1) * 1000);

	//encoder
	//int encoder = (int)(EncoderABZCtrl::GetAngle()*(360.0f/(ENCODER_PERIOD+1)));

//	int milVh = (int)(pMotorInfo.mVh * 1000 );


	//高周波重畳デバッグ用

//	int milConvIdc = pMotorInfo.mConvIdqc.at(0) * 1000;
//	int milConvIqc = pMotorInfo.mConvIdqc.at(1) * 1000;
//
//	int milIdch = pMotorInfo.mIdqch.at(0) * 1000;
//	int milIqch = pMotorInfo.mIdqch.at(1) * 1000;

//	int milHFOmega = pMotorInfo.mEstOmega_HF * 1000;
//	int milObsOmega = pMotorInfo.mEstOmega_Observer * 1000;

	//



//	//40k安定
//	mJScopeData.mLogCnt = mLogcount;
//	mJScopeData.mIg = milIg;
//	mJScopeData.mId = milId;
//	mJScopeData.EstOmega = EstOmega;
//	mJScopeData.EstTheta = EstThetaDeg;

//	//20k転送だと安定 40kだとしんどい
//	mJScopeData.mLogCnt = mLogcount;
//	mJScopeData.mVg= milVg;
//	mJScopeData.mVd = milVd;
//	mJScopeData.mIa = milIa;
//	mJScopeData.mIb = milIb;
//	mJScopeData.mIg = milIg;
//	mJScopeData.mId = milId;
//	mJScopeData.EstOmega = EstOmega;
//	mJScopeData.EstTheta = EstThetaDeg;


//	mJScopeData.mLogCnt = mLogcount;
//	mJScopeData.mVg= milVg;
//	mJScopeData.mVd = milVd;
//	mJScopeData.mIu = milIu;
//	mJScopeData.mIv = milIv;
//	mJScopeData.mIw = milIw;
//	mJScopeData.mIa = milIa;
//	mJScopeData.mIb = milIb;
//	mJScopeData.EstTheta = EstThetaDeg;

//    char msg[] = "Hello world\n";
//    SEGGER_RTT_Write(0, msg, strlen(msg));
//
//    SEGGER_RTT_printf(0, "Hello world\n");

	SEGGER_RTT_Write(1, &mJScopeData, sizeof(mJScopeData));

	mOutputStr = "";

	mLogcount++;
	if(	mLogcount > 65535){
		mLogcount=0;
	}

}
