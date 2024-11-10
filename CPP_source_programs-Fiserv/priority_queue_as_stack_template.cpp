#include<iostream>
#include<queue>

using namespace std;

template<typename T>
struct element{
	T t;
	int i;
	static int order;
	element(T t):t(t),i(order++) {
		cout<<"Creating element:order="<<order<<endl;
	}
	bool operator<(element& e){
		return i<e.i;
	}
	~element(){ 
		order--;
		 cout<<"inside dtructor  element:order="<<order<<endl;
	 }
};
template<typename T>
int element<T>::order=0;

template<typename T>
class mystack{
	priority_queue<element<T> > pq;
	public:
	void push(T t)
	{
		pq.push(element<T>(t));
	}
	T top()
	{
		return pq.top().t;
	}
	void pop()
	{
		//element::order--;
		element<T> e=pq.top();
		pq.pop();
		delete &e;
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
	mystack<int> ms;
	ms.push(10);
	ms.push(1);
	ms.push(3);
	ms.push(19);
	cout<<"Top of stack is:"<<ms.top()<<endl;
	ms.pop();
	cout<<"Top of stack is:"<<ms.top()<<endl;
	return 0;
}

