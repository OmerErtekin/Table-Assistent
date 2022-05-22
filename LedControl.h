#ifndef LEDCONTROL_H
#define LEDCONTROL_H
#include <Arduino.h>


void CheckTheLight(int roleOut);
void SetRoleAtStart(int roleOut);
void SetTheLamp(bool willOpen,int roleOut);

#endif
