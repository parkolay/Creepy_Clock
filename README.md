# Creepy_Clock
Creepy Doll head clock with moving features using Arduino Nano (ATmega328P)
//this ended up being a skull instead of a disembodied doll head
//I used https://www.thingiverse.com/thing:3803762 as my 3d model base
Project currently using an RTC(DS3231), some NeoPixels, and some servos 
 *  make a clock that the head moves acording to the time
 *  eyes light up according to RxData
 *  Display values on SSD1306


/* Creepy Clock
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
 *  DAP - 09-28-2021 Added Pixels and  more time varibles
 *  DAP - 10-15-2022 Added RxData to determine "eye" color
 *  DAP - 11-11-2022 Added Solar SolarCalculator for SunRise SunSet

Servo myservo1;  // PAN   create servo object to control a servo
Servo myservo2;  // TILT  create servo object to control a servo
Servo myservo3;  // SWING create servo object to control a servo
Servo myservo4;  // JAW   create servo object to control the 'jaw' servo

  "use of the [servo] library disables `analogWrite()` (PWM) functionality on pins 9 and 10, whether or not there is a Servo on those pins."
  So use pins 9 && 10 when using Servos...

Using library Wire at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\Wire 
Using library Servo at version 1.1.8 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\libraries\Servo 
Using library U8g2 at version 2.33.15 in folder: D:\Github\libraries\U8g2 
Using library RTCLib by NeiroN at version 1.6.2 in folder: D:\Github\libraries\RTCLib_by_NeiroN 
Using library SolarCalculator at version 2.0.1 in folder: D:\Github\libraries\SolarCalculator 
Using library Adafruit NeoPixel at version 1.10.6 in folder: D:\Github\libraries\Adafruit_NeoPixel 
Using library HCWireless in folder: D:\Github\libraries\HCWireless (legacy)
Using library SPI at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\SPI 
"C:\\Users\\ut4445o\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "C:\\Users\\ut4445o\\AppData\\Local\\Temp\\arduino-sketch-47D6A06096F4E1F4C575CCCF0A883E25/Creepy_Clock.ino.elf"
Sketch uses 26520 bytes (86%) of program storage space. Maximum is 30720 bytes.
Global variables use 1513 bytes (73%) of dynamic memory, leaving 535 bytes for local variables. Maximum is 2048 bytes.
