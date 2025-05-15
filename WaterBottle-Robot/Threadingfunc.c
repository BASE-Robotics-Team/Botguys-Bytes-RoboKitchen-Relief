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
