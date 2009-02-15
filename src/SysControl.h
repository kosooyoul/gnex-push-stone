/*
	PushStone 키입력 제어
	by www.Ahyane.net ^^*
*/

void ControlIcon(int SysData){
	switch(SysData){
		case SWAP_KEY_OK:
			//스킵1
			if(Status_Value1 < 6){
				Status_Value1 = 6;
				Status_Value2 = 0;
			//스킵2
			}else if(Status_Value1 < 11){
				Status_Value1 = 11;
				Status_Value2 = 0;
			}
	}
	return;
}

void ControlTitle(int SysData){
	switch(SysData){
		case SWAP_KEY_OK:
			//스킵
			if(Status_Value1 < 6){
				Status_Value1 = 6;
				Status_Value2 = 0;
			//게임 선택 메뉴로
			}else if(Status_Value1 == 6){
				Status_Value1 = 8;
				Status_Value2 = 0;
			}
			break;
		//임시 스테이지 - 삭제 부분
		case SWAP_KEY_SHARP:
			InitStatusValue();
			Status_GameMode = Game_Stage;
	}
	return;
}

void ControlSelectPart(int SysData){
	if(Status_Value1 < 2){
		if(SysData == SWAP_KEY_OK){
			Status_Value1 = 2;
			Status_Value2 = 0;
		}
	}else if(Status_Value1 == 2){
		//메뉴 종류
		switch(Status_Value5){
			case Menu_Main:
				switch(SysData){
					case SWAP_KEY_OK:
						//선택한 메인 메뉴 구분
						switch(Status_Select1){
							case Menu_Start:
								//게임 시작 하위 메뉴
								Status_Value5 = Menu_SubStart;
								return;
							case Menu_Guide:
								//도움말 모드
								Status_Value4 = Game_Guide;
								break;
							case Menu_Record:
								//기록 보기 모드
								Status_Value4 = Game_Record;
								break;
							case Menu_Option:
								//환경 설정 모드
								Status_Value4 = Game_Option;
						}
						//모드 이동 시키는 장면
						Status_Value2 = 0;
						Status_Value1 = 3;
						break;
					case SWAP_KEY_LEFT:
						Status_Select1 = (Status_Select1 + 3) % 4;
						break;
					case SWAP_KEY_RIGHT:
						Status_Select1 = (Status_Select1 + 1) % 4;
				}
				break;
			case Menu_SubStart:
				switch(SysData){
					case SWAP_KEY_OK:
						//선택한 서브 메뉴 구분
						switch(Status_Select2){
							case Menu_Travel:
								//게임 여행 모드
								Status_Value4 = Game_Travel;
								break;
							case Menu_Normal:
								//게임 일반 모드
								Status_Value4 = Game_Normal;
								break;
							case Menu_TimeAttack:
								//게임 타임어택 모드
								Status_Value4 = Game_TimeAttack;
								break;
							case Menu_Shop:
								//게임 상점 모드
								Status_Value4 = Game_Shop;
						}
						//모드 이동 시키는 장면
						Status_Value2 = 0;
						Status_Value1 = 3;
						break;
					case SWAP_KEY_LEFT:
						Status_Select2 = (Status_Select2 + 3) % 4;
						break;
					case SWAP_KEY_RIGHT:
						Status_Select2 = (Status_Select2 + 1) % 4;
						break;
					case SWAP_KEY_CLR:
						Status_Value5 = Menu_Main;
				}
		}
	}
	return;
}

void ControlTravel(int SysData){
	switch(SysData){
		case SWAP_KEY_CLR:
			Status_GameMode = Game_SelectPart;
	}
	return;
}

void ControlNormal(int SysData){
	Status_Value1 = SelectChara(Status_Value1, SysData);
	switch(SysData){
		case SWAP_KEY_CLR:
			Status_GameMode = Game_SelectPart;
	}
	return;
}

void ControlTimeAttack(int SysData){
	Status_Value1 = SelectChara(Status_Value1, SysData);
	switch(SysData){
		case SWAP_KEY_CLR:
			Status_GameMode = Game_SelectPart;
	}
	return;
}

void ControlShop(int SysData){
	switch(SysData){
		case SWAP_KEY_CLR:
			Status_GameMode = Game_SelectPart;
	}
	return;
}

void ControlGuide(int SysData){
	switch(SysData){
		case SWAP_KEY_CLR:
			Status_GameMode = Game_SelectPart;
	}
	return;
}

void ControlRecord(int SysData){
	switch(SysData){
		case SWAP_KEY_CLR:
			Status_GameMode = Game_SelectPart;
	}
	return;
}

void ControlOption(int SysData){
	switch(SysData){
		case SWAP_KEY_CLR:
			Status_GameMode = Game_SelectPart;
	}
	return;
}


int SelectChara(int NowChara, int SysData){
	int SelectedChara = NowChara;

	do{
		switch(SysData){
			case SWAP_KEY_LEFT:
				SelectedChara = (SelectedChara + MaxCharaCount - 1) % MaxCharaCount;
				break;
			case SWAP_KEY_RIGHT:
				SelectedChara = (SelectedChara + 1) % MaxCharaCount;
				break;
		}
	}while((Status_OpenedChara >> SelectedChara) % 2 == No);

	return SelectedChara;
}

void ControlStage(int SysData){
	if(SysData == SWAP_KEY_RELEASE){
		Status_MovingDirection = Null;
		return;
	}else{
		switch(SysData){
			case SWAP_KEY_UP:
			case SWAP_KEY_DOWN:
			case SWAP_KEY_LEFT:
			case SWAP_KEY_RIGHT:
				Status_MovingDirection = SysData;
				Status_MoveSuccess = MovePlayer(Status_MovingDirection);
				break;
			case SWAP_KEY_OK:
				Status_MovingDirection = Null;
				PushStone();
				break;
		}
	}
	if((Option_AutoPush == Yes && Status_MoveSuccess == No) || SysData == SWAP_KEY_OK){
		PushStone();
	}
}