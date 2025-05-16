#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int motor_id;
    int speed;
} motor_args_t;

// Thread function to control a single motor
void* run_motor_thread(void* arg) {
    motor_args_t* args = (motor_args_t*)arg;
    motor(args->motor_id, args->speed);
    free(args); // Free the dynamically allocated memory for arguments
    pthread_exit(NULL); // Explicitly exit the thread
    return NULL; // Should not be reached if pthread_exit is called
}