/*
	PushStone전용 스테이지 관련 - 돌덩이, 맵, 배치, 플레이어 포함
	by www.Ahyane.net ^^*
*/

#include "Stones.h"
#include "Maps.h"
#include "Places.h"
#include "Player.h"

struct Stage{
	//게임 시작위치
	int StartX;
	int StartY;
	//스테이지 맵 범위
	int StartCellX;
	int StartCellY;
	int EndCellX;
	int EndCellY;
}UnitStage[6];

void SetStage(int Index, int In_StartX, int In_StartY, int In_StartCellX, int In_StartCellY, int In_EndCellX, int In_EndCellY){
	UnitStage[Index].StartX = In_StartX;
	UnitStage[Index].StartY = In_StartY;
	UnitStage[Index].StartCellX = In_StartCellX;
	UnitStage[Index].StartCellY = In_StartCellY;
	UnitStage[Index].EndCellX = In_EndCellX;
	UnitStage[Index].EndCellY = In_EndCellY;
	return;
}

void StartStage(int Index){
	InitPlace();
	SetStone(0, S_Rect, M_Wood, 50, S_Out, 4, 9);
	SetStone(1, S_Rect, M_Wood, 50, S_Out, 3, 7);
	SetStone(2, S_Rect, M_Wood, 50, S_Out, 3, 4);
	SetStone(3, S_Rect, M_Wood, 50, S_Out, 7, 9);
	SetStone(4, S_Rect, M_Wood, 50, S_Out, 6, 7);

	SetPlace(0, 4, 9);
	SetPlace(1, 3, 7);
	SetPlace(2, 3, 4);
	SetPlace(3, 7, 9);
	SetPlace(4, 6, 7);
	UnitPlayer.X = UnitStage[Index].StartX;
	UnitPlayer.Y = UnitStage[Index].StartY;
}

void DrawStage(int Index, int StageScrollX, int StageScrollY){
	int x, y;
	//맵 출력
	DrawMap(UnitStage[Index].StartCellX, UnitStage[Index].StartCellY,
			UnitStage[Index].EndCellX, UnitStage[Index].EndCellY, StageScrollX, StageScrollY);

	//돌덩이와 플레이어 출력
	for(x = UnitStage[Index].StartCellX; x <= UnitStage[Index].EndCellX; x++){
		for(y = UnitStage[Index].StartCellY; y <= UnitStage[Index].EndCellY; y++){
			if(GetCurrentPlace(x, y) == Null){
				if(UnitPlayer.Y == y && UnitPlayer.X == x){
					ScrollPlayer();
					DrawPlayer(UnitStage[Index].StartCellX, UnitStage[Index].StartCellY, StageScrollX, StageScrollY);
				}
			}else{
				ScrollStone(GetCurrentPlace(x, y));
				DrawStone(GetCurrentPlace(x, y), UnitStage[Index].StartCellX, UnitStage[Index].StartCellY, StageScrollX, StageScrollY);
			}
		}
	}
	return;
}

int IsMoveAbleCell(int In_X, int In_Y){
	if(Map[In_Y][In_X] > D_MoveAble && GetCurrentPlace(In_X, In_Y) == -1
	&& In_Y >= 0 && In_Y < MaxSizeY	&& In_X >= 0 && In_X < MaxSizeX){
		if(UnitStage[Status_CurrentStage].StartCellX <= In_X && UnitStage[Status_CurrentStage].EndCellX >= In_X
		&& UnitStage[Status_CurrentStage].StartCellY <= In_Y && UnitStage[Status_CurrentStage].EndCellY >= In_Y){
			return Yes;
		}else{
			return Null;
		}
	}else{
		return No;
	}
}

int MoveStone(int Index, int Direction){
	if(UnitStone[Index].ScrollX || UnitStone[Index].ScrollY) return Null;

	switch(Direction){
		case D_Up:
			switch(IsMoveAbleCell(UnitStone[Index].X, UnitStone[Index].Y - 1)){
				case Yes:
					ReplacePlace(Index, UnitStone[Index].X, UnitStone[Index].Y
								, UnitStone[Index].X, UnitStone[Index].Y - 1);
					UnitStone[Index].Y--;
					UnitStone[Index].ScrollY = D_StoneSCM;
					return Yes;
				case No:
					return No;
				default:
					return Null;
			}

		case D_Down:
			switch(IsMoveAbleCell(UnitStone[Index].X, UnitStone[Index].Y + 1)){
				case Yes:
					ReplacePlace(Index, UnitStone[Index].X, UnitStone[Index].Y
								, UnitStone[Index].X, UnitStone[Index].Y + 1);
					UnitStone[Index].Y++;
					UnitStone[Index].ScrollY = -D_StoneSCM;
					return Yes;
				case No:
					return No;
				default:
					return Null;
			}

		case D_Left:
			switch(IsMoveAbleCell(UnitStone[Index].X - 1, UnitStone[Index].Y)){
				case Yes:
					ReplacePlace(Index, UnitStone[Index].X, UnitStone[Index].Y
								, UnitStone[Index].X - 1, UnitStone[Index].Y);
					UnitStone[Index].X--;
					UnitStone[Index].ScrollX = D_StoneSCM;
					return Yes;
				case No:
					return No;
				default:
					return Null;
			}

		case D_Right:
			switch(IsMoveAbleCell(UnitStone[Index].X + 1, UnitStone[Index].Y)){
				case Yes:
					ReplacePlace(Index, UnitStone[Index].X, UnitStone[Index].Y
								, UnitStone[Index].X + 1, UnitStone[Index].Y);
					UnitStone[Index].X++;
					UnitStone[Index].ScrollX = -D_StoneSCM;
					return Yes;
				case No:
					return No;
				default:
					return Null;
			}
		default:
			return Null;
	}
}

void SetPlayerDirection(int Direction){
	UnitPlayer.Direction = Direction;
}

int MovePlayer(int Direction){
	if(UnitPlayer.ScrollX || UnitPlayer.ScrollY) return Null;

	SetPlayerDirection(Direction);

	switch(Direction){
		case D_Up:
			switch(IsMoveAbleCell(UnitPlayer.X, UnitPlayer.Y - 1)){
				case Yes:
					UnitPlayer.Y--;
					UnitPlayer.ScrollY = D_PlayerSCM;
					return Yes;
				case No:
					return No;
				default:
					return Null;
			}

		case D_Down:
			switch(IsMoveAbleCell(UnitPlayer.X, UnitPlayer.Y + 1)){
				case Yes:
					UnitPlayer.Y++;
					UnitPlayer.ScrollY = -D_PlayerSCM;
					return Yes;
				case No:
					return No;
				default:
					return Null;
			}

		case D_Left:
			switch(IsMoveAbleCell(UnitPlayer.X - 1, UnitPlayer.Y)){
				case Yes:
					UnitPlayer.X--;
					UnitPlayer.ScrollX = D_PlayerSCM;
					return Yes;
				case No:
					return No;
				default:
					return Null;
			}

		case D_Right:
			switch(IsMoveAbleCell(UnitPlayer.X + 1, UnitPlayer.Y)){
				case Yes:
					UnitPlayer.X++;
					UnitPlayer.ScrollX = -D_PlayerSCM;
					return Yes;
				case No:
					return No;
				default:
					return Null;
			}
		default:
			return Null;
	}
}

void PushStone(){
	int TempIndex;
	TempIndex = GetPlace(UnitPlayer.X, UnitPlayer.Y, UnitPlayer.Direction);
	if(TempIndex != Null){
		Status_MoveSuccess = MoveStone(TempIndex, UnitPlayer.Direction);
		if(Status_MoveSuccess == Yes){
			return;//끌리는 소리
		}
	}
	return;
}

void ReplacePlace(int Index, int In_X1, int In_Y1, int In_X2, int In_Y2){
	SetPlace(-1, In_X1, In_Y1);
	SetPlace(Index, In_X2, In_Y2);
	return;
}