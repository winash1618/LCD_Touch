#include "DEV_Config.h"
#include "LCD_Driver.h"
#include "LCD_GUI.h"
#include "LCD_Touch.h"
#include "Button.h"
#include <EEPROM.h>
#include "Constants.h"
#include "Events.h"

Button btn[] = {
  Button(STYLE::COL0, STYLE::ROW0, STYLE::COL1, STYLE::ROW1, "Home", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Home),
  Button(STYLE::COL0, STYLE::ROW1, STYLE::COL1, STYLE::ROW2, "Stop", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Stop),
  Button(STYLE::COL0, STYLE::ROW2, STYLE::COL1, STYLE::ROW3, "Live", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Live),
  Button(STYLE::COL0, STYLE::ROW3, STYLE::COL1, STYLE::ROW4, "Manual", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Manual),
  Button(STYLE::COL0, STYLE::ROW4, STYLE::COL1, STYLE::ROW5, "Go", BUTTON_CLASS::MainButton, MAIN_BUTTON_NAME::Go),
  
  Button(STYLE::COL0, STYLE::ROW5, STYLE::COL1, STYLE::ROW6, "sp1", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp1),
  Button(STYLE::COL1, STYLE::ROW5, STYLE::COL2, STYLE::ROW6, "sp2", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp2),
  Button(STYLE::COL2, STYLE::ROW5, STYLE::COL3, STYLE::ROW6, "sp3", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp3),
  Button(STYLE::COL3, STYLE::ROW5, STYLE::COL4, STYLE::ROW6, "sp4", BUTTON_CLASS::SpeedButton, SPEED_BUTTON_NAME::sp4),
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

  Button(STYLE::COL4, STYLE::ROW0, STYLE::COL5, STYLE::ROW1, "Mem 1", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory1),
  Button(STYLE::COL5, STYLE::ROW0, STYLE::COL6, STYLE::ROW1, "Val 1", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value1),
  Button(STYLE::COL4, STYLE::ROW1, STYLE::COL5, STYLE::ROW2, "Mem 2", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory2),
  Button(STYLE::COL5, STYLE::ROW1, STYLE::COL6, STYLE::ROW2, "Val 2", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value2),
  Button(STYLE::COL4, STYLE::ROW2, STYLE::COL5, STYLE::ROW3, "Mem 3", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory3),
  Button(STYLE::COL5, STYLE::ROW2, STYLE::COL6, STYLE::ROW3, "Val 3", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value3),
  Button(STYLE::COL4, STYLE::ROW3, STYLE::COL5, STYLE::ROW4, "Mem 4", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory4),
  Button(STYLE::COL5, STYLE::ROW3, STYLE::COL6, STYLE::ROW4, "Val 4", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value4),
  Button(STYLE::COL4, STYLE::ROW4, STYLE::COL5, STYLE::ROW5, "Mem 5", BUTTON_CLASS::MemoryButton, MEMORY_BUTTON_NAME::Memory5),
  Button(STYLE::COL5, STYLE::ROW4, STYLE::COL6, STYLE::ROW5, "Val 5", BUTTON_CLASS::ValueButton, VALUE_BUTTON_NAME::Value5)
};


int num = 0;

int readValueFromEEPROM(int index)
{
  byte high = EEPROM.read((btn[index].id - 1) * 2);
  byte low = EEPROM.read((btn[index].id - 1) * 2 + 1);
  return (word(high, low));
}


void handleDigit(int i)
{
  if (btn[i].id == DisplayButtonName::Plus1)
  {
    Serial.println("plusButton");
    modifyDigit(100);
  }
  else if (btn[i].id == DisplayButtonName::Minus1)
  {
    Serial.println("minusButton");
    modifyDigit(-100);
  }
  else if (btn[i].id == DisplayButtonName::Plus2)
  {
    Serial.println("plusButton2");
    modifyDigit(10);
  }
  else if (btn[i].id == DisplayButtonName::Minus2)
  {
    Serial.println("minusButton2");
    modifyDigit(-10);
  }
  else if (btn[i].id == DisplayButtonName::Plus3)
  {
    Serial.println("plusButton3");
    modifyDigit(1);
  }
  else if (btn[i].id == DisplayButtonName::Minus3)
  {
    Serial.println("minusButton3");
    modifyDigit(-1);
  }
}

void modifyDigit(int val)
{
  num = num + val;
  if (num > 999)
    num = 999;
  if (num < 0)
    num = 0;
  btn[12].clear();
  btn[12].displayNumber(num);
}

void performMemoryButtonAction(int i) {
  Serial.println(btn[i].text);
  EEPROM.write((btn[i].id - 1) * 2,highByte(num));
  EEPROM.write((btn[i].id - 1) * 2 + 1,lowByte(num));
  btn[i + 1].clear();
  btn[i + 1].displayNumber(num);
  delay(5000);
}

void updateValueButton(int index)
{
  Serial.println(btn[index].text);
  Serial.println("valueButton5");
  num=readValueFromEEPROM(index);
  btn[12].clear();
  btn[12].displayNumber(num);
}

Events events;


void setup()
{
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(LIMIT, INPUT_PULLUP);
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
      btn[i].displayNumber(readValueFromEEPROM(i));
    }
  }
}

TP_DRAW event;

void eventControl(int btn)
{
  if(btn == Home)
  {
    events.Home();
    num = 0;
  }
  else if(btn == Stop)
  {
    events.Stop();
  }
  else if(btn == Go)
  {
    events.Go(num);
  }
}

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
            eventControl(btn[i].id);
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

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

