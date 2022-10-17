/*
 * UpdateServo  - Updates the servos postion 
 * 
 * DAP - 09-17-2021 Initial rev
 * DAP - 09-28-2021 Moved "stuff" around
 * DAP - 10-12-2022 Moved more stuff around
 */

int pos1    = 0;  // variable to store the servo position 1
int pos2    = 0;  // variable to store the servo position 2
int pos3    = 0;  // variable to store the servo position 3
int pos4    = 0;  // variable to store the servo position 4
int jaw     = 0;  // variable to read the value from the analog pin

void SetupServo()
{
  myservo1.attach(5);   // attaches the servo on pin 8 to the servo object  PAN
  myservo2.attach(6);   // attaches the servo on pin 9 to the servo object  TILT
  myservo3.attach(9);  // attaches the servo on pin 10 to the servo object SWING
  myservo4.attach(10);  // attaches the servo on pin 11 to the servo object JAW
  Serial.println("initializing Servo Control DONE. ");
}//end of void SetupServo()


void UpdateServo()
{
  //use BUTTON_2 with internal pullup to determine which servo mapping to use

  if (PosMapButton == HIGH) //this is the default state even if there is no switch present 
  {
    UpdateSkullPosition();    
  }
  else
  {
    UpdatePosition();   
  }

  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(pos3);
  myservo4.write(pos4);
  
}//end void UpdateServo()

void UpdatePosition()
{
/*
 *  // map the time varible range to the servo position range
    // pos1 = map(seconds, 0, 59, 0, 360); //another way to do the same thing

 */
    pos1 = map(seconds, 0, 59, -180, 180);//see notes below
    pos2 = map(minutes, 0, 59, -180, 180);
    pos3 = map(hours,   0, 23, 0, 180);  
    pos4 = map(jaw, 0,1023, 0 ,180);
    
      //this will handle the backward second sweep
      //it also makes the movement faster, if that's what is wanted
      //same back and forth as above but "simpler"
//      if (seconds > 30)
//      {
//        pos1 = 360 - pos1; 
//      }
      //same back and forth as above but "simpler"
      if (seconds <30)
      {
        pos1 *= -1;
      }
      if (minutes <30)
      {
        pos2 *= -1;
      }
}//end void UpdatePos()

void UpdateSkullPosition()
{
/*
// remapped for the Skull gimble based on the following results;
 *  //remap the analog read values to servo position values
    //these values were mapped using values read from three axis joystick
    //to get these values mapped properly they will need to be assigned limits after the midpoint evaluation
    pos1 = map(pan,  45, 975, 32, 137); //to be used as hour?  52 shold be around the midpoint
    pos2 = map(tilt, 45, 950, 62, 175);   //to be used as minute? 56 shold be around the midpoint
    pos3 = map(swing,319, 706, 50, 137);    //to be used as seconds? 43 shold be around the midpoint
    pos4 = map(jaw, ?,?,?,?) --> doesn't exist, but maybe it can be every 30 minutes like the regulator clocks?
 */

      if (seconds <30)
      {
        pos1 = map(seconds, 0,59,32,137);
      }
      else if (seconds > 29)
      {
        pos1 = map(seconds, 0,59,137,32);
      }

      if (minutes <30)
      {
        pos2 = map(minutes, 0,59,62,175);
      }
      else if (minutes > 29)
      {
        pos2 = map(minutes, 0,59,175,62);
      }
      
      if (hours <13)
      {
        pos3 = map(hours, 0,23,50,137);
      }
      else if (hours > 12)
      {
        pos3 = map(hours, 0,23,137,50);
      }
// the "real" value will need to be worked out for this application, the value of 180 was used as a place marker      
      pos4 = map(jaw, 0,1023, 0 ,180);
}//end void UpdateSkullPosition()
