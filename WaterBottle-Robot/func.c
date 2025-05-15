#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>

void slow(int portarm, int portarm2, int sevcurrent,int sevcurrent2,int end){
    while(sevcurrent != end){
        msleep(10);
        set_servo_position(portarm,(sevcurrent += 5)); // this servo starts at 0
        msleep(5); 
        set_servo_position(portarm2,(sevcurrent2 -= 5)); // this servo starts at ~1409
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
void crabl(int motorbr_port, int motorbl_port, int motorfl_port, int motorfr_port, int common_speed) {
    // Declare thread objects
    thread tid_br, tid_bl, tid_fl, tid_fr;

    // Prepare arguments for each thread.

    // For motorbr: motor(motorbr, common_speed)
    // Use run_motor_direct_speed_wrapper.
    motor_args args_br = {motorbr_port, common_speed};

    // For motorbl: motor(motorbl, -common_speed)
    // Use run_motor_negate_speed_wrapper.
    motor_args args_bl = {motorbl_port, common_speed};

    // For motorfl: motor(motorfl, common_speed)
    // Use run_motor_direct_speed_wrapper.
    motor_args args_fl = {motorfl_port, common_speed};

    // For motorfr: motor(motorfr, -common_speed)
    // Use run_motor_negate_speed_wrapper.
    motor_args args_fr = {motorfr_port, common_speed};

    // Create and start the threads
    if (thread_create(&tid_br, run_motor_direct_speed_wrapper, &args_br) == -1) {
        printf("Error creating thread for motorbr (crabl)\n");
    } else if (thread_start(&tid_br) == -1) {
        printf("Error starting thread for motorbr (crabl)\n");
    }

    if (thread_create(&tid_bl, run_motor_negate_speed_wrapper, &args_bl) == -1) {
        printf("Error creating thread for motorbl (crabl)\n");
    } else if (thread_start(&tid_bl) == -1) {
        printf("Error starting thread for motorbl (crabl)\n");
    }

    if (thread_create(&tid_fl, run_motor_direct_speed_wrapper, &args_fl) == -1) {
        printf("Error creating thread for motorfl (crabl)\n");
    } else if (thread_start(&tid_fl) == -1) {
        printf("Error starting thread for motorfl (crabl)\n");
    }

    if (thread_create(&tid_fr, run_motor_negate_speed_wrapper, &args_fr) == -1) {
        printf("Error creating thread for motorfr (crabl)\n");
    } else if (thread_start(&tid_fr) == -1) {
        printf("Error starting thread for motorfr (crabl)\n");
    }
}
void crabr_threaded(int motorbr_port, int motorbl_port, int motorfl_port, int motorfr_port, int common_speed) {
    // Declare thread objects
    thread tid_br, tid_bl, tid_fl, tid_fr;
    // For motorbr: motor(motorbr, -common_speed)
    // Use run_motor_negate_speed_wrapper, and it will negate the common_speed.
    motor_args args_br = {motorbr_port, common_speed};

    // For motorbl: motor(motorbl, common_speed)
    // Use run_motor_direct_speed_wrapper.
    motor_args args_bl = {motorbl_port, common_speed};

    // For motorfl: motor(motorfl, -common_speed)
    // Use run_motor_negate_speed_wrapper.
    motor_args args_fl = {motorfl_port, common_speed};

    // For motorfr: motor(motorfr, common_speed)
    // Use run_motor_direct_speed_wrapper.
    motor_args args_fr = {motorfr_port, common_speed};

    // Create and start the threads
    // int thread_create(thread *tid, void *(*routine)(void *), void *arg);
    // int thread_start(thread *tid);

    if (thread_create(&tid_br, run_motor_negate_speed_wrapper, &args_br) == -1) {
        printf("Error creating thread for motorbr (crabr)\n");
    } else if (thread_start(&tid_br) == -1) {
        printf("Error starting thread for motorbr (crabr)\n");
    }

    if (thread_create(&tid_bl, run_motor_direct_speed_wrapper, &args_bl) == -1) {
        printf("Error creating thread for motorbl (crabr)\n");
    } else if (thread_start(&tid_bl) == -1) {
        printf("Error starting thread for motorbl (crabr)\n");
    }

    if (thread_create(&tid_fl, run_motor_negate_speed_wrapper, &args_fl) == -1) {
        printf("Error creating thread for motorfl (crabr)\n");
    } else if (thread_start(&tid_fl) == -1) {
        printf("Error starting thread for motorfl (crabr)\n");
    }

    if (thread_create(&tid_fr, run_motor_direct_speed_wrapper, &args_fr) == -1) {
        printf("Error creating thread for motorfr (crabr)\n");
    } else if (thread_start(&tid_fr) == -1) {
        printf("Error starting thread for motorfr (crabr)\n");
    }
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
    if((gmpc(motorfr))!= 0||(gmpc(motorfl))!= 0||(gmpc(motorbr))!= 0||(gmpc(motorbl))!= 0){
	    exit(0);
    } // Corrected condition to use gmpc for all motor position checks

}
void gsp(int port){get_servo_position(port);}

void gse(int port){get_servo_enabled(port);}

void ssp(int port, int position){set_servo_position(port, position);} // Added position parameter

void stop(int motor){freeze(motor);}

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

