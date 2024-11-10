#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//https://www.geeksforgeeks.org/next-greater-element/


void NGE()
{
	int arr[]={4,5,2,25};
	int len=sizeof(arr)/sizeof(*arr);
	cout<<"len is "<<len<<endl;
	int *nge = new int[len];
	nge[len-1]=-1;
	stack<int> stk;		
	stk.push(len-1);
	for(int i=len-2;i>=0;i--)
	{
		while(!stk.empty() && arr[stk.top()]<arr[i])
			stk.pop();
		if(stk.empty())
			nge[i]=-1;
		else
			nge[i]=stk.top();
		stk.push(i);
	}
	for(int i=0;i<len;i++)
		cout<<"next greater element for "<<arr[i]<<" is "<<arr[nge[i]]<<endl;
	
}

int main()
{
	
	NGE();
	return 0;
	
}
