#include<stdio.h>
#include<sys/time.h>
#include<sys/stat.h>
#include<errno.h>

#define LOGFILE "/tmp/temp.out"
#define GLOBALFILE "/tmp/glb.out"

int main()
{
	char param[12],val[12];
	char buffer[32];
	struct stat statbuf;
	FILE* fp;
	int rc=stat(LOGFILE,&statbuf);
	if(rc==0)
	{
		printf("LogFile exists\n");	
		fp=fopen(LOGFILE,"a");
		if(!fp)
		{
			perror("failed to open file\n");
			return 0;
		}
		else
		{
			time_t current_time;
			char c_time_string[32];
			current_time=time(NULL);
			strcpy(c_time_string , ctime(&current_time));
			fprintf(fp,"Writing global parameters at %s\n",ctime(&current_time));
		}
	}
	else
	{
		printf("Log file does not exist will not write any log\n");
		return 0;
	}
	FILE *fp1=fopen(GLOBALFILE,"r");
	if(!fp1)
	{
		perror("failed to open global file\n");
		return 0;
	}
	else
	{
		fprintf(fp,"Failed to open global file %s\n",GLOBALFILE);
	}
	while(fgets(buffer,32,fp1))
	{
		sscanf(buffer,"%[^=] %[^\n]",param,val);
		fprintf(fp,"param=%s, val=%s\n",param,val);
	}

	return 0;
}
