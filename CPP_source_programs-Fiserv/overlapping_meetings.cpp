#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>

using namespace std;

struct sched{
	int start;
	int end;
	int overlaps;
	sched(int s,int e,int ol=0):start(s),end(e),overlaps(ol) {
	}
};

typedef multimap<int,sched> mmap;
int overlap_meetings()
{
	ifstream in("meeting.txt");
	mmap mymap;
	string s;
	cout<<"Reading meeting schedules"<<endl;
	string start,end;
	while(in>>s)
	{
		int pos=s.find_first_of("-");
		//cout<<"pos="<<pos;
		if(pos!=string::npos)
			start=s.substr(0,pos);
		end=s.substr(pos+1);
		//cout<<"start="<<start<<",end="<<end<<endl;
		int is=atoi(start.c_str());
		int ie=atoi(end.c_str());
		mymap.insert(make_pair(is,sched(is,ie)));
		//getline(in,s,);,
		//cout>>s>>endl;
	}
	mmap::iterator iter=mymap.begin();
	mmap::const_iterator fiter;
	mmap::reverse_iterator riter;
	cout<<"Iterating through the map"<<endl;
	for(int i=0;iter!=mymap.end();iter++,i++)
	{
		//cout<<iter->first<<","<<iter->second.start<<iter->second.end<<endl;
		//iter1=mymap.begin();
		int overlaps=0;
		fiter=mymap.begin();
		for(;fiter!=iter;fiter++)
		{
			if(fiter->second.end > iter->second.start)		//if finish time of earlier meetings is later than start time of meeting under consider
				overlaps++;
				//break;
		}
		//fiter++;
		for(;fiter!=mymap.end();fiter++)
		{
			if(fiter->second.start < iter->second.end)		//if start time of later meetings is earlier than finish time of meeting under consider
				overlaps++;
			else
				break;
		}
		iter->second.overlaps=overlaps;
	}
	cout<<"Map over"<<endl;
	for(iter=mymap.begin();iter!=mymap.end();iter++)
		cout<<"start time="<<iter->second.start<<", end time="<<iter->second.end<<", overlaps="<<iter->second.overlaps<<endl;
		
	
	return 0;
}


int main()
{
	cout<<"Find max number of overlapping meetings"<<endl;
	overlap_meetings();
	return 0;
	
}
