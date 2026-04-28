#include <stm32f4xx_hal.h>
#include <stm32f429i_discovery.h>
#include <stm32f429i_discovery_lcd.h>
#include <cstdio>

#define LINE_NUMBER 1





int main(void)
{
	unsigned int uiCounter {0};
	char cNum [2];
	BSP_LCD_Init();
	BSP_LCD_SetBackColor(LCD_COLOR_DARKBLUE);
	while (true) {
		sprintf(cNum, "%d",uiCounter);
		BSP_LCD_DisplayStringAtLine(LINE_NUMBER,reinterpret_cast<uint8_t*>(cNum));
		HAL_Delay(300);
		++uiCounter;

	}
}
