//epi; 17.1: find the number of combinations of plays that result in an aggregate score of s from W specific points
#include<iostream>
using namespace std;
#define SCORE 4

int w[]={1,2,3};
int *arr;
int reach(int s)
{
	//static int count;
	if(s==0)
	{
		arr[s]=1;
		return arr[s];
	}
	if(s<0)
		return 0;
	if(arr[s])
		return arr[s];
	arr[s]=reach(s-w[0])+ reach(s-w[1])+ reach(s-w[2]);
	return arr[s];
}

int main()
{
	int s=SCORE;
	arr=new int[SCORE];
	int count=reach(s);
	cout<<"Ways to get score "<<s<<" from points 1,2,3 is "<<count<<endl;
	return 0;
}
