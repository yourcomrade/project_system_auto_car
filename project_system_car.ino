/* Atuthor: Hoang Minh Le
 * Student number:511907
 * The main file of the project. 
 */
#include "pin_name.h"
#include "obs_detect.h"
#include "line_detect.h"
#include "motor_control.h"
#include "ramp_detect.h"
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
void get_up(){
  if(ramp_detect()){
    motor(0,STOP);
    delay(500);
    motor(35,BACK);
    delay(500);
    turn(an_stra);
    motor(180,FORWARD);
    delay(500);
  }
}
void avoid(){//function to check and avoid obstacle
 uint8_t dist=0;//distance for the car
  if(has_obs(&dist)){
    turn(an_stra);
    while(has_obs(&dist)){
      Serial.println("Move backward to start avoid obstacle");
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
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  /*if(data_r()&&data_l()){//if both right and left ir sensors detect the line, then stop
    Serial.println("Stop");
  motor(0,STOP);
  delay(5000);
}
else if(mid()){//if only the middle sensor detects the line, the move forward
  Serial.println("Straight");
  turn(an_stra);
  motor(35,FORWARD);
  avoid();
}
else if(left()){
  int angle=an_stra;//angle for the car, the angle will increase as the left 
  //ir sensor are continuing to detect the line
  int cspeed=30;//the speed of the car when it turns
  //the speed will increase as the car continue to turn left
  do{if(angle<140){angle+=5;}
  Serial.print("Left angle= ");
  Serial.println(angle);
  turn(angle);
  if(cspeed<55)cspeed++;
  motor(cspeed,FORWARD);
  delay(1);
    }while(left());
}
else if(right()){
   int angle=an_stra;//angle for the car, the angle will increase as the right
  //ir sensor are continuing to detect the line
  int cspeed=30;//the speed of the car when it turns
  //the speed will increase as the car continue to turn right
  do{if(angle>=5){
    angle-=5;
  }
  Serial.print("Right angle= ");
  Serial.println(angle);
  turn(angle);
  if(cspeed<55)cs1eed++;
  motor(cspeed,FORWARD);
  delay(1);
  }while(right());
}*/
motor(45,FORWARD);
get_up();
}
