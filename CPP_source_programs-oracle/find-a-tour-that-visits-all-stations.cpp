#include<iostream>

using namespace std;

#define N 4

struct petrol_dist{
	int petrol;
	int distance;
};

int find_a_tour_that_visits_all_stations()
{
	//petrol_dist pd[N]={ {6,4}, {3,6}, {7,3} };
	petrol_dist pd[N]={{4, 6}, {6, 5}, {7, 3}, {4, 5}};
	for(int i=0;i<N;i++)
	{
		cout<<"petrol and distance # "<<i<<": "<<pd[i].petrol<<", "<<pd[i].distance<<endl;
	}
	
	int start=0, end=1;
	int cur_petrol=pd[0].petrol - pd[0].distance;
	while(start<N)
	{
		end=start+1;
		
		while(end!=start && cur_petrol>=0)
		{
			cur_petrol+=pd[end].petrol-pd[end].distance;
			end=(end+1)%N;
		}
		if(end==start)
			return start;
		
		cur_petrol-=(pd[start].petrol-pd[start].distance);
		start++;
	}
	return -1;
}

int main()
{
	int start=find_a_tour_that_visits_all_stations();
	if(start==-1)
		cout<<"No Solution"<<endl;
	else
		cout<<"Starting point is "<<start<<endl;
	return 0;
}
