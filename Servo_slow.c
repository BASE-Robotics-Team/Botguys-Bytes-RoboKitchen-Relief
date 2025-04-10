#include <kipr/wombat.h>
// port the servo is connected to 
int arm = 0;
int second = 1000;
int arm_current= 0;
// servo home postion 
int sevhm = 0;


int main()
{
    enable_servos();
    set_servo_position(arm,sevhm);
    // when servo is not at desired location it will move up by 10 per loop 
    while(arm_current != 1700){
        msleep(50);
        set_servo_position(arm,(arm_current += 10));
    }
    
    return 0;
}
