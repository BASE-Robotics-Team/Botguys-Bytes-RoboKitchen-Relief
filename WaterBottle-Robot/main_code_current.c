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
    motorclear(motorbr,motorbl,motorfl,motorfr);
    enable_servo(0);
    msleep(500);
    //chkserv(0,1,2,3);
    //backward(motorbr,motorbl,motorfl,motorfr,100);
    //forward(motorbr,motorbl,motorfl,motorfr,100);
    //msleep(7000);
    //stop(0);
    //stop(1);
    //stop(2);
    //stop(3);
    //msleep(1000);
    crabr(motorbr,motorbl,motorfl,motorfr,10);
    msleep(10000);
    ao();
    return 0;
}