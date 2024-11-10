#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<iostream>
using namespace std;

#define SHM_SIZ 1024
class Base{
	int i;
	public:
	Base(int j):i(j)
	{
		cout<<"inside Base contructor,value of i="<<i<<"\n";
		cout<<"starting memory address is "<<&i<<endl;
	}
	~Base()
	{
		cout<<"inside detructor\n";
	}
};
void * operator new(size_t sz, char* &p)
{
	char *data=p;	//variable to be returned;
	//p+=sz;	
	cout<<"size allocated from shared memory is "<<sz<<endl;
	cout<<"starting memory address is "<<(int*)data<<endl;
	return data;
}

int main()
{
	int shmid;
	char *data;
	key_t key=ftok("/u/bkanhaiy/kan/shmdemo.c",'k');
	printf("Key for shared memory segment is %d\n",(int)key);

	shmid=shmget(key, SHM_SIZ, 0622 | IPC_CREAT);
	if(shmid <= 0)
	{
		printf("failed to get shared memory id shmid=%d,errno=%d\n",shmid,errno);
		return -1;
	}
	data=(char*)shmat(shmid,(void*)0,0);
	if(data==(char*)0)
	{
		printf("failed to attach to shared memory to shmid=%d,errno=%d\n", shmid,errno);
		return -1;
	}
	Base *b=new(data) Base(4);
	/*printf("give user data\n");
	scanf("%s",data);
	*/
	printf("Data in shared memory segment is %x\n",(int)data);
//	cout<<"starting memory address is "<<(int*)data<<endl;
	
	//now detach from shared memory
	int d=shmdt(data);
	if(d==-1)
	{
		printf("failed to dettach from shared memory to shmid=%d; errno=%d\n", shmid,errno);
		return -1;
	}
	shmctl(shmid,IPC_RMID, NULL);
	printf("share memory data destroyed\n");
	
	
	return 0;
}
