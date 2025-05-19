#include <kipr/wombat.h>
int arm = 2;
int arm2 = 3;
int second = 1000;
int arm_up= 500;
int arm_dn= 1200;


int main()
{
    enable_servos();
    set_servo_position(arm,arm_up);
    set_servo_position(arm2,arm_up);
    msleep(20000);
    disable_servos();
    
    return 0;
}
