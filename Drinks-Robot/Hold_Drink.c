#include <kipr/wombat.h>
 int arm = 3;
 int arm_Forward = 1300;
 int arm_Back = 250;
 int servo_Pause = 1000;
 int servo_Start = 0;
 int servo_Holding = 5000;

int main()
{
  enable_servos();
  set_servo_position(arm,servo_Start);
  	msleep(servo_Pause);
  set_servo_position(arm,arm_Forward);
  	msleep(servo_Pause);
    /*
  set_servo_position(arm,arm_Back);
  	msleep(servo_Pause);  
  set_servo_position(arm,servo_Start);
  	msleep(servo_Pause); 
    */
    
   disable_servos(); 
    return 0;
}