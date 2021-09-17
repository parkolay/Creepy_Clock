void UpdateDisplay()
{
  GetLine1();
  GetLine2();
  GetLine3();
  GetLine4();
  GetLine5();
  GetLine6();
}

void GetLine1()
{
    u8g2.setFont(u8g2_font_ncenB12_tr);
    u8g2.setCursor(0,13);
    u8g2.print("012345678901234567890"); 
}

void GetLine2()
{
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(0,24);
    u8g2.print("012345678901234567890"); 

}

void GetLine3()
{
    u8g2.setCursor(0,34);
    u8g2.print("012345678901234567890");     
}

void GetLine4()
{
    u8g2.setCursor(0,44);
    u8g2.print("012345678901234567890"); 
}

void GetLine5()
{
    
    //u8g2.setCursor(0,54);
    //u8g2.print("012345678901234567890"); 
}

void GetLine6()
{
    u8g2.setCursor(0,64);
    u8g2.print("012345678901234567890"); 
}

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
