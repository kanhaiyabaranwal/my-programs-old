#include <iostream>
extern "C"{
#include <pthread.h>
}

using namespace std;

void* func(void *pi)
{
	int *i=(int*)pi;
	cout<<"inside thread func. i= "<<*i<<endl;
	return NULL;
}
int main()
{
	pthread_t th;
	void *status;
	int worker=0;
	int val=3;
	int *pval=&val;
	pthread_create(&th,NULL,&func,(void*)pval);
	int s=pthread_join(th,&status);
	//int s=pthread_join(th,NULL);
	cout<<"status="<<(int*)status<<endl;
	return 0;
}
	
