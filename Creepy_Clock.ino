/* Creepy Clock
 *  using am RTC and some servos 
 *  make a clock that the head and eyes move acording to the time
 *  or something like that...?
 *  09-17-2021
 *  
*/
#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <U8g2lib.h>
#include "RTClib.h"

// twelve servo objects can be created on most boards
Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

DS3231 rtc;       //DS3231 rtc support;

int seconds = 0;  // varible to store the seconds from clock
int minutes = 0;  // varible to store the minutes from clock
int hours   = 0;  // varible to store the hours from clock

int pos1 = 0;     // variable to store the servo position 1
int pos2 = 0;     // variable to store the servo position 2
int pos3 = 0;     // variable to store the servo position 3


void setup() 
{
  Wire.begin();         //start the I2C, this is also most likely done inside u8g2
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 10 to the servo object
  myservo3.attach(11);  // attaches the servo on pin 11 to the servo object
  Serial.begin(57600); // open a serial connection
  u8g2.begin();       //start the display
  
  rtc.begin();        //start the clock
  
//This will need to be commented out to run other code
//If NOT, the clock will rest to the compile time every time it is powered ON
//rtc.adjust(DateTime(__DATE__, __TIME__)); // force the adjust if the cock is already running
  
}

void loop() 
{
            UpdateTime();
            UpdatePos();
            UpdateServo();
            UpdateSerial();
            u8g2.firstPage();
          do 
          {
            UpdateDisplay();
          } 
          while ( u8g2.nextPage() );
      

} //end void loop() 
