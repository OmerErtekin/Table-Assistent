#include "UltrasonikPart.h"
#include "LedControl.h"
#include "Loadcell.h"
//For ultrasonic part
int trigPin = 2,echoPin = 6;
int trigPin2 = 3,echoPin2 = 7;
//For load cell part
int loadCellDout = 4,loadCellSck = 5;
int servoPin = 9;
//For role and light --Current ldr in = A4
int roleOut = 8;
unsigned long time1;
unsigned long time2;
void setup()
{
  SetupTheLoadCell(loadCellDout,loadCellSck);
  SetRoleAtStart(roleOut);
  SetUltrasonikSensors(trigPin,echoPin,trigPin2,echoPin2);
  SetupTheServo(servoPin);
  time1 = millis();
}

void loop()
{
  time2 = millis();
  float mass = GetTheMass();
  //PrintTheMass(mass);
  if((time2-time1)/ 1000 > 3600)
  {
    CheckUserDidDrink(mass);
    time1 = time2;
  }
  CheckTheLight();
}
