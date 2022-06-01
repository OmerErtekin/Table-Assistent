#include <HX711_ADC.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif
#include "Loadcell.h"

//pins:
int HX711_dout = 4; //mcu > HX711 dout pin
int HX711_sck = 5; //mcu > HX711 sck pin
int buzzerPin;
Servo servoMotor;
//HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);

const int calVal_eepromAdress = 0;
unsigned long t = 0;

void SetupTheLoadCell(int doutPin,int sckPin)
{
    HX711_dout = doutPin;
    HX711_sck = sckPin;
    Serial.begin(9600); delay(10);
    Serial.println();
    Serial.println("Starting...");

    LoadCell.begin();
    //LoadCell.setReverseOutput(); //uncomment to turn a negative output value to positive
    float calibrationValue; // calibration value (see example file "Calibration.ino")
    calibrationValue = 696.0; // uncomment this if you want to set the calibration value in the sketch
    #if defined(ESP8266)|| defined(ESP32)
    //EEPROM.begin(512); // uncomment this if you use ESP8266/ESP32 and want to fetch the calibration value from eeprom
    #endif
    EEPROM.get(calVal_eepromAdress, calibrationValue); // uncomment this if you want to fetch the calibration value from eeprom

    unsigned long stabilizingtime = 2000; // preciscion right after power-up can be improved by adding a few seconds of stabilizing time
    boolean _tare = true; //set this to false if you don't want tare to be performed in the next step
    LoadCell.start(stabilizingtime, _tare);
    if (LoadCell.getTareTimeoutFlag()) {
      Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
      while (1);
    }
    else {
      LoadCell.setCalFactor(calibrationValue); // set calibration value (float)
      Serial.println("Startup is complete");
    }
}

void SetupTheBuzzer(int buzzPin)
{
    buzzerPin = buzzPin;
    pinMode(buzzerPin, OUTPUT);
    noTone(buzzerPin);
    Serial.println("setup");
}
void SetupTheServo(int servPin)
{
  servoMotor.attach(servPin);
  servoMotor.write(0);
}
float GetTheMass()
{
    static boolean newDataReady = 0;
    const int serialPrintInterval = 0; //increase value to slow down serial print activity

    // check for new data/start next conversion:
    if (LoadCell.update()) newDataReady = true;

    // get smoothed value from the dataset:
    if (newDataReady) {
      if (millis() > t + serialPrintInterval) {
        float i = LoadCell.getData();
        //Serial.print("Load_cell output val: ");
        //Serial.println(i);
        newDataReady = 0;
        t = millis();
        return i;
      }
    }

    // receive command from serial terminal, send 't' to initiate tare operation:
    if (Serial.available() > 0) {
      char inByte = Serial.read();
      if (inByte == 't') LoadCell.tareNoDelay();
    }

    // check if last tare operation is complete:
    if (LoadCell.getTareStatus() == true) {
      Serial.println("Tare complete");
  }
}
void CheckUserDidDrink(float mass)
{
  if(CheckIsThereAGlass(mass))
  {
      if(mass < 450)
      {
         Serial.println("Suyu içmiş al sana bir bardak daha");
         PlayTheBuzzer(5000);
         PoorTheWater();
      }
      else
      {
        Serial.println("Suyunu iç hemen");
        PlayTheBuzzer(10000);
      }
  }
  else
  {
    PlayTheBuzzer(1000);
    Serial.println("Bardak yok");
  }
  delay(100);
}
void PlayTheBuzzer(int buzTone)
{
  for(int i = 0;i<3;i++)
  {
    tone(buzzerPin, buzTone);
    delay(500);
    noTone(buzzerPin);
    delay(500);
  }  
}
void PoorTheWater()
{
    servoMotor.write(16);
    delay(500);
    servoMotor.write(32);
    delay(500);
    servoMotor.write(48);
    delay(8000);
    servoMotor.write(32);
    delay(500);
    servoMotor.write(16);
    delay(500);
    servoMotor.write(0);
}
bool CheckIsThereAGlass(float currentMass)
{
  return currentMass > 350;
}
void PrintTheMass(float mass)
{
  Serial.print("Current mass : ");
  Serial.println(mass);
  delay(100);
}