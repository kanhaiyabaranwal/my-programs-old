#include<iostream>
#include<pthread.h>
#include<semaphore.h>
using namespace std;

sem_t sem1,sem2;
int count=0;
pthread_mutex_t mutex1,mutex2;
pthread_cond_t pcond;

void* func1(void* f1)
{
        for(int i=0;i<2;i++)
        {
                pthread_mutex_lock(&mutex1);
                count+=1;
                cout<<"executing thread n="<<count<<",i="<<i<<"\n";

                if(count==3)
                {
                        sem_post(&sem1);
                        sem_wait(&sem2);
                        cout<<"i="<<i<<",barrier crossed,n="<<count<<"\n";
                }
                pthread_mutex_unlock(&mutex1);

                sem_wait(&sem1);
                sem_post(&sem1);

                pthread_mutex_lock(&mutex1);
                count-=1;
                cout<<"executing thread n="<<count<<",i="<<i<<"\n";

                if(count==0)
                {
                        sem_post(&sem2);
                        sem_wait(&sem1);
                        cout<<"i="<<i<<",barrier crossed,n="<<count<<"\n";
                }
                pthread_mutex_unlock(&mutex1);
                sem_wait(&sem2);
                sem_post(&sem2);
        }

        pthread_exit((void *) 0);
        return 0;
}

int main()
{
        cout<<"barrier crossing\n";
        pthread_mutex_init(&mutex1,NULL);
        pthread_mutex_init(&mutex2,NULL);
        sem_init(&sem1,0,0);
        sem_init(&sem2,0,1);
        pthread_cond_init(&pcond,NULL);
        int status;
        pthread_t t1,t2,t3;
        pthread_create(&t1,NULL,func1,NULL);
        pthread_create(&t2,NULL,func1,NULL);
        pthread_create(&t3,NULL,func1,NULL);
        pthread_join(t1,(void**)&status);
        pthread_join(t2,(void**)&status);
        pthread_join(t3,(void**)&status);
        return 0;
}
                                                                                                                              66,1          Bot
u
