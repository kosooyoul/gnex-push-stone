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
	#DEFINE SCRIPTNAME	"PressStone GVM2X App"
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
	#DEFINE APPNAME		"PressStone GNEX App"
	#DEFINE COMPTYPE	0
	#DEFINE AGENTTYPE	0
	#DEFINE VALIDCOUNT	255
	#DEFINE VALIDTERM	255
	#DEFINE DIRECTRUN	0
	#DEFINE APPVER		1
%}
#endif

#include <SScript.h>
#include "Stages.h"

int ScrollX = 0;
int ScrollY = 0;

void main(){
	SetTimer(30, 1);
	return;
}

void EVENT_TIMEOUT(){
	ClearBlack();
	
	DrawMap(0, 0, 10, 10, ScrollX + 2 * 16, ScrollY + 2 * 16);
	DrawPlayer(ScrollX + 2 * 16, ScrollY + 2 * 16);
	Flush();

}

void EVENT_KEYPRESS(){
	switch(swData){
		case SWAP_KEY_UP:
			MovePlayer(D_Up);
			break;
		case SWAP_KEY_DOWN:
			MovePlayer(D_Down);
			break;
		case SWAP_KEY_LEFT:
			MovePlayer(D_Left);
			break;
		case SWAP_KEY_RIGHT:
			MovePlayer(D_Right);
			break;
	}
}