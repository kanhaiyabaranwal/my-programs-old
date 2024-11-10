#include<sys/stat.h>
#include<iostream>
using namespace std;
#define file "/u/bkanhaiy/kan/stat.cpp"

int main()
{
	struct stat fdstat;
	if(stat(file, &fdstat) < 0)
	{
		cout<<"stat failed for "<<file<<endl;
		return -1;
	}
	cout<<"file stats:userid="<<fdstat.st_uid<<",permissions="<<fdstat.st_mode<<endl;
	return 0;
}
