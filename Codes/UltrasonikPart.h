#ifndef ULTRASONIKPART_H
#define ULTRASONIKPART_H
#include <Arduino.h>

int GetDistance();
void SetUltrasonikSensors(int trigPin,int ecoPin);
bool CheckIsThereAHuman();
#endif
