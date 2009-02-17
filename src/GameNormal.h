//최대 노멀 스테이지의 갯수
#define MaxNormalStage	6

//스테이지 번호
const int Str_NormalStageNumber[MaxNormalStage] = {0, 1, 2, 3, 4, 5};

//스테이지 난이도
const int Str_NormalStageStar[MaxNormalStage] = {2, 3, 5, 4, 2, 2};

//스테이지 이름
const string Str_NormalStageName[MaxNormalStage] = {
	"징검다리 건너기",
	"학교 소풍 보물 찾기",
	"군대 재설 작업",
	"아파트 앞 쓰레기장",
	"원시인 석빙고",
	"교실 청소 시간"
};

//스테이지 도움말
const string Str_NormalStageNote[MaxNormalStage] = {
	"돌을 빠트려 길을 만들어 나가요",
	"돌 사이에 숨겨진 보물들을 찾아요",
	"군인 아저씨와 같이 눈을 치워요",
	"더러운 쓰레기통에서 빠져나와요",
	"어떤 음식이 있을까 찾아요",
	"어질러졌어요! 청소도구를 가져와요"
};

void InitPlayNormalGame(int Selected){
	SetStage(0, 2, 3, 0, 0, 13, 11);	//14 * 12 사이즈가 최적임
	Status_CurrentStage = 0;
	StartStage(0);
	SetTimer(50, 1);
	return;
}

void DrawPlayNormalGame(int Selected){
	DrawStage(Selected
			, (MaxMapOptimalSizeX - (UnitStage[Selected].EndCellX - UnitStage[Selected].StartCellX)) * 8
			, (MaxMapOptimalSizeY - (UnitStage[Selected].EndCellY - UnitStage[Selected].StartCellY)) * 8 + Size_TwoHalf);
	if(Status_Moving == Yes){
		Status_MoveSuccess = MovePlayer(Status_MovingDirection);
	}
	return;
}

void ControlPlayNormalGame(int SysData){
	if((Status_MovingDirection == SysData && Option_AutoPush == Yes && Status_MoveSuccess == No)
	|| SysData == SWAP_KEY_OK){
		PushStone();
		return;
	}
	if(SysData == SWAP_KEY_RELEASE){
		Status_Moving = No;
		return;
	}else{
		switch(SysData){
			case SWAP_KEY_UP:
			case SWAP_KEY_DOWN:
			case SWAP_KEY_LEFT:
			case SWAP_KEY_RIGHT:
				Status_Moving = Yes;
				Status_MovingDirection = SysData;
				Status_MoveSuccess = MovePlayer(Status_MovingDirection);
				break;
			case SWAP_KEY_OK:
				Status_MovingDirection = Null;
				PushStone();
				break;
		}
	}
	return;
}

//게임 메뉴출력
void DrawNormalMenu(int Selected){
	int i, j;

	SetColor(S_MOON);	
	FillRectEx(10, 45 + 20 * Selected + Scroll_ShowCounter, 210, 65 + 20 * Selected + Scroll_ShowCounter, 2);

	SetFontType(S_FONT_LARGE, S_BLACK, S_BLACK, S_ALIGN_LEFT);
	for(i = 0; i < MaxNormalStage; i++){
		if(Selected != i){
			DrawStr(20, 50 + 20 * i, Str_NormalStageName[i]);
		}else{
			DrawStr(25, 50 + 20 * i, Str_NormalStageName[i]);
		}
		for(j = 0; j < 5;j++){
			if(Str_NormalStageStar[i] > j){
		 		DrawStr(150 + 10 * j, 50 + 20 * i, "★");
			}else{
				DrawStr(150 + 10 * j, 50 + 20 * i, "☆");
			}
		}
	}

	SetColor(S_ROSE);
	DrawRect(10, 45 + 20 * Selected + Scroll_ShowCounter, 210, 65 + 20 * Selected + Scroll_ShowCounter);
	
	return;	
}

//게임 미리보기
void DrawPreview(int Selected){
	SetFontType(S_FONT_LARGE, S_BLACK, S_BLACK, S_ALIGN_LEFT);
	DrawStr(20, 200, Str_NormalStageNote[Selected]);
}

//게임 시작화면 및 준비
void DrawGameNormalReady(int Selected){
	int i;
	
	SetFontType(S_FONT_LARGE, S_BLACK, S_BLACK, S_ALIGN_LEFT);
	DrawStr(10, 30, Str_NormalStageName[Selected]);
	for(i = 0; i < 5;i++){
		if(Str_NormalStageStar[Selected] > i){
			DrawStr(30 + 10 * i, 50, "★");
		}else{
			DrawStr(30 + 10 * i, 50, "☆");
		}
	}
	DrawStr(10, 70, Str_NormalStageNote[Selected]);
}