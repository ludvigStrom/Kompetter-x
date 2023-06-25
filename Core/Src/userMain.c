#include "main.h"
#include "SSD1306.h"

void run(){
	SSD1306_GotoXY(10,30);
	SSD1306_Puts("Kompetter-X", &Font_11x18, 1);
	SSD1306_UpdateScreen();
}
