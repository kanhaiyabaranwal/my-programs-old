#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <errno.h>

#define LOGNAME "/tmp/me"

int main()
{
	int i=1<<16;
	static int debug;
	printf("i=%d\n",i);
	fd_set set;
	FD_SET (i, &set);
	printf("i=%d\n",i);
	int ipc = IPC_CREAT | 0622;
	printf("IPC_CREAT=%d,ipc=%d\n",IPC_CREAT,ipc);
	int pid = getpid();
	printf("current pid=%d\n",pid);
	char logfile[255];
	sprintf(logfile,"%s.%d.log",LOGNAME,pid);
	FILE *fp = fopen(logfile,"w");
	if (!fp)
		return errno;
	else
		printf("file %s created successfully!\n",logfile);
	fprintf(fp,"Process id=%d\n",pid);
	char value[10]={NULL};
	strcpy(value,getenv("DEBUG"));
	printf("value=%s,len(value)=%d",value,strlen(value));
	value[strlen(value)]='\n';	
	printf("value=%s,len(value)=%d",value,strlen(value));
	if(getenv("DEBUG"))
	{
		debug=1;
		printf("debug is on\n");
	}
	if(!debug)
	{
	printf("removing file\n");
	int rm=remove(logfile);
	if(rm)
	{
		fprintf(fp,"failed to delete log file %s \n",logfile);
		perror("failed to delete file: Contact AIX Administrator");
		return -1;
	}		
	}
	fclose(fp);
	printf("successfully deleted log file\n");
	
	return 0;
}
