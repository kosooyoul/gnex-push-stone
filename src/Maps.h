/*
	PushStone전용 맵 관련
	by www.Ahyane.net ^^*
*/

#include "MapImages.sbm"
#include "MapData.h"

int MapScrollX = 0;
int MapScrollY = 0;

void ScrollMap(){
	if(MapScrollX > 0){
		MapScrollX -= D_MapSCU;
	}else if(MapScrollX < 0){
		MapScrollX += D_MapSCU;
	}

	if(MapScrollY > 0){
		MapScrollY -= D_MapSCU;
	}else if(MapScrollY < 0){
		MapScrollY += D_MapSCU;
	}
}

void DrawMap(int StartCellX, int StartCellY, int EndCellX, int EndCellY, int StageX, int StageY){
	int x, y;

	for(x = StartCellX; x <= EndCellX; x++){
		for(y = StartCellY; y <= EndCellY ; y++){
			if(x >= 0 && x < MaxSizeX && y >= 0 && y < MaxSizeY){
				CopyImage(MapScrollX + (x - StartCellX) * 16 + StageX
						, MapScrollY + (y - StartCellY) * 16 + StageY
						, MapChip[Map[y][x]]);
			}
		}
	}		
}