/*
	PushStone 키입력 제어
	by www.Ahyane.net ^^*
*/

void ControlIcon(int SysData){
	switch(SysData){
		case SWAP_KEY_OK:
			//스킵1
			if(Status_Value[0] < 6){
				Status_Value[0] = 6;
				Status_Value[1] = 0;
			//스킵2
			}else if(Status_Value[0] < 11){
				Status_Value[0] = 11;
				Status_Value[1] = 0;
			}
	}
	return;
}

void ControlTitle(int SysData){
	switch(SysData){
		case SWAP_KEY_OK:
			//스킵
			if(Status_Value[0] < 6){
				Status_Value[0] = 6;
				Status_Value[1] = 0;
			//게임 선택 메뉴로
			}else if(Status_Value[0] == 6){
				Status_Value[0] = 8;
				Status_Value[1] = 0;
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
	if(Status_Value[0] < 2){
		if(SysData == SWAP_KEY_OK){
			Status_Value[0] = 2;
			Status_Value[1] = 0;
		}
	}else if(Status_Value[0] == 2){
		//메뉴 종류
		switch(Status_Value[4]){
			case Menu_Main:
				switch(SysData){
					case SWAP_KEY_OK:
						//선택한 메인 메뉴 구분
						switch(Status_Select[0]){
							case Menu_Start:
								//게임 시작 하위 메뉴
								Status_Value[4] = Menu_SubStart;
								return;
							case Menu_Guide:
								//도움말 모드
								Status_Value[3] = Game_Guide;
								break;
							case Menu_Record:
								//기록 보기 모드
								Status_Value[3] = Game_Record;
								break;
							case Menu_Option:
								//환경 설정 모드
								Status_Value[3] = Game_Option;
						}
						//모드 이동 시키는 장면
						Status_Value[1] = 0;
						Status_Value[0] = 3;
						break;
					case SWAP_KEY_LEFT:
						Status_Select[0] = (Status_Select[0] + 3) % 4;
						break;
					case SWAP_KEY_RIGHT:
						Status_Select[0] = (Status_Select[0] + 1) % 4;
				}
				break;
			case Menu_SubStart:
				switch(SysData){
					case SWAP_KEY_OK:
						//선택한 서브 메뉴 구분
						switch(Status_Select[1]){
							case Menu_Travel:
								//게임 여행 모드
								Status_Value[3] = Game_Travel;
								break;
							case Menu_Normal:
								//게임 일반 모드
								Status_Value[3] = Game_Normal;
								break;
							case Menu_TimeAttack:
								//게임 타임어택 모드
								Status_Value[3] = Game_TimeAttack;
								break;
							case Menu_Shop:
								//게임 상점 모드
								Status_Value[3] = Game_Shop;
						}
						//모드 이동 시키는 장면
						Status_Value[1] = 0;
						Status_Value[0] = 3;
						break;
					case SWAP_KEY_LEFT:
						Status_Select[1] = (Status_Select[1] + 3) % 4;
						break;
					case SWAP_KEY_RIGHT:
						Status_Select[1] = (Status_Select[1] + 1) % 4;
						break;
					case SWAP_KEY_CLR:
						Status_Value[4] = Menu_Main;
				}
		}
	}
	return;
}

void ControlTravel(int SysData){
	//MoveTravelMap(SysData);
	switch(SysData){
		case SWAP_KEY_CLR:
			Status_GameMode = Game_SelectPart;
	}
	return;
}

void ControlNormal(int SysData){
	//Status_Value[0] = SelectChara(Status_Value[0], SysData);
	switch(Status_Value[0]){
		case 0:
		case 1:
			if(SysData == SWAP_KEY_OK){
				Status_Value[0] = 2;
				Status_Value[1] = 0;
			}
			break;
		case 2://메뉴선택
			switch(SysData){
				case SWAP_KEY_OK:
					//메뉴선택 함
					Status_CurrentStage = Status_Select[0];
					Status_Value[1] = 0;
					Status_Value[0] = 3;
					break;
					//메뉴 고르기
				case SWAP_KEY_UP:
					Status_Select[0] = (Status_Select[0] - 1 + MaxNormalStage) % MaxNormalStage;
					break;
				case SWAP_KEY_DOWN:
					Status_Select[0] = (Status_Select[0] + 1) % MaxNormalStage;
					break;
					//취소 및 이전
				case SWAP_KEY_CLR:
					InitStatusValue();
					Status_GameMode = Game_SelectPart;
			}
			break;
		case 3://게임 시작화면
			switch(SysData){
				case SWAP_KEY_OK:
					Status_Value[1] = 0;
					Status_Value[0] = 4;
			}
			break;
		case 4://게임 플레이!!
			switch(SysData){
				case SWAP_KEY_OK:
					Status_Value[1] = 0;
					Status_Value[0] = 5;
			}
			break;
		case 6://점수 보기
			switch(SysData){
				case SWAP_KEY_OK:
					Status_Value[1] = 0;
					Status_Value[0] = 7;
			}
	}
	return;
}

void ControlTimeAttack(int SysData){
	//Status_Value[0] = SelectChara(Status_Value[0], SysData);
	switch(Status_Value[0]){
		case 0:
		case 1:
			if(SysData == SWAP_KEY_OK){
				Status_Value[0] = 2;
				Status_Value[1] = 0;
			}
			break;
		case 3://게임 시작화면
			switch(SysData){
				//임시 다음 스테이지
				case SWAP_KEY_OK:
					Status_Select[0]++;	//다음 스테이지
					Status_Value[1] = 0;
					Status_Value[0] = 4;
					break;
				//임시 점수보기로
				case SWAP_KEY_CLR:
					Status_Value[1] = 0;
					Status_Value[0] = 6;
			}
			break;

		case 7://점수 보기
			switch(SysData){
				case SWAP_KEY_OK:
					Status_Value[1] = 0;
					Status_Value[0] = 8;
			}
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

/*
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
*/

void ControlStage(int SysData){
	if((Status_MovingDirection == SysData && Option_AutoPush == Yes && Status_MoveSuccess == No)
	|| SysData == SWAP_KEY_OK){
		PushStone();
		return;
	}

	if(SysData == SWAP_KEY_RELEASE){
		Status_Moving = No;
		return;
	}else{
		switch(SysData){
			case SWAP_KEY_UP:
			case SWAP_KEY_DOWN:
			case SWAP_KEY_LEFT:
			case SWAP_KEY_RIGHT:
				Status_Moving = Yes;
				Status_MovingDirection = SysData;
				Status_MoveSuccess = MovePlayer(Status_MovingDirection);
				break;
			case SWAP_KEY_OK:
				Status_MovingDirection = Null;
				PushStone();
				break;
		}
	}
}