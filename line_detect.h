/*
 * This file contains functions for detecting the line
 */
 #ifndef LINE_DETECT_H
 #define LINE_DETECT_H
 #include "pin_name.h"

extern bool right(){
  return !(digitalRead(rig_ir)&&!digitalRead(left_ir));
}

extern bool left(){
  return !(digitalRead(left_ir)&&!digitalRead(rig_ir));
}

extern bool mid(){
  return !(digitalRead(mid_ir)&&!digitalRead(rig_ir)&&!digitalRead(left_ir));
}
#endif
