#include<iostream>
#include<queue>
using namespace std;

int main()
{
	priority_queue<int> pq;
	pq.push(3);
	pq.push(5);
	pq.push(1);
	pq.push(7);
	cout<<"Elements in pq are: "<<endl;
	while(pq.size())
	{
		cout<<"next in pq "<<pq.top()<<endl;
		pq.pop();
	}
	return 0;
}
