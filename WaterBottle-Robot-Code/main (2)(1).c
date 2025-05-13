#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>

void slow(int portarm, int portarm2, int sevcurrent,int sevcurrent2,int end){
    while(sevcurrent != end){
        msleep(20);
        set_servo_position(portarm,(sevcurrent += 5));
        msleep(0); // This msleep(0) might not be necessary or intended.
        set_servo_position(portarm2,(sevcurrent2 -= 5));
    }
}

void forward(int motorbr, int motorbl, int motorfl, int motorfr, int speed){
	motor(motorbr,-speed);
	motor(motorbl,-speed);
    motor(motorfl,-speed);
    motor(motorfr,-speed);
}
void backward(int motorbr, int motorbl, int motorfl, int motorfr, int speed){
	motor(motorbr,speed);
	motor(motorbl,speed);
    motor(motorfl,speed);
    motor(motorfr,speed);
}
void crabl(int motorbr, int motorbl, int motorfl, int motorfr, int speed){
	motor(motorbr,speed);
	motor(motorbl,-speed);
    motor(motorfl,speed);
    motor(motorfr,-speed);
}
void crabr(int motorbr, int motorbl, int motorfl, int motorfr, int speed){
	motor(motorbr,-speed);
	motor(motorbl,speed);
    motor(motorfl,-speed);
    motor(motorfr,speed);
}
void move_in_place_ccw(int motorbr, int motorbl, int motorfl, int motorfr, int speed){
	motor(motorbr,speed);
	motor(motorbl,-speed);
    motor(motorfl,-speed);
    motor(motorfr,speed);
}
void move_in_place_cw(int motorbr, int motorbl, int motorfl, int motorfr, int speed){
	motor(motorbr,-speed);
	motor(motorbl,speed);
    motor(motorfl,speed);
    motor(motorfr,-speed);
}
void motorclear(int motorbr, int motorbl, int motorfl, int motorfr){
    cmpc(motorfr);
    cmpc(motorfl);
    cmpc(motorbr);
    cmpc(motorbl);
    // Corrected the condition to use gmpc for all motor position checks
    if((gmpc(motorfr))!= 0||(gmpc(motorfl))!= 0||(gmpc(motorbr))!= 0||(gmpc(motorbl))!= 0){exit(0);}

}
void gsp(int port){get_servo_position(port);}
void gse(int port){get_servo_enabled(port);}
void ssp(int port, int position){set_servo_position(port, position);} // Added position parameter
void stop(int motor){freeze(motor);}
void servo_check(int port0, int port1, int port2, int port3){
void chkserv(int sev1, int sev2, int sev3, int sev4){
    int result; // Variable to store the result of gse

    // Check sev1
    result = get_servo_enabled(sev1); // Call gse once and store the result
    if(result != 1){
        printf("servo failure %d\n", result);
    } else {
        printf("servo success %d\n", result);
    }

    // Check sev2
    result = get_servo_enabled(sev2);
    if(result != 1){
        printf("servo failure %d\n", result);
    } else {
        printf("servo success %d\n", result);
    }

    // Check sev3
    result = get_servo_enabled(sev3);
    if(result != 1){
        printf("servo failure %d\n", result);
    } else {
        printf("servo success %d\n", result);
    }

    // Check sev4
    result = get_servo_enabled(sev4);
    if(result != 1){
        printf("servo failure %d\n", result);
    } else {
        printf("servo success %d\n", result);
    }
}


    // if(gse(port0) != // Incomplete function - add implementation 
	// printf("%d\n", x);
}
