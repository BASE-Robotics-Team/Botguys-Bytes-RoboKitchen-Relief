#include <kipr/wombat.h>
#include <stdio.h>
#include <stdlib.h>

// Struct to hold parameters for our motor threads
typedef struct {
    int port;
    int speed;
} motor_args;

// Wrapper function for the first motor (motorbr)
void *run_motorbr(void *args) {
    motor_args *params = (motor_args *)args;
    motor(params->port, params->speed);
    return NULL;
}

// Wrapper function for the second motor (motorbl)
void *run_motorbl(void *args) {
    motor_args *params = (motor_args *)args;
    motor(params->port, -params->speed); // Note the -speed
    return NULL;
}

// Wrapper function for the third motor (motorfl)
void *run_motorfl(void *args) {
    motor_args *params = (motor_args *)args;
    motor(params->port, params->speed);
    return NULL;
}

// Wrapper function for the fourth motor (motorfr)
void *run_motorfr(void *args) {
    motor_args *params = (motor_args *)args;
    motor(params->port, -params->speed); // Note the -speed
    return NULL;
}
// Wrapper function that applies the speed directly as passed in motor_args
void *run_motor_direct_speed_wrapper(void *args) {
    motor_args *params = (motor_args *)args;
    motor(params->port, params->speed);
    // KIPR threads are detached and auto-cleaned up.
    // If params were malloc'd, free(params) would go here.
    return NULL;
}

// Wrapper function that applies the NEGATIVE of the speed passed in motor_args
void *run_motor_negate_speed_wrapper(void *args) {
    motor_args *params = (motor_args *)args;
    motor(params->port, -params->speed); // Note the negation here
    return NULL;
}
