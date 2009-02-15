/*
	PushStone전용 정의 목록
	by www.Ahyane.net ^^*
*/

//-------------------- 변경 있는 정의 --------------------//
//맵 데이터 최대 사이즈
#define MaxSizeX	20
#define MaxSizeY	20

//케릭터 수
#define MaxCharaCount		10
#define D_SelectedCharaOk	-1

//D_MoveAble번칩까지는 이동 불가능
#define D_MoveAble	0

//-------------------- 변경 가능 정의 --------------------//
//돌덩이 스크롤 단위 24에서 2씩 증감/또는 26에서 2를 나누며 증감
#define D_StoneSCM	26
#define D_StoneSCU	2

//플레이어 스크롤 단위 14에서 2씩 증감
#define D_PlayerSCM	12
#define D_PlayerSCU	3

//맵 스크롤 단위 15에서 3씩 증감
#define D_MapSCM	15
#define D_MapSCU	3

//각 갯수별 셀의 사이즈
#define Size_Half	8
#define Size_One	16
#define Size_Inch	24
#define Size_Two	32
#define Size_Three	48
#define Size_Thalf	56
#define Size_Four	64

//-------------------- 변경 없는 정의 --------------------//
//방향 정의, 상하좌우
#define D_Up		SWAP_KEY_UP
#define D_Down		SWAP_KEY_DOWN
#define D_Left		SWAP_KEY_LEFT
#define D_Right		SWAP_KEY_RIGHT

//리턴값 정의
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