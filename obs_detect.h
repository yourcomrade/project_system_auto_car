/*
 * This file for calculating obstacle detection
 */
#ifndef OBS_DETECT_H
#define OBS_DETECT_H
 #include "pin_name.h"
 #define MAX_DISTANCE 200
 NewPing sonar(trigPin,echoPin,MAX_DISTANCE);
 bool has_obs(uint8_t *dist)
 {
  delay(10);
    (*dist)=sonar.ping_cm();
    if((*dist)<=50){
      return true;
    }
    else
    return false;
 }
#endif
