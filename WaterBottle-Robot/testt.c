#include <kipr/wombat.h>
int motorfr = 2;
int motorfl = 3;
int motorbr = 1;
int motorbl = 0;
int speed = 50;
int second = 1000;
int lline = 9;
int rline = 8;
int target = 2450;
int box_target = 1775;
int mbox = 0;

int main()
{
    while(analog(rline)<target){
        if(analog(lline)>target){
            veer_right();
        }
        if(analog(lline)<target){
            veer_left();
        }
        if(analog(mbox)>box_target){
            break;
        }
    }
    ao();
    return 0;
}


// function definitions 
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