#include "LedControl.h"
bool isOpened = false;
int roleIn;

void CheckTheLight()
{
    int light = analogRead(A4);
    
    Serial.print("Işık değeri : ");
    Serial.println(light);
    /*delay(50);*/
    if(light < 500 && isOpened == false)
    {

      isOpened = true;
      SetTheLamp(true);
      return;
    }
    else if(isOpened == true && light > 700)
    {

      isOpened = false;
      SetTheLamp(false);
      return;
    }
}

void SetTheLamp(bool willOpen)
{
  if(willOpen)
  {
    digitalWrite(roleIn,HIGH);
  }
  else
  {
    digitalWrite(roleIn,LOW);
  }
}

void SetRoleAtStart(int roleOut)
{
  roleIn = roleOut;
  pinMode(roleOut,OUTPUT);
  digitalWrite(roleOut,LOW);
}
