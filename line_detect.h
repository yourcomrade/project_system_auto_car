/* Author: Vladislav Serafimove
 * Student number: 509761
 * This file contains functions for detecting the line
 */
 #ifndef LINE_DETECT_H
 #define LINE_DETECT_H
 #include "pin_name.h"

bool data_r() { return !digitalRead(rig_ir);}
bool data_m() { return !digitalRead(mid_ir);}
bool data_l() { return !digitalRead(left_ir);}

//exposes a getter for the right data
extern bool get_data_r(){
  return data_r();
}

//exposes a get for the left data
extern bool get_data_l(){
  return data_l();
}

//exposes a get for the middle data
extern bool get_data_m(){
  return data_m();
}

//function that checks if 
extern bool right(){
    return data_r() && !data_l();
}

extern bool mid(){
    return data_m() && !data_l() && !data_r();
}

extern bool left() {
    return !data_r() && data_l();
}
#endif
