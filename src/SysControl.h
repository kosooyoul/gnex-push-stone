/*
	PushStone 키입력 제어
	by www.Ahyane.net ^^*
*/

void ControlMoveFrame(int FrameName){
	Status_Value[1] = 0;
	Status_Value[0] = FrameName;
}

void ControlIcon(int SysData){
	switch(SysData){
		case SWAP_KEY_OK:
			//스킵1
			if(Status_Value[0] < 6){
				ControlMoveFrame(6);
			//스킵2
			}else if(Status_Value[0] < 11){
				ControlMoveFrame(11);
			}
	}
	return;
}

void ControlTitle(int SysData){
	switch(SysData){
		case SWAP_KEY_OK:
			//스킵
			if(Status_Value[0] < 6){
				ControlMoveFrame(6);
			//게임 선택 메뉴로
			}else if(Status_Value[0] == 6){
				ControlMoveFrame(8);
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
			ControlMoveFrame(2);
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
				ControlMoveFrame(3);
				break;
			case SWAP_KEY_1:	Status_Value[3] = Game_Normal;ControlMoveFrame(3);break;
			case SWAP_KEY_2:	Status_Value[3] = Game_TimeAttack;ControlMoveFrame(3);break;
			case SWAP_KEY_3:	Status_Value[3] = Game_Shop;ControlMoveFrame(3);break;
			case SWAP_KEY_4:	Status_Value[3] = Game_Guide;ControlMoveFrame(3);break;
			case SWAP_KEY_5:	Status_Value[3] = Game_Record;ControlMoveFrame(3);break;
			case SWAP_KEY_6:	Status_Value[3] = Game_Option;ControlMoveFrame(3);break;

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
				ControlMoveFrame(2);
			}
			break;
		case 2://메뉴선택
			switch(SysData){
				case SWAP_KEY_OK:
					//메뉴선택 함
					InitPlayNormalGame(Str_NormalStageNumber[Status_Select[0]]);
					ControlMoveFrame(3);
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
		case 4://게임 시작화면
			switch(SysData){
				case SWAP_KEY_OK:
					ControlMoveFrame(5);
			}
			break;
		case 5://게임 플레이!!
			ControlPlayNormalGame(SysData);
			switch(SysData){
				case SWAP_KEY_CLR:
					ControlMoveFrame(6);
			}
			break;
		case 7://점수 보기
			switch(SysData){
				case SWAP_KEY_OK:
					ControlMoveFrame(8);
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
				ControlMoveFrame(2);
			}
			break;
		case 2://메뉴선택
			switch(SysData){
				case SWAP_KEY_OK:
					//메뉴선택 함
					InitPlayNormalGame(Str_NormalStageNumber[Status_Select[0]]);
					ControlMoveFrame(3);
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
		case 4://게임 시작화면
			switch(SysData){
				case SWAP_KEY_OK:
					ControlMoveFrame(5);
			}
			break;
		case 5://게임 플레이!!
			ControlPlayNormalGame(SysData);
			switch(SysData){
				case SWAP_KEY_CLR:
					ControlMoveFrame(6);
			}
			break;
		case 7://점수 보기
			switch(SysData){
				case SWAP_KEY_OK:
					ControlMoveFrame(8);
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