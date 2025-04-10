#include <kipr/wombat.h>
int arm = 0;
int second = 1000;
int arm_up= 500;
int arm_dn= 1200;


int main()
{
    enable_servos();
    set_servo_position(arm,arm_up);
    msleep(second/2);
    set_servo_position(arm,arm_dn);
    msleep(second/2);
    set_servo_position(arm,arm_up);
    msleep(second/2);
    disable_servos();
    
    return 0;
}
