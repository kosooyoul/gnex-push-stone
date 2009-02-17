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
		switch(SysData){
			case SWAP_KEY_OK:
				//선택한 메인 메뉴 구분
				switch(Status_Select[0]){
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
						break;
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
			case SWAP_KEY_UP:
			case SWAP_KEY_LEFT:
				//스크롤 중 메뉴 변경
				//if(Scroll_ShowCounter == 0){
					Status_Select[0] = (Status_Select[0] + MAXMainMenu - 1) % MAXMainMenu;
					Scroll_ShowCounter = -MaxShowScroll;
				//}
				break;
			case SWAP_KEY_DOWN:
			case SWAP_KEY_RIGHT:
				//if(Scroll_ShowCounter == 0){
					Status_Select[0] = (Status_Select[0] + 1) % MAXMainMenu;
					Scroll_ShowCounter = MaxShowScroll;
				//}
		}
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
					InitPlayNormalGame(Status_Select[0]);
					Status_Value[1] = 0;
					Status_Value[0] = 3;
					break;
					//메뉴 고르기
				case SWAP_KEY_UP:
				case SWAP_KEY_LEFT:
					//스크롤 중 메뉴 변경
					//if(Scroll_ShowCounter == 0){
						Status_Select[0] = (Status_Select[0] - 1 + MaxNormalStage) % MaxNormalStage;
						Scroll_ShowCounter = MaxShowScroll;
					//}
					break;
				case SWAP_KEY_DOWN:
				case SWAP_KEY_RIGHT:
					//if(Scroll_ShowCounter == 0){
						Status_Select[0] = (Status_Select[0] + 1) % MaxNormalStage;
						Scroll_ShowCounter = -MaxShowScroll;
					//}
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
			ControlPlayNormalGame(SysData);
			switch(SysData){
				case SWAP_KEY_CLR:
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
		case 2:
			if(SysData == SWAP_KEY_OK){
				//다음 스테이지로 설정
				InitPlayNormalGame(Status_Select[0]);
				Status_Value[0] = 3;
				Status_Value[1] = 0;
			}
			break;
		case 3:
			//게임 플레이!!
			ControlPlayNormalGame(SysData);
			switch(SysData){
				case SWAP_KEY_CLR:
					//임시-스테이지 스킵
					Status_Value[0] = 4;
					Status_Value[1] = 0;
					break;
			}
			break;
		case 5://계속 할거야?
			switch(SysData){
				case SWAP_KEY_OK:
					//예-아니오 메뉴 번호[1]
					if(Status_Select[1] == 0){
						Status_Select[0]++;		//다음 스테이지[0]
						Status_Value[0] = 2;
					}else{
						Status_Value[0] = 6;
					}
					Status_Value[1] = 0;
					break;
				case SWAP_KEY_UP:
				case SWAP_KEY_LEFT:
				case SWAP_KEY_DOWN:
				case SWAP_KEY_RIGHT:
					//스크롤 중 메뉴 변경
					////스크롤 중이 아닐때 선택 변경 가능
					//if(Scroll_ShowCounter == 0){
						Status_Select[1] = 1 - Status_Select[1];
						//2개 항목이므로 선택 번호에 따라 스크롤값 부여
						if(Status_Select[1] == 0){
							Scroll_ShowCounter = MaxShowScroll;
						}else{
							Scroll_ShowCounter = -MaxShowScroll;
						}
					//}
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