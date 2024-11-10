#include<iostream>
#include<queue>
#define K 3

using namespace std;

void sliding_window_maximum_maximum_of_all_subarrays_of_size_k(int *a,int n)
{
	deque<int> dq;
	cout<<"n="<<n<<endl;
	for(int i=0;i<K;i++)
	{
		while(!dq.empty() && a[dq.back()] < a[i])
			dq.pop_back();
		dq.push_back(i);
	}
	
	for(int i=K;i<n;i++)
	{
		cout<<a[dq.front()]<<",";
		while(!dq.empty() && dq.front() <= i-K)
			dq.pop_front();
		
		while(!dq.empty() && a[dq.back()] < a[i])
			dq.pop_back();
		
		dq.push_back(i);
	}
	cout<<a[dq.front()]<<"\n";
		
}


int main()
{
	//int arr[]={1,2,3,1,4,5,2,3,6};
	int arr[]={9,8,7,6,5,4,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	sliding_window_maximum_maximum_of_all_subarrays_of_size_k(arr,n);
	return 0;
}
