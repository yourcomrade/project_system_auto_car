/*
 *The main file of the project. 
 */
#include "pin_name.h"
#include "obs_detect.h"
#include "line_detect.h"
#include "motor_control.h"
#define FORWARD 2
#define STOP 1
#define BACK 0
#define my_speed 50
#define an_stra 30//angle to turn straight is 30 degree
#define an_left 60//angle to turn left is 60 degree
#define an_rig 0//angle to turn right is 0 degree
void setup() {
  // put your setup code here, to run once:
  pin_mode();
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t dist=0;//distance for the car
  if(has_obs(&dist)){
    while(dist<45){
      Serial.println("Move backward to start avoid obstacle");
      motor(40,BACK);//Move backward
      has_obs(&dist);//update distance between car and obstacle
    }
    turn(an_rig);
    motor(my_speed,FORWARD);
    delay(2000);
    turn(an_left);
    motor(my_speed,FORWARD);
    delay(3000);
    turn_right(my_angle);
  }
  if(mid()){
    Serial.println("Move forward");
    turn(an_stra);
    motor(my_speed,FORWARD);
  }
  if(left()){
    Serial.println("Turn left and move");
    turn(an_left);
    motor(my_speed,FORWARD);
  }
  if(right()){
    Serial.println("Turn right and move");
    turn(an_rig);
    motor(my_speed,FORWARD);
  }
  else{
    Serial.println("No white line detected. Stop");
    motor(my_speed,STOP);
  }

}
