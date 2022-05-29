/* Author: Hoang Minh Le
 * Student number: 511907
 * This file contain functions to control speed and direction of 
 * the car
 */
#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H
#include "pin_name.h"

extern void turn(uint8_t degree){//Function to control steering of the car
  myServo.write(degree);
}

extern void motor(uint8_t car_speed, char state){//Function to control the speed and direction of car
  if(state==1)//Condition to stop the car
  {
    digitalWrite(EN,LOW);
    digitalWrite(CCWPin,LOW);
    digitalWrite(CWPin,LOW);
  }
  if(state==0)//Condition to go forward 
  {
    digitalWrite(EN,HIGH);
    digitalWrite(CWPin,HIGH);
    digitalWrite(CCWPin,LOW);
    analogWrite(PWM,car_speed);
  }
  if(state==2){//Condition to go backward
    digitalWrite(EN,HIGH);
    digitalWrite(CWPin,LOW);
    digitalWrite(CCWPin,HIGH);
    analogWrite(PWM,car_speed);
  }
}
#endif
