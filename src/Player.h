/*
	PushStone전용 플레이어 관련
	by www.Ahyane.net ^^*
*/

struct Player{
	int X;
	int Y;
	int Direction;
	int Frame;
	int ScrollX;
	int ScrollY;
}UnitPlayer;

void SetPlayer(int In_X, int In_Y, int In_Direction){
	UnitPlayer.X = In_X;
	UnitPlayer.Y = In_Y;
	UnitPlayer.Direction = In_Direction;
	UnitPlayer.Frame = 0;
	UnitPlayer.ScrollX = 0;
	UnitPlayer.ScrollY = 0;
	return;
}

void ScrollPlayer(){
	if(UnitPlayer.ScrollX != 0 || UnitPlayer.ScrollY != 0){
		UnitPlayer.Frame = (UnitPlayer.Frame + 1) % 12;
	}

	if(UnitPlayer.ScrollX > 0){
		UnitPlayer.ScrollX -= D_PlayerSCU;
	}else if(UnitPlayer.ScrollX < 0){
		UnitPlayer.ScrollX += D_PlayerSCU;
	}

	if(UnitPlayer.ScrollY > 0){
		UnitPlayer.ScrollY -= D_PlayerSCU;
	}else if(UnitPlayer.ScrollY < 0){
		UnitPlayer.ScrollY += D_PlayerSCU;
	}
}

void DrawPlayer(int StartCellX, int StartCellY, int StageX, int StageY){
	int TempFrmae;
	
	switch(UnitPlayer.Direction){
		case D_Up:		TempFrmae = 0;break;
		case D_Down:	TempFrmae = 3;break;
		case D_Left:	TempFrmae = 6;break;
		case D_Right:	TempFrmae = 9;break;
	}
	
	switch(UnitPlayer.Frame / 3){
		case 1:		TempFrmae += 1;break;
		case 2:		TempFrmae += 2;break;
		case 3:		TempFrmae += 1;break;
	}

	CopyImage(UnitPlayer.ScrollX + (UnitPlayer.X - StartCellX) * Size_Connected + StageX
			, UnitPlayer.ScrollY + (UnitPlayer.Y - StartCellY) * Size_Connected + StageY
			, Img_Chara[TempFrmae]);
}