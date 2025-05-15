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
void crabl(int motorbr, int motorbl, int motorfl, int motorfr, int speed) {
    pthread_t thread_br, thread_bl, thread_fl, thread_fr;
    motor_args_t *args_br, *args_bl, *args_fl, *args_fr;

    // --- Motor Back Right (motorbr) ---
    args_br = (motor_args_t*)malloc(sizeof(motor_args_t));
    if (args_br == NULL) {
        perror("Failed to allocate memory for motorbr args");
        return; // Or handle error appropriately
    }
    args_br->motor_id = motorbr;
    args_br->speed = speed;
    if (pthread_create(&thread_br, NULL, run_motor_thread, args_br) != 0) {
        perror("Error creating thread for motorbr");
        free(args_br); // Clean up allocated memory on error
        // Potentially handle error for other threads too
        return;
    }

    // --- Motor Back Left (motorbl) ---
    args_bl = (motor_args_t*)malloc(sizeof(motor_args_t));
    if (args_bl == NULL) {
        perror("Failed to allocate memory for motorbl args");
        // Consider how to handle partial failures (e.g., join created threads before returning)
        pthread_join(thread_br, NULL); // Wait for already created thread
        return;
    }
    args_bl->motor_id = motorbl;
    args_bl->speed = -speed;
    if (pthread_create(&thread_bl, NULL, run_motor_thread, args_bl) != 0) {
        perror("Error creating thread for motorbl");
        free(args_bl);
        pthread_join(thread_br, NULL);
        return;
    }

    // --- Motor Front Left (motorfl) ---
    args_fl = (motor_args_t*)malloc(sizeof(motor_args_t));
    if (args_fl == NULL) {
        perror("Failed to allocate memory for motorfl args");
        pthread_join(thread_br, NULL);
        pthread_join(thread_bl, NULL);
        return;
    }
    args_fl->motor_id = motorfl;
    args_fl->speed = speed;
    if (pthread_create(&thread_fl, NULL, run_motor_thread, args_fl) != 0) {
        perror("Error creating thread for motorfl");
        free(args_fl);
        pthread_join(thread_br, NULL);
        pthread_join(thread_bl, NULL);
        return;
    }

    // --- Motor Front Right (motorfr) ---
    args_fr = (motor_args_t*)malloc(sizeof(motor_args_t));
    if (args_fr == NULL) {
        perror("Failed to allocate memory for motorfr args");
        pthread_join(thread_br, NULL);
        pthread_join(thread_bl, NULL);
        pthread_join(thread_fl, NULL);
        return;
    }
    args_fr->motor_id = motorfr;
    args_fr->speed = -speed;
    if (pthread_create(&thread_fr, NULL, run_motor_thread, args_fr) != 0) {
        perror("Error creating thread for motorfr");
        free(args_fr);
        pthread_join(thread_br, NULL);
        pthread_join(thread_bl, NULL);
        pthread_join(thread_fl, NULL);
        return;
    }

    pthread_join(thread_br, NULL);
    pthread_join(thread_bl, NULL);
    pthread_join(thread_fl, NULL);
    pthread_join(thread_fr, NULL);

    printf("crabl function finished.\n");
}

void crabr(int motorbr, int motorbl, int motorfl, int motorfr, int speed) {
    pthread_t thread_br, thread_bl, thread_fl, thread_fr;
    motor_args_t *args_br, *args_bl, *args_fl, *args_fr;

    // --- Motor Back Right (motorbr) ---
    args_br = (motor_args_t*)malloc(sizeof(motor_args_t));
    if (args_br == NULL) {
        perror("Failed to allocate memory for motorbr args");
        return; // Or handle error appropriately
    }
    args_br->motor_id = motorbr;
    args_br->speed = -speed;
    if (pthread_create(&thread_br, NULL, run_motor_thread, args_br) != 0) {
        perror("Error creating thread for motorbr");
        free(args_br); // Clean up allocated memory on error
        // Potentially handle error for other threads too
        return;
    }

    // --- Motor Back Left (motorbl) ---
    args_bl = (motor_args_t*)malloc(sizeof(motor_args_t));
    if (args_bl == NULL) {
        perror("Failed to allocate memory for motorbl args");
        // Consider how to handle partial failures (e.g., join created threads before returning)
        pthread_join(thread_br, NULL); // Wait for already created thread
        return;
    }
    args_bl->motor_id = motorbl;
    args_bl->speed = speed;
    if (pthread_create(&thread_bl, NULL, run_motor_thread, args_bl) != 0) {
        perror("Error creating thread for motorbl");
        free(args_bl);
        pthread_join(thread_br, NULL);
        return;
    }

    // --- Motor Front Left (motorfl) ---
    args_fl = (motor_args_t*)malloc(sizeof(motor_args_t));
    if (args_fl == NULL) {
        perror("Failed to allocate memory for motorfl args");
        pthread_join(thread_br, NULL);
        pthread_join(thread_bl, NULL);
        return;
    }
    args_fl->motor_id = motorfl;
    args_fl->speed = -speed;
    if (pthread_create(&thread_fl, NULL, run_motor_thread, args_fl) != 0) {
        perror("Error creating thread for motorfl");
        free(args_fl);
        pthread_join(thread_br, NULL);
        pthread_join(thread_bl, NULL);
        return;
    }

    // --- Motor Front Right (motorfr) ---
    args_fr = (motor_args_t*)malloc(sizeof(motor_args_t));
    if (args_fr == NULL) {
        perror("Failed to allocate memory for motorfr args");
        pthread_join(thread_br, NULL);
        pthread_join(thread_bl, NULL);
        pthread_join(thread_fl, NULL);
        return;
    }
    args_fr->motor_id = motorfr;
    args_fr->speed = speed;
    if (pthread_create(&thread_fr, NULL, run_motor_thread, args_fr) != 0) {
        perror("Error creating thread for motorfr");
        free(args_fr);
        pthread_join(thread_br, NULL);
        pthread_join(thread_bl, NULL);
        pthread_join(thread_fl, NULL);
        return;
    }

    pthread_join(thread_br, NULL);
    pthread_join(thread_bl, NULL);
    pthread_join(thread_fl, NULL);
    pthread_join(thread_fr, NULL);

    printf("crabl function finished.\n");
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

