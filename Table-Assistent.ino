#include "LedControl.h"
#include "Loadcell.h"
//For load cell part
int loadCellDout = 4,loadCellSck = 5;
int servoPin = 9;
//For role and light --Current ldr in = A4
int roleOut = 8;
int buzPin = 6;
unsigned long time1;
unsigned long time2;
void setup()
{
  SetupTheLoadCell(loadCellDout,loadCellSck);
  SetRoleAtStart(roleOut);
  SetupTheServo(servoPin);
  SetupTheBuzzer(buzPin);
  time1 = millis();
}

void loop()
{
  time2 = millis();
  float mass = GetTheMass();
  PrintTheMass(mass);
  if((time2-time1)/ 1000 > 15)
  {
    CheckUserDidDrink(mass);
    time1 = time2;
  }
  CheckTheLight();
}
