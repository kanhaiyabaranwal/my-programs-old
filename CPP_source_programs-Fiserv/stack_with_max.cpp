#include<iostream>
#include<utility>
using namespace std;

class stack{
	pair<int,int> *arr;
	int index;
	int cur;
	
	public:
	stack(int sz=100):index(sz),cur(0) 
	{
		arr=new pair<int,int>[index];
	}	
	int  push(int i)
	{
		if(cur==index)
			return -1;
		int max;
		if(cur)
			max=arr[cur-1].second>i?arr[cur-1].second:i;
		else
			max=i;
		arr[cur]=pair<int,int>(i,max);
		cur++;
		return 0;
	}
	void pop()
	{
		if(cur)
			cur--;
	}
	int max() const
	{
		if(cur)
			return arr[cur-1].second;
		else
			return -1;
	}
	int top() const
	{
		if(cur)
			return arr[cur-1].first;
		else
			return -1;
	}
};
		
	
int main()
{
	stack stk;
	stk.push(5);
	stk.push(12);
	stk.push(52);
	stk.push(42);
	stk.push(2);
	cout<<"stack's top:"<<stk.top()<<", stack's max:"<<stk.max()<<endl;
	stk.pop();
	cout<<"stack's top:"<<stk.top()<<", stack's max:"<<stk.max()<<endl;
	stk.pop();
	cout<<"stack's top:"<<stk.top()<<", stack's max:"<<stk.max()<<endl;
	stk.pop();
	cout<<"stack's top:"<<stk.top()<<", stack's max:"<<stk.max()<<endl;
	stk.push(1);
	cout<<"stack's top:"<<stk.top()<<", stack's max:"<<stk.max()<<endl;

	return 0;
}
