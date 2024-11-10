#include<stdio.h>
#include <sys/types.h> /* pid_t */
#include <sys/wait.h>  /* waitpid */
#include <unistd.h>    /* _exit, fork */
#include <sys/msg.h>

typedef struct   {
        int jobId;
        char jobName[9];
	int ProgId;
	char ProgName[9];
        char jobStartTime[9];
        char jobEndTime[9];
        char jobDate[9];
        char rc[7];
        char title[33];
} JobLogData;

typedef struct {
	int NumberofLines;
	JobLogData logData[1000];
} Rsp;

int main(int argc,char *argv[])
{
	int status;
	//char buff[50]={0};
	char buff1[5000]={0};
	JobLogData *pData=(JobLogData*)calloc(1,sizeof(JobLogData));
	Rsp *rsp=(Rsp*)calloc(1,sizeof(Rsp));
	char jobname[9];
	if(argc<2)
	{
		printf("requires job parameter\n");
		return 0;
	}
	strcpy(jobname,argv[1]);

	printf("size of rsp=%d and pData=%d\n",sizeof( Rsp), sizeof( JobLogData));
	int	qid = msgget(IPC_PRIVATE, IPC_EXCL | IPC_CREAT | 0622) ;
	if (qid < 0 )
	{	
		printf("failed to create a message queue\n");
		return -1;
	}
	printf("parent:message qid=%d\n",qid);
	char qidC[10]={0};
	sprintf(qidC,"%d",qid);

	pid_t pid=fork();
	printf("fork created, process id is %d\n",pid);	
	if(pid < 0)
	{
		perror("fork failed\n");
		return -1;
	}
	if(pid ==0)	//child
	{
		execlp("b_status","b_status",jobname,qidC,NULL);
		//execlp("hell","hell",jobname,qidC,NULL);
		printf("child failed, it should never reach here\n");
		return -1;	
	}
	else		//parent
	{
		waitpid(pid,&status,0);
		printf("child completed,showing IPC message\n");
		//memset(buff,NULL,sizeof buff);
		if (msgrcv(qid, (void *)rsp, sizeof(Rsp), 0, IPC_NOWAIT) == -1)
		{
			printf("parent:Failed to receive message in queue %d\n",qid);
			return -1;
		}
		for(int i=0;i<rsp->NumberofLines;i++)
        	{
                	printf("Data Set # %d:%d, %s, %d, %s, %s, %s, %s, %s, %s \n",i+1, 
                        rsp->logData[i].jobId,
                        rsp->logData[i].jobName,
                        rsp->logData[i].ProgId,
                        rsp->logData[i].ProgName,
                        rsp->logData[i].jobStartTime,
                        rsp->logData[i].jobEndTime,
                        rsp->logData[i].jobDate,
                        rsp->logData[i].rc,
                        rsp->logData[i].title
                	);      
        	}
		printf("parent:message received is %s\n",buff1);
	}
	return 0;
}
	
