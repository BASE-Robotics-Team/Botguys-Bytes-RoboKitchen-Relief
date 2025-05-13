#include <stdio.h>
#include <pthread.h>

void *my_thread_function(void *thread_id) {
    int tid = *((int *)thread_id);
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1;
    int id2 = 2;

    printf("Main thread: Creating thread 1...\n");
    int ret1 = pthread_create(&thread1, NULL, my_thread_function, (void *)&id1);

    if (ret1 != 0) {
        perror("Error creating thread 1");
        return 1;
    }

    printf("Main thread: Creating thread 2...\n");
    int ret2 = pthread_create(&thread2, NULL, my_thread_function, (void *)&id2);

    if (ret2 != 0) {
        perror("Error creating thread 2");
        return 1;
    }

    printf("Main thread: Threads created. Waiting for threads to finish...\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread: Both threads finished. Exiting.\n");

    return 0;
}
