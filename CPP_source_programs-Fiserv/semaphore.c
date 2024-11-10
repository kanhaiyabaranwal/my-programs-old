#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void *doSomething1();
void *doSomething2();
void *doSomething3();
void *doSomething4();
void *doSomething5();

sem_t sem;

int main() {
    // initialize semaphore to 2
    sem_init(&sem, 1, 1);

    pthread_t thread1, thread2, thread3,thread4,thread5;

    pthread_create(&thread1, NULL, &doSomething1, NULL);
    pthread_create(&thread2, NULL, &doSomething2, NULL);
    pthread_create(&thread3, NULL, &doSomething3, NULL);
    pthread_create(&thread4, NULL, &doSomething4, NULL);
    pthread_create(&thread5, NULL, &doSomething5, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    return 0;
}

void doSomething(char c) {
    int i, time;
    for (i = 0; i < 3; i++) {

        // P operation
        if (sem_wait(&sem) == 0) {

            // generate random amount of time (< 30 seconds)
            time = (int) ((double) rand() / RAND_MAX * 10);

            printf("Thread %c enters and sleeps for %d seconds...\n", c, time);

            sleep(time);

            printf("Thread %c leaves the critical section\n", c);

            // V operation
            sem_post(&sem);
        }
    }
}

void *doSomething1() {
    // thread A
    doSomething('A');

    return 0;
}

void *doSomething2() {
    // thread B
    doSomething('B');

    return 0;
}

void *doSomething3() {
    // thread C
    doSomething('C');

    return 0;
} 
void *doSomething4() {
    // thread D
    doSomething('D');

    return 0;
} 
void *doSomething5() {
    // thread D
    doSomething('E');

    return 0;
} 
