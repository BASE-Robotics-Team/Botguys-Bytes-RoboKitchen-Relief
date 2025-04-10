#include <kipr/wombat.h>
// Defining Variables for which colour is which number
int pink = 0;
int green = 2;
int blue = 1;
//Servo port number
int arm = 0;
//Quick access to seconds
int second = 1000;
//The up and down positions we want the servo to be at
int arm_up= 500;
int arm_dn= 1200;
//Keeping track of loop iterations
int count = 0;
//Port number of the button
int button = 9;


int main()
{
    //Defining colour file and initializing the camera
    camera_load_config("colours.conf");
    camera_open();
    camera_update();
    //The while loop initializes this while the button is not pressed.
    while(digital(button) != 1 ){
    //This constently updates camera picture
     camera_update();
    //This checks if the objects are pink
    if(get_object_count(pink) != 0 ){
        camera_update();
    //If a pink object is deceted, pink will be printed to console.
        printf("pink\n");
        enable_servos();
    	set_servo_position(arm,arm_up);
    	msleep(second/2);
        disable_servos();
    //This checks if objects are green
    }else if(get_object_count(green) != 0 ){
        camera_update();
    //If a green object is deceted, green will be printed to console.        
        printf("green\n");
        enable_servos();
    	set_servo_position(arm,arm_dn);
    	msleep(second/2);
        disable_servos();
    //This assumes the objects are blue
    }else{
        camera_update();
    //If a blue object is deceted, blue will be printed to console.
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
