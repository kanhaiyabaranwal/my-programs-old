#include<iostream>
#include<cstdlib>
using namespace std;

int comp(const void *p1,const void *p2)
{
	return *(int*)p1 > *(int*)p2;
}

int main()
{
	int arr[]={4,3,78,2,87,34,1};
	int sz=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	qsort(arr,sz,sizeof(int),comp);
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	return 0;
}
