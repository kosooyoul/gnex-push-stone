/*
	PushStone전용 정의 목록
	by www.Ahyane.net ^^*
*/

//-------------------- 변경 있는 정의 --------------------//
//맵 데이터 최대 사이즈
#define MaxSizeX	20
#define MaxSizeY	20

//배치 데이터 최대 사이즈
#define MaxPlaceSizeX	14
#define MaxPlaceSizeY	12

//맵 최적의 사이즈
#define MaxMapOptimalSizeX	14
#define MaxMapOptimalSizeY	12

//D_MoveAble번칩까지는 이동 불가능
#define D_MoveAble	0

//케릭터 수
//#define MaxCharaCount		10
//#define D_SelectedCharaOk	-1

//-------------------- 변경 가능 정의 --------------------//
//돌덩이 스크롤 단위 24에서 2씩 증감/또는 26에서 2를 나누며 증감
#define D_StoneSCM	27
#define D_StoneSCU	2

//플레이어 스크롤 단위 14에서 2씩 증감
#define D_PlayerSCM	16
#define D_PlayerSCU	4

//맵 스크롤 단위 15에서 3씩 증감
#define D_MapSCM	15
#define D_MapSCU	3

//각 갯수별 셀의 사이즈
#define Size_Half		8
#define Size_One		16
#define Size_Two		32
#define Size_TwoHalf	40

//-------------------- 변경 없는 정의 --------------------//
//4 방향 정의, 상하좌우
#define D_Up		SWAP_KEY_UP
#define D_Down		SWAP_KEY_DOWN
#define D_Left		SWAP_KEY_LEFT
#define D_Right		SWAP_KEY_RIGHT

//6 방향 정의, 상하*좌우
#define D_Clock0	SWAP_KEY_2
#define D_Clock2	SWAP_KEY_3
#define D_Clock4	SWAP_KEY_6
#define D_Clock6	SWAP_KEY_5
#define D_Clock8	SWAP_KEY_4
#define D_Clock10	SWAP_KEY_1

//리턴값 정의
#define ERROR		-2
#define Null		-1
#define No			0
#define Yes			1

//돌덩이의 모양
#define S_Rect		0
#define S_Hexa		1
#define S_Star		2
#define S_Heart		3
#define S_Ball		4
#define S_Nailed	5

//돌덩이의 재질
#define M_Wood		0
#define M_Stone		1
#define M_Iorn		2
#define M_Glass		3
#define M_Rubber	4
#define M_ETC		5

//돌덩이의 상태
#define S_Hide		0
#define S_Fixed		1
#define S_In		2
#define S_Out		3
#define S_CoupIn	4
#define S_CoupOut	5