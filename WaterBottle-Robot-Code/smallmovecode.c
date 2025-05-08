#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>

int motorfr = 2;
int motorfl = 3;
int motorbr = 1;
int motorbl = 0;
int speed = 100;
int arm = 0;
int second = 1000;
int arm_current= 0;
// servo home postion change when new postion is set 
int sevhm = 0;

void slow(port,end,current){
    int sevcurrent = current;
    while(current != end){
        msleep(25);
        set_servo_position(port,(sevcurrent += 5));
    }
}
void forward(){
	motor(motorbr,speed);
	motor(motorbl,speed);
    motor(motorfl,speed);
    motor(motorfr,speed);
}
void backward(){
	motor(motorbr,-speed);
	motor(motorbl,-speed);
    motor(motorfl,-speed);
    motor(motorfr,-speed);
}
void motorclear(motorfr,motorfl,motorbr,motorbl){
    cmpc(motorfr)
    cmpc(motorfl)
    cmpc(motorbr)
    cmpc(motorbl)
    if((gmpc(motorfr))||(gmpc(motorfl))||(motorbr)||(motorbl)){exit(0);}

}

int main()
{
    motorclear(motorfr,motorfl,motorbr,motorbl);
    enable_servos();
    set_servo_position(arm,sevhm);
    slow(arm,1700,arm_current);
    msleep(second*10);
    ao();
    return 0;
}
