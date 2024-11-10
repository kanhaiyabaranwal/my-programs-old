//https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/faizu-on-a-space-war/description/
#include<iostream>
#include<set>
using namespace std;
#define N 4

void swap(int *a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	
}

void max_xor_sum(int *a,int index,int sum,int &gsum)
{
	/*if(index==N-1)
	{
		if(sum>gsum)
			gsum=sum;
		cout<<"sum found="<<sum<<" and gsum="<<gsum<<endl;
		return;
	}
	
	int xor1=a[index]^a[index+1];	
	//cout<<"a[index]^a[index+1]"<<xor1<<endl;
	int newsum=xor1+sum;
	cout<<"sum until index= "<<index<<",newsum="<<newsum<<" and sum was "<<sum<<endl;
	max_xor_sum(a,index+1,newsum,gsum);
	int in;
	cin>>in;
	*/
	for(int j=index+1;j<N;j++)
	{
		swap(a,index,j);
		cout<<"Printing values for j="<<j<<" and index="<<index<<"->";
		for(int i=j;i<N;i++)
			cout<<a[i]<<",";
		cout<<endl;
		max_xor_sum(a,index+1,sum,gsum);
		swap(a,index,j);
	}
	int xor1=0;
	cout<<"array is: ";
	for(int i=0;i<N;i++)
		cout<<a[i]<<",";
	cout<<endl;	
	for(int i=0;i<N-1;i++)
	{
		int res=a[i]^a[i+1];
		cout<<"xor of "<<a[i]<<" and "<<a[i+1]<<" is "<< res<<endl;
		xor1+=res;
	}
		
	
	int res=a[0]^a[N-1];
	xor1=xor1+res;
	cout<<"Xor sum found="<<xor1<<endl;
	if(xor1>gsum)
			gsum=xor1;
}

void max_xor_sum_jitendra(int *a,int index,int sum,int &gsum)
{
	int max=0,maxi=0,maxj=0;
	int xtable[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			xtable[i][j]=a[i]^a[j];
			if(xtable[i][j] > max)
			{
				max=xtable[i][j];
				maxi=i;
				maxj=j;
			}
				
		}
	}
	cout<<"max xor obtained="<<max<<" at index "<<maxi<<","<<maxj<<endl;
	int max1=0,max2=0;
	for(int i=0;i<N;i++)
	{
		if(i!=maxi && max1>xtable[maxi][i]  )
			max1=xtable[maxi][i];
	}
	
	for(int i=0;i<N;i++)
	{
		if(i!=maxj && max2>xtable[maxj][i]  )
			max2=xtable[maxj][i];
	}
	int first,second;
	if(max1>max2)
		first=maxj,second=maxi;
	else
		first=maxi,second=maxj;
		
	cout<<"Printing array in sequence "<<a[first]<<","<<a[second]<<",";
	int next=second;
	set<int> iset;
	iset.insert(first);
	iset.insert(second);
	while(iset.size()<N)
	{
		int max=0;
		for(int j=0;j<N;j++)
		{
		
			if(iset.find(j) == iset.end() && xtable[next][j]>max)
				max=j;
		}
		cout<<max<<",";
		iset.insert(max);
	}
}

int main()
{
	int arr[]={7,2,3,1};
	int gsum=0;
	//max_xor_sum(arr,0,0,gsum);
	cout<<"Now using Jitendra's algo"<<endl;
	max_xor_sum_jitendra(arr,0,0,gsum);
	int out=3^2;
	//cout<<"xor of 3^2"<<out<<endl;
	cout<<"max xor_sum="<<gsum<<endl;
	return 0;
}
