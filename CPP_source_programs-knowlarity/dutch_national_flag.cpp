#include<iostream>
using namespace std;


void swap(int *arr,int i,int j)
{
	cout<<"before swap "<<arr[i]<<","<<arr[j]<<endl;
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	cout<<"before swap "<<arr[i]<<","<<arr[j]<<endl;
}	

void dutch_flag()
{
	int a[]={1,1,0,0,0,2,1,0,1};
	for(auto i :a)
		cout<<i<<",";
	cout<<endl;
	int p0=0,cur=0,p2=sizeof(a)/sizeof(a[0])-1;
	while(cur<=p2)
	{
		if(a[cur]==0)
		{
			swap(a,p0,cur);
			p0++;
			cur++;
		}
		else if(a[cur]==2)
		{		
			swap(a,p2,cur);
			p2--;
		}
		else
			cur++;
	}	
	for(auto i :a)
		cout<<i<<",";
	cout<<endl;
}
int main()
{
	dutch_flag();
	return 0;
}

