#include <kipr/wombat.h>
int motorfr = 1;
int motorfl = 2;
int motorbr = 3;
int motorbl = 0;
int speed = 50;
int second = 1000;
int lline = 5;
int rline = 4;
int target = 2450;
int box_target = 1775;
int mbox = 3;

int main()
{
    camera_load_config("colours.conf");
    camera_open();
    camera_update();
    while(1){
         camera_update();
        if(get_object_center_x(2,0) < 270){
            veer_left();
        }
         camera_update();
       if(get_object_center_x(2,0) > 330){
            veer_right();
        }
         camera_update();
       if(get_object_center_x(2,0) > 270 && get_object_center_x(2,0) < 330){
            forward();
       }
            if(analog(3) > 2900){break;}
    
    }
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