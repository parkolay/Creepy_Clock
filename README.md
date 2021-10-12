# Creepy_Clock
Creepy Doll head clock with moving features using Arduino Nano (ATmega328P)
//this ended up being a skull instead of a disembodied doll head
//I used https://www.thingiverse.com/thing:3803762 as my 3d model base

/* Creepy Clock
 *  using an RTC(DS3231), some NeoPixels, and some servos 
 *  make a clock that the head and eyes move and light up acording to the time
 *  or something like that...?
 *  LOTS of code copied from multiple examples
 *  09-29-2021

Using library Wire at version 1.0 in folder: C:\Users\XXXXX\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.3\libraries\Wire 
Using library Servo at version 1.1.5 in folder: C:\Arduino\libraries\Servo 
Using library U8g2 at version 2.26.14 in folder: C:\Arduino\libraries\U8g2 
Using library RTCLib at version 1.5.4 in folder: C:\Arduino\libraries\RTCLib 
Using library Adafruit_NeoPixel at version 1.2.5 in folder: C:\Arduino\libraries\Adafruit_NeoPixel 
Using library SPI at version 1.0 in folder: C:\Users\XXXXX\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.3\libraries\SPI 
"C:\\Users\\XXXXX\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "C:\\Users\\XXXXX\\AppData\\Local\\Temp\\arduino_build_83623/Creepy_Clock_10-12-2021.ino.elf"
Sketch uses 17196 bytes (55%) of program storage space. Maximum is 30720 bytes.
Global variables use 1103 bytes (53%) of dynamic memory, leaving 945 bytes for local variables. Maximum is 2048 bytes.
