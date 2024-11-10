#include<stdio.h>
#include <sys/msg.h>

int main(int argc, char *argv[])
{

	int arg,rc,pid;
	long qid;
	char msg[50]="Kanhaiya, You are sending message again";
	printf("program is %s and arg1 is %s\n", argv[0],argv[1]);
	qid=atol(argv[1]);
	printf("child:qid=%ld\n",qid);
	rc=msgsnd(qid,(void*)&msg,sizeof(msg),0);
	if(rc<0)
	{
		printf("failed to send message to queue id %d\n",qid);
		return -1;
	}	
	return 0;
	
}
