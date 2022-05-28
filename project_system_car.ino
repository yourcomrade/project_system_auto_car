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
#define my_speed 60
#define an_stra 70//angle to turn straight is 70 degree
#define an_left 140//angle to turn left is 140 degree
#define an_rig 0//angle to turn right is 0 degree
int prev_state = 0;
void setup() {
  // put your setup code here, to run once:
  pin_mode();
  turn(an_stra);
}
void avoid(){//function to control avoid obstacle
// turn(an_stra);
 uint8_t dist=0;//distance for the car
  if(has_obs(&dist)){
    turn(an_stra);
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
    motor(50,FORWARD);
    delay(1600);
    motor(0,STOP);
    turn(an_left);
    delay(200);
    Serial.println("Turn left");
    motor(60,FORWARD);
    
   // motor(30,FORWARD);
    //motor(0,STOP);
    //delay(10000);
  }}void loop() {
  // put your main code here, to run repeatedly:
  
 
    //turn(an_stra);
    //motor(my_speed,FORWARD);
    //delay(3000);
  if(data_r()&&data_l()){
    Serial.println("Stop");
  motor(0,STOP);
  delay(5000);
  
}
else if(mid()){
  Serial.println("Straight");
  turn(an_stra);
  motor(35,FORWARD);
  avoid();
}
else if(left()){
  int angle=an_stra;//angle for the car, the angle will increase as the left
  int cspeed=30;
  do{if(angle<140){angle+=5;}
  Serial.print("Left angle= ");
  Serial.println(angle);
  turn(angle);
  if(cspeed<55)cspeed++;
  motor(cspeed,FORWARD);
  delay(1);
  //avoid();
    }while(left());
}
else if(right()){
  int cspeed=30;
  int angle=an_stra;
  do{if(angle>=5){
    angle-=5;
  }
  Serial.print("Right angle= ");
  Serial.println(angle);
  turn(angle);
  if(cspeed<55)cspeed++;
  motor(cspeed,FORWARD);
  delay(1);
  //avoid();
  }while(right());
}

}
