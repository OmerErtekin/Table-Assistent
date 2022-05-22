#include "UltrasonikPart.h"
#include "LedControl.h"
#include "Loadcell.h"
//For ultrasonic part
int trigPin = 2,echoPin = 6;
int trigPin2 = 3,echoPin2 = 7;
//For load cell part
int loadCellDout = 4,loadCellSck = 5;
//For role and light --Current ldr in = A4
int roleOut = 8;
unsigned long time1;
unsigned long time2;
void setup()
{
  SetupTheLoadCell(loadCellDout,loadCellSck);
  SetRoleAtStart(roleOut);
  SetUltrasonikSensors(trigPin,echoPin,trigPin2,echoPin2);
  time1 = millis();
  Serial.println(time1);
}

void loop()
{
  time2 = millis();
  float mass = GetTheMass();
  if((time2-time1)/ 1000 > 30)
  {
    CheckUserDidDrink(mass);
    time1 = time2;
  }
  //Serial.println((time2-time1)/1000);

  //delay(1000);
}
