#include<iostream>
#include<vector>
using namespace std;
#define N 6


int dp[N+2];
vector<int> a=vector<int>{1,2,3,2,1,4};
int count(int n)
{
	if(n==0)
	{
		dp[n]=1;
	}
	if(dp[n])
		return dp[n];
	
	if(a[n-1]==1 || (a[n-1]==2 && a[n]<=6))
		dp[n]=count(n-2)+count(n-1);
	else
		dp[n]=count(n-1);
	return dp[n];
}

int count_j(int n)
{
	int dp[7];
	dp[0]=dp[1]=1;
	for(int i=1;i<n;i++)
	{
		if(a[i-1]==1 || (a[i-1]==2 && a[i]<=6))
			dp[i+1]=dp[i]+dp[i-1];
		else
			dp[i+1]=dp[i];
	}
	return dp[n];
}




int main()
{
	for(int i=0;i<N+2;i++)
		dp[i]=0;
	
	cout<<"count:"<<count(5)<<endl;
	cout<<"count_j:"<<count_j(6)<<endl;
	return 0;
	
}
