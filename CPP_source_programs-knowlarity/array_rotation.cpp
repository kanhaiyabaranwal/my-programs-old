#include<iostream>
using namespace std;

void left_rotate(int *arr,int len)
{
	int temp=arr[len-1];
	arr[len-1]=arr[0];
	for(int i=len-2;i>=0;i--)
	{
		int temp1=arr[i];
		arr[i]=temp;
		temp=temp1;
	}	
}

void swap(int *arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void rotate(int *arr,int start,int end)
{
	while(start<end)
	{
		swap(arr,start,end);
		start++,end--;
	}
	return;
}
	

int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int len=7;
	cout<<"Array is: ";
	for(int i=0;i<len;i++)
		cout<<arr[i]<<", ";
	cout<<"Rotating array left by 3 places"<<endl;
	//for(int i=0;i<3;i++)
	//	left_rotate(arr,len);
	rotate(arr,0,1);
	rotate(arr,2,6);
	rotate(arr,0,6);
	cout<<"Array after rotation is: ";
	for(int i=0;i<len;i++)
		cout<<arr[i]<<", ";
	return 0;
}	
