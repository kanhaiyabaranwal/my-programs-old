#include<iostream>
using namespace std;

void swap(char *arr,int k)
{
	char temp=arr[k];
	arr[k]=arr[k+1];
	arr[k+1]=temp;
}

void swap_array()
{
	char arr[]="abcdef123456";
	int n=5;
	int i=n,j=n+1;
	while(i>0)
	{	
		int k=i;
		while(k<j)
		{		
			swap(arr,k); 
			k+=2;
		}
		i--;
		j++;
	}
	cout<<"Swapped Array: "<<arr<<endl;
}	

int main()
{
	swap_array();
	return 0;
}
