/*#include <MQ2.h>
#include <Wire.h> 
#define Threshold 400
#define MQ2pin 0

int Analog_Input = A0;
float sensorValue;  //variable to store sensor value
int lpg, co, smoke;

MQ2 mq2(MQ2pin);

void setup() {
	Serial.begin(9600); // sets the serial port to 9600
	Serial.println("MQ2 warming up!");
	delay(20000); // allow the MQ2 to warm up
  mq2.begin();
}

void loop() {
  sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  float* values= mq2.read(true);
  lpg = mq2.readLPG();
  //co = values[1];
  co = mq2.readCO();
  //smoke = values[2];
  smoke = mq2.readSmoke();

  /*Serial.print("LPG: ");
  Serial.print(lpg);

  Serial.print("Carbon monoxide: ");
  Serial.print(co);

  Serial.print("Smoke");
  Serial.print(smoke);

  if(sensorValue > Threshold)
  {
    Serial.print(" | Smoke detected!");
  }
  
  Serial.println("");
  delay(2000); // wait 2s for next reading
}*/

#include <MQ2.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal_I2C lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal_I2C lcd(0x3F, 16, 2);
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int Analog_Input = A0;
int lpg, co, smoke;

float sensorValue;

MQ2 mq2(Analog_Input);

void setup(){
  Serial.begin(9600);
  lcd.init();
  //lcd.begin();//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();
  mq2.begin();
  //lcd.print("Hello");
}
void loop(){
  float* values= mq2.read(true); //set it false if you don't want to print the values in the Serial
  //lpg = values[0];
  lpg = mq2.readLPG();
  //co = values[1];
  co = mq2.readCO();
  //smoke = values[2];
  smoke = mq2.readSmoke();

  sensorValue = analogRead(Analog_Input); // read analog input pin 0
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  lcd.setCursor(0,0);
  lcd.print("LPG:");
  lcd.print(lpg);
  lcd.print(" CO:");
  lcd.print(co);
  lcd.setCursor(0,1);
  lcd.print("SMOKE:");
  lcd.print((smoke*100)/1000000);
  lcd.print(" %");
  delay(500);
}

