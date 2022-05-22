#include "UltrasonikPart.h"
int GetDistance(int trigPin,int ecoPin,int trigPin2,int ecoPin2)
{
  int distance1 = GetByEachSensor(trigPin,ecoPin);
  delayMicroseconds(10);
  int distance2 = GetByEachSensor(trigPin2,ecoPin2);
  return (int)distance1 - (int)distance2;
}

int GetByEachSensor(int trigPin,int ecoPin)
{
  long duration,distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(ecoPin, HIGH);
  distance = duration / 58.2;
  return (int)distance;
}

void UseTheBuzzer(int buzzerPin,float second,bool willOpen)
{
  if(willOpen)
    digitalWrite(buzzerPin,HIGH);
  else
    digitalWrite(buzzerPin,LOW);
}

void SetUltrasonikSensors(int trigPin,int ecoPin,int trigPin2,int ecoPin2)
{
  pinMode(trigPin,OUTPUT);
  pinMode(ecoPin,INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(ecoPin2,INPUT);
}
