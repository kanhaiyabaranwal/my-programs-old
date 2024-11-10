#include<iostream>
using namespace std;

int triangle_combos(int *a,int len)
{
	int K=0;int k;
	for(int i=0;i<len-2;i++)
	{
		K=0;
		for(int j=i+1;j<len-1;j++)
		{
			if(K)
				k=K;
			else
				k=j+1;
			while(k<len && a[i]+a[j]>a[k])
			{
				//if(a[i]+a[j]<a[k])
				for(int t=j+1;t<k;t++)
					cout<<a[i]<<","<<a[t]<<","<<a[k]<<endl;
				cout<<a[i]<<","<<a[j]<<","<<a[k]<<endl;
				k++;
			}
		}
		K=k;
	}
}

int main()
{
	cout<<"Print all triangle combos"<<endl;
	int arr[]={4,5,7,8,10,12,14,16,19};
	triangle_combos(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
