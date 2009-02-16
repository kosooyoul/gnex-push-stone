void DrawTimeAttackStatus(int StageNumber, int PlayTime){
	string TempString;

	MakeStr1(TempString, "현재 스테이지 : %d", StageNumber);
	DrawStr(20, 30, TempString);

	MakeStr1(TempString, "플레이 시간 : %d", PlayTime);
	DrawStr(20, 50, TempString);
}