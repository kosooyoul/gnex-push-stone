/*
	PushStone (2009.01.12.Thu ~ 2009.01.18)
	by www.Ahyane.net ^^*

# Making History
--------------------------------------------------------------------------------------
	No	Date		Memo
--------------------------------------------------------------------------------------
	01	2009.02.12	게임 분석, 구성요소 선언 및 정의
	02	2009.02.13	맵과 배치, 스테이지 구현 및 타이틀 화면 제작, 입체화 도형표시 적용
	03	2009.02.14	타이틀화면 구성 및 애니매이션 구현, 타이틀 화면 구성
	04	2009.02.15	로고에서 타이틀까지 구현 -> 다운로드 테스트(속도가 느렸음)
	05	2009.02.16	게임 선택 메뉴, 일반모드/타임어택 모드 구현(타이틀까지 속도 조절)
	06	2009.02.17	선택 메뉴 수정, 각 모드 별 뼈대 및 그래픽 적용 작업
>	07	2009.02.18	게임플레이 전까지 그래픽 작업, 게임 구성 수정

	08	2009.02.19	맵칩제작 및 점수보기 구현, 상세 게임과 상점 구현
	09	2009.02.20	상세 게임 구현 완료 및 게임 도움말과 옵션 구현, 다운 로드 테스트
	10	2009.02.21	배포ㅋㅋ 꿈이 야무지구나!!ㅋㅋ(상용화 문의!! 가능해!!)

--------------------------------------------------------------------------------------
*/

///////////////////////////////////////////////////////////////////////////
// PushStone.mc - Auto Created by GNEX IDE
///////////////////////////////////////////////////////////////////////////

#ifdef _GVM
%{
	#DEFINE SCRIPTVER	2
	#DEFINE LCDCLASS	255
	#DEFINE IMAGETYPE	255
	#DEFINE AUDIOTYPE	255
	#DEFINE SCRIPTTYPE	1
	#DEFINE SCRIPTCPID	19732
	#DEFINE SCRIPTID	1
	#DEFINE SCRIPTNAME	"PushStone♡1"
	#DEFINE VALIDCOUNT	255
	#DEFINE VALIDTERM	255
%}
#else
%{
	#DEFINE PLAYERVER	4
	#DEFINE LCDCLASS	255
	#DEFINE IMAGETYPE	255
	#DEFINE AUDIOTYPE	255
	#DEFINE APPTYPE		1
	#DEFINE APPCPID		19732
	#DEFINE APPID		10216
	#DEFINE APPNAME		"PushStone♡1"
	#DEFINE COMPTYPE	0
	#DEFINE AGENTTYPE	0
	#DEFINE VALIDCOUNT	255
	#DEFINE VALIDTERM	255
	#DEFINE DIRECTRUN	0
	#DEFINE APPVER		1
%}
#endif

#include <SScript.h>
#include "Define.h"
#include "Colors.h"
#include "Effects.h"
#include "System.h"
#include "Option.h"
#include "Status.h"
#include "Stages.h"

void main(){
	DivGameShow(Null);
	return;
}

void EVENT_TIMEOUT(){
	DivGameShow(swData);
	if(DebugView == Yes) Debug();
	Flush();
}

void EVENT_KEYPRESS(){
	DivGameControl(swData);
	if(swData == SWAP_KEY_SHARP) DebugView = DebugView? No : Yes;
	if(swData == SWAP_KEY_STAR){INT_MAX = INT_MAX << 1;BIT++;}

}

int DebugView = No;int BIT = 1;int INT_MAX = 0x01;
void Debug(){
	string Temp;
	int x, y;
	
	SetColor(S_MOON);
	FillRectEx( 5,  5, 235, 285, 2);
	SetColor(S_WHITE);
	FillRectEx( 8,  8, 232,  82, 2);
	FillRectEx( 8, 88, 232, 282, 2);

	SetFontType(S_FONT_MEDIUM, S_BLACK, S_BLACK, S_ALIGN_CENTER);
	DrawStr(120, 10, "--------------[ Debug ]--------------");
	SetFontType(S_FONT_MEDIUM, S_BLACK, S_BLACK, S_ALIGN_LEFT);
	MakeStr2(Temp, "Unit.X = %d, Unit.Y = %d", UnitReturnPosition.X, UnitReturnPosition.Y);
	DrawStr(10, 20, Temp);
	MakeStr1(Temp, "STT_VAL1 = %d", Status_Value[0]);
	DrawStr(10, 30, Temp);
	MakeStr1(Temp, "STT_VAL2 = %d", Status_Value[1]);
	DrawStr(10, 40, Temp);
	MakeStr1(Temp, "STT_VAL3 = %d", Status_Value[2]);
	DrawStr(10, 50, Temp);
	MakeStr1(Temp, "STT_VAL4 = %d", Status_Value[3]);
	DrawStr(10, 60, Temp);
	MakeStr1(Temp, "STT_VAL5 = %d", Status_Value[4]);
	DrawStr(10, 70, Temp);
	MakeStr1(Temp, "STT_SEL1 = %d", Status_Select[0]);
	DrawStr(130, 30, Temp);
	MakeStr1(Temp, "STT_SEL2 = %d", Status_Select[1]);
	DrawStr(130, 40, Temp);
	MakeStr1(Temp, "CurrentStage = %d", Status_CurrentStage);
	DrawStr(130, 50, Temp);
	MakeStr2(Temp, "INT_MAX = %d, BIT = %d", INT_MAX, BIT);
	DrawStr(10, 80, Temp);

	for(x = 0; x < MaxPlaceSizeX; x++){
		for(y = 0; y < MaxPlaceSizeY; y++){
			if(Place[y][x] > -1){
				MakeStr1(Temp, "%3d ", Place[y][x]);
				DrawStr(x * 11, y * 8 + 90, Temp);
			}
		}
	}

	return;
}
