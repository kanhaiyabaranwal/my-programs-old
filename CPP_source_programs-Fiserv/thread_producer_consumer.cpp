#include<iostream>
#include<pthread.h>
#include<semaphore.h>
using namespace std;
#define BUFFSIZE 5
char buff[BUFFSIZE];
sem_t sem_full,sem_empty;
int n;
void * producer(void *p)
{
        while(true)
        {
                cout<<"I am producer"<<endl;
                sem_wait(&sem_empty);
                buff[n]=n+1;
                n++;
                cout<<"buffsize is "<<n<<endl;
                sem_post(&sem_full);
        }
        return 0;
}
void*  consumer(void *p)
{
        while(true)
        {
                cout<<"I am consumer"<<endl;
                sem_wait(&sem_full);
                cout<<"buffsize is "<<n<<endl;
                n--;
                sem_post(&sem_empty);
        }
        return 0;
}
int main()
{
        cout<<"Producer-Consumer implementation"<<endl;
        pthread_t t1,t2;
        sem_init(&sem_full,0,0);
        sem_init(&sem_empty,0,BUFFSIZE);
        pthread_create(&t1,0,producer,NULL);
        pthread_create(&t2,0,consumer,NULL);
        int status;
        pthread_join(t1,(void**)&status);
        pthread_join(t2,(void**)&status);
        return 0;
}        
