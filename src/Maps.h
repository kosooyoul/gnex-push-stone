#include "MapImages.sbm"

#define D_MoveAble	0

const int Map[11][11] = {
	1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0,
	1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0,
	0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0,
	1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0,
	0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0,
	0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0,
	0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
	1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void DrawMap(int StartX, int StartY, int SizeX, int SizeY, int StageX, int StageY){
	int x, y;

	for(x = 0; x < SizeX+10; x++){
		for(y = 0; y < SizeY+10; y++){
			if(x + StartX > -1 && x + StartX < 11 && y + StartY > -1 && y + StartY < 11){
				CopyImage(x * 16 + StageX, y * 16 + StageY, MapChip[Map[y + StartY][x + StartX]]);
			}else{
				SetColor(S_BLACK);
				FillRect(x * 16 + StageX, y * 16 + StageY, (x + 1) * 16 + StageX - 1, (y + 1) * 16 + StageY - 1);
			}
		}
	}		
}