#include <kipr/wombat.h>
int motorfr = 2;
int motorfl = 3;
int motorbr = 1;
int motorbl = 0;
int speed = 100;
int sec = 1000;
int lline = 5;
int rline = 4;
int target = 2450;
int box_target = 1775;
int mbox = 3;
int main()
{
    crab_r();
    msleep(2.57*sec);
    forward();
    msleep(2.7*sec);
    ao();
    right();
    msleep(1.3*sec);
    ao();
    return 0;
}
void right(){
    motor(motorbr,speed);
    motor(motorfr,speed);
    motor(motorbl,-speed);
    motor(motorfl,-speed);
}
void forward(){
    motor(motorbr,speed);
    motor(motorbl,speed);
    motor(motorfl,speed);
    motor(motorfr,speed);
}
void crab_r(){
    motor(motorbr,-speed);
    motor(motorbl,speed);
    motor(motorfl,-speed);
    motor(motorfr,speed);
}
void crab_l(){
    motor(motorbr,speed);
    motor(motorbl,-speed);
    motor(motorfl,speed);
    motor(motorfr,-speed);
}
void backward(){
    motor(motorbr,-speed);
    motor(motorbl,-speed);
    motor(motorfl,-speed);
    motor(motorfr,-speed);
}