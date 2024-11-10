#include<iostream>
#include<cstdio>
#include<pthread.h>
#include<semaphore.h>
using namespace std;
char buff=0;            //this is critical section here
sem_t sem_read,sem_write,sem_turnstile;
pthread_mutex_t m1;
pthread_cond_t pcond1;
int n;
int r=0;
int w=0;
void * writer(void *p)
{
        while(true)
        {
                sem_wait(&sem_turnstile);
                if(r)
                        sem_wait(&sem_read);
                sem_wait(&sem_write);
                pthread_mutex_lock(&m1);
                w=1;
                pthread_mutex_unlock(&m1);
                printf("I am writer %d\n",w);
                buff=1;
                sleep(1);
                printf("buff is %d\n",buff);
                pthread_mutex_lock(&m1);
                w=0;
                pthread_mutex_unlock(&m1);
                if(r)
                        pthread_cond_broadcast(&pcond1);
                sem_post(&sem_write);
                sem_post(&sem_turnstile);
        }
        return 0;
}
void*  reader(void *p)
{
        while(true)
        {
                sem_wait(&sem_turnstile);
                sem_post(&sem_turnstile);
                pthread_mutex_lock(&m1);
                r++;
                pthread_mutex_unlock(&m2);

                if(r==1)
                {
                        printf("Reader# %d:locking read semaphore\n",r);
                        sem_wait(&sem_read);
                }
                if(w)
                {
                        printf("Reader# %d:Waiting for writer\n",r);
                        pthread_mutex_lock(&m1);
                        pthread_cond_wait(&pcond1,&m1);
                        pthread_mutex_unlock(&m1);
                        printf("Reader# %d:Waiting for writer over\n",r);
                }
                printf("I am reader# %d,buff is %d\n",r,buff);
                sleep(1);
                if(r==1)
                {
                        pthread_mutex_lock(&m1);
                        r--;
                        pthread_mutex_unlock(&m1);
                        printf("Reader# %d:Last reader\n",r);
                        sem_post(&sem_read);
                }
        }
        return 0;
}
int main()
{
        cout<<"Reader-Writer implementation"<<endl;
        pthread_t t1,t2,t3,t4;
        sem_init(&sem_write,0,1);
        sem_init(&sem_read,0,1);
        sem_init(&sem_turnstile,0,1);
        pthread_cond_init(&pcond1,NULL);
        pthread_create(&t1,0,writer,NULL);
        pthread_create(&t2,0,writer,NULL);
        //pthread_create(&t2,0,reader,NULL);
        pthread_create(&t3,0,reader,NULL);
        pthread_create(&t4,0,writer,NULL);
        int status;
        pthread_join(t1,(void**)&status);
        pthread_join(t2,(void**)&status);
        return 0;
}
                                                                                                                             

