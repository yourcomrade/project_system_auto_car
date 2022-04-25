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
#define my_speed 50
#define my_angle 30
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
    turn_right(my_angle);
    motor(my_speed,FORWARD);
    delay(2000);
    turn_left(my_angle);
    delay(500);
    turn_left(my_angle);
    delay(3000);
    turn_right(my_angle);
  }
  if(mid()){
    Serial.println("Move forward");
    motor(my_speed,FORWARD);
  }
  if(left()){
    Serial.println("Turn left and move");
    turn_left(my_angle);
    motor(my_speed,FORWARD);
  }
  if(right()){
    Serial.println("Turn right and move");
    turn_right(my_angle);
    motor(my_speed,FORWARD);
  }
  else{
    Serial.println("No white line detected. Stop");
    motor(my_speed,STOP);
  }

}
