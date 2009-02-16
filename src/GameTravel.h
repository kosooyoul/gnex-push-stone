#include "TravelMap.sbm"

#define MAXTravelSizeX	4
#define MAXTravelSizeY	4

const int TravelMap[MAXTravelSizeY][MAXTravelSizeX] = {
	1, 0, 1, 1,
	0, 1, 0, 0,
	1, 0, 1, 0,
	0, 1, 1, 1
};

/*
	LSB:12시 방향
	MSB:10시 방향
	MSB:00_0000:LSB
*/
const int TravelRoad[MAXTravelSizeY][MAXTravelSizeX] = {
	0x0C, 0x28, 0x14, 0x28,
	0x09, 0x07, 0x28, 0x11,
	0x05, 0x30, 0x17, 0x28,
	0x06, 0x26, 0x20, 0x01
};

struct TravelBlock{
	int StageNumber;
	int DrawX;
	int DrawY;
}UnitTravel[7];

int State_TravelCurrentX = 0;
int State_TravelCurrentY = 0;

int IsMoveAbleTravelRoad(int X, int Y, int Direction){
	int BitPosition;

	switch(Direction){
		case D_Clock0:		BitPosition = 0;break;
		case D_Clock2:		BitPosition = 1;break;
		case D_Clock4:		BitPosition = 2;break;
		case D_Clock6:		BitPosition = 3;break;
		case D_Clock8:		BitPosition = 4;break;
		case D_Clock10:		BitPosition = 5;break;
	}

	if((TravelRoad[Y][X] >> BitPosition) % 2 == Yes){
		return Yes;
	}else{
		return No;
	}
}

void DrawTravelMap(){
	int x, y;
	
	for(x = 0; x < MAXTravelSizeX; x++){
		for(y = 0; y < MAXTravelSizeY; y++){
			if(TravelMap[y][x] == 1){
				CopyImage(20 + x * 50, 80 + y * 30 + (x ) * 15, Img_TravelMapBlock[1]);
			}
		}
	}
	CopyImage(20 + State_TravelCurrentX  * 50, 80 + State_TravelCurrentY * 30 + (State_TravelCurrentX ) * 15, Img_TravelMapBlock[0]);

	return;
}

void MoveTravelMap(int SysData){
	switch(SysData){
		case SWAP_KEY_1:
			if(IsMoveAbleTravelRoad(State_TravelCurrentX, State_TravelCurrentY, D_Clock10) == Yes){
				State_TravelCurrentX--;
			}
			break;
		case SWAP_KEY_2:
			if(IsMoveAbleTravelRoad(State_TravelCurrentX, State_TravelCurrentY, D_Clock0) == Yes){
				State_TravelCurrentY--;
			}
			break;
		case SWAP_KEY_3:
			if(IsMoveAbleTravelRoad(State_TravelCurrentX, State_TravelCurrentY, D_Clock2) == Yes){
				State_TravelCurrentX++;
				State_TravelCurrentY--;
			}
			break;
		case SWAP_KEY_4:
			if(IsMoveAbleTravelRoad(State_TravelCurrentX, State_TravelCurrentY, D_Clock8) == Yes){
				State_TravelCurrentX--;
				State_TravelCurrentY++;
			}
			break;
		case SWAP_KEY_5:
			if(IsMoveAbleTravelRoad(State_TravelCurrentX, State_TravelCurrentY, D_Clock6) == Yes){
				State_TravelCurrentY++;
			}
			break;
		case SWAP_KEY_6:
			if(IsMoveAbleTravelRoad(State_TravelCurrentX, State_TravelCurrentY, D_Clock4) == Yes){
				State_TravelCurrentX++;
			}
			break;
	}
}