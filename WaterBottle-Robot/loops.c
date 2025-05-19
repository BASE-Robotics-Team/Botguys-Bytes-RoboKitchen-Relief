#include <kipr/wombat.h>
int motorfr = 2;
int motorfl = 3;
int motorbr = 1;
int motorbl = 0;
int front_eye = 3;
int button = 9;
int box_target = 2800;
int speed = 50;

int main()
{
    while(analog(front_eye) < box_target){
        forward();
    }
    ao();
    while ( digital(button) != 1){
        backward();
    } 
    ao();
    return 0;
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