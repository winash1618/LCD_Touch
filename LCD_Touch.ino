#include "DEV_Config.h"
#include "LCD_Driver.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "Button.h"
#include <EEPROM.h>

// create enum of button names
// Buttons for the main button

enum STYLE {
  COL0 = 10,
  COL1 = 110,
  COL2 = 180,
  COL3 = 250,
  COL4 = 330,
  COL5 = 400,
  COL6 = 480,
  ROW0 = 10,
  ROW1 = 60,
  ROW2 = 110,
  ROW3 = 160,
  ROW4 = 210,
  ROW5 = 260
};

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
  Go = 5,
  Status = 6
};

enum MEMORY_BUTTON_NAME {
  Memory1 = 1,
  Memory2 = 2,
  Memory3 = 3,
  Memory4 = 4,
  Memory5 = 5
};

enum VALUE_BUTTON_NAME {
  Value1 = 1,
  Value2 = 2,
  Value3 = 3,
  Value4 = 4,
  Value5 = 5
};

enum SPEED_BUTTON_NAME {
  sp1 = 1,
  sp2 = 2,
  sp3 = 3,
  sp4 = 4,
  sp5 = 5,
  sp6 = 6
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


Button btn[] = {
  Button(STYLE::COL0, STYLE::ROW0, STYLE::COL1, STYLE::ROW1, "Home", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Home),
  Button(STYLE::COL0, STYLE::ROW1, STYLE::COL1, STYLE::ROW2, "Stop", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Stop),
  Button(STYLE::COL0, STYLE::ROW2, STYLE::COL1, STYLE::ROW3, "Live", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Live),
  Button(STYLE::COL0, STYLE::ROW3, STYLE::COL1, STYLE::ROW4, "Manual", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Manual),
  Button(STYLE::COL0, STYLE::ROW4, STYLE::COL1, STYLE::ROW5, "Go", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Go),
  
  Button(STYLE::COL0, STYLE::ROW5, STYLE::COL1, STYLE::ROW5, "sp1", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp1),
  Button(STYLE::COL1, STYLE::ROW5, STYLE::COL2, STYLE::ROW5, "sp2", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp2),
  Button(STYLE::COL2, STYLE::ROW5, STYLE::COL3, STYLE::ROW5, "sp3", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp3),
  Button(STYLE::COL3, STYLE::ROW5, STYLE::COL4, STYLE::ROW5, "sp4", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp4),
  // Button(STYLE::COL4, STYLE::ROW5, STYLE::COL5, STYLE::ROW5, "sp5", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp5),
  // Button(STYLE::COL5, STYLE::ROW5, STYLE::COL6, STYLE::ROW5, "sp6", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp6),

  Button(STYLE::COL1, STYLE::ROW0, STYLE::COL2, STYLE::ROW1, "+", BUTTON_CLASS::DisplayButton, DisplayButtonName::Plus1),
  Button(STYLE::COL2, STYLE::ROW0, STYLE::COL3, STYLE::ROW1, "+", BUTTON_CLASS::DisplayButton, DisplayButtonName::Plus2),
  Button(STYLE::COL3, STYLE::ROW0, STYLE::COL4, STYLE::ROW1, "+", BUTTON_CLASS::DisplayButton, DisplayButtonName::Plus3),
  Button(STYLE::COL1, STYLE::ROW1, STYLE::COL4, STYLE::ROW2, "000", BUTTON_CLASS::DisplayButton, DisplayButtonName::Digit1),
  Button(STYLE::COL1, STYLE::ROW2, STYLE::COL2, STYLE::ROW3, "-", BUTTON_CLASS::DisplayButton, DisplayButtonName::Minus1),
  Button(STYLE::COL2, STYLE::ROW2, STYLE::COL3, STYLE::ROW3, "-", BUTTON_CLASS::DisplayButton, DisplayButtonName::Minus2),
  Button(STYLE::COL3, STYLE::ROW2, STYLE::COL4, STYLE::ROW3, "-", BUTTON_CLASS::DisplayButton, DisplayButtonName::Minus3),
  Button(STYLE::COL1, STYLE::ROW3, STYLE::COL4, STYLE::ROW4, "Status", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Status),

  Button(STYLE::COL4, STYLE::ROW0, STYLE::COL5, STYLE::ROW1, "Memory 1", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory1),
  Button(STYLE::COL5, STYLE::ROW0, STYLE::COL6, STYLE::ROW1, "Value 1", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value1),
  Button(STYLE::COL4, STYLE::ROW1, STYLE::COL5, STYLE::ROW2, "Memory 2", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory2),
  Button(STYLE::COL5, STYLE::ROW1, STYLE::COL6, STYLE::ROW2, "Value 2", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value2),
  Button(STYLE::COL4, STYLE::ROW2, STYLE::COL5, STYLE::ROW3, "Memory 3", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory3),
  Button(STYLE::COL5, STYLE::ROW2, STYLE::COL6, STYLE::ROW3, "Value 3", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value3),
  Button(STYLE::COL4, STYLE::ROW3, STYLE::COL5, STYLE::ROW4, "Memory 4", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory4),
  Button(STYLE::COL5, STYLE::ROW3, STYLE::COL6, STYLE::ROW4, "Value 4", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value4),
  Button(STYLE::COL4, STYLE::ROW4, STYLE::COL5, STYLE::ROW5, "Memory 5", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory5),
  Button(STYLE::COL5, STYLE::ROW4, STYLE::COL6, STYLE::ROW5, "Value 5", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value5)
};


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
  GUI_Clear(WHITE);
  for (int i = 0; i < 26; i++) {
    btn[i].draw();
    if (btn[i].class_id == BUTTON_CLASS::ValueButton) {
      btn[i].clear();
      btn[i].displayNumber(EEPROM.read((btn[i].id - 1) * 2));
    }
  }
}
TP_DRAW event;
int num = 0;
void handleDigit(int i);
void modifyDigit(int i);
void loop()
{
  // TP_DrawBoard();
  event = touchEvent();
  if (event.Xpoint != -1 && event.Ypoint != -1) {
    for (int i = 0; i < sizeof(btn) / sizeof(btn[0]); i++) {
      if (btn[i].contains(event.Xpoint, event.Ypoint)) {
        switch (btn[i].class_id) {
          case BUTTON_CLASS::MainButton:
            Serial.println(btn[i].text);
            break;
          case BUTTON_CLASS::SpeedButton:
            Serial.println(btn[i].text);
            break;
          case BUTTON_CLASS::DisplayButton:
            handleDigit(i);
            break;
          case BUTTON_CLASS::MemoryButton:
            performMemoryButtonAction(i);
            break;
          case BUTTON_CLASS::ValueButton:
            updateValueButton(i);
            break;
        }
        break;
      }
    }
  }
  delay(10);
}

void handleDigit(int i)
{
  if (btn[i].id == DisplayButtonName::Plus1)
  {
    Serial.println("plusButton");
    modifyDigit(i, 100);
  }
  else if (btn[i].id == DisplayButtonName::Minus1)
  {
    Serial.println("minusButton");
    modifyDigit(i, -100);
  }
  else if (btn[i].id == DisplayButtonName::Plus2)
  {
    Serial.println("plusButton2");
    modifyDigit(i, 10);
  }
  else if (btn[i].id == DisplayButtonName::Minus2)
  {
    Serial.println("minusButton2");
    modifyDigit(i, -10);
  }
  else if (btn[i].id == DisplayButtonName::Plus3)
  {
    Serial.println("plusButton3");
    modifyDigit(i, 1);
  }
  else if (btn[i].id == DisplayButtonName::Minus3)
  {
    Serial.println("minusButton3");
    modifyDigit(i, -1);
  }
}
void modifyDigit(int i, int val)
{
  num = num + val;
  if (num > 999)
    num = num - val;
  btn[i].clear();
  btn[i].displayNumber(num);
}

void performMemoryButtonAction(int i) {
  Serial.println(btn[i].text);
  EEPROM.write((btn[i].id - 1) * 2, num);
  btn[i + 1].clear();
  btn[i + 1].displayNumber(i);
  delay(5000);
}
void updateValueButton(int index)
{
  Serial.println(btn[index].text);
  Serial.println("valueButton5");
  num = EEPROM.read((btn[index].id - 1) * 2);
  btn[14].clear();
  btn[14].displayNumber(num);
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

