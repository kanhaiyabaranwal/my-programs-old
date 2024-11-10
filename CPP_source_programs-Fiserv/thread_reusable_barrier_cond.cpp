#include<iostream>
#include<pthread.h>
#include<semaphore.h>
using namespace std;

sem_t s1,s2;
int count=0;
pthread_mutex_t mutex1,mutex2;
pthread_cond_t pcond;

void* func1(void* f1)
{
        for(int i=0;i<2;i++)
        {
                pthread_mutex_lock(&mutex1);
                count+=1;
                cout<<"i="<<i<<",executing thread n="<<count<<"\n";
                if(count==3)
                {
                        pthread_cond_broadcast(&pcond);
                        cout<<"i="<<i<<",barrier crossed,n="<<count<<"\n";
                }
                pthread_mutex_unlock(&mutex1);

                pthread_mutex_lock(&mutex2);
                if(count!=3)
                        pthread_cond_wait(&pcond,&mutex2);
                pthread_mutex_unlock(&mutex2);

                pthread_mutex_lock(&mutex1);
                count-=1;
                cout<<"i="<<i<<",executing thread n="<<count<<"\n";
                if(count==0)
                {
                        pthread_cond_broadcast(&pcond);
                        cout<<"i="<<i<<",barrier crossed,n="<<count<<"\n";
                }
                pthread_mutex_unlock(&mutex1);

                pthread_mutex_lock(&mutex2);
                                                                                                                              1,1           Top
                if(count!=0)
                pthread_cond_wait(&pcond,&mutex2);
                pthread_mutex_unlock(&mutex2);
        }

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
        cout<<"barrier crossing\n";
        pthread_mutex_init(&mutex1,NULL);
        pthread_mutex_init(&mutex2,NULL);
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
                                                                                                                              74,1          Bot

