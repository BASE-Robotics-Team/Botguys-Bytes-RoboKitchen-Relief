#include <kipr/wombat.h>
int front_eye = 1;
int target =2900;
int button = 0;
int main()    
{

    while(analog(front_eye)<target)       
	{
        
    forward();    
	}
 ao();
 msleep(1000);   
    while(digital(button)==0)
    {
    backwards();
    }
   ao();
    
return 0;
}

void forward()
{
    motor(0,50);

    motor(3,50);
}
void backwards()
{
    motor(0,-50);

    motor(3,-50);
}