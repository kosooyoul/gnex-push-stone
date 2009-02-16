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
	CopyImage(UnitPlayer.ScrollX + (UnitPlayer.X - StartCellX) * 16 + StageX
			, UnitPlayer.ScrollY + (UnitPlayer.Y - StartCellY) * 16 + StageY
			, MapChip[4]);
}