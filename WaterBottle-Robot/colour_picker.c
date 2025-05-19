#include <kipr/wombat.h>
int pink = 0;
int green = 2;
int blue = 1;
int arm = 0;
int second = 1000;
int arm_up= 500;
int arm_dn= 1200;
int count = 0;
int button = 9;


int main()
{
    camera_load_config("colours.conf");
    camera_open();
    camera_update();
    while(digital(button) != 1 ){
     camera_update();
    if(get_object_count(pink) != 0 ){
        camera_update();
        printf("pink\n");
        enable_servos();
    	set_servo_position(arm,arm_up);
    	msleep(second/2);
        disable_servos();
    }else if(get_object_count(green) != 0 ){
        camera_update();
        printf("green\n");
        enable_servos();
    	set_servo_position(arm,arm_dn);
    	msleep(second/2);
        disable_servos();
    }else{
        camera_update();
        printf("blue\n");
        enable_servos();
    	set_servo_position(arm,700);
    	msleep(second/2);
        disable_servos();
    }
        msleep(second*2);
    }
    return 0;
}
