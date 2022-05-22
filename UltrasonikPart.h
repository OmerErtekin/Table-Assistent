#ifndef ULTRASONIKPART_H
#define ULTRASONIKPART_H
#include <Arduino.h>

int GetDistance(int trigPin,int ecoPin,int trigPin2,int ecoPin2);
void UseTheBuzzer(int buzzerPin,float second,bool willOpen);
int GetByEachSensor(int trigPin,int ecoPin);
void SetUltrasonikSensors(int trigPin,int ecoPin,int trigPin2,int ecoPin2);
#endif
