#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstring>
using namespace std;

void calc_time()
{
char buffer[30];
  struct timeval tv;

  time_t curtime;
 gettimeofday(&tv, NULL); 
 curtime=tv.tv_sec;

 strftime(buffer,30,"%m-%d-%Y  %T.",localtime(&curtime));
 printf("%s%ld\n",buffer,tv.tv_usec);
}

int main()
{
	cout<<"Time is "<<endl;
	calc_time();
	return 0;
}
