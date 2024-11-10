#include<iostream>
#include<queue>

using namespace std;

class element{
	int t;
	int i;
	static int order;
	public:
	element(int t):t(t),i(order++) {
		cout<<"Creating element:order="<<order<<endl;
	}
	friend bool operator<(const element& e1,const element& e) {
		return e1.i<e.i;
	}
	~element(){ 
		order--;
		 cout<<"inside dtructor  element:order="<<order<<endl;
	 }
	int getT() const {
		return t;
	}
};
int element::order=0;

class mystack{
	priority_queue<element> pq;
	public:
	void push(int t)
	{
		pq.push(element(t));
	}
	int top()
	{
		return pq.top().getT();
	}
	void pop()
	{
		//element::order--;
		const element& e=pq.top();
		pq.pop();
		//delete &e;
	}
};
		

int main()
{
	/*priority_queue<int,vector<int>,less<int> > pq;
	pq.push(10);
	pq.push(1);
	pq.push(3);
	pq.push(19);
	cout<<"Top of priority_queue is:"<<pq.top()<<endl;
	*/
	mystack ms;
	ms.push(10);
	ms.push(1);
	ms.push(3);
	ms.push(19);
	cout<<"Top of stack is:"<<ms.top()<<endl;
	ms.pop();
	cout<<"Top of stack is:"<<ms.top()<<endl;
	return 0;
}

