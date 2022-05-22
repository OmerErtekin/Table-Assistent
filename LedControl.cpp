#include "LedControl.h"
bool isOpened = false;

void CheckTheLight(int roleOut)
{
    int light = analogRead(A4);
    Serial.println("Işık değeri : ");
    Serial.print(light);
    if(light > 200 && isOpened == false)
    {
      isOpened = true;
      SetTheLamp(true,roleOut);
    }
    else
    {
      isOpened = false;
      SetTheLamp(false,roleOut);
    }
    delay(500);
}

void SetTheLamp(bool willOpen,int roleOut)
{
  if(willOpen)
  {
    digitalWrite(roleOut,HIGH);
  }
  else
  {
    digitalWrite(roleOut,LOW);
  }
}

void SetRoleAtStart(int roleOut)
{
  pinMode(roleOut,OUTPUT);
  digitalWrite(roleOut,LOW);
}
