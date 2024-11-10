#include <iostream>
extern "C"{
#include <pthread.h>
#include <semaphore.h>
}

//producer-consumer problem

using namespace std;
sem_t full,empty;
void* func(void *pi)
{
	int *i=(int*)pi;
	cout<<"inside thread func. i= "<<*i<<endl;
	return NULL;
}
int main()
{
	pthread_t thr1,thr2;
	pthread_create(&thr1,NULL,&put,(void*)val);
	//int s=pthread_join(th,(void*)status);
	int s=pthread_join(th,NULL);
	//cout<<"status="<<(int*)status<<endl;
	return 0;
}
	
