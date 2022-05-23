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
  turn(an_stra);
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
    delay (2000);
    
    //turn(an_stra);
    //motor(my_speed,FORWARD);
    //delay(3000);
  }
if(mid()){
  Serial.println("Straight");
  turn(an_stra);
  motor(47,FORWARD);
}
else if(left()){
  
  int i=30;
  do{if(i<70){i+=2;}
  Serial.print("Left i= ");
  Serial.println(i);
  turn(i);
  motor(my_speed,FORWARD);
  delay(1);
    }while(!mid()&&left());
}
else if(right()){
 
  int i=30;
  do{if(i>=10){
    i-=2;
  }
  Serial.print("Right i= ");
  Serial.println(i);
  turn(i);
  motor(my_speed,FORWARD);
  delay(1);
  }while(!mid()&&right());
}
}
