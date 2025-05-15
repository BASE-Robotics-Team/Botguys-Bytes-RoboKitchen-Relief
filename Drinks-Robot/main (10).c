#include <kipr/wombat.h>
int fr = 1;
int fl = 0;
int arm = 2;
int arm_up = 1500;
int servopause = 500;
int armm = 641;
int armd = 1749;
int w = 1;

void forward()
{
    motor(fr,100);
    motor(fl,100);
    
}

void backwards()
{
    motor(fr,-100);
    motor(fl,-100);
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

int main()
{
    enable_servos();
    /*
    set_servo_position(2,1000);
    set_servo_position(3,1000);
    */
    //forward();
    backwards();
    msleep(3000);
    ao();
    /*
    msleep(500);
    set_servo_position(3,0);
    msleep(1000);
    set_servo_position(2,0);
    msleep(2000);
    set_servo_position(2,1000);
    bang();
    ao();
    */
    return 0;
}
