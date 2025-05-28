#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // using sleep()

// thread 1: Thread 1: increments its own variable i and prints it every 1 second
void *task1(void * data){
    static int i = 0;
    while (1){
        printf("count task 1: %d\n", i++);
        sleep(1); // stop for 1 second
    }
    return NULL;
}

// thread 2: Thread 1: increments its own variable i and prints it every 3 second
void *task2(void *data){
    static int i = 0;
    while (1){
        printf("count task 2: %d\n", i++);
        sleep(3); // stop for 3 second
    }
    return NULL;
}

int main(int argc, char const *argv[]){
    pthread_t t1; // thread 1
    pthread_t t2; // thread 2

    // create 2 threads to execute function task1 and task2
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);

    // wait for both threads to finish (they run infinitely)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}