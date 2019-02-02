// LIBRARIES
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h> 





// DEFINE
#define PIN_TRIG 2
#define PIN_ECHO 3
#define PIN_TOUCH_B 4
#define PIN_TOUCH_S 5
#define PIN_NEOPIXEL 6
#define PIN_B 7
#define PIN_SERVO_R 9
#define PIN_SERVO_L 10
#define PIN_MOON_R 11
#define PIN_MOON_L 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(19, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo wolfR;
Servo wolfL;
Servo moonR;
Servo moonL;
int battery = 5;
int start = 0;
int wolf = 0;
int moon = 0;






// SETUP
void setup()
{
  lcd.init();
  lcd.backlight();
  strip.begin(); //네오픽셀을 초기화하기 위해 모든LED를 off시킨다
  strip.show();
  pinMode(PIN_TOUCH_B, INPUT);             // 디지털 3번핀을 입력모드로 설정
  pinMode(PIN_TOUCH_S, INPUT);
  Serial.begin(9600);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  wolfR.attach(PIN_SERVO_R);
  wolfL.attach(PIN_SERVO_L);
  moonR.attach(PIN_MOON_R);
  moonL.attach(PIN_MOON_L);
}






// LOOP
void loop()
{
  // unsigned long ms = millis();
  // unsigned long sec = millis()/1000;
  long duration, distance;
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, LOW);
  duration = pulseIn(PIN_ECHO, HIGH);
  distance = duration / 29 /2 ;
  Serial.print(distance);
  Serial.println("cm");
  colorWipe(strip.Color(255, 255, 255), 50);
  lcd.setCursor(0, 0);
  lcd.print("Now Battery:");
  lcd.setCursor(12, 0);
  lcd.print(battery);
  lcd.setCursor(13,0);
  lcd.print("0%");
  int B = digitalRead(PIN_TOUCH_B);          // 변수 a를 선언하여 디지털 3번핀의 값을 입력
  int S = digitalRead(PIN_TOUCH_S);
  Serial.print(B);                   // 변수 a를 시리얼 모니터에 출력
  Serial.print(S);
  Serial.println(battery);

 // BATTERY SET
  if(B == 0)
  {
    if(battery == 9)
    {
      battery = 0;
    }
    else
    {
      battery = battery + 1;
    }
  }
  else if(B == 1)
  {
    battery = battery;
  }

// LCD
  if(S == 1)
  {
    lcd.setCursor(0, 1);
    lcd.print("Waiting......");
    start = 0;
  }
  else if(S == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("Charge Start!");
    start = 1;
  }

// BATTERY CHARGE
  if(start == 1)
  {
    // CHARGNING TIME
    unsigned long sec = millis()/1000; // 1초 단위면 millisTime = millis()/1000;
    int sec_01 = sec%10;
    int sec_10 = (sec/10)%10;
    int min_01 = (sec/100)%10;
    int min_10 = (sec/1000)%10;
    // passed_time = min_10 * 10 + min_01 * 1 + sec_10 * 0.1 + sec_01 * 0.01;
    
    // LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(min_10);
    lcd.setCursor(1, 0);
    lcd.print(min_01);
    lcd.setCursor(2, 0);
    lcd.print(":");
    lcd.setCursor(3, 0);
    lcd.print(sec_10);
    lcd.setCursor(4, 0);
    lcd.print(sec_01);
    lcd.setCursor(0, 1);
    lcd.print("Charging");
    int left = 10 - battery;
    // SERVO
    if(battery != 10)
    {
      if(sec_10 == 1){battery = battery + 1;left = left - 1;}
      else if(sec_10 == 2){battery = battery + 1;left = left - 1;for(moon = 0; moon <= 30; moon += 1){moonR.write(moon);moonL.write(30-moon);delay(15);}}
      else if(sec_10 == 3){battery = battery + 1;left = left - 1;for(moon = 0; moon <= 30; moon += 1){moonR.write(moon);moonL.write(30-moon);delay(15);}}
      else if(sec_10 == 4){battery = battery + 1;left = left - 1;for(moon = 0; moon <= 30; moon += 1){moonR.write(moon);moonL.write(30-moon);delay(15);}}
      else if(sec_10 == 5){battery = battery + 1;left = left - 1;for(moon = 0; moon <= 30; moon += 1){moonR.write(moon);moonL.write(30-moon);delay(15);}}
      else if(sec_10 == 6){battery = battery + 1;left = left - 1;for(moon = 0; moon <= 30; moon += 1){moonR.write(moon);moonL.write(30-moon);delay(15);}}
      else if(sec_10 == 7){battery = battery + 1;left = left - 1;for(moon = 0; moon <= 30; moon += 1){moonR.write(moon);moonL.write(30-moon);delay(15);}}
      else if(sec_10 == 8){battery = battery + 1;left = left - 1;for(moon = 0; moon <= 30; moon += 1){moonR.write(moon);moonL.write(30-moon);delay(15);}}
      else if(sec_10 == 9){battery = battery + 1;left = left - 1;for(moon = 0; moon <= 30; moon += 1){moonR.write(moon);moonL.write(30-moon);delay(15);}}
    }
    else if(battery == 10)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Battery: 100%");
      lcd.setCursor(0, 1);
      lcd.print("Charged!");
      for(moon = 180; moon>=0; moon-=1){moonR.write(wolf);moonL.write(180-moon);delay(15);} 
    }
  }
  
// WOLF ARM SERVO
  if(start == 0 && distance <= 10 && battery != 10)
  {
      for(wolf = 0; wolf <= 30; wolf += 1)
      {
        wolfR.write(wolf);
        wolfL.write(30-wolf);
        delay(15);
      }
      for(wolf = 30; wolf>=0; wolf-=1)
      {
        wolfR.write(wolf);
        wolfL.write(30-wolf);
        delay(15);
      } 
  }
  
  delay(1000);  
}






// FUNCTIONS
void colorWipe(uint32_t c, uint8_t wait)
{
  for(uint16_t i=0; i<strip.numPixels(); i++)
  {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
uint32_t Wheel(byte WheelPos)
{
  if(WheelPos < 85)
  {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  else if(WheelPos < 170)
  {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  else
  {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
