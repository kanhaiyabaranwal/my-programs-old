#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef struct {
	int jobnbr;
	int start_time;
	int end_time;
} JobSchedule;
typedef std::multimap<int,JobSchedule> JOBMAP_T ;

int jobMachine(char* input1[])
{
	//Write code here
	char **jobschedule=input1;		//renamed for convenient reading and save initial pointer
	int nbrOfJobs=0;
	while(**input1)
	{
		nbrOfJobs++,input1++;
	}
	char start_time[5];
	char end_time[5];
	int time1;
	int time2;
	JOBMAP_T jobmap;
	std::pair<int,JobSchedule> jobpair;
	for(int i=0;i<nbrOfJobs;i++)
	{
		memset(start_time,NULL,sizeof(start_time));
		memset(end_time,NULL,sizeof(end_time));
		char* ch=strchr(jobschedule[i],'#');
		if(!ch)
			return -1;
		int pos1=ch-jobschedule[i];
		if(pos1>0)
		{
			strncpy(start_time,jobschedule[i],pos1);
			strcpy(end_time,ch+1);
		}

		//extract start time
		if(strlen(start_time)==4)
			time1=(start_time[0]-48)*10+(start_time[1]-48);
		else if(strlen(start_time)==3)
			time1=(start_time[0]-48);
		else					//error, correct input is in format 6AM,12AM,6PM,12PM 
			return -1;				
		if(time1>12 || time1<1)				//only 1-12 is acceptable
			return -1;
		if(start_time[strlen(start_time)-2]=='P')		
			time1+=12;
		//12AM, 12PM is different; 12AM is 0 and 12PM is 12. so subtract 12 
		if(time1==24 || time1==12)
			time1-=12;

		//extract end time
		if(strlen(end_time)==4)
			time2=(end_time[0]-48)*10+(end_time[1]-48);
		else if(strlen(end_time)==3)
			time2=(end_time[0]-48);
		else					//error, correct input is in format 6AM,12AM,6PM,12PM 
			return -1;				
		if(time2>12 || time2<1)				//only 1-12 is acceptable
			return -1;
		if(end_time[strlen(end_time)-2]=='P')
			time2+=12;
		//12AM, 12PM is different; 12AM is 0 and 12PM is 12. so subtract 12 
		if(time2==24 || time2==12)
			time2-=12;

		if(time2<time1)			//end time can't be less than start time
			return -1;

		JobSchedule js={i+1,time1,time2};
		jobpair=make_pair(time2,js);
		jobmap.insert(jobpair);
	}
	JOBMAP_T::const_iterator iter=jobmap.begin();
	int prevjob_endtime=0;
	int nbrofscheduledjobs=0;
	for(int i=0;iter!=jobmap.end();iter++,i++)
	{
		//cout<<i+1<<"th job schedule->finish time:"<<iter->first<<" start time:"<<iter->second.start_time<<endl;
		if(prevjob_endtime <= iter->second.start_time)
		{
			nbrofscheduledjobs++;
			prevjob_endtime=iter->second.end_time;
		}
	}
	return nbrofscheduledjobs*500;
}

int main()
{
	//char *jobschedule[]={"6AM#8AM","11AM#1PM","7AM#3PM","7AM#10AM","10AM#12PM","2PM#4PM","1PM#4PM","8AM#9AM"};
	//char *jobschedule[]={"7AM#8AM","9AM#11AM","8AM#10AM","11AM#12PM","2PM#3PM","8AM#3PM","2PM#5PM","3PM#5PM","7PM#9PM","8PM#10PM","6PM#7PM","3PM#4PM"};
	char *jobschedule[]={6AM#8AM,11AM#1PM,7AM#3PM}
	int maxJobScheduled=jobMachine(jobschedule);
	cout<<"maxJobScheduled="<<maxJobScheduled<<endl;
	
	return 0;
}
