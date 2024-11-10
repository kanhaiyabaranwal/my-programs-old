//dutch national flag problem- divide an array into smaller, equal, larger numbers
#include<iostream>
#include<array>
using namespace std;

void swap(int *arr,int m,int n)
{
	/*int temp=arr[m];
	arr[m]=arr[n];
	arr[n]=temp;
	*/
	if(m==n)
		return;
	/*arr[m]=arr[m]+arr[n];
	arr[n]=arr[m]-arr[n];
	arr[m]=arr[m]-arr[n];
	*/    
	arr[m]^=arr[n];
	arr[n]^=arr[m];
	arr[m]^=arr[n];
	
}

//partition elements into 3 parts, lower,equal and higher
int dutch_national_flag(int *arr,int n,int index)
{
	int smaller=0,larger=n-1,cur=0,equal=0;
	int val=arr[index];
	while(equal<=larger)
	{
		if(arr[equal]<val)
			swap(arr,smaller++,equal++);
	 else if(arr[equal]==val)
			equal++;
		else	//larger value
			swap(arr,equal,larger--);
	}
}

//partition elements into 4 sequential elements
int dutch_national_flag_key(int *arr,int n,int index)
{
	int val1=0,val2=0,val3=0,val4=n-1;
	while(val3<=val4)
	{
		if(arr[val3]==1)
		{
			swap(arr,val1++,val3);
			swap(arr,val2++,val3++);
		}
	 	else if(arr[val3]==2)
	 		swap(arr,val2++,val3++);
		else if(arr[val3]==3)	//larger value
			val3++;
		else
			swap(arr,val3,val4--);
	}
}
//partition boolean elements into false and true elements
int dutch_national_flag_key1(int *arr,int n,int index)
{
	int val1=0,val2=n-1;
	while(val1<=val2)
	{
		if(arr[val1]==1)
		{
			swap(arr,val1,val2--);
		}
	 	else
			val1++;
	}
}



int main()
{
	//int arr[]{4,67,34,87,12,54,2,5,9,12,96,48,3,12,2,48};
	//int arr[]{4,67,12,87,12,54,2,5};
	//int arr[]{1,2,2,1,3,4,2,4,3,2,4,2,1,3,2,4};
	int arr[]{1,0,1,1,0,1,0,1,1,1,0};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int index=4;
	cout<<"Original array"<<endl;
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	dutch_national_flag_key1(arr,sz,index);
	cout<<"Array after dutch national flag partitioning"<<endl;
	for(int i=0;i<sz;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
