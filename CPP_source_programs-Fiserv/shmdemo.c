#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>

#define SHM_SIZ 1024
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
	data=shmat(shmid,(void*)0,0);
	if(data==(char*)0)
	{
		printf("failed to attach to shared memory to shmid=%d,errno=%d\n", shmid,errno);
		return -1;
	}
	printf("give user data\n");
	scanf("%s",data);
	printf("Data in shared memory segment is %s\n",data);
	
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
