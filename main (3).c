#include <kipr/wombat.h>
int arm = 0;
int second = 1000;
int arm_current= 0;
int sevhm = 0;


int main()
{
    enable_servos();
    set_servo_position(arm,sevhm);
    while(arm_current != 1700){
        msleep(50);
        set_servo_position(arm,(arm_current += 10));
    }
    
    return 0;
}
