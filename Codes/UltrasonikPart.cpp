#include "UltrasonikPart.h"
#include "Loadcell.h"

int checkCount = 0;
int trPin,ecPin;

int GetDistance()
{
  long duration,distance;

  digitalWrite(trPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trPin, LOW);
  
  duration = pulseIn(ecPin, HIGH);
  distance = duration / 58.2;
  return (int)distance;
}

bool CheckIsThereAHuman()
{
  Serial.println(GetDistance());
  return true;
}
void SetUltrasonikSensors(int trigPin,int ecoPin)
{
  pinMode(trigPin,OUTPUT);
  pinMode(ecoPin,INPUT);
  trPin = trigPin;
  ecPin = ecoPin;
}
