/*
 * UpdateSerial - Added to project for debugging code
 * this can be removed later if space becomes scarce
 * 
 * DAP 09-17-2021 Initial setup
 * DAP 09-28-2021 Added more serial messages to debug code
 */

void UpdateSerial()
{
        Serial.print("Position 1 Value: ");
        Serial.println(pos1);
        Serial.print("Seconds Value: ");
        Serial.println(seconds);
        Serial.print("PixColorRed Value: ");
        Serial.println(PixColorRed);
        Serial.print("PixColorGreen Value: ");
        Serial.println(PixColorGreen);
        Serial.print("PixColorBlue Value: ");
        Serial.println(PixColorBlue);
//        Serial.print("Minutes Value: ");
//        Serial.println(minutes);
//        Serial.print("Position 3 Value: ");
//        Serial.println(pos3);
//        Serial.print("Seconds Value: ");
//        Serial.println(hours);
       
}// end of void UpdateSerial()
