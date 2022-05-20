/*
 * This file is to define which pin is used for which sensor
 */
#ifndef PIN_NAME_H
#define PIN_NAME_H

#include<Servo.h>//include servo motor library
#include<NewPing.h>//library for sonar sensor
//Pin used for motor driver
#define EN A0//Enable is pin A0
#define PWM 11//PWM for the motor
#define CWPin 12//Clock wise pin
#define CCWPin 9//Counter clock wise pin

//Pin used for 3 IR sensors
#define left_ir 8//left ir sensor
#define mid_ir 7//middle ir sensor
#define rig_ir 4//right ir sensor

//Pin used for servo motor to control direction of the car
#define serPin 6

//Pin used for sonar sensor
#define echoPin 2
#define trigPin 3

//Pin used for gyroscope sensor
#define SCLPin A5
#define SDAPin A4

//define servo motor to control
Servo myServo;


//function to define pin mode 

extern void pin_mode(){
  Serial.begin(115200);
  //Pin mode for motor driver
  pinMode(EN,OUTPUT);
  pinMode(PWM,OUTPUT);
  pinMode(CWPin,OUTPUT);
  pinMode(CCWPin,OUTPUT);
  //Pin mode for ir sensor
  pinMode(left_ir,INPUT);
  pinMode(mid_ir,INPUT);
  pinMode(rig_ir,INPUT);
  //Pin mode for servo motor
  myServo.attach(serPin);
  
  
}

#endif
