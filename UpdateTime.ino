void UpdateTime()
{
  DateTime now = rtc.now();
    seconds = now.second();
    minutes = now.minute();
    hours   = now.hour();
}
