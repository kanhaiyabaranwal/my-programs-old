#include<stdio.h>
#include <sys/msg.h>

typedef struct  {
        int jobId;
        char jobName[9];
        char jobStartTime[9];
        char jobEndTime[9];
        char jobDate[9];
        int rc;
        char title[33];
} JobLogPrimData; 
typedef struct  {
        int jobId;
        int subJobId;
        char jobStartTime[9];
        char jobEndTime[9];
        char subJobName[9];
        int rc;
} JobLogSecData ;

int main(int argc, char *argv[])
{

	int arg,rc,pid;
	int qid;
	char buff[2*sizeof (JobLogPrimData)];
	JobLogPrimData *pData = (JobLogPrimData*)malloc(sizeof(JobLogPrimData));
	pData->jobId=1;
	strcpy(pData->jobName,"svathprg");
	strcpy(pData->jobStartTime,"00:02:41");
	strcpy(pData->jobEndTime,"00:02:53");
	strcpy(pData->jobDate,"06-30-14");
	pData->rc=0;
	strcpy(pData->title,"SVATHPRG,VISA AUTH PURGE");
	memcpy(buff,pData,sizeof(pData);

	JobLogSecData *sData = (JobLogSecData*)malloc(sizeof(JobLogSecData));
	sData->jobId=1;
	sData->subJobId=5;
	strcpy(sData->jobStartTime,"00:02:42");
	strcpy(sData->jobEndTime,"00:02:53");
	strcpy(sData->subJobName,"svathprg");
	sData->rc=0;
	
	char msg[5000]="Kanhaiya sending test message from hell";
	char msg1[50]="Kanhaiya, You are sending message again";
	printf("program is %s and arg1 is %s\n", argv[0],argv[1]);
	memset(msg,'-',4000);
	strcat(msg,"Kanhaiya sending test message from hell");
	arg=atoi(argv[1]);
	qid=arg;
	printf("child:qid=%d\n",qid);
	//rc=msgsnd(qid,(void*)&msg,sizeof(msg),0);
	rc=msgsnd(qid,(void*)pData,sizeof(JobLogPrimData),0);
	if(rc<0)
	{
		printf("failed to send message to queue id %d\n",qid);
		return -1;
	}	
	arg=atoi(argv[2]);
	qid=arg;
	printf("Sending 2nd message\n");
	printf("child:qid=%d\n",qid);
	
	rc=msgsnd(qid,(void*)sData,sizeof(JobLogSecData),0);
	if(rc<0)
	{
		printf("failed to send message to queue id %d\n",qid);
		return -1;
	}	
	return 0;
	
}
