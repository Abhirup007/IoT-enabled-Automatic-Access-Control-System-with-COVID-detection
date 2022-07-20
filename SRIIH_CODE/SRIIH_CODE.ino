#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include "MAX30100_PulseOximeter.h"
#include <Servo.h> 
#include <LiquidCrystal_I2C.h>

Servo Servo1;
int servoPin = 3; 
int relay = 4;
int f=0;
int threshold=6.2;
int objectTemp;

LiquidCrystal_I2C lcd(0x26,16,2);
#define REPORTING_PERIOD_MS     1000
PulseOximeter pox = PulseOximeter();
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
uint32_t tsLastReport = 0;

void(* resetFunc) (void) = 0;

void setup()
{
  lcd.init();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  Serial.begin(9600);

  pinMode(relay, OUTPUT);
 
  //begin function for mlx90614 (ir temperature sensor)
  if (!mlx.begin())
  {
    Serial.println("mlx FAILED");
  }
  else
  {
    Serial.println("mlx SUCCESS");
  }
  //begin function for max30100 (pulse oximeter sensor)

  Serial.print("Initializing pulse oximeter..");

  if (!pox.begin())
  {
    Serial.println("pox FAILED");
  }
  else
  {
    Serial.println("pox SUCCESS");
  }
  Wire.setClock(100000) ; 
 }
void loop()
{
  //getting the SPO2 value from max30100 sensor
  pox.update();
  objectTemp=threshold+mlx.readObjectTempC();
  if (millis() - tsLastReport > REPORTING_PERIOD_MS)
  {
//    Serial.println("!!! WELCOME TO SMART HEALTH CARE SYSTEM !!!");
//    Serial.println("===========================================");
    Serial.print("Heart rate:");
    Serial.print(pox.getHeartRate());
    Serial.print("\t SpO2:");
    Serial.print(pox.getSpO2());
    Serial.println("%");
    lcd.clear();
    lcd.print("SpO2 :");
    lcd.print(pox.getSpO2());
    lcd.setCursor (0,5);
    tsLastReport = millis();
    Serial.print("Ambient Temperature = ");
    Serial.print(mlx.readAmbientTempC());
    Serial.print("*C\tHuman Body Temperature = ");
    Serial.print(objectTemp);
    Serial.println("*C");
    lcd.setCursor (0,1);
    lcd.print("Temp :");
    lcd.setCursor (7,1);
    lcd.print(objectTemp);
    lcd.setCursor (9,1);
    lcd.print("*C");
    
    
//    //CONDITION OF THE PROJECT
//    if ((objectTemp>=30)&&(pox.getSpO2()>=92) && (f==0))
//    { 
//      lcd.clear();
//      lcd.setCursor(1,0);
//      lcd.print("Gate Open >>>");
//      Servo1.attach(servoPin);
//      Servo1.write(180); 
//      digitalWrite(relay,HIGH);
//      Serial.println("Relay On");
//      delay(4000);
//      digitalWrite(relay,LOW);
//      Serial.println("Relay Off");
//      Servo1.write(90);
//      delay(500); 
//      resetFunc();
//    }
  }
}
