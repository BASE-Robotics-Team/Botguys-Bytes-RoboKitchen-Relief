#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>

void forward( int motorl, int motorr, int speed){
  motor(motorl, speed);
  motor(mororr, speed);
}

void backwards( int motorl, int motorr, int speed){
  motor(motorl, -speed);
  motor(mororr, -speed);
}
void motorclear(int motorl, int motorr){
    cmpc(motorr);
    cmpc(motorl);
    if((gmpc(motorr))!= 0||(gmpc(motorl))!= 0){
	    exit(0);
    } // Corrected condition to use gmpc for all motor position checks
void gsp(int port){get_servo_position(port);}

void gse(int port){get_servo_enabled(port);}

void ssp(int port, int position){set_servo_position(port, position);} // Added position parameter

void stop(int motor){freeze(motor);}
