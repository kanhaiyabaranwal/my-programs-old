#include<iostream>
#include<cstdlib>
using namespace std;

int arr[16]={4,10,11,13,0,15,28,6,0,0,8,4,0,9,11,0};
int K=40;
int L=4;

int FindSum(int N,int sum,int level)
{
	sum=sum+arr[N];
	cout<<"level="<<level<<",sum="<<sum<<endl;
	if(level>=4 || arr[N]<=0 || sum >= K || N >=16 )	//terminating condition, level reached, or leaf or sum>K
	{
		if(sum==K)
		{
			int pos=N;
			while(pos>=1)
			{
				cout<<arr[pos]<<" <- ";
				pos/=2;
			}
			cout<<"This path qualifies\n";
		}
		return 0;
	}
	if(level < L )
	{
		FindSum(N*2,sum,level+1);
		FindSum(N*2+1,sum,level+1);
	}
	return 0;
}

int main()
	
{	
	cout<<"Tree implementation in array format"<<endl;
	cout<<sizeof arr/sizeof *arr<<endl;
	int level=0;
	int sum;
	int curpos=1;
	FindSum(curpos,sum,level);
	//for(int i=0;i<sizeof arr;i++)
	
}
