#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>
int rightWheel = 1;
int leftWheel = 0;

//Arm int's
int arm_Port = 0;
int servo_Pause = 1000; 
int servo_Start = 950;
int servo_Up = 800;
int servo_Mid1 = 1066;
int servo_Mid2 = 1232;
int servo_Floor = 1550;

//Grabber int's
int Grabber = 3;
int Grab_Cup = 940; //920
int Grab_Drink = 1300;
int Grab_Ice = 1200;
int Grab_Back = 250;
int Grab_Start = 0;
int Grab_Hold = 5000;


void goForwards()
{
    motor(rightWheel,100);
    motor(leftWheel,100);
    
}

void goBackwards()
{
    motor(rightWheel,-100);
    motor(leftWheel,-100);
    
}

void turnRight()
{
    motor(rightWheel,100);
    
}

void turnLeft()
{
    motor(leftWheel,100);
    
}

void full180LEFT()
{
    motor(leftWheel,100);
    msleep(3450);
    
}

void full180RIGHT()
{
    motor(rightWheel,100);
    msleep(3450);
    
}


int main()
{
    wait_for_light(5);
    shut_down_in(119);
    enable_servos();
    set_servo_position(arm_Port,servo_Start);
    set_servo_position(Grabber,Grab_Cup);
    	msleep(6000); //3500
    turnRight();
    	msleep(1550); //1250, 1320 OR 1400
    ao();
  	set_servo_position(arm_Port,servo_Mid1);
    set_servo_position(Grabber,Grab_Start);
  		msleep(servo_Pause);
  	set_servo_position(arm_Port,servo_Mid2);
  		msleep(servo_Pause);
    goForwards();
    	msleep(3350); //3350
    ao();
    turnRight();
    	msleep(200);
    ao();
  	set_servo_position(arm_Port,servo_Floor);
  		msleep(servo_Pause);
    goForwards();
    	msleep(150); //175
    ao();
  	set_servo_position(Grabber,Grab_Cup);
    	msleep(servo_Pause);
    goBackwards();
        msleep(1000); //1000
    ao();
  	set_servo_position(Grabber,Grab_Start);
    goBackwards();
        msleep(500); //500
	turnRight();
    	msleep(200); //200
  	set_servo_position(Grabber,700); //700
    goForwards();
    	msleep(1600); //1000
    ao();
	//turnLeft();
    	//msleep(250); //250
    //goForwards();
    	//msleep(400); //300
    ao();
    set_servo_position(Grabber,Grab_Drink);
    	msleep(1000);
    goBackwards();
        msleep(1000);
    ao();
    /*
    turnLeft();
    	msleep(1000);
    ao();
  	set_servo_position(Grabber,700); //700
    set_servo_position(arm_Port,servo_Mid1);
    	msleep(1000);
    turnRight();
    	msleep(1000);
    ao();
    set_servo_position(arm_Port,servo_Floor);
    	msleep(1000);
    goForwards();
    	msleep(1600); //1000
	*/
    
    set_servo_position(arm_Port,servo_Up);
    	msleep(500);
	turnLeft();
    	msleep(500);
    ao();
    set_servo_position(Grabber,Grab_Start);
    	msleep(500);
    
    
    
    ao();
    disable_servos(); 
    return 0;
}
