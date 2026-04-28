#include <stm32f4xx_hal.h>
#include <stm32f429i_discovery.h>
#include <stm32f429i_discovery_lcd.h>

#define XPOS 10
#define YPOS 20
#define HEIGHT 40
#define WIDTH 30
#define LETTER_A 65
#define LETTER_B 66



int main(void)
{
	BSP_LCD_Init();
	while (true) {
		BSP_LCD_SetBackColor(LCD_COLOR_DARKBLUE);
		BSP_LCD_DisplayChar(XPOS,YPOS,LETTER_A);
		HAL_Delay(1000);
		BSP_LCD_DisplayChar(XPOS,YPOS,LETTER_B);
		HAL_Delay(1000);
	}
}
