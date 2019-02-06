// JK TEST TIMER

// SETUP
void setup()
{
  Serial.begin(9600);
}

// LOOP
void loop()
{
  unsigned long micro_sec = millis();
  unsigned long sec = millis()/1000;
  int sec_01 = sec%10;
  int sec_10 = (sec/10)%10;
  int min_01 = (sec/100)%10;
  int min_10 = (sec/1000)%10;

  Serial.print(min_10);
  Serial.print(" : ");
  Serial.print(min_01);
  Serial.print(" : ");
  Serial.print(sec_10);
  Serial.print(" : ");
  Serial.print(sec_01);
  Serial.println();
  delay(1000);
}
