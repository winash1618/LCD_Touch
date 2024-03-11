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