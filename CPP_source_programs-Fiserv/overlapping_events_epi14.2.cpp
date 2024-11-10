#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;
struct timeI{
	int time;
	bool IsStart;
	bool operator<(const timeI& t) const {
		return time<t.time;
	}
	timeI(int time,bool IsStart):time(time),IsStart(IsStart) {}
	friend ostream& operator<<(ostream &os,timeI t)
	{
		os<<t.time<<" "<<t.IsStart;
		return os;
	}
};

int overlapping_events()
{
	ifstream in("meeting.txt");
	string str1,str2;
	multiset<timeI> tset;
	stringstream ss;
	string temp;
	while(in>>str1>>str2)
	{
		int time=atoi(str1.c_str());
		tset.insert(timeI(time,true));
		time=atoi(str2.c_str());
		tset.insert(timeI(time,false));
		cout<<"start time "<<str1<<", end time "<<str2<<endl;
	}
	multiset<timeI>::const_iterator iter=tset.begin();
	cout<<"Iterating through the set"<<endl;
	copy(tset.begin(),tset.end(),ostream_iterator<timeI>(cout,"\n"));
	int max_count=0,count=0;
	while(iter!=tset.end())
	{
		if((*iter).IsStart)
			count++;
		else
			count--;
		if(count>max_count)
			max_count=count;
		iter++;
		//cout<<(*iter).time<<" "<<(*iter).IsStart<<endl;
	}
	cout<<"Maximum number of overlapping events are "<<max_count<<endl;
	return 0;
}
int main()
{
	overlapping_events();
	return 0;
}
	
