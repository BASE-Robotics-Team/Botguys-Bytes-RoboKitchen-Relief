#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>
int rightWheel = 1;
int leftWheel = 0;

void goForwards()
{
    motor(rightWheel,100);
    motor(leftWheel,100);
    
}

void goBackwards()
{
    motor(rightWheel,-100);
    motor(leftWheel,-100);
    
}

void turnRight()
{
    motor(rightWheel,100);
    
}

void turnLeft()
{
    motor(leftWheel,100);
    
}

int main()
{
    turnLeft();
    msleep(3450);
    ao();
    return 0;
}
