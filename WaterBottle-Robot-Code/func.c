#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>

void slow(end){
    while(sevcurrent != end){
        msleep(20);
        set_servo_position(portarm,(sevcurrent += 5));
        msleep(0);
        set_servo_position(portarm2,(sevcurrent2 -= 5));
    }
}

void slowu(end){
    printf("broken function")
     exit(0);
    while(sevcurrentv != end){
        msleep(20);
        set_servo_position(portarm,(sevcurrent -= 5));
        msleep(0);
        set_servo_position(portarm2,(sevcurrent2 += 5));
    }
}
void forward(){
	motor(motorbr,speed);
	motor(motorbl,speed);
    motor(motorfl,speed);
    motor(motorfr,speed);
}
void backward(){
	motor(motorbr,-speed);
	motor(motorbl,-speed);
    motor(motorfl,-speed);
    motor(motorfr,-speed);
}
void motorclear(){
    cmpc(motorfr);
    cmpc(motorfl);
    cmpc(motorbr);
    cmpc(motorbl);
    if((gmpc(motorfr))!= 0||(gmpc(motorfl))!= 0||(motorbr)!= 0||(motorbl)!= 0){exit(0);}

}
void gsp(port){get_servo_position(port);}
void gse(port){get_servo_enabled(port);}
void ssp(port){set_servo_position(port);}
void stop(motor){freeze(motor);}
int main()
{
    printf("Hello World\n");
    return 0;
}
