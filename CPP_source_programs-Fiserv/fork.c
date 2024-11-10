#include<stdio.h>
#include<signal.h>

int main()
{
	pid_t pid;
	int i,num=6;
	signal(SIGCHLD, SIG_IGN);
	
	if(pid=fork())
	{
		printf("this is parent. pid=%d\n",getpid());
		wait(NULL);
		return 0;
	}
	else
	{
		printf("This is child.pid=%d,ppid=%d\n",getpid(),getppid());
		return 0;
	}
	printf("Program never reaches here\n");
	return -1;
}
		
