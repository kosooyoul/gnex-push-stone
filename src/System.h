/*
	PushStone화면 출력 및 키입력 제어
	by www.Ahyane.net ^^*
*/

//-------------------- 변경 예정 정의 --------------------//
//게임 모드
#define Game_Init		-1
#define Game_Icon		0
#define Game_Title		1
#define Game_SelectPart	2

#define Game_Travel		111
#define Game_Normal		112
#define Game_TimeAttack	113
#define Game_Shop		114
#define Game_Guide		12
#define Game_Record		13
#define Game_Option		14

#define Game_Stage		201
#define Game_GameMenu	210
#define Game_Status		2100
#define Game_UseItem	2101
#define Game_UseTarget	21010
#define Game_GameReset	2102
#define Game_GotoSelect	2103
#define Game_GotoMenu	2104
#define Game_GameExit	2105
#define Game_StageClear	22
#define Game_GameOver	23
#define Game_GameFinish	24
#define Game_Network	3
#define Game_UpRank		30
#define Game_DownRank	31

//선택 게임 메뉴
//메뉴 종류 0
#define Menu_Main		0
#define Menu_Start		0
#define Menu_Guide		1
#define Menu_Record		2
#define Menu_Option		3
//메뉴 종류 1
#define Menu_SubStart	1
#define Menu_Travel		0
#define Menu_Normal		1
#define Menu_TimeAttack	2
#define Menu_Shop		3

//-------------------- 진행 변수 정의 --------------------//
//이전 게임 모드
int HistoryMode = Game_Icon;

//메뉴 선택 번호
int Status_Select1 = 0;
int Status_Select2 = 0;
int Status_Select3 = 0;

//진행 변수(애니매이션장면번호, 타이머시간, 각도, 투명도 등)
int Status_Value1 = 0;
int Status_Value2 = 0;
int Status_Value3 = 0;
int Status_Value4 = 0;
int Status_Value5 = 0;

//배열(도형 등)
int Temp1[4];
int Temp2[4];

//진행 변수 초기화
void InitStatusValue(){
	//진행 변수
	Status_Value1 = 0;
	Status_Value2 = 0;
	Status_Value3 = 0;
	Status_Value4 = 0;
	Status_Value5 = 0;
	//메뉴 선택 번호	
	Status_Select1 = 0;
	Status_Select2 = 0;
	Status_Select3 = 0;
	return;
}

#include "TitleImages.sbm"
#include "SysShow.h"
#include "SysControl.h"

//화면 출력 구분
void DivGameShow(int SysData){
	switch(Status_GameMode){
		case Game_Init:
			SetTimer(20, 1);
			Status_GameMode = Game_Icon;
			break;

		case Game_Icon:
			ShowIcon();
			break;

		case Game_Title:
			ShowTitle();
			break;

		case Game_SelectPart:
			ShowSelectPart();
			break;

		case Game_Travel:
			ShowTravel();
			break;

		case Game_Normal:
			ShowNormal();
			break;

		case Game_TimeAttack:
			ShowTimeAttack();
			break;

		case Game_Shop:
			ShowShop();
			break;

		case Game_Guide:
			ShowGuide();
			break;

		case Game_Record:
			ShowRecord();
			break;

		case Game_Option:
			ShowOption();
			break;

		//
		case Game_Stage:
			ShowStage();
			break;

		default:
			ShowStage();
		
	}
	return;
}

//키입력 제어 구분
void DivGameControl(int SysData){
	switch(Status_GameMode){
		case Game_Icon:
			ControlIcon(SysData);
			break;

		case Game_Title:
			ControlTitle(SysData);
			break;

		case Game_SelectPart:
			ControlSelectPart(SysData);
			break;

		case Game_Travel:
			ControlTravel(SysData);
			break;

		case Game_Normal:
			ControlNormal(SysData);
			break;

		case Game_TimeAttack:
			ControlTimeAttack(SysData);
			break;

		case Game_Shop:
			ControlShop(SysData);
			break;

		case Game_Guide:
			ControlGuide(SysData);
			break;

		case Game_Record:
			ControlRecord(SysData);
			break;

		case Game_Option:
			ControlOption(SysData);
			break;

		//
		case Game_Stage:
			ControlStage(SysData);
			break;

		default:
			ControlStage(SysData);
	}
	return;
}