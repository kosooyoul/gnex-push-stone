#define D_Up		0
#define D_Down		1
#define D_Left		2
#define D_Right		3

#define No			0
#define Yes			1

#include "Stones.h"
#include "Maps.h"
#include "Places.h"
#include "Player.h"

struct Stage{
	int StartX;
	int StartY;

	int StartCellX;
	int StartCellY;
	int SizeCellX;
	int SizeCellY;
}UnitStage[3];

void SetStage(int Index){
	return;
}

void DrawStage(int Index){
	return;
}

int IsMoveAbleCell(int In_X, int In_Y){
	if(Map[In_Y][In_X] > D_MoveAble && Place[In_Y][In_X] == -1){
		return Yes;
	}else{
		return No;
	}
}

void MoveStone(int Index, int Direction){
	switch(Direction){
		case D_Up:
			if(IsMoveAbleCell(UnitStone[Index].X, UnitStone[Index].Y - 1) == Yes){
				UnitStone[Index].Y--;
			}
			break;
		case D_Down:
			if(IsMoveAbleCell(UnitStone[Index].X, UnitStone[Index].Y + 1) == Yes){
				UnitStone[Index].Y++;
			}
			break;
		case D_Left:
			if(IsMoveAbleCell(UnitStone[Index].X - 1, UnitStone[Index].Y) == Yes){
				UnitStone[Index].X--;
			}
			break;
		case D_Right:
			if(IsMoveAbleCell(UnitStone[Index].X + 1, UnitStone[Index].Y) == Yes){
				UnitStone[Index].X++;
			}
			break;
	}
	return;
}