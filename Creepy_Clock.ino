/* Creepy Clock
 *  using an RTC(DS3231), some NeoPixels, and some servos 
 *  make a clock that the head and eyes move and light up acording to the time
 *  or something like that...?
 *  LOTS of code copied from multiple examples
 *  09-29-2021
 *  
 *  DAP - 09-17-2021 initial rev
 *  DAP - 09-28-2021 Added Pixels and  more time varibles
 *  
*/
#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <U8g2lib.h>
#include "RTClib.h"
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define NEO_PIN 2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 5

//Add a buttons for input
#define BUTTON_1  4
#define BUTTON_2  5


// twelve servo objects can be created on most boards
Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control the 'jaw' servo

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //note to self, you must select the CORRECT device type for this to work properly

DS3231 rtc;       //DS3231 rtc support;

int seconds = 0;  // varible to store the seconds from clock
int minutes = 0;  // varible to store the minutes from clock
int hours   = 0;  // varible to store the hours from clock
int days    = 0;  // varible to store the seconds from clock
int months  = 0;  // varible to store the minutes from clock
int years   = 0;  // varible to store the hours from clock

int pos1    = 0;  // variable to store the servo position 1
int pos2    = 0;  // variable to store the servo position 2
int pos3    = 0;  // variable to store the servo position 3
int pos4    = 0;  // variable to store the servo position 4
int jaw     = 0;  // variable to read the value from the analog pin

const int Joystick_JAW = 3;  // analog pin used to connect the 'Jaw' slider  --> "Jaw"

int PosMapButton = 0;

int ButtonState = 0;  // variable to read the value from the joystick button

int PixelCycles   = 6;  //set a number of cycles before turning OFF pixels
int PixColorRed   = 0;  //varible to control the Red portion of the pixel
int PixColorGreen = 0;  //varible to control the Green portion of the pixel
int PixColorBlue  = 0;  //varible to control the Blue portion of the pixel

//this didn't work as well as I had hoped for this application, so it was removed from here
//char TimeBuffer [100];  //generate an array for the time display
//char TimeReadout [20];

void setup() 
{
  Wire.begin();         //start the I2C, this is also most likely done inside u8g2
  myservo1.attach(8);   // attaches the servo on pin 8 to the servo object
  myservo2.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(10);  // attaches the servo on pin 10 to the servo object
  myservo4.attach(11);  // attaches the servo on pin 11 to the servo object
  Serial.begin(57600);  // open a serial connection
  u8g2.begin();         //start the display
  
  rtc.begin();          //start the clock
  
//This will need to be commented out to run other code
//If NOT, the clock will rest to the compile time every time it is powered ON
//rtc.adjust(DateTime(__DATE__, __TIME__)); // force the adjust if the cock is already running

  pixels.begin();       // This initializes the NeoPixel library.
  
  pinMode(BUTTON_1, INPUT_PULLUP);  // initialize the button pin as an input with an internal pull up resistor :
  pinMode(BUTTON_2, INPUT_PULLUP);  // initialize the button pin as an input with an internal pull up resistor :

  PosMapButton = digitalRead(BUTTON_2);   //read the position Map button input only at startup
  
}

void loop() 
{
      UpdateTime();       //this will jump to update the time
      UpdateServo();      //this will jump to update the servo postion
      UpdateSerial();     //this will jump to update the serial (debug) output
      UpdateNeoPixel();   //this will jump to update the pixel colors
      u8g2.firstPage();
      //delay(100); //there is already enough going on 
      do 
      {
        UpdateDisplay();  //this will jump to update the display
      } 
      while ( u8g2.nextPage() );
      

} //end void loop() 
