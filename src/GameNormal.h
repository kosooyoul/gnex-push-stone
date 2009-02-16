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

//게임 메뉴출력
void DrawNormalMenu(int Selected){
	int i, j;

	for(i = 0; i < MaxNormalStage; i++){
		if(Selected != i){
			DrawStr(20, 50 + 20 * i, Str_NormalStageName[i]);
		}else{
			DrawStr(25, 50 + 20 * i, Str_NormalStageName[i]);
		}
		for(j = 0; j < 5;j++){
			if(Str_NormalStageStar[i] > j){
		 		DrawStr(170 + 10 * j, 50 + 20 * i, "★");
			}else{
				DrawStr(170 + 10 * j, 50 + 20 * i, "☆");
			}
		}
	}

	DrawRect(10, 45 + 20 * Selected, 230, 65 + 20 * Selected);
	
	return;	
}

//게임 미리보기
void DrawPreview(int Selected){
	SetColor(S_SKY);
	FillRectEx(10, 180, 230, 290, 2);
	DrawStr(20, 190, Str_NormalStageNote[Selected]);
}

//게임 시작화면
void DrawGameNormalStart(int Selected){
	int i;
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