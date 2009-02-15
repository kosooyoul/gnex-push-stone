/*
	PushStone (2009.01.12.Thu ~ 2009.01.15)
	by www.Ahyane.net ^^*

# Making History
--------------------------------------------------------------------------------------
	No	Date		Memo
--------------------------------------------------------------------------------------
	01	2009.02.12	게임 분석, 구성요소 선언 및 정의
	02	2009.02.13	맵과 배치, 스테이지 구현 및 타이틀 화면 제작, 입체화 도형표시 적용
	03	2009.02.14	타이틀화면 구성 및 애니매이션 구현, 타이틀 화면 구성
>	04	2009.02.15	로고에서 타이틀까지 구현

	05	2009.02.16	게임 선택 화면 구현 및 게임 화면 디자인
	06	2009.02.17	게임 구현
	07	2009.02.18	게임 도움말 및 옵션 구현
	08	2009.02.19	다운 로드 및 테스트
	09	2009.02.20	

--------------------------------------------------------------------------------------
*/

///////////////////////////////////////////////////////////////////////////
// PressStone.mc - Auto Created by GNEX IDE
///////////////////////////////////////////////////////////////////////////

#ifdef _GVM
%{
	#DEFINE SCRIPTVER	2
	#DEFINE LCDCLASS	255
	#DEFINE IMAGETYPE	255
	#DEFINE AUDIOTYPE	255
	#DEFINE SCRIPTTYPE	1
	#DEFINE SCRIPTCPID	60000
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
	#DEFINE APPCPID		60000
	#DEFINE APPID		1
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
}

int DebugView = No;
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
	MakeStr1(Temp, "STT_VAL1 = %d", Status_Value1);
	DrawStr(10, 30, Temp);
	MakeStr1(Temp, "STT_VAL2 = %d", Status_Value2);
	DrawStr(10, 40, Temp);
	MakeStr1(Temp, "STT_VAL3 = %d", Status_Value3);
	DrawStr(10, 50, Temp);
	MakeStr1(Temp, "STT_VAL4 = %d", Status_Value4);
	DrawStr(10, 60, Temp);
	MakeStr1(Temp, "STT_VAL5 = %d", Status_Value5);
	DrawStr(10, 70, Temp);
	MakeStr1(Temp, "STT_SEL1 = %d", Status_Select1);
	DrawStr(130, 30, Temp);
	MakeStr1(Temp, "STT_SEL2 = %d", Status_Select2);
	DrawStr(130, 40, Temp);
	MakeStr1(Temp, "STT_SEL3 = %d", Status_Select3);
	DrawStr(130, 50, Temp);

	for(x = 0; x < MaxSizeX; x++){
		for(y = 0; y < MaxSizeY; y++){
			if(Place[y][x] > -1){
				MakeStr1(Temp, "%3d ", Place[y][x]);
				DrawStr(x * 11, y * 8 + 90, Temp);
			}
		}
	}

	return;
}