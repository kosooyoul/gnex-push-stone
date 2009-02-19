/*
	PushStone전용 돌덩이 배치 관련
	by www.Ahyane.net ^^*
*/

int Place[MaxPlaceSizeY][MaxPlaceSizeX];

void InitPlace(){
	int x, y;
	for(x = 0; x < MaxPlaceSizeX; x++){
		for(y = 0; y < MaxPlaceSizeY; y++){
			Place[y][x] = Null;
		}
	}
}

void SetPlace(int Index, int In_X, int In_Y){
	Place[In_Y - UnitStage[Status_CurrentStage].StartCellY][In_X - UnitStage[Status_CurrentStage].StartCellX] = Index;
	return;
}

int GetCurrentPlace(int In_X, int In_Y){
	if(In_X - UnitStage[Status_CurrentStage].StartCellX > MaxPlaceSizeX
	|| In_Y - UnitStage[Status_CurrentStage].StartCellY > MaxPlaceSizeY) return ERROR;
	return Place[In_Y - UnitStage[Status_CurrentStage].StartCellY][In_X - UnitStage[Status_CurrentStage].StartCellX];
}

int GetPlace(int In_X, int In_Y, int Direction){
	switch(Direction){
		case D_Up:
			if(In_Y - 1 < UnitStage[Status_CurrentStage].StartCellY) return Null;
			return GetCurrentPlace(In_X - UnitStage[Status_CurrentStage].StartCellX, In_Y - 1 - UnitStage[Status_CurrentStage].StartCellY);
		case D_Down:
			if(In_Y + 1 >= MaxPlaceSizeY + UnitStage[Status_CurrentStage].StartCellY) return Null;
			return GetCurrentPlace(In_X - UnitStage[Status_CurrentStage].StartCellX, In_Y + 1 - UnitStage[Status_CurrentStage].StartCellY);
		case D_Left:
			if(In_X - 1 < UnitStage[Status_CurrentStage].StartCellX) return Null;
			return GetCurrentPlace(In_X - 1 - UnitStage[Status_CurrentStage].StartCellX, In_Y - UnitStage[Status_CurrentStage].StartCellY);
		case D_Right:
			if(In_X + 1 >= MaxPlaceSizeX + UnitStage[Status_CurrentStage].StartCellX) return Null;
			return GetCurrentPlace(In_X + 1 - UnitStage[Status_CurrentStage].StartCellX, In_Y - UnitStage[Status_CurrentStage].StartCellY);
		default:
			return Null;
	}
}