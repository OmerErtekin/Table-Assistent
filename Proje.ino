#include "UltrasonikPart.h"
#include "LedControl.h"
#include "Loadcell.h"
//For ultrasonic part
int trigPin = 2,echoPin = 6;
int trigPin2 = 3,echoPin2 = 7;
//For load cell part
int loadCellDout = 4,loadCellSck = 5;
void setup()
{
  SetupTheLoadCell(loadCellDout,loadCellSck);
}

void loop()
{
  PrintTheMass();
}
