/*
 * UpdateNeoPixel - uses time information to set pixel color and updates pixels
 * 
 * DAP - 09-28-2021 initial rev
 */

void UpdateNeoPixel()
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
    pixels.setPixelColor(3,pixels.Color(PixColorRed,0,0));
    pixels.setPixelColor(4,pixels.Color(0,PixColorGreen,0));
    pixels.setPixelColor(5,pixels.Color(0,0,PixColorBlue));
     
    pixels.show();
  
}


void DisplayNeoPixel()
{
    int Button_1Value = digitalRead(BUTTON_1);    //set up an int var and set it to the value read on BUTTON_1

  if (Button_1Value == LOW)  //this will compare the int var above to a value (LOW)
  {                           //if you push the button the cycle will start all over again
    while(PixelCycles > 0)    //we want to do something a bunch of times or while some condition is "right"
    {
      Serial.println("top of UpdateNeoPixel");
      Serial.println(Button_1Value);
      rainbow(100);           //here we are calling a function to run (look for it below)
      rainbowCycle(100);      //another function call
      --PixelCycles;          //this is a decrement, which means we take the var and subtract '1' from it's value
      Serial.println(PixelCycles);
    }
   
    if (PixelCycles <= 0) //check to see if we should turn off pixels
    {
      TurnOFFPixels();    //turn off pixels
      PixelCycles = 6;    //reset the count down
    }    
  }//end if (Button_1Value == HIGH)
  else
  {
            //I got nothing for here yet
  }
}//end void DisplayNeoPixel()

void rainbow(uint8_t wait)
{
  uint16_t i, j;
  Serial.println("top of rainbow");
  for(j=0; j<256; j++) 
  {
    Serial.println("inside j for loop");
    for(i=0; i<pixels.numPixels(); i++) 
    {
      Serial.println("inside i for loop");
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}//end void rainbow(uint8_t wait)

void rainbowCycle(uint8_t wait)
{
  uint16_t i, j;
      Serial.println("top of Rainbow Cycle");
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
          Serial.println("inside 2nd j for loop");
    for(i=0; i< pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
      Serial.println("inside 2nd i for loop");
    }
    pixels.show();
    delay(wait);
  }
}// end void rainbowCycle(uint8_t wait)

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
 
  if(WheelPos < 85)
  {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
 
  else if(WheelPos < 170)
  {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
 
  else
  {
     WheelPos -= 170;
     return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}//end uint32_t Wheel(byte WheelPos)

void TurnOFFPixels()
{
    pixels.clear();//set to 0
    pixels.show();//light 'em up (or not...)
    //pixels.setPixelColor(0,pixels.Color(0,0,0));
    //pixels.Show();
}// end void TurnOFFPixels()
