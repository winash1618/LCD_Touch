#include "DEV_Config.h"
#include "LCD_Driver.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"

void setup()
{
  System_Init();

  Serial.println("3.5inch TFT Touch Shield Touch Demo");
  Serial.println("Init...");
  LCD_SCAN_DIR Lcd_ScanDir = SCAN_DIR_DFT;    //SCAN_DIR_DFT = D2U_L2R
  LCD_Init( Lcd_ScanDir, 200);  

  Serial.println("Init Touch Pad...");
  TP_Init( Lcd_ScanDir );
  TP_GetAdFac();
  TP_Dialog();

  Serial.println("Drawing...");

  // draw a box on screen similar to GUI_DrawRectangle(20, 20, 70, 70, BLUE, DRAW_FULL, DOT_PIXEL_1X1);
  GUI_DrawRectangle(20, 20, 70, 70, BLUE, DRAW_FULL, DOT_PIXEL_1X1);
  // draw box in the center
  GUI_DrawRectangle(200, 120, 280, 200, RED, DRAW_FULL, DOT_PIXEL_1X1);
  // get touch event from 

}

void loop()
{
  // TP_DrawBoard();
  printTouchEvent();

}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

