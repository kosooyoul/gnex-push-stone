/*
	PushStone전용 게임 상태 관련
	by www.Ahyane.net ^^*
*/

//게임 모드
int Status_GameMode = Game_Init;
int Status_OpenedChara = 3;		//LSB:1100_0000_00XX_XXXX:MSB
int Status_SelectedChara = 0;	//    ^

//현재 이동 방향
int Status_MovingDirection = Null;

//현재 실행중 스테이지 레벨
int Status_CurrentStage = 0;

//개체 이동 성공했는지
int Status_MoveSuccess = No;