#include<iostream>
using namespace std;
#define NUM 5

int max(int x,int y)
{
	return x>y?x:y;
}
int knaps[8+1][NUM];

int knapsack(int *w,int *v,int W,int n)
{
	//static int[NUM];
	if(n<0)
		return 0;
	if(knaps[W][n]>0)
		return knaps[W][n];
	int val;
	if(W<w[n])
		val=knapsack(w,v,W,n-1);
	else
		val=max(knapsack(w,v,W,n-1),knapsack(w,v,W-w[n],n-1)+v[n]);
	knaps[W][n]=val;
	return val; 
}
int main()
{
	int w[]={2,3,5,2,4};
	int val[]={4,2,3,2,5};
	int max_wt=8;
	int max_val=knapsack(w,val,max_wt,NUM-1);
	cout<<"Maximum value obtained is "<<max_val<<endl;
	return 0;
}
