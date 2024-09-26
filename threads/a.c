#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* routine() {
    printf("Hello from thread\n");
    sleep(3);
    printf("Ending thread\n");
}

int main(int argc, char* argv[]) {
    pthread_t t1, t2; // contains information about the thread
    // args: pointer to thread infro, thread attributes, pointer to function to run, args to function
    // the if statement checks if the thread was successfully created, since this could fail
    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL) != 0) {
        return 2;
    }

    // args: thread info, return value from thread -- this ensures that the calling thread waits for the new thread to finish
    // the if statement checks if the thread was successfully joined, since this could fail
    if (pthread_join(t1, NULL) != 0) {
        return 3;
    }
    if (pthread_join(t2, NULL)) {
        return 4;
    }
    return 0;
}