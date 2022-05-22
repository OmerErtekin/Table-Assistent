#ifndef LOADCELL_H
#define LOADCELL_H
#include <Arduino.h>

void SetupTheLoadCell(int doutPin,int sckPin);
float GetTheMass();
void CheckUserDidDrink(float mass);
bool CheckIsThereAGlass(float currentMass);
void PrintTheMass(float mass);
#endif
