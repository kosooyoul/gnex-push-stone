/*
	PushStone전용 돌덩이 관련
	by www.Ahyane.net ^^*
*/

#include "StoneImages.sbm"

struct Stone{
	int Shape;		//모양 - 블럭 결합에 사용
	int Metrial;	//재질 - 제거하는데 사용
	int Power;		//힘 - 미는데 필요한 힘 비율
	int State;		//상태 - 숨김, 블럭, 자리고정, 홀, 겹침

	int X;
	int Y;
	int ScrollX;
	int ScrollY;
}UnitStone[20];

void SetStone(int Index, int In_Shape, int In_Metrial, int In_Power, int In_State, int In_X, int In_Y){
	UnitStone[Index].Shape = In_Shape;
	UnitStone[Index].Metrial = In_Metrial;
	UnitStone[Index].Power = In_Power;
	UnitStone[Index].State = In_State;
	UnitStone[Index].X = In_X;
	UnitStone[Index].Y = In_Y;
	return;
}

int GetStoneImageIndex(int Index){
	return UnitStone[Index].Shape + UnitStone[Index].Metrial * 5;
}

void ScrollStone(int Index){
	if(UnitStone[Index].ScrollX > 0){
		UnitStone[Index].ScrollX -= UnitStone[Index].ScrollX / D_StoneSCU+1 ;
	}else if(UnitStone[Index].ScrollX < 0){
		UnitStone[Index].ScrollX -= UnitStone[Index].ScrollX / D_StoneSCU-1 ;
	}

	if(UnitStone[Index].ScrollY > 0){
		UnitStone[Index].ScrollY -= UnitStone[Index].ScrollY / D_StoneSCU+1 ;
	}else if(UnitStone[Index].ScrollY < 0){
		UnitStone[Index].ScrollY -= UnitStone[Index].ScrollY / D_StoneSCU-1 ;
	}
}

void DrawStone(int Index, int CellX, int CellY, int StageX, int StageY){
	switch(UnitStone[Index].State){
		case S_CoupIn:
			CopyImage(StageX + (UnitStone[Index].X - CellX) * 16
					, StageY + (UnitStone[Index].Y - CellY) * 16
					, StoneCoupIn[GetStoneImageIndex(Index)]);
			break;
		case S_CoupOut:
			CopyImage(StageX + (UnitStone[Index].X - CellX) * 16
					, StageY + (UnitStone[Index].Y - CellY) * 16
					, StoneCoupOut[GetStoneImageIndex(Index)]);
			break;
		case S_In:
			CopyImage(StageX + (UnitStone[Index].X - CellX) * 16
					, StageY + (UnitStone[Index].Y - CellY) * 16
					, StoneIn[GetStoneImageIndex(Index)]);
			break;
		case S_Fixed:
			CopyImage(StageX + (UnitStone[Index].X - CellX) * 16
					, StageY + (UnitStone[Index].Y - CellY) * 16
					, StoneOut[0]);
			break;
		case S_Out:
			CopyImage(UnitStone[Index].ScrollX + StageX + (UnitStone[Index].X - CellX) * 16
					, UnitStone[Index].ScrollY + StageY + (UnitStone[Index].Y - CellY) * 16
					, StoneOut[0]);
			break;
	}
	return;
}