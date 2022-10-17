/*
 * UpdateNeoPixel - uses time information to set pixel color and updates pixels
 * 
 * DAP - 09-28-2021 initial rev
 */
// Which pin on the Arduino is connected to the NeoPixels?

int TestTemp      = 0;
int TestVarRed    = 0;
int TestVarBlue   = 0;
int TestVarGreen  = 0;

int PixColorRed   = 0;  //varible to control the Red portion of the pixel
int PixColorGreen = 0;  //varible to control the Green portion of the pixel
int PixColorBlue  = 0;  //varible to control the Blue portion of the pixel

//UpdateNeoPixelTime adjusts the pixel color according to RTC
void UpdateNeoPixelTime()
{
    pixels.clear();//set to 0
    //pixels.show();//light 'em up (or not...)
     //for(int i=0; i<NUMPIXELS; i++) 
     for(int i=0; i<2; i++) //only select and set color for the first two pixels
     {
        //select the color for the RED portion of the pixel
        if (seconds < 30)
        {
          PixColorRed = map(seconds, 0, 29, 6, 125); //difference between 155 - 255 range was minimal 
        }
        if (seconds >=30)
        {
          PixColorRed = map(seconds, 30, 59, 125, 6);// 6 was the lowest value before they turned off
        }
        
        //select the color for the GREEN portion of the pixel
        if (minutes < 30)
        {
          PixColorGreen = map(minutes, 0, 29, 6, 125); //difference between 155 - 255 range was minimal 
        }
        if (minutes >=30)
        {
          PixColorGreen = map(minutes, 30, 59, 125, 6);// 6 was the lowest value before they turned off
        }
        
        //select the color for the BLUE portion of the pixel
        if (hours < 12)
        {
          PixColorBlue = map(hours, 0, 11, 6, 125); //difference between 155 - 255 range was minimal 
        }
        if (hours >=12)
        {
          PixColorBlue = map(hours, 12, 24, 125, 6);// 6 was the lowest value before they turned off
        }
        //I don't have any idea what this will look like...
        //strip.setPixelColor(n, red, green, blue);
        pixels.setPixelColor(i,pixels.Color(PixColorRed,PixColorGreen,PixColorBlue));
     }   
// set the color for the remaining pixels
    // pixels.setPixelColor(3,pixels.Color(PixColorRed,0,0));
    // pixels.setPixelColor(4,pixels.Color(0,PixColorGreen,0));
    // pixels.setPixelColor(5,pixels.Color(0,0,PixColorBlue));
     
    pixels.show();
  
}//end void UpdateNeoPixelTime()

//UpdateNeoPixelTemp adjusts the pixel color according to Rxdata Temp
void UpdateNeoPixelTemp()
{
    int temp = (int(Rxdata.Rx_Temperature));

    pixels.clear();//set to 0
    //pixels.show();//light 'em up (or not...)
     //for(int i=0; i<NUMPIXELS; i++) 
for(int i=0; i<2; i++) //only select and set color for the first two pixels
     {
        //select the color for the RED portion of the pixel
        if (temp >=100)
        {
          PixColorRed   = 125;
          PixColorGreen = 0;
          PixColorBlue  = 0;
        }
        
        if (temp < 100)
        {
          PixColorRed   = map(TestTemp, 50, 100, 6, 125); //difference between 155 - 255 range was minimal
          PixColorGreen = map(TestTemp, 50, 100, 125, 6); //difference between 155 - 255 range was minimal
          PixColorBlue  = 0; 
        }
        if (temp <50)
        {
          PixColorRed = 0;
          PixColorGreen = map(TestTemp, 20, 50, 6, 125);// 6 was the lowest value before they turned off
          PixColorBlue = map(TestTemp, 20, 50, 125, 6);// 6 was the lowest value before they turned off
        }
        if (temp < 20)
        {
          PixColorRed   = map(TestTemp, 0, 20, 37, 6); //difference between 155 - 255 range was minimal
          PixColorGreen = map(TestTemp, 0, 20, 37, 6);// 6 was the lowest value before they turned off
          PixColorBlue  = map(TestTemp, 0, 20, 37, 125);// 6 was the lowest value before they turned off
        }
                
        //I don't have any idea what this will look like...
        //strip.setPixelColor(n, red, green, blue);
        pixels.setPixelColor(i,pixels.Color(PixColorRed,PixColorGreen,PixColorBlue));
     }   
     
    pixels.show();
  
}// end void UpdateNeoPixelTemp()

////UpdateNeoPixelTest adjusts the pixel color according to analog read 1
void UpdateNeoPixelTest()
{
            TestTemp = (analogRead(1) / 10);
        //  PixColorRed = (analogRead(1) / 10);
        //  PixColorBlue = (analogRead(2) / 10);
        //  PixColorGreen = (analogRead(3) / 10);

        //  TestVarRed = PixColorRed;
        //  TestVarBlue = PixColorBlue;
        //  TestVarGreen = PixColorGreen;
        //select the color for the RED portion of the pixel
    
    pixels.clear();//set to 0
    //pixels.show();//light 'em up (or not...)
     //for(int i=0; i<NUMPIXELS; i++) 
     for(int i=0; i<2; i++) //only select and set color for the first two pixels
     {
        //select the color for the RED portion of the pixel
        if (TestTemp >=100)
        {
          PixColorRed   = 125;
          PixColorGreen = 0;
          PixColorBlue  = 0;
        }
        
        if (TestTemp < 100)
        {
          PixColorRed   = map(TestTemp, 50, 100, 6, 125); //difference between 155 - 255 range was minimal
          PixColorGreen = map(TestTemp, 50, 100, 125, 6); //difference between 155 - 255 range was minimal
          PixColorBlue  = 0; 
        }
        if (TestTemp <50)
        {
          PixColorRed = 0;
          PixColorGreen = map(TestTemp, 20, 50, 6, 125);// 6 was the lowest value before they turned off
          PixColorBlue = map(TestTemp, 20, 50, 125, 6);// 6 was the lowest value before they turned off
        }
        if (TestTemp < 20)
        {
          PixColorRed   = map(TestTemp, 0, 20, 37, 6); //difference between 155 - 255 range was minimal
          PixColorGreen = map(TestTemp, 0, 20, 37, 6);// 6 was the lowest value before they turned off
          PixColorBlue  = map(TestTemp, 0, 20, 37, 125);// 6 was the lowest value before they turned off
        }
                
        //I don't have any idea what this will look like...
        //strip.setPixelColor(n, red, green, blue);
        pixels.setPixelColor(i,pixels.Color(PixColorRed,PixColorGreen,PixColorBlue));
     }     
     
    pixels.show();
  
}// end void UpdateNeoPixelTest()

void TurnOFFPixels()
{
    pixels.clear();//set to 0
    pixels.show();//light 'em up (or not...)
    //pixels.setPixelColor(0,pixels.Color(0,0,0));
    //pixels.Show();
}// end void TurnOFFPixels()
