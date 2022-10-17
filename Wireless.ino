// Digital pin used to connect to the Tx modules data input pin
// The instructions I read said that the Antenna should be ~13cm
// but 1/4 wave I calculated for 315MHz is ~23.8cm (23.793052222222222cm)
// using ~13cm worked poorly, using ~23.8cm worked well.

void Setup_RxWireless()
{
  // Initialise the Rx part of the library 
  boolean Rxresult = HCWireless.rxInit(RX_PIN, RX_BUFFER_SIZE);

  if(!Rxresult)
  {
    Serial.println("Error: Can't allocate memory for Rx buffer");
    while(1);
  }
    Serial.println("initializing Wireless Rx DONE. ");
}

void RxWireless()
{
    // Check to see if any data has been received...
  byte size = HCWireless.available();

  if(size)
  {
    // ...if so then transfer the data out of the Rx buffer and into the structure 
    HCWireless.read(Rxdata);

    // Print out the contents of the structure
    Serial.println(Rxdata.Rx_Humidity);
    Serial.println(Rxdata.Rx_Pressure);
    Serial.println(Rxdata.Rx_Temperature);
    Serial.println(Rxdata.Rx_Altitude);
    Serial.println(Rxdata.Rx_DewPoint);
    Serial.println();
  }

}


