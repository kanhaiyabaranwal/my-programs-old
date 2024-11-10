#include<iostream>
#include<cstring>
#include<map>
using namespace std;

typedef struct {
	int jobnbr;
	int start_time;
	int end_time;
} JobSchedule;
multimap<int,JobSchedule> jobmap;
int main()
{
	char *jobschedule[]={"6AM#8AM","11AM#1PM","7AM#3PM","7AM#10AM","10AM#12PM","2PM#4PM","1PM#4PM","8AM#9AM"};
	int nbrofjobs=sizeof(jobschedule)/sizeof(jobschedule[0]);
	cout<<"nbrofjobs="<<nbrofjobs<<endl;
	char start_time[5];
	char end_time[5];
	
	for(int i=0;i<nbrofjobs;i++)
	{
		memset(start_time,NULL,sizeof(start_time));
		memset(end_time,NULL,sizeof(end_time));
		char* ch=strchr(jobschedule[i],'#');
		int pos1=ch-jobschedule[i];
		if(pos1>0)
		{
			strncpy(start_time,jobschedule[i],pos1);
			strcpy(end_time,ch+1);
		}
		cout<<"job schedule="<<jobschedule[i]<<",start_time="<<start_time<<" and end_time="<<end_time<<endl;
		//process start time
		int time1;
		int time2;
	
		if(strlen(start_time)==4)
			time1=(start_time[0]-48)*10+(start_time[1]-48);
		else if(strlen(start_time)==3)
			time1=(start_time[0]-48);
		if(start_time[strlen(start_time)-2]=='P')		
			time1+=12;
		//12AM, 12PM is different; 12AM is 0 and 12PM is 12. so subtract 12 
		if(time1==24 || time1==12)
			time1-=12;

		//process end time
		if(strlen(end_time)==4)
			time2=(end_time[0]-48)*10+(end_time[1]-48);
		else if(strlen(end_time)==3)
			time2=(end_time[0]-48);
		if(end_time[strlen(end_time)-2]=='P')
			time2+=12;
		//12AM, 12PM is different; 12AM is 0 and 12PM is 12. so subtract 12 
		if(time2==24 || time2==12)
			time2-=12;

		cout<<"starttime="<<time1<<" and endtime="<<time2<<endl;
		JobSchedule js={i+1,time1,time2};
		jobmap.insert(make_pair(time2,js));
	}
	multimap<int,JobSchedule>::const_iterator iter=jobmap.begin();
	int prevjob_endtime=0;
	int nbrofscheduledjobs=0;
	for(int i=0;iter!=jobmap.end();iter++,i++)
	{
		cout<<i+1<<"th job schedule->finish time:"<<iter->first<<" start time:"<<iter->second.start_time<<endl;
		if(prevjob_endtime <= iter->second.start_time)
		{
			nbrofscheduledjobs++;
			prevjob_endtime=iter->second.end_time;
		}
	}
	cout<<"Max number of jobs scheduled is "<<nbrofscheduledjobs<<endl;
	return 0;
}
			
