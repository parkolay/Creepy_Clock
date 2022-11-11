/* Creepy Clock
 *  using an RTC(DS3231), some NeoPixels, and some servos 
 *  make a clock that the head moves according to the time
 *  eyes light up according to RxData
 *  Display values on SSD1306
 *  LOTS of code copied from multiple examples
 *  09-29-2021
 *
*  // Pinout
 *  //  Interrupt D02
 *  //  MQ135 analog Output --> A00
 *  //  TestTemp (debug)    --> A01
 *  //  Interrupt           --> PIN D02 with INT0
 *  //  BUTTON              --> PIN D03 (INT1)
 *  //  NEO_PIXEL(WS2812B)  --> PIN D04
 *  //  servo object  PAN   --> PIN D05
 *  //  servo object  TILT  --> PIN D06
 *  //  Data Rx             --> PIN D08
 *  //  servo object  SWING --> PIN D09
 *  //  servo object  JAW   --> PIN D10
 *  //  SCL                 --> A04 Tied HIGH W/ 3k3 Ohm resistor
 *  //  SDA                 --> A05 Tied HIGH W/ 3k3 Ohm resistor
 *   
 *  
 *  DAP - 09-17-2021 initial rev
 *  DAP - 09-28-2021 Added Pixels and  more time variables
 *  DAP - 10-15-2022 Added RxData to determine "eye" color 
*/

#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include "U8g2lib.h"
#include "RTClib.h"
#include "SolarCalculator.h"
#include "Adafruit_NeoPixel.h"
#include "HCWireless.h"

//Add a buttons for input
//#define BUTTON_1  7
#define BUTTON_2  3

#define NEO_PIN 4

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 2

// Digital pin connected to the Rx modules data output pin
#define RX_PIN 8
#define RX_BUFFER_SIZE 32

// twelve servo objects can be created on most boards this has only 4
Servo myservo1;  // PAN   create servo object to control a servo
Servo myservo2;  // TILT  create servo object to control a servo
Servo myservo3;  // SWING create servo object to control a servo
Servo myservo4;  // JAW   create servo object to control the 'jaw' servo

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //note to self, you must select the CORRECT device type for this to work properly

DS3231 rtc;       //DS3231 rtc support;

//initialize wireless
HCWireless HCWireless;

// Create a structure to hold the received data
typedef struct 
{
  float Rx_Humidity;
  float Rx_Pressure;
  float Rx_Temperature;
  float Rx_Altitude;
  float Rx_DewPoint;  
} Rx_teststruct;

Rx_teststruct Rxdata;

const int Joystick_JAW = 3;  // analog pin used to connect the 'Jaw' slider  --> "Jaw"

int seconds = 0;  // variable to store the seconds from clock
int minutes = 0;  // variable to store the minutes from clock
int hours   = 0;  // variable to store the hours from clock
int days    = 0;  // variable to store the seconds from clock
int months  = 0;  // variable to store the minutes from clock
int years   = 0;  // variable to store the hours from clock

int DSTSwitch_mode = 1;
int DelayPeriod = 10;           //setup for using millis() instead of delay()
unsigned long Current_Time = 0; //the "other part" of millis() (roll over around 50 days which might not work in this application)

// Location
double transit, sunrise, sunset;
double latitude = 39.7565;
double longitude = -77.966;
double HoursOLight = 0;
int utc_offset = -5;

int SunRiseHour = 0;
int SunRiseMinute = 0;
int SunSetHour = 0;
int SunSetMinute = 0;

int PosMapButton = 0;

bool DebugOn = true; //set to true for debug serial messages

int ButtonState = 0;  // variable to read the value from the joystick button

//this didn't work as well as I had hoped for this application, so it was removed from here
//char TimeBuffer [100];  //generate an array for the time display
//char TimeReadout [20];

void setup() 
{
  Wire.begin();         //start the I2C, this is also most likely done inside u8g2
  Serial.begin(57600);  // open a serial connection
    Serial.println("initializing Creepy Clock 10/15/22...");

  Serial.println("initializing SSD1306...");
  u8g2.begin();         //start the display
  Serial.println("initializing SSD1306 DONE. ");

  Serial.println("initializing Servo Control...");
  SetupServo();
     
  Serial.println("initializing Wireless Rx...");
  Setup_RxWireless();

  Serial.println("initializing DS3231...");
  SetupRTC();          //start the clock

  
//This will need to be commented out to run other code
//If NOT, the clock will rest to the compile time every time it is powered ON
//rtc.adjust(DateTime(__DATE__, __TIME__)); // force the adjust if the cock is already running

  pixels.begin();       // This initializes the NeoPixel library.
     Serial.println("initializing WS2812B...");
  
  //pinMode(BUTTON_1, INPUT_PULLUP);  // initialize the button pin as an input with an internal pull up resistor :
  pinMode(BUTTON_2, INPUT_PULLUP);  // initialize the button pin as an input with an internal pull up resistor :

  PosMapButton = digitalRead(BUTTON_2);   //read the position Map button input only at startup

  // connect AREF to 3.3V and use that as VCC, less noisy!  
  //thank you for the tip Lady Ada
  analogReference(EXTERNAL);  
  
  Serial.println("initializing Creepy Clock DONE. ");
}

void loop() 
{
      UpdateTime();       //this will jump to update the time
      UpdateClockServo();      //this will jump to update the servo position
      RxWireless();
      // UpdateSerial();     //this will jump to update the serial (debug) output
      UpdateNeoPixelTemp();   //this will jump to update the pixel colors
      u8g2.firstPage();
      //delay(100); //there is already enough going on 
      do 
      {
        UpdateDisplay();  //this will jump to update the display
      } 
      while ( u8g2.nextPage() );
      

} //end void loop() 
