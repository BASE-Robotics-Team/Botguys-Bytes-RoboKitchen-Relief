#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>
#include "/home/kipr/Documents/KISS/Default User/func/src/main.c"

int motorfr = 2;
int motorfl = 3;
int motorbr = 1;
int motorbl = 0;
int speed = 100;
int portarm = 2;
int portarm2 = 3;
int second = 1000;
int arm_current= 0;
int sevcurrent = 0;
int sevcurrentv = 2047;
int sevcurrent2 = 1600;
int x = 4;
// servo home postion change when new postion is set 
int sevhm = 0;


int main() 
{
    ao();
    printf("START \n");
    //wait_for_light(0);
    shut_down_in(119);
    enable_servo(3);
    enable_servo(2);
    enable_servo(0);
    chkserv(3,2,0,1);
    ssp(0,0);
    msleep(50);
    ssp(2,1350);
    ssp(3,320);
    msleep(500);
    disable_servos();
    msleep(50);
    motorclear(motorbr,motorbl,motorfl,motorfr);
    msleep(50);
	backward(motorbr,motorbl,motorfl,motorfr,speed);
    msleep(600);
    ao();
    move_in_place_ccw(motorbr,motorbl,motorfl,motorfr,speed);
    msleep(1500);
    ao();
    forward(motorbr,motorbl,motorfl,motorfr,speed);
    msleep(3950);
    ao();
    enable_servo(3);
    enable_servo(2);
    chkserv(3,2,0,1);
    msleep(25);
    ssp(2,0);
    ssp(3,1600);
    msleep(1200);
    move_in_place_ccw(motorbr,motorbl,motorfl,motorfr,speed);
    msleep(1350);
    ao();
    printf("analog placeing start \n");
    while( digital(9) != 1){
        forward(motorbr,motorbl,motorfl,motorfr,10);
    }
        printf("analog placeing end \n");
    msleep(290);
    ao();
    slow(portarm,portarm2,1200);
    msleep(2000);
    backward(motorbr,motorbl,motorfl,motorfr,15);
    msleep(400);
    forward(motorbr,motorbl,motorfl,motorfr,15);
    msleep(400);
    ao();
    printf("Phase 1 pass \n");
    enable_servo(0);
    chkserv(3,2,0,1);
    msleep(25);
    ssp(0,2047);
    msleep(1500);
    slowdwn(portarm,portarm2,700);
    msleep(2500);
    backward(motorbr,motorbl,motorfl,motorfr,35);
    msleep(750);
    ao();
    move_in_place_ccw(motorbr,motorbl,motorfl,motorfr,20);
    msleep(12600); // at 45 6300
    ao();
    crabr(motorbr,motorbl,motorfl,motorfr,45);
    msleep(2000);
    ao();
    printf("analog placeing start \n");
    while( digital(9) != 1){
        forward(motorbr,motorbl,motorfl,motorfr,25);
    }
        printf("analog placeing end \n");
    msleep(290);
    ao();
    msleep(1200);
    slow(portarm,portarm2,1700);
    msleep(1000);
    chkserv(3,2,0,1);
    msleep(25);
    ssp(0,0);
    msleep(1000);
    return 0;
}