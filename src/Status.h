/*
	PushStone전용 게임 상태 관련
	by www.Ahyane.net ^^*
*/

//-------------------- 메모리 저장 됨 --------------------//
//열린 케릭터
//int Status_OpenedChara = 3;		//LSB:1100_0000_00XX_XXXX-XXXX_XXXX_XXXX:MSB

//진행한 여행모드
//int Status_CurrentTravel = 0;	//LSB:0000_0000_0000_0000-0000_0000_0000:MSB

//열린 일반모드 스테이지
int Status_OpenedStage = 1;		//LSB:1000_0000_0000_0000-0000_0000_0000:MSB

//소지 아이템
//int Status_PlayerItem = 0;		//LSB:0000_????_XXXX_XXXX-XXXX_XXXX_XXXX:MSB

//구입가능한 아이템
//int Status_BuyableItem = 0;		//LSB:00??_????_????_????-????_????_????:MSB

//소지 포인트 달의 조각
//int Status_Point = 500;			//MAX



//-------------------- 메모리저장안됨 --------------------//
//게임 모드
int Status_GameMode = Game_Init;

//선택한 케릭터
//int Status_SelectedChara = 0;

//현재 이동 방향
int Status_MovingDirection = Null;
int Status_Moving = No;

//개체 이동 성공했는지
int Status_MoveSuccess = No;

//현재 실행중 스테이지 레벨
int Status_CurrentStage = 0;