#include<iostream>
extern "C"{
#include<pthread.h>
}

struct complex{
	int real;
	int img;
	complex(int i,int j): real(i),img(j) { }
};

using namespace std;
void* print(void *t)
{
	struct complex *nbr=(struct complex*)t;
	cout<<"Nbr inside thread is"<<nbr->real<<", "<<nbr->img<<"i\n";
	//printf("Number inside thread is %ld\n", *nbr);
	int stat=4;
	int *ps=&stat;
	pthread_exit((void*)stat);
	//return 0;
}


int main()
{
	pthread_t pt;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	long num=1;
	long *pnum=&num;
	complex num1(2,3);
	complex *pn=&num1;
	int rc=pthread_create(&pt,&attr,print,(void*)pn);
	if(rc)
	{		cout<<"failed to create thread\n";
		return 0;
	}
	void* status;
	//free attributes
	pthread_attr_destroy(&attr);
	pthread_join(pt, status);
	cout<<"state from print function="<<(int *)status<<endl;
	pthread_exit(NULL);
	return 0;	
}
