/*
 * UpdateDisplay  - Updates the ssd1307 display using u8g2 library
 * 
 * DAP - 09-17-2021 initital rev
 * DAP - 09-28-2021 Added RTC, Pixel and Position information
 */

void UpdateDisplay()
{
  GetLine1();
  GetLine2();
  GetLine3();
  GetLine4();
  GetLine5();
  GetLine6();
} //end void UpdateDisplay()

void GetLine1()
{
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setCursor(0,13);
    //u8g2.print(" "); 
    if (hours <=9)
    {
      u8g2.print("0"); 
    }
    u8g2.print(hours); 
    u8g2.print(":"); 
    if (minutes <=9)
    {
      u8g2.print("0"); 
    }
    u8g2.print(minutes); 
    u8g2.print(":"); 
    if (seconds <=9)
    {
      u8g2.print("0"); 
    }
    u8g2.print(seconds); 
    
    u8g2.setCursor(64,13); //start calendar in the middle
    if (days <=9)
    {
      u8g2.print("0"); 
    }
    u8g2.print(days); 
    u8g2.print("/"); 
    if (months <=9)
    {
      u8g2.print("0"); 
    }
    u8g2.print(months); 
    u8g2.print("/"); 
    u8g2.print(years); 
    u8g2.print(" "); 
         
//  DateTime now = rtc.now(); //I would have liked to not call this here, but 
//  strncpy(TimeBuffer,"DD.MM.YY  hh:mm:ss\0",100); //this formats the TimeBuffer array
//    u8g2.setCursor(0,13);
//    u8g2.setFont(u8g2_font_ncenB10_tr);
//    //u8g2.print(" ");
//    //u8g2.print(strncpy(TimeReadout, TimeBuffer, 20));//this worked but was stepping on the saved values for servo postion
//    u8g2.print(now.format(TimeBuffer));
   
} //end void GetLine1()

void GetLine2()
{
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(0,24);
    //u8g2.print("012345678901234567890"); 

}

void GetLine3()
{
    u8g2.setCursor(0,34);
    u8g2.print("Pix ");
    u8g2.print("R ");
    u8g2.print(PixColorRed);
    u8g2.print(" G ");
    u8g2.print(PixColorGreen);
    u8g2.print(" B ");
    u8g2.print(PixColorBlue);
}

void GetLine4()
{
    u8g2.setCursor(0,44);
    u8g2.print("Position 1 Value ");
    u8g2.print(pos1); 
}

void GetLine5()
{
    
    u8g2.setCursor(0,54);
    u8g2.print("Position 2 Value ");
    u8g2.print(pos2); 
}

void GetLine6()
{
    u8g2.setCursor(0,64);
    u8g2.print("Position 3 Value ");
    u8g2.print(pos3);
}


    //u8g2.print("012345678901234567890"); 
//    u8g2.drawStr(0,13,"Air Quality Sensor");
//    u8g2.drawStr(0,13,"AirQltySensor");
//    u8g2.print(RHRawSensorValue);
//    u8g2.setCursor(25,64);
//    u8g2.print("Tks ");
//    u8g2.setCursor(43,64);
//    u8g2.print(RHSensorValue);
//    u8g2.setCursor(64,64);
//    u8g2.print("V ");
//    u8g2.setCursor(72,64); 
//    u8g2.print(RHValue); 
//    u8g2.setCursor(96,64); 
//    u8g2.print("%RH"); 
