#include<iostream>

using namespace std;
#define N 11
void min_jump_required()
{
	int a[]={1,3,5,8,9,2,6,7,6,8,9};
	int current=0,jump=0,backup=0;
	if(N==1 || a[0]==0)
	{
	
		cout<<"No jump required/possible"<<endl;
		return;
	}
	for(int i=0;i<N;i++)
	{
		if(current=0 && backukp==0)		//terminating condition
			return;
		if(current==0)
			jump++;
		
		if(a[i]>backup)
			backup=a[i];
		if(current==0)
			current=backup;
		current--;
		backup--;
	}
	cout<<"Minimum jumps:"<<jump<<endl;
}

int main()
{
	min_jump_required();
	return 0;
}
