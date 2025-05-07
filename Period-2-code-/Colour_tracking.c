#include <kipr/wombat.h>
//These defines the port for each moter
//fr = front right
int motorfr = 1;
//fl = front left
int motorfl = 2;
//br = back right
int motorbr = 3;
//bl = back left
int motorbl = 0;
int speed = 50;
int second = 1000;
// These are the ports for line sensor
//ll = left line
int lline = 5;
//rl = right line
int rline = 4;
//The point where the sensor is right in front of the "target"
int target = 2450;
//Port number of the middle distance sensor
int mbox = 3;

int main()
{
    //opens colour file and initializes camera
    camera_load_config("colours.conf");
    camera_open();
    camera_update();
    //The while loop is always true
    while(1){
         camera_update();
	//Checks if the object is to the left of the camera
        if(get_object_center_x(2,0) < 270){
            veer_left();
        }
         camera_update();
	//Checks if the object is to the right of the camera
       if(get_object_center_x(2,0) > 330){
            veer_right();
        }
         camera_update(); 
	//Checks if the second object in the colour file is approximately in the center of the cameras vision.
	if(get_object_center_x(2,0) > 270 && get_object_center_x(2,0) < 330){
            forward();
       }
	    //If object is close enough to the robot, it breaks from the while loop
            if(analog(3) > 2900){break;}
    
    }
    //Prints that the while loop has ended
    printf("fronteye = %d\n",analog(3));
     ao();
    return 0;
}
void veer_left(){
	motor(motorbr,speed);
	motor(motorbl,speed-30);
    motor(motorfl,speed-30);
    motor(motorfr,speed);
}
void veer_right(){
	motor(motorbr,speed-30);
	motor(motorbl,speed);
    motor(motorfl,speed);
    motor(motorfr,speed-30);
}
void forward(){
	motor(motorbr,speed);
	motor(motorbl,speed);
    motor(motorfl,speed);
    motor(motorfr,speed);
}
