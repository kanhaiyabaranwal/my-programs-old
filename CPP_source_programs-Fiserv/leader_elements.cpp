#include<iostream>
#include<stack>
using namespace std;

void leaders(int arr[], int len)
{
	stack<int> stk;
	for(int i=0;i<len;i++)
	{
		while(!stk.empty() && arr[i]>arr[stk.top()])
		{
			//arr[stk.top()]=arr[i];
			stk.pop();
		}
		stk.push(i);
	}
	cout<<"Leaders are :";
	while(!stk.empty())
	{
		cout<<arr[stk.top()]<<",";
		stk.pop();
	}
	cout<<endl;
}

int main()
{
	cout<<"Leaders in array\n";
	//Leader is an element which is larger than all elements on its right
	int arr[]={16,17,4,3,5,2};
	leaders(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
