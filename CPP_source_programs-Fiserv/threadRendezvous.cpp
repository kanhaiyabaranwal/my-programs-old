#include<iostream>
extern "C"
{
#include<semaphore.h>
#include<pthread.h>
}

using namespace std;

sem_t sem1,sem2;

void* func1(void *v1)
{
	printf("a1\n");
	sem_post(&sem2);
	sem_wait(&sem1);
	printf("a2\n");
	//for(int i=0;i<10;i++)
	//printf("inside func1,i=%d\n",i);
}

void* func2(void *v1)
{
	printf("b1\n");
	sem_post(&sem1);
	sem_wait(&sem2);
	printf("b2\n");
	//for(int i=0;i<10;i++)
	//printf("inside func2, i=%d\n",i);
}


int main()
{
	sem_init(&sem1,0,0);
	sem_init(&sem2,0,0);
	pthread_t thread1,thread2;
	
	pthread_create(&thread1,NULL,func1,NULL);
	pthread_create(&thread2,NULL,func2,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
}
