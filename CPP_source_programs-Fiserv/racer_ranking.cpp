//You have the start time, end time and index number of racers in a race. 
//You need to tell the rank of each racer. 
//The rank is calculated as following: if racer B starts after racer A but finishes before racer A, then the rank of racer A increases by 1.

#include<iostream>
#include<iomanip>
using namespace std;

struct racer{
	int index;
	int st;
	int et;
	int rank;
};

//takes racers and show their ranks 
void racer_ranking(racer *r,int n)
{
	for(int i=0;i<n;i++)	
		for(int j=1;j<n;j++)	
		{
			if(r[j].st > r[i].st and r[j].et < r[i].et )
				r[i].rank++;
		}
	cout<<setw(5)<<"index"<<setw(5)<<"rank"<<endl;
	for(int i=0;i<n;i++)	
	{
		cout<<setw(5)<<r[i].index<<setw(5)<<r[i].rank<<endl;
	}
}

int main()
{
	/*racer *r=new racer[4];
	r[0]={0,100,170,0};
	r[1]={1,80,150,0};
	r[2]={2,120,165,0};
	r[3]={3,110,145,0};
	*/racer r[]={{0,100,170},{1,80,150},{2,120,165},{3,110,145}};
	racer_ranking(r,4);
	//delete []r;
	return 0;
}
	
