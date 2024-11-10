#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct job{
	int st_time;
	int end_time;
	int profit;
	job(int s,int e,int p):st_time(s),end_time(e),profit(p){
	}
	bool operator<(job& j){
		
		return end_time<j.end_time;
	}
};


int findMaxProfit(vector<job> & jvec, int max_end_time,int index)
{
	if(index<=0)
		return 0;
	while(index>0)
	{
		if(jvec[index].end_time < max_end_time)
			break;
		index--;
	}
	int profit=max(findMaxProfit(jvec,jvec[index].st_time,index-1)+jvec[index].profit,
				findMaxProfit(jvec,max_end_time,index-1));
	return profit;
}

int main()
{
	vector<job> jvec;
	jvec.push_back(job(1,2,50));
	jvec.push_back(job(3,5,20));
	jvec.push_back(job(6,19,100));
	jvec.push_back(job(2,100,200));
	sort(jvec.begin(),jvec.end());
	for(vector<job>::iterator it=jvec.begin();it<jvec.end();it++)
		cout<<(*it).profit<<endl;
	int max_profit=0;
	int ind=3;
	int max_end_time=INT_MAX;
	int profit=findMaxProfit(jvec,INT_MAX,ind);
	cout<<"Max profit:"<<profit<<endl;
}
