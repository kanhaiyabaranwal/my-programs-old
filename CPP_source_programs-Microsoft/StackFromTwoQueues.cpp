#include<iostream>
#include<queue>
using namespace std;

//Problem: implement stack using 2 queues
//Strategy: push-O(n), pop(1), top(1)
//			Keep all elements in reversed order, i.e. in stack format right from the beginning
//			Before pushing new element, move all element to qaux, then push new element to qp and then move all qaux elements to qprime.

class Stack{
	queue<int> qprim,qaux;
	public:
		void push(int i);
		int top() const{
			return qprim.front();
		}
		void pop(){
			if(!qprim.empty())
				qprim.pop();
		}
		int length() const{
			return 	qprim.size();
		}
};
void Stack::push(const int i)
{
	while(!qprim.empty())
	{
		qaux.push(qprim.front());
		qprim.pop();
	}
	qprim.push(i);
	while(!qaux.empty())
	{
		qprim.push(qaux.front());
		qaux.pop();
	}
	
}

int main()
{
	Stack stk;
	for(int i=1;i<6;i++)
		stk.push(i*2);
	for(int i=1;i<6;i++)
	{
		cout<<stk.top()<<",";
		stk.pop();
	}
		
	return 0;
}
