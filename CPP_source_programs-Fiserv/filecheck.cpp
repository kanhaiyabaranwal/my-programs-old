#include<iostream>
#include<cstdio>
#include <sys/stat.h>
using namespace std;
#define PROC_LOGNAME "/tmp/BMgrGlbInqUpd.log"
int main()
{

	struct stat sbuf;
	if (stat(PROC_LOGNAME, &sbuf) < 0)
	{
		cout<<"log file not found"<<endl;
		return -1;
	}
	 if (!S_ISREG(sbuf.st_mode))
	{
		cout<<" log file not a regular file, no logging"<<endl;
		return -1;
	}
	FILE *fp=fopen(PROC_LOGNAME, "a");
	if(fp)
		fprintf(fp,"Logging starts\n");
	cout<<"Logging starts\n";
	return 0;
}
