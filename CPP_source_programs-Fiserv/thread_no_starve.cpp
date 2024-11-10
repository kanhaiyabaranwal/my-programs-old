#include<semaphore.h>
#include<unistd.h>
#define NBR_OF_THREADS 6
pthread_mutex_t m1;
sem_t s1,s2;
int r1,r2;

void* no_starve(void* arg)
{
        int tid=(int)arg;
        printf("calling thread# %d\n",tid);
        for(int i=0;i<2;i++)
        {
	        pthread_mutex_lock(&m1);
    	    r1+=1;
        	pthread_mutex_unlock(&m1);
	        printf("thread=%d,after increasing r1=%d\n",tid,r1);
	
    	    sem_wait(&s1);
        	r2+=1;
        	printf("thread=%d,after increasing r2=%d\n",tid,r2);
        	pthread_mutex_lock(&m1);
        	r1-=1;
        	printf("thread=%d,after decreasing r1=%d\n",tid,r1);
        	if(r1==0)
	                sem_post(&s2);
    	    else
        	        sem_post(&s1);
        	pthread_mutex_unlock(&m1);
        
        	sem_wait(&s2);
        	r2-=1;
        	printf("thread=%d,after decreasing r2=%d\n",tid,r2);
        	//critical section
        	printf("I am in critical section\n");
        	sleep(1);

        	if(r2==0)
	                sem_post(&s1);
    	    else
                sem_post(&s2);
        	printf("After loop=%d, in thread %d\n",i,tid);
        }

        pthread_exit(0);
        return 0;
}
int main()
{
        pthread_t th[NBR_OF_THREADS];
        sem_init(&s1,0,1);
        sem_init(&s2,0,0);
        pthread_mutex_init(&m1,NULL);
        int status;
        for(int i=0;i<NBR_OF_THREADS;i++)
                pthread_create(&th[i],0,no_starve,(void*)i);
        for(int i=0;i<NBR_OF_THREADS;i++)
                pthread_join(th[i],(void**)&status);
        return 0;
}
                                                                    
                                                        
