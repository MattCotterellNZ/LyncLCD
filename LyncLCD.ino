/*
  LiquidCrystal Library - Serial Input
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch displays text sent over the serial port 
 (e.g. from the Serial Monitor) on an attached LCD.
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/LiquidCrystalSerial
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
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
    // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // initialize the serial communications:
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
