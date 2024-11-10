#include<iostream>
#include<cstdlib>
using namespace std;

int comp(const void* v1,const void* v2)
{
	return *(int*)v1 - *(int*)v2;
}

int platforms_required(int arr[],int dep[],int sz)
{
	qsort(arr,sz,sizeof(int),comp);
	qsort(dep,sz,sizeof(int),comp);
	cout<<"Arrivals:";
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<",";
	cout<<endl<<"Departures:";
	for(int i=0;i<sz;i++)
		cout<<dep[i]<<",";
	cout<<endl;
	int i=1,j=0;
	int count=1;
	int max=count;
	while(i<sz)
	{
		if(arr[i]<dep[j])
		{
			count++;
			if(max<count)
				max=count;
			i++;
		}
		else
		{
			count--;
			j++;
		}	
	}
	cout<<"Maximum platforms required:"<<max<<endl;
	return 0;
}

int main()
{
	int arr[]={900,940,950,1100,1500,1800};
	int dep[]={910,1200,1120,1130,1900,2000};
	int p=platforms_required(arr,dep,6);
	cout<<"Number of platforms required:"<<p<<endl;
	return 0;
}
