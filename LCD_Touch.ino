#include "DEV_Config.h"
#include "LCD_Driver.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "Button.h"
#include <EEPROM.h>

// create enum of button names
// Buttons for the main button

enum BUTTON_CLASS {
  MainButton = 1,
  MemoryButton = 2,
  ValueButton = 3,
  SpeedButton = 4,
  DisplayButton = 5
};

enum MAIN_BUTTON_NAME {
  Home = 1,
  Stop = 2,
  Live = 3,
  Manual = 4,
  Go = 5
  Status = 6
};

enum MemoryButtonName {
  Memory1 = 1,
  Memory2 = 2,
  Memory3 = 3,
  Memory4 = 4,
  Memory5 = 5
};

enum ValueButtonName {
  Value1 = 1,
  Value2 = 2,
  Value3 = 3,
  Value4 = 4,
  Value5 = 5
};

enum SpeedButtonName {
  sp1 = 1,
  sp2 = 2,
  sp3 = 3,
  sp4 = 4,
  sp5 = 5,
};

enum DisplayButtonName {
  Digit1 = 1,
  Digit2 = 2,
  Plus1 = 3,
  Plus2 = 4,
  Plus3 = 5,
  Minus1 = 6,
  Minus2 = 7,
  Minus3 = 8
};

// create array of buttons
Button btn[] = {
  Button(10, 10, 100, 50, "Home", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Home),
  Button(10, 60, 100, 100, "Stop", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Stop),
  Button(10, 110, 100, 150, "Live", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Live),
  Button(10, 160, 100, 200, "Manual", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Manual),
  Button(10, 210, 100, 250, "Go", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Go),
  Button(10, 260, 80, 310, "sp1", BUTTON_CLASS::SpeedButton, SpeedButtonName::sp1),
  Button(90, 260, 160, 310, "sp2", BUTTON_CLASS::SpeedButton, SpeedButtonName::sp2),
  Button(170, 260, 240, 310, "sp3", BUTTON_CLASS::SpeedButton, SpeedButtonName::sp3),
  Button(250, 260, 320, 310, "sp4", BUTTON_CLASS::SpeedButton, SpeedButtonName::sp4),
  Button(320, 260, 390, 310, "sp5", BUTTON_CLASS::SpeedButton, SpeedButtonName::sp5),
  Button(400, 260, 470, 310, "sp6", BUTTON_CLASS::SpeedButton, SpeedButtonName::sp6),
  Button(110, 10, 150, 50, "+", BUTTON_CLASS::DisplayButton, DisplayButtonName::Plus1),
  Button(160, 10, 200, 50, "+", BUTTON_CLASS::DisplayButton, DisplayButtonName::Plus2),
  Button(210, 10, 250, 50, "+", BUTTON_CLASS::DisplayButton, DisplayButtonName::Plus3),
  Button(110, 60, 250, 100, "000", BUTTON_CLASS::DisplayButton, DisplayButtonName::Digit1),
  Button(110, 110, 150, 150, "-", BUTTON_CLASS::DisplayButton, DisplayButtonName::Minus1),
  Button(160, 110, 200, 150, "-", BUTTON_CLASS::DisplayButton, DisplayButtonName::Minus2),
  Button(210, 110, 250, 150, "-", BUTTON_CLASS::DisplayButton, DisplayButtonName::Minus3),
  Button(110, 160, 250, 200, "Status", BUTTON_CLASS::DisplayButton, DisplayButtonName::Status),
  Button(110, 210, 250, 250, "Status 2", BUTTON_CLASS::DisplayButton, DisplayButtonName::Status2),
  Button(260, 10, 360, 50, "Memory 1", BUTTON_CLASS::MemoryButton, MemoryButtonName::Memory1),
  Button(370, 10, 470, 50, "Value 1", BUTTON_CLASS::ValueButton, ValueButtonName::Value1),
  Button(260, 60, 360, 100, "Memory 2", BUTTON_CLASS::MemoryButton, MemoryButtonName::Memory2),
  Button(370, 60, 470, 100, "Value 2", BUTTON_CLASS::ValueButton, ValueButtonName::Value2),
  Button(260, 110, 360, 150, "Memory 3", BUTTON_CLASS::MemoryButton, MemoryButtonName::Memory3),
  Button(370, 110, 470, 150, "Value 3", BUTTON_CLASS::ValueButton, ValueButtonName::Value3),
  Button(260, 160, 360, 200, "Memory 4", BUTTON_CLASS::MemoryButton, MemoryButtonName::Memory4),
  Button(370, 160, 470, 200, "Value 4", BUTTON_CLASS::ValueButton, ValueButtonName::Value4),
  Button(260, 210, 360, 250, "Memory 5", BUTTON_CLASS::MemoryButton, MemoryButtonName::Memory5),
  Button(370, 210, 470, 250, "Value 5", BUTTON_CLASS::ValueButton, ValueButtonName::Value5)
};

  

// Create Home, Stop, Live, Manual, Go buttons
// Button homeButton(10, 10, 100, 50, "Home", 1);
// Button stopButton(10, 60, 100, 100, "Stop", 2);
// Button liveButton(10, 110, 100, 150, "Live", 3);
// Button manualButton(10, 160, 100, 200, "Manual", 4);
// Button goButton(10, 210, 100, 250, "Go", 5);

// Button sp1Button(10, 260, 80, 310, "sp1", 17);
// Button sp2Button(90, 260, 160, 310, "sp2", 18);
// Button sp3Button(170, 260, 240, 310, "sp3", 19);
// Button sp4Button(250, 260, 320, 310, "sp4", 20);
// Button sp5Button(320, 260, 390, 310, "sp5", 21);
// Button sp6Button(400, 260, 470, 310, "sp6", 22);

// Button plusButton(110, 10, 150, 50, "+", 6);
// Button plusButton2(160, 10, 200, 50, "+", 7);
// Button plusButton3(210, 10, 250, 50, "+", 8);

// Button digitButton(110, 60, 250, 100, "000", 9);

// Button minusButton(110, 110, 150, 150, "-", 10);
// Button minusButton2(160, 110, 200, 150, "-", 11);
// Button minusButton3(210, 110, 250, 150, "-", 12);

// Button statusButton(110, 160, 250, 200, "Status", 13);
// Button statusButton2(110, 210, 250, 250, "Status 2", 24);


// Button memoryButton(260, 10, 360, 50, "Memory 1", 13);
// Button valueButton(370, 10, 470, 50, "Value 1", 13);
// Button memoryButton2(260, 60, 360, 100, "Memory 2", 14);
// Button valueButton2(370, 60, 470, 100, "Value 2", 14);
// Button memoryButton3(260, 110, 360, 150, "Memory 3", 15);
// Button valueButton3(370, 110, 470, 150, "Value 3", 15);
// Button memoryButton4(260, 160, 360, 200, "Memory 4", 16);
// Button valueButton4(370, 160, 470, 200, "Value 4", 16);
// Button memoryButton5(260, 210, 360, 250, "Memory 5", 23);
// Button valueButton5(370, 210, 470, 250, "Value 5", 25);

// create value button below memory buttons 


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
  // TP_Dialog();

  Serial.println("Drawing...");

  // draw each button in the array
  for (int i = 0; i < 26; i++) {
    btn[i].draw();
  }

  // homeButton.draw();
  // stopButton.draw();
  // liveButton.draw();
  // manualButton.draw();
  // goButton.draw();

  // sp1Button.draw();
  // sp2Button.draw();
  // sp3Button.draw();
  // sp4Button.draw();
  // sp5Button.draw();
  // sp6Button.draw();

  // plusButton.draw();
  // minusButton.draw();

  // plusButton2.draw();
  // minusButton2.draw();

  // plusButton3.draw();
  // minusButton3.draw();

  // digitButton.draw();

  // statusButton.draw();
  // statusButton2.draw();

  // memoryButton.draw();
  // valueButton.draw();
  // valueButton.clear();
  // valueButton.displayNumber(EEPROM.read(0));
  // memoryButton2.draw();
  // valueButton2.draw();
  // valueButton2.clear();
  // valueButton2.displayNumber(EEPROM.read(4));
  // memoryButton3.draw();
  // valueButton3.draw();
  // valueButton3.clear();
  // valueButton3.displayNumber(EEPROM.read(8)));
  // memoryButton4.draw();
  // valueButton4.draw();
  // valueButton4.clear();
  // valueButton4.displayNumber(EEPROM.read(12));
  // memoryButton5.draw();
  // valueButton5.draw();
  // valueButton5.clear();
  // valueButton5.displayNumber(EEPROM.read(16));
  
}
TP_DRAW event;
int i = 0;
void loop()
{
  // TP_DrawBoard();
  event = touchEvent();
  if (event.Xpoint != -1 && event.Ypoint != -1) {
    if (homeButton.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("Home");
    } 
    if (stopButton.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("Stop");
    } 
    if (liveButton.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("Live");
    } 
    if (manualButton.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("Manual");
    } 
    if (goButton.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("Go");
    } 
    if (sp1Button.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("sp1");
    } 
    if (sp2Button.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("sp2");
    } 
    if (sp3Button.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("sp3");
    } 
    if (sp4Button.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("sp4");
    } 
    if (sp5Button.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("sp5");
    } 
    if (sp6Button.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("sp6");
    } 
    if (plusButton.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("plusButton");
      i = i + 100;
      if (i > 999)
        i = i - 100;
      digitButton.clear();
      digitButton.displayNumber(i);
      // GUI_DisNum(120, 70, i, &Font16, WHITE, BLACK);
    } 
    if (minusButton.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("minusButton");
      i = i - 100;
      if (i < 0)
        i = i + 100;
      digitButton.clear();
      digitButton.displayNumber(i);
      // GUI_DisNum(120, 70, i, &Font16, WHITE, BLACK);
    } 
    if (plusButton2.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("plusButton2");
      i = i + 10;
      if (i > 999)
        i = i - 10;
      digitButton.clear();
      digitButton.displayNumber(i);
      // GUI_DisNum(120, 70, i, &Font16, WHITE, BLACK);
    } 
    if (minusButton2.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("minusButton2");
      i = i - 10;
      if (i > 999)
        i = i + 10;
      digitButton.clear();
      digitButton.displayNumber(i);
      // GUI_DisNum(120, 70, i, &Font16, WHITE, BLACK);
    } 
    if (plusButton3.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("plusButton3");
      i = i + 1;
      if (i > 999)
        i = i - 1;
      digitButton.clear();
      digitButton.displayNumber(i);
      // GUI_DisNum(120, 70, i, &Font16, WHITE, BLACK);
    } 
    if (minusButton3.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("minusButton3");
      i = i - 1;
      if (i < 0)
        i = i + 1;
      digitButton.clear();
      digitButton.displayNumber(i);
      // GUI_DisNum(120, 70, i, &Font16, WHITE, BLACK);
    } 
    if (memoryButton.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("memoryButton");
      EEPROM.write(0, i);
      valueButton.clear();
      valueButton.displayNumber(i);
      delay(5000);
    }
    if (valueButton.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("valueButton");
      i = EEPROM.read(0);
      digitButton.clear();
      digitButton.displayNumber(i);
    }

    if (memoryButton2.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("memoryButton2");
      EEPROM.write(4, i);
      valueButton2.clear();
      valueButton2.displayNumber(i);
      delay(5000);
    }
    if (valueButton2.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("valueButton2");
      i = EEPROM.read(4);
      digitButton.clear();
      digitButton.displayNumber(i);
    }

    if (memoryButton3.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("memoryButton3");
      EEPROM.write(8, i);
      valueButton3.clear();
      valueButton3.displayNumber(i);
      delay(5000);
    }
    if (valueButton3.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("valueButton3");
      i = EEPROM.read(8);
      digitButton.clear();
      digitButton.displayNumber(i);
    }

    if (memoryButton4.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("memoryButton4");
      EEPROM.write(12, i);
      valueButton4.clear();
      valueButton4.displayNumber(i);
      delay(5000);
    }
    if (valueButton4.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("valueButton4");
      i = EEPROM.read(12);
      digitButton.clear();
      digitButton.displayNumber(i);
    }

    if (memoryButton5.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("memoryButton5");
      EEPROM.write(16, i);
      valueButton5.clear();
      valueButton5.displayNumber(i);
      delay(5000);
    }
    if (valueButton5.contains(event.Xpoint, event.Ypoint)) {
      Serial.println("valueButton5");
      i = EEPROM.read(16);
      digitButton.clear();
      digitButton.displayNumber(i);
    }
  }
  delay(10);

}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

