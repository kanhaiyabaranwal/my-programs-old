#include<iostream>
#include<vector>
#include<array>
using namespace std;

typedef struct user_bandwidth{
	int st;
	int et;
	int bw;
} UB;

int main()
{
	array<UB,5> ub;
	ub[0]={9,15,2};
	ub[1]={11,12,3};
	ub[2]={15,17,5};
	ub[3]={10,13,2};
	ub[4]={11,16,3};
	for( UB& ubdata:ub)
		cout<<ubdata.st<<", "<<ubdata.et<<", "<<ubdata.bw<<endl;
	return 0;
	
}
