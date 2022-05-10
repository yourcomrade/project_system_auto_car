/*
 * This file contain functions to control speed and direction of 
 * the car
 */
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H
#include "pin_name.h"

extern void turn(uint8_t degree){
  myServo.write(degree);
}

extern void motor(uint8_t car_speed, char state){
  if(state==1)
  {
    digitalWrite(EN,LOW);
    digitalWrite(CCWPin,LOW);
    digitalWrite(CWPin,LOW);
  }
  if(state==0)
  {
    digitalWrite(EN,HIGH);
    digitalWrite(CWPin,HIGH);
    digitalWrite(CCWPin,LOW);
    analogWrite(PWM,car_speed);
  }
  if(state==2){
    digitalWrite(EN,HIGH);
    digitalWrite(CWPin,LOW);
    digitalWrite(CCWPin,HIGH);
    analogWrite(PWM,car_speed);
  }
}
#endif
