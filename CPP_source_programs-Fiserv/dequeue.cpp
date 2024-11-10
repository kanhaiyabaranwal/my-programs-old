#include<iostream>
#include<list>
#include<deque>
#include<stack>

using namespace std;

int main()
{
	int j=0;
	cout<<"j++="<<j++<<"j+2="<<j++<<endl;
	
	list<int> ilist;
	for(int i=0;i<10;i++)
		ilist.push_back(i*3);
	list<int>::iterator iter=ilist.begin();
	cout<<"list is = ";
	while(iter != ilist.end())
		cout<<*iter++<<"\t";
		
	deque<int> deq1, deq2;
	iter=ilist.begin();
	for(int i=1; iter != ilist.end();iter++,i++)
	{
		if(i%2 == 0)
			deq1.push_back(*iter);
		else
			deq2.push_back(*iter);
	}
	cout<<"\ndeq1 size="<<deq1.size()<<endl;
	cout<<"deq2 size="<<deq2.size()<<endl;
	deque<int>::iterator iter1=deq1.begin();
	cout<<"deque1 is"<<endl;
	while(iter1 != deq1.end())
	{
		cout<<(*iter1++)++<<"\t";
		//iter1++;
	}
	iter1=deq1.begin();
	cout<<"deque1 is"<<endl;
	while(iter1 != deq1.end())
	{
		cout<<(*iter1++)++<<"\t";
		//iter1++;
	}
	
	cout<<"\ndeque2 is"<<endl;
	iter1=deq2.begin();
	while(iter1 != deq2.end())
	{
		cout<<*iter1<<"\t";
		iter1++;
	}
	stack<int> stk(deq2);
	cout<<"top of the stack is "<<stk.top();
	return 0;
}
