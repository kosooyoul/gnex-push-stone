/*
	PushStone화면 출력
	by www.Ahyane.net ^^*
*/

/*
	Status_Value1 : 애니매이션 장면 번호 [조건:Status_Value2 == N 일 경우 증가]
		0 ~ End - 1	> 애니매이션 및 장면 출력
		End			> 다음 모드로

	Status_Value2 : 타이머 [조건:0 이상 일 경우 증가]
		-1			> 작동 안함
		0 ~ N - 1	> 카운터 값 증가
		N			> 카운터 값 초기화

	Status_Value3 : 해당 장면의 최대 카운터 [조건:Status_Value2 == 0 일 경우 설정]
	Status_Value4 : 이미지의 투명도 값
*/
void ShowIcon(){
	ClearWhite();

	//장면의 프레임수 결정
	if(Status_Value2 == 0){
		switch(Status_Value1){
			case 0:		Status_Value3 = 20;		break;//+1
			case 1:		Status_Value3 = 20;		break;//+2
			case 2:		Status_Value3 = 20;		break;//+3
			case 3:		Status_Value3 = 20;		break;//+4
			case 4:		Status_Value3 = 20;		break;//+5
			case 5:		Status_Value3 = 20;		break;//BLINK
			case 6:		Status_Value3 = 100;	break;//+URL
			case 7:		Status_Value3 = 20;		break;//-URL
			case 8:		Status_Value3 = 20;		break;//+6
			case 9:		Status_Value3 = 20;		break;//-N
			case 10:	Status_Value3 = 30;		break;//NO
			case 11:	Status_Value3 = 30;		break;//FADEOUT
		}
	}
	
	//장면 출력
	switch(Status_Value1){
		case 0:
			GetAnimationPosition(56,-66, 106, 134, Status_Value2, Status_Value3, Movement_FadeOut, 1, Guide_ZigZagGourd, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage(106, 134, Img_TitleBlock);//1
			break;

		case 1:
			CopyImage(106, 134, Img_TitleBlock);//1
			GetAnimationPosition(40,-58, 90, 142, Status_Value2, Status_Value3, Movement_FadeOut, 1, Guide_RightGourd, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage( 90, 142, Img_TitleBlock);//2
			break;

		case 2:
			GetAnimationPosition(24,-66, 74, 134, Status_Value2, Status_Value3, Movement_FadeOut, 1, Guide_ZigZagGourd, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage( 74, 134, Img_TitleBlock);//3
			CopyImage(106, 134, Img_TitleBlock);//1
			GetAnimationPosition(88,-66, 138, 134, Status_Value2, Status_Value3, Movement_FadeOut, 1, Guide_LeftGourd, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage(138, 134, Img_TitleBlock);//3
			CopyImage( 90, 142, Img_TitleBlock);//2
			break;

		case 3:
			GetAnimationPosition(40,-90, 90, 110, Status_Value2, Status_Value3, Movement_FadeOut, 1, Guide_ZigZagGourd, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage( 90, 110, Img_TitleBlock);//4
			GetAnimationPosition(56,-82, 106, 118, Status_Value2, Status_Value3, Movement_FadeOut, 1, Guide_RightGourd, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage(106, 118, Img_TitleBlock);//4
			CopyImage( 74, 134, Img_TitleBlock);//3
			CopyImage(106, 134, Img_TitleBlock);//1
			CopyImage(138, 134, Img_TitleBlock);//3
			CopyImage( 90, 142, Img_TitleBlock);//2
			break;

		case 4:
			CopyImage( 90, 110, Img_TitleBlock);//4
			GetAnimationPosition(24,-82, 74, 118, Status_Value2, Status_Value3, Movement_FadeOut, 1, Guide_RightGourd, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage( 74, 118, Img_TitleBlock);//5
			CopyImage(106, 118, Img_TitleBlock);//4
			GetAnimationPosition(72,-74, 122, 126, Status_Value2, Status_Value3, Movement_FadeOut, 1, Guide_ZigZagGourd, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage(122, 126, Img_TitleBlock);//5
			CopyImage( 74, 134, Img_TitleBlock);//3
			CopyImage(106, 134, Img_TitleBlock);//1
			CopyImage(138, 134, Img_TitleBlock);//3
			CopyImage( 90, 142, Img_TitleBlock);//2
			GetAnimationPosition(56,-50, 106, 150, Status_Value2, Status_Value3, Movement_FadeOut, 1, Guide_LeftGourd, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage(106, 150, Img_TitleBlock);//5
			break;
		case 5:
			if(Status_Value2 % 5 < 3){
				CopyImage( 90, 110, Img_TitleBlock);//4
				CopyImage( 74, 118, Img_TitleBlock);//5
				CopyImage(106, 118, Img_TitleBlock);//4
				CopyImage(122, 126, Img_TitleBlock);//5
				CopyImage( 74, 134, Img_TitleBlock);//3
				CopyImage(106, 134, Img_TitleBlock);//1
				CopyImage(138, 134, Img_TitleBlock);//3
				CopyImage( 90, 142, Img_TitleBlock);//2
				CopyImage(106, 150, Img_TitleBlock);//5
			}
			break;

		case 6:
			CopyImage( 90, 110, Img_TitleBlock);//4
			CopyImage( 74, 118, Img_TitleBlock);//5
			CopyImage(106, 118, Img_TitleBlock);//4
			CopyImage(122, 126, Img_TitleBlock);//5
			CopyImage( 74, 134, Img_TitleBlock);//3
			CopyImage(106, 134, Img_TitleBlock);//1
			CopyImage(138, 134, Img_TitleBlock);//3
			CopyImage( 90, 142, Img_TitleBlock);//2
			CopyImage(106, 150, Img_TitleBlock);//5
			if(Status_Value2 < 5) Status_Value4 = 3;
			else if(Status_Value2 < 10) Status_Value4 = 2;
			else if(Status_Value2 < 15) Status_Value4 = 1;
			else Status_Value4 = 0;
			CopyImageEx(106, 190, Img_TitleWWW, Status_Value4, 0, 0, 0);
			CopyImageEx(106, 190, Img_TitleAHYANE, Status_Value4, 0, 0, 0);
			CopyImageEx(106, 190, Img_TitleNET, Status_Value4, 0, 0, 0);
			break;

		case 7:
			CopyImage( 90, 110, Img_TitleBlock);//4
			CopyImage( 74, 118, Img_TitleBlock);//5
			CopyImage(106, 118, Img_TitleBlock);//4
			CopyImage(122, 126, Img_TitleBlock);//5
			CopyImage( 74, 134, Img_TitleBlock);//3
			CopyImage(106, 134, Img_TitleBlock);//1
			CopyImage(138, 134, Img_TitleBlock);//3
			CopyImage( 90, 142, Img_TitleBlock);//2
			CopyImage(106, 150, Img_TitleBlock);//5
			if(Status_Value2 < 5) Status_Value4 = 1;
			else if(Status_Value2 < 10) Status_Value4 = 2;
			else if(Status_Value2 < 15) Status_Value4 = 3;
			else Status_Value4 = 0;
			if(Status_Value4 > 0){
				CopyImageEx(106, 190, Img_TitleWWW, Status_Value4, 0, 0, 0);
				CopyImageEx(106, 190, Img_TitleAHYANE, Status_Value4, 0, 0, 0);
				CopyImageEx(106, 190, Img_TitleNET, Status_Value4, 0, 0, 0);
			}
			break;

		case 8:
			CopyImage( 90, 110, Img_TitleBlock);//4
			CopyImage( 74, 118, Img_TitleBlock);//5
			CopyImage(106, 118, Img_TitleBlock);//4
			CopyImage(122, 126, Img_TitleBlock);//5
			CopyImage( 74, 134, Img_TitleBlock);//3
			CopyImage(106, 134, Img_TitleBlock);//1
			CopyImage(138, 134, Img_TitleBlock);//3
			CopyImage( 90, 142, Img_TitleBlock);//2
			CopyImage(106, 150, Img_TitleBlock);//5
			GetAnimationPosition(89,-104, 90, 96, Status_Value2, Status_Value3, Movement_FadeIn, 2, Guide_Straight, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage( 90, 96, Img_TitleBlock);//6
			break;

		case 9:
			GetAnimationPosition(90,134, 95, 310, Status_Value2, Status_Value3, Movement_FadeOut, 4, Guide_Straight, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage( 90, 310, Img_TitleBlock);//4
			GetAnimationPosition(90, 96, 91, 300, Status_Value2, Status_Value3, Movement_FadeIn, 3, Guide_Straight, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage( 90,  96, Img_TitleBlock);//6
			GetAnimationPosition(74,134, 70, 318, Status_Value2, Status_Value3, Movement_FadeOut, 3, Guide_Straight, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage( 74, 318, Img_TitleBlock);//5
			CopyImage(106, 118, Img_TitleBlock);//4
			CopyImage(122, 126, Img_TitleBlock);//5
			CopyImage( 74, 134, Img_TitleBlock);//3
			GetAnimationPosition(106,134, 110, 334, Status_Value2, Status_Value3, Movement_FadeOut, 2, Guide_Straight, 20);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleBlock);
			//CopyImage(106, 334, Img_TitleBlock);//1
			CopyImage(138, 134, Img_TitleBlock);//3
			CopyImage( 90, 142, Img_TitleBlock);//2
			CopyImage(106, 150, Img_TitleBlock);//5
			break;

		case 10:
			CopyImage(106, 118, Img_TitleBlock);//4
			CopyImage(122, 126, Img_TitleBlock);//5
			CopyImage( 74, 134, Img_TitleBlock);//3
			CopyImage(138, 134, Img_TitleBlock);//3
			CopyImage( 90, 142, Img_TitleBlock);//2
			CopyImage(106, 150, Img_TitleBlock);//5
			break;

		case 11:
			if(Status_Value2 < 5) Status_Value4 = 1;
			else if(Status_Value2 < 10) Status_Value4 = 2;
			else if(Status_Value2 < 15) Status_Value4 = 3;
			else Status_Value4 = 0;
			if(Status_Value4 > 0){
				CopyImageEx(106, 118, Img_TitleBlock, Status_Value4, 0, 0, 0);//4
				CopyImageEx(122, 126, Img_TitleBlock, Status_Value4, 0, 0, 0);//5
				CopyImageEx( 74, 134, Img_TitleBlock, Status_Value4, 0, 0, 0);//3
				CopyImageEx(138, 134, Img_TitleBlock, Status_Value4, 0, 0, 0);//3
				CopyImageEx( 90, 142, Img_TitleBlock, Status_Value4, 0, 0, 0);//2
				CopyImageEx(106, 150, Img_TitleBlock, Status_Value4, 0, 0, 0);//5
			}
			break;

		case 12:
			InitStatusValue();
			Status_GameMode = Game_Title;
			return;
	}

	//타이머 작동
	if(Status_Value2 >= Status_Value3 && Status_Value3 != -1){
		//다음 장면으로 이동
		Status_Value2 = 0;
		Status_Value1++;
	}else{
		//타이머 증가
		Status_Value2++;
	}
	return;
}

/*
	Status_Value1 : 애니매이션 장면 번호 [조건:Status_Value2 == N 일 경우 증가]
		0			> 초기화
		1 ~ End - 1	> 애니매이션 및 장면 출력
		End			> 다음 모드로

	Status_Value2 : 타이머 [조건:0 이상 일 경우 증가]
		-1			> 작동 안함
		0 ~ N - 1	> 카운터 값 증가
		N			> 카운터 값 초기화

	Status_Value3 : 해당 장면의 최대 카운터 [조건:Status_Value2 == 0 일 경우 설정]
	Status_Value4 : 이미지의 투명도 값
	Status_Value5 : 도형 회전 각도 값
*/
void ShowTitle(){
	ClearWhite();
	
	//기본 배경
	CopyImage(   0,   0, Img_TitleBackground1);
	CopyImage(   0, 150, Img_TitleBackground2);

	//장면의 프레임수 결정
	if(Status_Value2 == 0){
		switch(Status_Value1){
			case 0:		Status_Value3 = 0;		break;//INIT
			case 1:		Status_Value3 = 20;		break;//+S1
			case 2:		Status_Value3 = 20;		break;//+S2
			case 3:		Status_Value3 = 20;		break;//+S3
			case 4:		Status_Value3 = 30;		break;//+W1
			case 5:		Status_Value3 = 30;		break;//+W2
			case 6:		Status_Value3 = 1000;	break;//NO
			case 7:		Status_Value3 = -1;		break;//DEMO
			case 8:		Status_Value3 = 15;		break;//FADEOUT
		}
	}

	switch(Status_Value1){
		case 0:
			Temp1[0] = 00;Temp2[0] = 15;
			Temp1[1] = 30;Temp2[1] = 00;
			Temp1[2] = 15;Temp2[2] = 15;
			Temp1[3] = 30;Temp2[3] = 30;
			break;

		case 1:
			GetAnimationPosition(-100, 120, 28, 84, Status_Value2, Status_Value3, Movement_FadeOut, 3, Guide_Straight, 100);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleStone);
			break;

		case 2:
			CopyImage( 28,  84, Img_TitleStone);
			GetAnimationPosition(-20, 300, 55, 154, Status_Value2, Status_Value3, Movement_FadeOut, 3, Guide_Straight, 100);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleStone);
			break;

		case 3:
			CopyImage( 28,  84, Img_TitleStone);
			CopyImage( 55, 154, Img_TitleStone);
			GetAnimationPosition(140, -80, 104, 10, Status_Value2, Status_Value3, Movement_FadeOut, 3, Guide_Straight, 100);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleStone);
			break;

		case 4:
			CopyImage( 28,  84, Img_TitleStone);
			CopyImage( 55, 154, Img_TitleStone);
			CopyImage(104,  10, Img_TitleStone);
			GetAnimationPosition(-140, 20, 33, 38, Status_Value2, Status_Value3, Movement_Straight, 0, Guide_RightGourd, 70);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleWord1);
			break;

		case 5:
			CopyImage( 28,  84, Img_TitleStone);
			CopyImage( 55, 154, Img_TitleStone);
			CopyImage(104,  10, Img_TitleStone);
			CopyImage( 33,  38, Img_TitleWord1);
			GetAnimationPosition(240, 20, 33, 38, Status_Value2, Status_Value3, Movement_Straight, 0, Guide_LeftGourd, 70);
			CopyImage(UnitReturnPosition.X, UnitReturnPosition.Y, Img_TitleWord2);
			break;

		case 6:
			CopyImage( 28,  84, Img_TitleStone);
			CopyImage( 55, 154, Img_TitleStone);
			CopyImage(104,  10, Img_TitleStone);
			CopyImage( 33,  38, Img_TitleWord1);
			CopyImage( 33,  38, Img_TitleWord2);
			if(Status_Value2 % 20 < 10){
				SetColor(S_WHITE);
				FillRectEx( 5, 220, 235, 236, 2);
				CopyImage( 75, 225, Img_TitlePress);
				CopyImage( 75, 225, Img_TitleOk);
				CopyImage( 75, 225, Img_TitleButton);
			}
			break;

		case 7:
			InitStatusValue();
			//Status_GameMode = Game_Demo;	//데모보기
			return;

		case 8:
			if(Status_Value2 > 12) Status_Value4 = 4;
			else if(Status_Value2 >  9) Status_Value4 = 3;
			else if(Status_Value2 >  6) Status_Value4 = 2;
			else if(Status_Value2 >  3) Status_Value4 = 1;
			else Status_Value4 = 0;
			if(Status_Value4 < 4){
				CopyImageEx(28, 84, Img_TitleStone, Status_Value4, 0, 0, 0);
				CopyImageEx(55, 154, Img_TitleStone, Status_Value4, 0, 0, 0);
				CopyImageEx(104, 10, Img_TitleStone, Status_Value4, 0, 0, 0);
				CopyImageEx( 33,  38, Img_TitleWord1, Status_Value4, 0, 0, 0);
				CopyImageEx( 33,  38, Img_TitleWord2, Status_Value4, 0, 0, 0);
			}
			/*{
				if(Status_Value5 < 360) Status_Value5 += 10 + Status_Value2;
				else Status_Value5 = 0;
				SetColorRGB(200, 200, 200);
				RotatePolygon(Temp1, Temp2, 220, 270, Status_Value5 +  60, 120, 175, Status_Value2 * 4);
				RotatePolygon(Temp1, Temp2, 220, 270, Status_Value5 + 180, 120, 175, Status_Value2 * 4);
				RotatePolygon(Temp1, Temp2, 220, 270, Status_Value5 + 300, 120, 175, Status_Value2 * 4);
				SetColor(S_SKY);
				RotatePolygon(Temp1, Temp2, 220,  90, Status_Value5      , 120, 175, Status_Value2 * 4);
				RotatePolygon(Temp1, Temp2, 220,  90, Status_Value5 + 120, 120, 175, Status_Value2 * 4);
				RotatePolygon(Temp1, Temp2, 220,  90, Status_Value5 + 240, 120, 175, Status_Value2 * 4);
			}*/
			
			break;
		case 9:
			InitStatusValue();
			Status_GameMode = Game_SelectPart;
			return;
	}

	//작자 표시
	CopyImage( 110, 287, Img_TitleCopyright);
	CopyImage( 110, 287, Img_TitleAHYANE);

	//타이머 작동
	if(Status_Value2 >= Status_Value3 && Status_Value3 != -1){
		//다음 장면으로 이동
		Status_Value2 = 0;
		Status_Value1++;
	}else{
		//타이머 증가
		Status_Value2++;
	}
	return;
}

/*
	Status_Value1 : 애니매이션 장면 번호 [조건:Status_Value2 == N 일 경우 증가]
		0 ~ End - 1	> 애니매이션 및 장면 출력
		End			> 다음 모드로

	Status_Value2 : 타이머 [조건:0 이상 일 경우 증가]
		-1			> 작동 안함
		0 ~ N - 1	> 카운터 값 증가
		N			> 카운터 값 초기화

	Status_Value3 : 해당 장면의 최대 카운터 [조건:Status_Value2 == 0 일 경우 설정]
	
	Status_Value4 : 이동할 게임 모드

	Status_Value5 : 메뉴 깊이

	Status_Select1 : 선택한 메인 메뉴 번호

	Status_Select2 : 선택한 서브 메뉴 번호
*/
void ShowSelectPart(){
	string Temp;		//곧 지움
	ClearWhite();
	
	//기본 배경
	CopyImage(   0,   0, Img_TitleBackground1);
	CopyImage(   0, 150, Img_TitleBackground2);

	//장면의 프레임수 결정
	if(Status_Value2 == 0){
		switch(Status_Value1){
			case 0:		Status_Value3 = 30;		break;//BACK
			case 1:		Status_Value3 = 30;		break;//ITEM
			case 2:		Status_Value3 = -1;		break;//SELECT MENU
			case 3:		Status_Value3 = 30;		break;//CLEAR
		}
	}

	switch(Status_Value1){
		case 0:
			//화면 열리는 모양
			DrawStr(10,10,"화면 열리는 모양");
			break;

		case 1:
			//구성요소 나타나는 모양
			DrawStr(10,10,"구성요소 나타나는 모양");
			break;

		case 2:
			//선택한 메뉴에 대한 장면
			switch(Status_Select1){
				case Menu_Start:
					DrawStr(10,10,"선택한 메뉴에 대한 장면");
					DrawStr(30,30,"- 게임 시작");
	
					//메뉴 종류 구분
					switch(Status_Value5){
						case Menu_Main:
							DrawStr(50,50,"+ 서브 메뉴");
							break;

						case Menu_SubStart:
							switch(Status_Select2){
								case Menu_Travel:
									DrawStr(50,50,"- 여행 모드");
									break;

								case Menu_Normal:
									DrawStr(50,50,"- 일반 모드");
									break;

								case Menu_TimeAttack:
									DrawStr(50,50,"- 타임 어택");
									break;

								case Menu_Shop:
									DrawStr(50,50,"- 아이템 상점");
							}
					}
					break;

				case Menu_Guide:
					DrawStr(10,10,"선택한 메뉴에 대한 장면");
					DrawStr(30,30,"- 게임 도움말");
					break;

				case Menu_Record:
					DrawStr(10,10,"선택한 메뉴에 대한 장면");
					DrawStr(30,30,"- 게임 점수보기");
					break;

				case Menu_Option:
					DrawStr(10,10,"선택한 메뉴에 대한 장면");
					DrawStr(30,30,"- 게임 환경설정");
					break;
			}
			break;

		case 3:
			MakeStr2(Temp, "NextMode = %d, Frame = %d", Status_Value4, Status_Value2);
			DrawStr(10,10,"모드 이동");
			DrawStr(30,30,Temp);
			break;

		case 4:
			Status_GameMode = Status_Value4;	//초기화전에 먼저 변경(!주의해야함)
			InitStatusValue();					//초기화 수행
			return;								//그리고 리턴(!주의해야함:값이 변경 되므로 리턴)

	}

	//타이머 작동
	if(Status_Value2 >= Status_Value3 && Status_Value3 != -1){
		//다음 장면으로 이동
		Status_Value2 = 0;
		Status_Value1++;
	}else{
		//타이머 증가
		Status_Value2++;
	}
	return;
}

void ShowTravel(){
	ClearWhite();
	//케릭터 선택 일단 없음 기본케릭터에 얻음 : 구상중..
	DrawStr(10,20,"여행모드임");
	return;
}

void ShowNormal(){
	ClearWhite();
	//케릭터 선택후 : 난이도별로 열려 있는 스테이지 선택 - 미니맵과 요약해서 미리 보여줌
	DrawChara(Status_Value1);
	DrawStr(10,20,"일반모드임");
	return;
}

void ShowTimeAttack(){
	ClearWhite();
	//케릭터 선택후 : 난이도 순서대로 시작함
	DrawChara(Status_Value1);
	DrawStr(10,20,"타임어택모드임");
	return;
}

void ShowShop(){
	ClearWhite();
	//구입 템과 판매템을 보여줌, 초기 슬롯 4개에 슬롯 획득하면서 최대 8개 슬롯까지한슬롯에 최대 갯수 10개 생각
	DrawStr(10,20,"상점모드임");
	return;
}

void ShowGuide(){
	ClearWhite();
	//재즈 잭 래빗의 도움말 처럼 보여주는 방식
	DrawStr(10,20,"도움말모드임");
	return;
}

void ShowRecord(){
	ClearWhite();
	//일반 모드의 각 스테이지별 최대 점수, 타임어택 모드의 전체 플레이 점수 및 마지막 플레이 스테이지 번호 및 케릭터까지 표시
	DrawStr(10,20,"기록보기모드임");
	return;
}

void ShowOption(){
	ClearWhite();
	//사운드, 자동 밀기, 일단 여기까지
	DrawStr(10,20,"환경설정모드임");
	return;
}


//케릭터 선택
void DrawChara(int CharaIndex){
	string Temp;
	int i;

	MakeStr1(Temp, "선택한 케릭터 = %d", CharaIndex);
	DrawStr(10,40, Temp);
	for(i = 0; i < MaxCharaCount; i++){
		if(CharaIndex == i){
			DrawStr(10 + i * 10, 60, "▣");
		}else{
			if((Status_OpenedChara >> i) % 2 == Yes){
				DrawStr(10 + i * 10, 60, "■");
			}else{
				DrawStr(10 + i * 10, 60, "□");
			}
		}
	}
	return;
}

void ShowStage(){
	if(Status_Value1 == 0){
		SetStage(0, 7, 5, 0, 0, 13, 11);
		Status_CurrentStage = 0;
		StartStage(Status_CurrentStage);
		Status_Value1 = 1;
		SetTimer(40, 1);
	}else if(Status_Value1 == 1){
		ClearBlack();
		DrawStage(Status_CurrentStage, Size_Half, Size_Thalf);
		if(Status_MovingDirection != Null){
			Status_MoveSuccess = MovePlayer(Status_MovingDirection);
		}
	}
}