void DrawTimeAttackStatus(int PlayTime){
	string TempString;

	SetFontType(S_FONT_LARGE, S_BLACK, S_BLACK, S_ALIGN_LEFT);
	MakeStr1(TempString, "현재 스테이지 : %d", Status_CurrentStage);
	DrawStr(20, 30, TempString);

	MakeStr1(TempString, "플레이 시간 : %d", PlayTime);
	DrawStr(20, 50, TempString);
}

void DrawTimeAttackContinue(int Selected){
	SetFontType(S_FONT_LARGE, S_BLACK, S_BLACK, S_ALIGN_CENTER);
	DrawStr(120, 150, "다음 스테이지로");
	DrawStr(120, 170, "그만 할래");
	SetColor(S_SKY);
	DrawRect(10, 145 + Selected * 20 + Scroll_ShowCounter
			, 230, 165 + Selected * 20 + Scroll_ShowCounter);

	return;
}