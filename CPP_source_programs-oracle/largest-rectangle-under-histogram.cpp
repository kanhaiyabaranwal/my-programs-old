#include<iostream>
#include<stack>
using namespace std;

#define N 7

void largest_rectangle_under_histogram()
{
	int bar[]={6,2,5,4,5,1,6};
	
	stack<int> stk;
	stk.push(0);
	int minL[N]={0};
	//cout<<minL[0]=bar[0]<<",";
	cout<<"Printing min Left"<<endl;
	for(int i=0;i<N; i++)
	{
		while(stk.size() && bar[stk.top()] >= bar[i] )
			stk.pop();
		
		//if 
		minL[i]= stk.empty() ? -1 : stk.top();		
		/*
		if(stk.size() && stk.top() < bar[i])
			minL[i]=stk.top();
		else
			minL[i]=-1;
		*/
		stk.push(i);
		cout<<bar[minL[i]]<<",";
	}
	while(!stk.empty()) stk.pop();
	int minR[N]={0};
	//cout<<minL[0]=bar[0]<<",";
	cout<<"Printing min right"<<endl;
	for(int i=N-1;i>=0; i--)
	{
		while(stk.size() && bar[stk.top()] >= bar[i] )
			stk.pop();
		minR[i]= stk.empty() ? n  : stk.top();
		/*
		if(stk.size() && stk.top() < bar[i])
			minR[i]=stk.top();
		else
			minR[i]=n;
		*/
		stk.push(i);
		cout<<bar[minR[i]]<<",";
	}
	
	cout<<"Calculating maximum height at each bar "<<endl;
	int cur_area;
	int global_max=0;
	for(int i=0;i<N; i++)
	{
		cur_area=(minR[i]-1-minL[i])*bar[i];
		if(cur_area> global_max)
			global_max=cur_area;
	}
	cout<<"Max possible area is "<<global_max<<endl;
	
}

int main()
{
	largest_rectangle_under_histogram();
	return 0;
}
