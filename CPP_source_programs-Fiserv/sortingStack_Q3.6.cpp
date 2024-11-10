//Q3.6CTCI: sort a stack in ascending order with atmost 1 more stack.
#include<iostream>
#include<stack>
#include<ctime>
#include<cstdlib>
using namespace std;
#define NUM 6

void stack_sort(stack<int> s1,stack<int> s2)
{
	int s1elem,s2elem;
	while(s1.size()>0)
	{
		s1elem=s1.top();
		s1.pop();
		//keep moving elements to s2 until elements are smaller than current one.
		//If next element is larger, push current elemnt to s2 as it is smaller.
		while(s2.size()>0 && s1elem > s2.top())
		{
			s2.push(s1elem);
			s1elem=s1.top();
			s1.pop();
		}
		s2elem=s1elem;
		while(s2.size()>0 && s2elem < s2.top())
		{
			s1.push(s2.top());
			//s2elem=s2.top();
			s2.pop();
		}
		s2.push(s2elem);
	}
	cout<<"sorted stack of size "<<s2.size()<<" is "<<endl;

	while(s2.size()>0)
	{
		cout<<s2.top()<<" ";
		s2.pop();
	}
	cout<<endl;
	return ;
}

int main()
{
	cout<<"Sorting a stack"<<endl;
	stack<int> s1,s2;
	srand(time(NULL));
	int val;
	for(int i=0;i<NUM;i++)
	{
		val=rand()%10;
		cout<<val<<" ";
		s1.push(val);
	}
	cout<<endl;
	stack_sort(s1,s2);
	return 0;
}
		

