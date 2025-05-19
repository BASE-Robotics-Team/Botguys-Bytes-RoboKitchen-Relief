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
int sevhm = 2;

int main()
{
    
    while(1){
    if(digital(9) == 1){printf("%d\n",1);}
    if(digital(9) == 0){printf("%d\n",0);}
    }
    return 0;
}
