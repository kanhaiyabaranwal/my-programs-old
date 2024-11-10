#include<iostream>

using namespace std;

float average(int a1,int a2)
{
	return (a1+a2)/2;
}

int max(int a1,int a2)
{
	return a1>a2?a1:a2;
}

int min(int a1,int a2)
{
	return a1<a2?a1:a2;
}

void median_of_two_sorted_arrays(int *arr1,int *arr2, int n)
{
	if(n==0)
		cout<<"n is zero"<<endl;
	if(n==1)
		cout<<"median is "<<(arr1[0]+arr1[0])/2<<endl;
		
	if(n==2)
	{
		cout<<"Mediain is "<<average(max(arr1[0],arr2[0]),min(arr1[1],arr2[1]))<<endl;
		
	}
	if(n<=2)
		return;
	
	int mid=(n-1)/2;			//mid index
	if(arr1[mid] > arr2[mid])
		median_of_two_sorted_arrays(arr1,arr2+mid,n-mid);
	else	
		median_of_two_sorted_arrays(arr1+mid,arr2,n-mid);
}

int main()
{
	int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    median_of_two_sorted_arrays(arr1,arr2,5);
    return 0;
}
