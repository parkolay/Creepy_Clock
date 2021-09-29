/*
 * UpdateServo  - Updates the servos postion 
 * 
 * DAP - 09-17-2021 Initial rev
 * DAP - 09-28-2021 Moved "stuff" around
 */
 
void UpdateServo()
{
  UpdatePos();
  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(pos3);
}//end void UpdateServo()

void UpdatePos()
{
    //map the time varible range to the servo position range
//    pos1 = map(seconds, 0, 59, 0, 360); //another way to do the same thing
    pos1 = map(seconds, 0, 59, -180, 180);//see notes below
    pos2 = map(minutes, 0, 59, -180, 180);
    pos3 = map(hours,   0, 23, 0, 180);  

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
