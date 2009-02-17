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
#define Menu_Normal		0
#define Menu_TimeAttack	1
#define Menu_Shop		2
#define Menu_Guide		3
#define Menu_Record		4
#define Menu_Option		5

//메뉴 갯수
#define MAXMainMenu		6

//-------------------- 진행 변수 정의 --------------------//
const string Str_MainMenuName[MAXMainMenu] = {
	"1 노멀 플레이",
	"2 타임 어택",
	"3 아이템 상점",
	"4 기록 보기",
	"5 도움말",
	"6 환경 설정"
};

//이전 게임 모드
//int HistoryMode = Game_Icon;

//메뉴 선택 번호
int Status_Select[3] = {0,0,0};

//진행 변수(애니매이션장면번호, 타이머시간, 각도, 투명도 등)
int Status_Value[6] = {0,0,0,0,0,0};

//배열(도형 등)
int Temp1[4];
int Temp2[4];

//진행 변수 초기화
void InitStatusValue(){
	//진행 변수
	Status_Value[0] = 0;
	Status_Value[1] = 0;
	Status_Value[2] = 0;
	Status_Value[3] = 0;
	Status_Value[4] = 0;
	Status_Value[5] = 0;
	//메뉴 선택 번호	
	Status_Select[0] = 0;
	Status_Select[1] = 0;
	Status_Select[2] = 0;
	return;
}

#include "TitleImages.sbm"
#include "SysShow.h"
#include "SysControl.h"

//화면 출력 구분
void DivGameShow(int SysData){
	switch(Status_GameMode){
		case Game_Init:
			SetTimer(40, 1);
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
	}
	return;
}