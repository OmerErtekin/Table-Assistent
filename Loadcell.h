#ifndef LOADCELL_H
#define LOADCELL_H
#include <Arduino.h>
#include <Servo.h>
void SetupTheLoadCell(int doutPin,int sckPin);
void SetupTheServo(int servPin);
void SetupTheBuzzer(int buzzPin);
float GetTheMass();
void CheckUserDidDrink(float mass);
bool CheckIsThereAGlass(float currentMass);
void PrintTheMass(float mass);
void PoorTheWater();
void PlayTheBuzzer(int buzTone);
#endif
