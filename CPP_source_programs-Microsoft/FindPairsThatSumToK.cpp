#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;

void FindPairsWithSum(int *arr,int n,int k)
{
	
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	int low=0,high=n-1;
	while(low<high)
	{
		if(arr[low]+arr[high]==k)
		{
			cout<<"Pair found:"<<arr[low]<<","<<arr[high]<<endl;
			low++;
		}
			
		else if(arr[low]+arr[high]>k)
			high--;	
		else
			low++;
	}		
		
}


int main()
{
	int k=8;
	int arr[]={1,2,3,3,4,5,7,5,6,9};
	int n=sizeof(arr)/sizeof(*arr);
	cout<<"n"<<n<<endl;
	FindPairsWithSum(arr,n,k);
	return 0;
}
