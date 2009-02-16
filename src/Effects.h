/*
	PushStone에 사용할 애니매이션 및 이펙트 관련
	by www.Ahyane.net ^^*
*/

//-------------------- 변경 없을 정의 --------------------//
//운동 타입
#define Movement_Straight	0
#define Movement_FadeIn		1
#define Movement_FadeOut	2
#define Movement_Circular	3

//경로 타입
#define Guide_Straight		0
#define Guide_LeftCurve		1
#define Guide_RightCurve	2
#define Guide_ZigZagCurve	3
#define Guide_LeftGourd		4
#define Guide_RightGourd	5
#define Guide_ZigZagGourd	6
#define Guide_LeftEdge		7
#define Guide_RightEdge		8

//반환 포인트
struct Position{
	int X;
	int Y;
}UnitReturnPosition, UnitRotated;

//해당 프레임의 애니매이션 좌표를 구함
void GetAnimationPosition(int StartX, int StartY, int EndX, int EndY, int CurrentFrame, int TotalFrame
						, int MovementType, int MovementDgree, int GuideType, int GuideDgree){
	struct Position TempPoint;
	int Length;
	int Angle;
	int i;

	//Straight-Straight
	if(MovementType == Movement_Straight && GuideType == Guide_Straight){
		UnitReturnPosition.X = StartX + (EndX - StartX) * CurrentFrame / TotalFrame;
		UnitReturnPosition.Y = StartY + (EndY - StartY) * CurrentFrame / TotalFrame;
		return;
	}
	
	//Other	
	Length = Sqrt(((EndX - StartX) * (EndX - StartX) + (EndY - StartY) * (EndY - StartY)));
	Angle = GetAngle(StartX, StartY, EndX, EndY);
	
	//속도선택
	switch(MovementType){
		case Movement_Straight:
			TempPoint.X = (Length) * CurrentFrame / TotalFrame;
			break;

		case Movement_FadeIn:
			TempPoint.X = (Length) * CurrentFrame / TotalFrame;
			for(i = 0; i < MovementDgree; i++){
				TempPoint.X = TempPoint.X * CurrentFrame / TotalFrame;
			}
			break;

		case Movement_FadeOut:
			TempPoint.X = (Length) * (TotalFrame - CurrentFrame) / TotalFrame;
			for(i = 0; i < MovementDgree; i++){
				TempPoint.X = TempPoint.X * (TotalFrame - CurrentFrame) / TotalFrame;
			}
			TempPoint.X = Length - TempPoint.X;
			break;
		
		case Movement_Circular:
			TempPoint.X = (Length) * Sin100(90 * CurrentFrame / TotalFrame) / 100;
			for(i = 0; i < MovementDgree; i++){
				TempPoint.X = TempPoint.X * Sin100(90 * CurrentFrame / TotalFrame) / 100;
			}
			break;
	}

	//경로선택
	switch(GuideType){
		case Guide_Straight:
			TempPoint.Y = 0;
			break;
		
		case Guide_LeftCurve:
			TempPoint.Y = Sin100(180 * TempPoint.X / Length) * GuideDgree / 100;
			break;

		case Guide_RightCurve:
			TempPoint.Y = -Sin100(180 * TempPoint.X / Length) * GuideDgree / 100;
			break;

		case Guide_ZigZagCurve:
			TempPoint.Y = Sin100(360 * TempPoint.X / Length) * GuideDgree / 100;
			break;

		case Guide_LeftGourd:
			TempPoint.Y = Sin100(180 * CurrentFrame / TotalFrame) * GuideDgree / 100;
			break;

		case Guide_RightGourd:
			TempPoint.Y = -Sin100(180 * CurrentFrame / TotalFrame) * GuideDgree / 100;
			break;

		case Guide_ZigZagGourd:
			TempPoint.Y = Sin100(360 * CurrentFrame / TotalFrame) * GuideDgree / 100;
			break;

		case Guide_LeftEdge:
			TempPoint.Y = Length - Abs(Length - TempPoint.X * 2);
			break;
		
		case Guide_RightEdge:
			TempPoint.Y = - Length + Abs(Length - TempPoint.X * 2);
			break;
	}

	GetRotatePoint(TempPoint.X, TempPoint.Y, Angle);
	UnitReturnPosition.X = StartX + UnitRotated.X;
	UnitReturnPosition.Y = StartY + UnitRotated.Y;

	return;
}

//포인트 회전위치
void GetRotatePoint(int X, int Y, int Angle){
	UnitRotated.X = (X * Sin100(Angle)/100 + Y * Cos100(Angle)/100);
	UnitRotated.Y = (X * Cos100(Angle)/100 - Y * Sin100(Angle)/100);
}

//두 점에 대한 각도 구하기
int GetAngle(int BaseX, int BaseY, int TargetX, int TargetY){
	int Length;
	int Angle;

	if(BaseX < TargetX && BaseY == TargetY){
		return 0;
	}else if(BaseX == TargetX && BaseY < TargetY){
		return 90;
	}else if(BaseX > TargetX && BaseY == TargetY){
		return 180;
	}else if(BaseX == TargetX && BaseY > TargetY){
		return 270;
	}else if(BaseX == TargetX && BaseY == TargetY){
		return Null;
	}else{
		Length = Sqrt(((TargetX - BaseX) * (TargetX - BaseX) + (TargetY - BaseY) * (TargetY - BaseY)) *100);

		if(Length < 256){
			Angle = Abs(ArcSin100((TargetY - BaseY) * 1000 / Length));
		}else{
			Length = Sqrt((TargetX - BaseX) * (TargetX - BaseX)	+ (TargetY - BaseY) * (TargetY - BaseY));
			Angle = Abs(ArcSin100((TargetY - BaseY) * 100 / Length));
		}

		//2사분면
		if(BaseX > TargetX && BaseY < TargetY){
			Angle = Angle - 90;
		//3사분면
		}else if(BaseX > TargetX && BaseY > TargetY){
			Angle = -90 - Angle;
		//4사분면
		}else if(BaseX < TargetX && BaseY > TargetY){
			Angle = Angle - 270;
		//1사분면
		}else{
			Angle = 90 - Angle;
		}
		return Angle;
	}
}

/*
//도형 회전
void RotatePolygon(int *VX, int *VY, int AngleX, int AngleY, int AngleZ, int DgreeX, int DgreeY, int Spread){
	int TX[4], TY[4];
	int UX, UY;
	int DX, DY;
	int VEdge = sizeof(VX);
	int i;

	for(i = 0; i < VEdge; i++){
		UX = *(VX+i) + Spread;
		UY = *(VY+i) + Spread;
		DX = (UX * Sin100(AngleZ)/100 + UY * Cos100(AngleZ)/100);
		DY = (UX * Cos100(AngleZ)/100 - UY * Sin100(AngleZ)/100);
		UX = (DX * Sin100(AngleY)/100 + DY * Cos100(AngleY)/100);
		UY = (DX * Cos100(AngleX)/100 - DY * Sin100(AngleX)/100);
		TX[i] = UX + DgreeX;
		TY[i] = UY + DgreeY;
	}
	FillPoly(TX, TY, VEdge);		
}
*/

/*
void ShowIcon(){
	int i;
	
	if(Status_Value1 == 0){
		Temp1[0] = 00;Temp2[0] = 15;
		Temp1[1] = 30;Temp2[1] = 00;
		Temp1[2] = 15;Temp2[2] = 15;
		Temp1[3] = 30;Temp2[3] = 30;
	}else if(Status_Value1 < 100){
		Clear(S_WHITE);
		if(Status_Value2 < 360) Status_Value2 += 10;
		else Status_Value2 = 0;
		SetColorRGB(200,200,200);
		RotatePolygon(Temp1, Temp2, 4, 240, 100, Status_Value2 +  30, 0, 0);
		RotatePolygon(Temp1, Temp2, 4, 240, 100, Status_Value2 + 150, 0, 0);
		RotatePolygon(Temp1, Temp2, 4, 240, 100, Status_Value2 + 270, 0, 0);
		SetColor(S_SKY);
		RotatePolygon(Temp1, Temp2, 4, 240, 100, Status_Value2      , 0, 0);
		RotatePolygon(Temp1, Temp2, 4, 240, 100, Status_Value2 + 120, 0, 0);
		RotatePolygon(Temp1, Temp2, 4, 240, 100, Status_Value2 + 240, 0, 0);
	
		CopyImage(110, 170, Img_AhyaneIcon);
		SetFontType(S_FONT_MEDIUM, S_BLACK, S_BLACK, S_ALIGN_CENTER);
		DrawStr(120, 270, "Ahyane");
		DrawStr(120, 280, "- 2009.2 -");
		DrawStr(120, 290, "http://www.ahyane.net");

	}else{
		Clear(S_WHITE);
		Status_Value1 = 0;
		Status_Value2 = 0;
		Status_GameMode = Game_Title;
		return;
	}
	Status_Value1++;	//타이머용
}
*/