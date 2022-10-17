/*
 * UpdateTime - Reads the RTC and set multiple varibles for use in other parts of the code
 *  pinout +5V-SDA-SCL-N/C-GND I think the N/C is an alarm pin...?
 * 
 * DAP - 09-17-2021 Initial rev
 * DAP - 09-28-2021 added more vars 
 */

 



void SetupRTC()
{
  //initialize RTC
  rtc.begin();
      //rtc.adjust(DateTime(__DATE__, __TIME__));   //--> this is to force the time is it is set to something already
    if (! rtc.isrunning()) 
    {
      Serial.println("RTC is NOT running!");
      // following line sets the RTC to the date & time this sketch was compiled
      rtc.adjust(DateTime(__DATE__, __TIME__));
      
    }

  Serial.println("RTC has begun");
}

void UpdateTime()
{
  DateTime now = rtc.now();
//  strncpy(TimeBuffer,"DD.MM.YY  hh:mm:ss\0",100); //this formats the TimeBuffer array
//  TimeReadout = (now.format(TimeBuffer));
//  Serial.println(strncpy(TimeReadout, TimeBuffer, 20);
  //Serial.println(now.format(TimeBuffer));
      
    seconds = now.second();
    minutes = now.minute();
    hours   = now.hour();
    days    = now.day();
    months  = now.month();
    years   = (now.year() - 2000);  //remove the first 2 digits
}// end void UpdateTime()
