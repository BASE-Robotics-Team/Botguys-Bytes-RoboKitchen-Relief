#include <kipr/wombat.h>
 int arm_Port = 0; //0
 int servo_Pause = 1000; //1000
 int servo_Floor_Pause = 5000; //5000
 int servo_Start = 800; //1024
 int servo_Mid1 = 1066; //1316
 int servo_Mid2 = 1432; //1608
 int servo_Floor = 1700; //1900

int main()
{
  enable_servos();
  set_servo_position(arm_Port,servo_Start);
  	msleep(servo_Pause);
  set_servo_position(arm_Port,servo_Mid1);
  	msleep(servo_Pause);
  set_servo_position(arm_Port,servo_Mid2);
  	msleep(servo_Pause);
  set_servo_position(arm_Port,servo_Floor);
  	msleep(servo_Pause);
  //set_servo_position(arm_Port,servo_Start);
	//msleep(servo_Pause);

   disable_servos(); 
 return 0;
}
