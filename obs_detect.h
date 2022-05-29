/* Author: Hoang Minh Le
 * Student number: 511907
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
    Serial.print("Distance: ");
    Serial.println((*dist),DEC);
    if((*dist)<=42 && *dist > 0){
      Serial.println("\tObstacle detected");
      return true;
    }
    else
    return false;
 }
#endif
