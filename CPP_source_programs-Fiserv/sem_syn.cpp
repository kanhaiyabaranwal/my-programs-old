//Rendezvous: Both a1 and b1 should execute before a2 and b2 executes.
#include<iostream>
#include<pthread.h>
#include<semaphore.h>
using namespace std;

sem_t s1,s2;

void* func1(void* f1)
{
        cout<<"executing prcess a1\n";
        sem_post(&s1);
        sem_wait(&s2);
        cout<<"executing process a2\n";
        pthread_exit((void *) 0);
        return 0;
}

void* func2(void *f2)
{
        cout<<"executing prcess b1\n";
        sem_post(&s2);
        sem_wait(&s1);
        cout<<"executing process b2\n";
        pthread_exit((void *) 0);
        return 0;
}
int main()
{
        cout<<"synchronization of 2 processes\n";
        int status;
        sem_init(&s1,0,0);
        sem_init(&s2,0,0);
        pthread_t t1,t2;
        pthread_create(&t1,NULL,func1,NULL);
        pthread_create(&t2,NULL,func2,NULL);
        pthread_join(t1,(void**)&status);
        pthread_join(t2,(void**)&status);
        return 0;
}

