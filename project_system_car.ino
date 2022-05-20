/*
 *The main file of the project. 
 */
#include "pin_name.h"
#include "obs_detect.h"
#include "line_detect.h"
#include "motor_control.h"
#define FORWARD 0
#define STOP 1
#define BACK 2
#define my_speed 55
#define an_stra 30//angle to turn straight is 30 degree
#define an_left 70//angle to turn left is 60 degree
#define an_rig 0//angle to turn right is 0 degree
int prev_state = 0;
void setup() {
  // put your setup code here, to run once:
  pin_mode();
}

void loop() {
  // put your main code here, to run repeatedly:
  /*turn(an_stra);
  uint8_t dist=0;//distance for the car
  if(has_obs(&dist)){
    while(has_obs(&dist)){
      Serial.println("Move backward to start avoid obstacle");
     // motor(0,STOP);
      //delay(500);
      motor(50,BACK);//Move backward
      
    }
    motor(0,STOP);
    turn(an_rig);
    delay(200);
    Serial.println("Turn right");
    motor(my_speed,FORWARD);
    delay(1200);
    motor(0,STOP);
    turn(an_left);
    delay(500);
    Serial.println("Turn left");
    motor(60,FORWARD);
    delay (1500);
    
    //turn(an_stra);
    //motor(my_speed,FORWARD);
    //delay(3000);
  }
 motor(35,FORWARD);*/
 /* motor(50,BACK);
  delay(2000);
  motor(0,STOP);
  delay(2000);*/
  /*if(mid()){
    Serial.println("Move forward");
    turn(an_stra);
    motor(my_speed,FORWARD);
    prev_state = 0;
//    delay(120);
  }
  if(left()){
    Serial.println("Turn left and move");
    turn(an_left);
    motor(my_speed,FORWARD);
//    delay(120);
  }
  if(right() || prev_state == 2){
    Serial.println("Turn right and move");
    turn(an_rig);
    motor(my_speed,FORWARD);
//    delay(120);
//    delay(90);
  }
  else{
    Serial.println("No white line detected. Stop");
    motor(my_speed,STOP);
  }
  if ( prev_state == 1){
    while(!mid()) {
      turn(an_rig);
      delay(5);
    }
  }
  else if (prev_state == 2){
    while (!mid()){
      turn(an_left);
      delay(5);
    }
  }
prev_state = 0;*/
for(int i=10;i<255;i+=20){
  motor(i,FORWARD);
  delay(1000);
  Serial.println(i);
}
}
