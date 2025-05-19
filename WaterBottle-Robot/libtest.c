#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <kipr/wombat.h>

// Structure to pass multiple arguments to the thread function
typedef struct {
    int thread_id;
    const char* message;
} thread_args_t;

// The function that will be executed by each thread
void* myThreadFunction(void* arg) {
    // Cast the void* argument back to the expected structure type
    thread_args_t* args = (thread_args_t*)arg;

    printf("Thread %d received message: %s\n", args->thread_id, args->message);

    // Thread can return a value (optional)
    pthread_exit(NULL);
}

int main() {
    int num_threads = 5; // Number of threads to create
    pthread_t threads[num_threads]; // Array to store thread IDs
    thread_args_t thread_args[num_threads]; // Array to store arguments for each thread
    int rc; // To store return codes from pthread functions

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        // Prepare arguments for the current thread
        thread_args[i].thread_id = i;
        // Allocate memory for the message and copy the string
        // This is important if the message is not a string literal or needs to persist
        // beyond the scope of this loop iteration. For simplicity, using a literal here.
        // In a real application, consider dynamic allocation and freeing in the thread.
        thread_args[i].message = "Hello from thread";

        printf("Creating thread %d\n", i);

        // Create the thread
        rc = pthread_create(&threads[i], NULL, myThreadFunction, (void*)&thread_args[i]);

        if (rc) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < num_threads; i++) {
        printf("Joining thread %d\n", i);
        rc = pthread_join(threads[i], NULL); // The second argument can capture the return value

        if (rc) {
            perror("Error joining thread");
            exit(EXIT_FAILURE);
        }
        printf("Thread %d joined\n", i);
    }

    printf("All threads finished.\n");

    return 0;
}
