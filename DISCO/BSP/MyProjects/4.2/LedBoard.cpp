#include "LedBoard.h"

#include "Keyboard.h"

LedBoard::LedBoard(unsigned int uiLedColumn) : uiLedPos(uiLedColumn){
	uiCurrOn =NONE;
	BSP_LCD_Init();
	BSP_LCD_SetFont(&Font24);
	unsigned int uiLCDHeight = BSP_LCD_GetYSize();
	unsigned int uiButtonCounter= 0;
	for (uiButtonCounter = 0; uiButtonCounter * RectHigh< uiLCDHeight; uiButtonCounter++) {
		  DrawButton(LCD_COLOR_BLUE,uiButtonCounter);
	}
}

void LedBoard::DrawButton(uint32_t FillColor, uint8_t number){

	unsigned int Xpos = uiLedPos * RectWidth;
	unsigned int Ypos = number * RectHigh;
	BSP_LCD_SetTextColor(FillColor);
	BSP_LCD_FillRect(Xpos, Ypos, RectWidth ,RectHigh);
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_DrawRect(Xpos, Ypos,RectWidth,RectHigh);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_RED);

	unsigned int uitextX = Xpos + 5;
	unsigned int uitextY = Ypos + 5;

	BSP_LCD_DisplayChar(uitextX, uitextY, Number0 + number);
}

void LedBoard::On(unsigned int uiLedCtr){
		if (uiLedCtr==uiCurrOn){
			return;
		}
		if (uiCurrOn!=NONE){
			DrawButton(LCD_COLOR_BLUE, uiCurrOn); //sciagamy palucha
		}
		if (uiLedCtr!=NONE){
			DrawButton(LCD_COLOR_GREEN, uiLedCtr); //kladziemy palucha
		}
		uiCurrOn = uiLedCtr;
}
void LedBoard::Off(){
	On(NONE);
}

