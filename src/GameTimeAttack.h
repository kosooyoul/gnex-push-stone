void DrawTimeAttackStatus(int PlayTime){
	string TempString;

	SetFontType(S_FONT_LARGE, S_WHITE, S_BLACK, S_ALIGN_RIGHT);
	MakeStr1(TempString, "시간 %d", PlayTime);
	DrawStr(225, 15, TempString);
}