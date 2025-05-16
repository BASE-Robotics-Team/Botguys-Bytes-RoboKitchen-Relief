#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>
#include "/home/kipr/Documents/KISS/Default User/New_main_func/src/main.c"

int motorl = 0;
int motorr = 1;
int* line1 = NULL;
int* line2 = NULL;

//Arm int's
int arm_Port = 0;
int servo_Pause = 1000;
int servo_Start = 950;
int servo_Up = 800;
int servo_Mid1 = 1066;
int servo_Mid2 = 1432;
int servo_Floor = 1700;

//Grabber int's
int Grabber = 3;
int Grab_Cup = 920;
int Grab_Drink = 1300;
int Grab_Ice = 1200;
int Grab_Back = 250;
int Grab_Start = 0;
int Grab_Hold = 5000;


int main(){
  enable_servos();
    set_servo_position(0,950); // arm_Port, servo_Start
    set_servo_position(3,920); // Grabber, Grab_Cup
        //msleep(3500);
    turnRight();
        msleep(1480); //1250, 1320 OR 1400
    ao();
      set_servo_position(0,1066); // arm_Port, servo_Mid1
    set_servo_position(3,0);    // Grabber, Grab_Start
          msleep(1000); // servo_Pause
      set_servo_position(0,1432); // arm_Port, servo_Mid2
          msleep(1000); // servo_Pause
    goForwards();
        msleep(3350); //3350
    ao();
      set_servo_position(0,1700); // arm_Port, servo_Floor
          msleep(1000); // servo_Pause
    goForwards();
        msleep(180); //175
    ao();
      set_servo_position(3,920);  // Grabber, Grab_Cup
        msleep(1000); // servo_Pause
    goBackwards();
        msleep(1000); //1000
    ao();
      set_servo_position(3,0);    // Grabber, Grab_Start
    goBackwards();
        msleep(500); //500
    turnRight();
        msleep(200); //200
      set_servo_position(3,700);  // Grabber, 700 (literal value, not a predefined variable)
    goForwards();
        msleep(1000); //1000
    ao();
    //turnLeft();
        //msleep(250); //250
    goForwards();
        msleep(400); //300




    disable_servos();
    ao();
    return 0;
}





  
}
