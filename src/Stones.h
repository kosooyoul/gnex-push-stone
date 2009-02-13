#include "StoneImages.sbm"

#define S_Rect		0
#define S_Hexa		1
#define S_Star		2
#define S_Heart		3
#define S_Ball		4
#define S_Nailed	5

#define M_Wood		0
#define M_Stone		1
#define M_Iorn		2
#define M_Glass		3
#define M_Rubber	4
#define M_ETC		5

#define S_Hide		0
#define S_Fixed		1
#define S_In		2
#define S_Out		3
#define S_CoupIn	4
#define S_CoupOut	5

struct Stone{
	int Shape;		//모양 - 블럭 결합에 사용
	int Metrial;	//재질 - 제거하는데 사용
	int Power;		//힘 - 미는데 필요한 힘 비율
	int State;		//상태 - 숨김, 블럭, 자리고정, 홀, 겹침

	int X;			//셀좌표X
	int Y;			//셀좌표Y
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

void DrawStone(int Index, int StageX, int StageY){
	switch(UnitStone[Index].State){
		case S_CoupIn:
			CopyImage(StageX + UnitStone[Index].X * 16
			, StageY + UnitStone[Index].Y * 16
			, StoneCoupIn[GetStoneImageIndex(Index)]);
			break;
		case S_CoupOut:
			CopyImage(StageX + UnitStone[Index].X * 16
			, StageY + UnitStone[Index].Y * 16
			, StoneCoupOut[GetStoneImageIndex(Index)]);
			break;
		case S_In:
			CopyImage(StageX + UnitStone[Index].X * 16
			, StageY + UnitStone[Index].Y * 16
			, StoneIn[GetStoneImageIndex(Index)]);
			break;
		case S_Out:
		case S_Fixed:
			CopyImage(StageX + UnitStone[Index].X * 16
			, StageY + UnitStone[Index].Y * 16
			, StoneOut[GetStoneImageIndex(Index)]);
			break;
	}
	return;
}