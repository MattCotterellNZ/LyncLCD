#include <LiquidCrystal.h>

// initialization
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
boolean isFirstLine = true;
byte mobile[8] = {
  B10000,
  B11111,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
};
byte computer[8] = {
  B11111,
  B10001,
  B10001,
  B11111,
  B00100,
  B11111,
  B11111,
  B00000,
};

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.createChar(0, mobile);
  lcd.createChar(1, computer);
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    if (isFirstLine)
    {
      lcd.setCursor(0,0);
    }
    else
    {
      lcd.setCursor(0,1);
    }
    // clear the screen
    lcd.write("                ");
    // set the correct line
    if (isFirstLine)
    {
      lcd.setCursor(0,0);
    }
    else
    {
      lcd.setCursor(0,1);
    }
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
    // then set the mobile/computer icon
    lcd.setCursor(15,0);
    lcd.print((char)1);
    if (isFirstLine)
    {
      isFirstLine = false;
    }
    else
    {
      isFirstLine = true;
    }
  }
}
