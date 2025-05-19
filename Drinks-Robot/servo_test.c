#include <kipr/wombat.h>
 int arm = 3;
 int arm_up = 500;
 int servopause = 1000;
 int servoStart = 0;
 int armm = 641;
 int arm_down = 250;

int main()
{
  enable_servos();
  set_servo_position(arm,0);
  	msleep(servopause);
  set_servo_position(arm,arm_up);
  	msleep(servopause);
  set_servo_position(arm,arm_down);
  	msleep(servopause);  
  set_servo_position(arm,arm_up);
  	msleep(servopause); 
  set_servo_position(arm,0);
  	msleep(servopause); 
    
   disable_servos(); 
    return 0;
}

void bang() {
    msleep(1000);
    set_servo_position(2,0);
    msleep(2000);
    set_servo_position(2,1000);
    msleep(1000);
    set_servo_position(2,0);
    msleep(2000);
    set_servo_position(2,1000);
    msleep(1000);
    set_servo_position(2,0);
    msleep(2000);
    set_servo_position(2,1000);
    msleep(1000);
    set_servo_position(2,0);
    msleep(2000);
    set_servo_position(2,1000);
    msleep(1000);
    set_servo_position(2,0);
    msleep(2000);
    set_servo_position(2,1000);
    msleep(1000);
    set_servo_position(2,0);
    msleep(2000);
    set_servo_position(2,1000);

}