#include <kipr/wombat.h>
#include <stdio.h>

int arm = 0;
int second = 1000;
int arm_current= 0;
// servo home postion change when new postion is set 
int sevhm = 0;

void slow(port,end,current){
    int sevcurrent = current;
    while(current != end){
        msleep(25);
        set_servo_position(port,(sevcurrent += 5));
    }
}



int main()
{
    enable_servos();
    set_servo_position(arm,sevhm);
    slow(arm,1700,arm_current)
    return 0;
}
