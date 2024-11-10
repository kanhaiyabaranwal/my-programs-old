#include<iostream>
using namespace std;

void swap(int *arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int quick(int *arr,int beg,int end)
{
	if(beg==end)
		return 0;
	if(beg==end-1)
	{
		if(arr[beg]>arr[end])
			swap(arr,beg,end);
		return 0;
	}	
	int mid=(beg+end+1)/2;
	cout<<"mid="<<mid<<endl;
	int i=beg;
	int j=end;
	while(i<mid || j> mid )
	{
		if(arr[i]>arr[mid])
			swap(arr,i,mid);
		i++;
		if(arr[j]<arr[mid])
			swap(arr,j,mid);
		j--;
	}
	quick(arr,beg,mid-1);	
	quick(arr,mid+1,end);	
	return 0;
}
int main()
{
	int arr[]={3,5,7,9,1,12,13,6};
	int numOfElem=sizeof(arr)/sizeof(int);
	for(int i=0;i<numOfElem;i++)
		cout<<arr[i]<<"\t";
	cout<<"quick sorting\n";
	quick(arr,0,numOfElem);
	cout<<"sorted array is ";
	for(int i=0;i<numOfElem;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
	return 0;
}
