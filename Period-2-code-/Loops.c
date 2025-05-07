#include <kipr/wombat.h>
int motorfr = 2;
int motorfl = 3;
int motorbr = 1;
int motorbl = 0;
//This is the camera
int front_eye = 3;
//Port number of the button
int button = 9;
int box_target = 2800;
int speed = 50;

int main()
{
    // while the target is far away the bot will move forword 
    while(analog(front_eye) < box_target){
        forward();
    }
    ao();
// when button is not pressed the bot will move backward
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
