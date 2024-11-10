#include<iostream>
using namespace std;


void swap(int *arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	
}

int placement(int *arr, int lower, int upper)
{
	//place 1st element correctly
	int i=lower+1;
	int j=upper;
	while(i<j)
	{
		
		if(arr[i] < arr[lower])
			i++; 
		if(arr[j] > arr[lower] && j>i)
			j--;
		if(arr[i] > arr[j])
			swap(arr,i,j);
	}
	if(arr[lower]>arr[i-1])
		swap(arr,lower,i-1);
	return i-1;
}

int qsort(int *arr, int lower, int upper)
{
	//correctly place 1st element in the array from lower to upper
	int place;
	if(lower<upper)
	{
	
		place = placement( arr, lower,upper);
		qsort(arr,lower,place-1);
		qsort(arr,place+1,upper);	
	}
}
int arr[]={15,82,5,25,17,16,16,75,3,6};
int main()
{
	
	int size=sizeof(arr)/sizeof(int);
	cout<<"size of arr="<<size;
	qsort(arr, 0,size-1);
}
