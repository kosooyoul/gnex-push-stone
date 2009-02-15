/*
	PushStone전용 돌덩이 배치 관련
	by www.Ahyane.net ^^*
*/

int Place[MaxSizeY][MaxSizeX];

void InitPlace(){
	int x, y;
	for(x = 0; x < MaxSizeX; x++){
		for(y = 0; y < MaxSizeY; y++){
			Place[y][x] = Null;
		}
	}
}

void SetPlace(int Index, int In_X, int In_Y){
	Place[In_Y][In_X] = Index;
	return;
}

int GetPlace(int In_X, int In_Y, int Direction){
	switch(Direction){
		case D_Up:
			if(In_Y - 1 < 0) return Null;
			return Place[In_Y - 1][In_X];
		case D_Down:
			if(In_Y + 1 >= MaxSizeY) return Null;
			return Place[In_Y + 1][In_X];
		case D_Left:
			if(In_X - 1 < 0) return Null;
			return Place[In_Y][In_X - 1];
		case D_Right:
			if(In_X + 1 >= MaxSizeX) return Null;
			return Place[In_Y][In_X + 1];
		default:
			return Null;
	}
}