#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// initialize mutex to lock shared resources
pthread_mutex_t lock;

// shared resource
int count = 0;

void* display(void* a)
{
    char* label = (char*)a;
    for (int i = 0; i < 10; i++) // each thread only run 10 times
    {
        pthread_mutex_lock(&lock);
        printf("%s: count = %d\n", label, count++);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}


int main(int argc, char const argv[]){
    const char *str = "Thien Bao";
    const char *ptr = "Hello Thread";

    // initialize mutex
    pthread_mutex_init(&lock, NULL);

    pthread_t t1, t2;

    // create 2 threads to run display function with different data
    pthread_create(&t1, NULL, display, (void*)str);
    pthread_create(&t2, NULL, display, (void*)ptr);

    // wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // print final value
    printf("Final count: %d\n", count);

    // destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}