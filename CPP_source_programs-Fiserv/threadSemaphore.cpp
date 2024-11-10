#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void *doSomething1(void*);
void *doSomething2(void*);
void *doSomething3(void*);

sem_t sem;

int main() {
    // initialize semaphore to 2
    int rc=sem_init(&sem, 0, 2);
	    printf("rc=%d\n",rc);
    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, &doSomething1, NULL);
    pthread_create(&thread2, NULL, &doSomething2, NULL);
    pthread_create(&thread3, NULL, &doSomething3, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}

void doSomething(char c) {
	printf("char is %c",c);
    int i, time;
    for (i = 0; i < 3; i++) {

        // P operation
        //int rc=sem_wait(&sem);
       // printf("rc=%d\n",rc);
        if (sem_wait(&sem) == 0) {

            // generate random amount of time (< 30 seconds)
            time = (int) ((double) rand() / RAND_MAX * 30);

            printf("Thread %c enters and sleeps for %d seconds...\n", c, time);

            sleep(time);

            printf("Thread %c leaves the critical section\n", c);

            // V operation
            sem_post(&sem);
            printf("outside thread lock block\n");
        }
    }
}

void *doSomething1(void* p) {
    // thread A
    doSomething('A');

    return 0;
}

void *doSomething2(void* p) {
    // thread B
    doSomething('B');

    return 0;
}

void *doSomething3(void *p) {
    // thread C
    doSomething('C');

    return 0;
} 
