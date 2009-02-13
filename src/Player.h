struct Player{
	int X;
	int Y;
	int Direction;
	int Frame;
	int Scroll;
}UnitPlayer;

void DrawPlayer(int StageX, int StageY){
	CopyImage(UnitPlayer.X * 16 + StageX, UnitPlayer.Y * 16 + StageY, MapChip[4]);
}

void MovePlayer(int Direction){
	switch(Direction){
		case D_Up:
			if(IsMoveAbleCell(UnitPlayer.X, UnitPlayer.Y - 1) == Yes){
				UnitPlayer.Y--;
			}
			break;
		case D_Down:
			if(IsMoveAbleCell(UnitPlayer.X, UnitPlayer.Y + 1) == Yes){
				UnitPlayer.Y++;
			}
			break;
		case D_Left:
			if(IsMoveAbleCell(UnitPlayer.X - 1, UnitPlayer.Y) == Yes){
				UnitPlayer.X--;
			}
			break;
		case D_Right:
			if(IsMoveAbleCell(UnitPlayer.X + 1, UnitPlayer.Y) == Yes){
				UnitPlayer.X++;
			}
			break;
	}
	return;
}