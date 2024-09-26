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
    pthread_create(&t1, NULL, &routine, NULL); // args: pointer to thread infro, thread attributes, pointer to function to run, args to function
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL); // args: thread info, return value from thread -- this ensures that the calling thread waits for the new thread to finish
    pthread_join(t2, NULL);
    return 0;
}