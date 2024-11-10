#include<iostream>
#include<stack>
using namespace std;

void replace(int arr[], int len)
{
	stack<int> stk;
	for(int i=0;i<len;i++)
	{
		while(!stk.empty() && arr[i]>arr[stk.top()])
		{
			arr[stk.top()]=arr[i];
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty())
	{
		arr[stk.top()]=-1;
		stk.pop();
	}
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	cout<<"Replace algorithm\n";
	int arr[]={12,15,78,23,6,10,21,2,91,5,1,3};
	replace(arr,12);
	return 0;
}
