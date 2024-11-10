#include<iostream>
#include "PriorityQueue.h"
using namespace std;

int main_Test_PriorityQueue()
{
	samal::PriorityQueue<int> pq;
	pq.add(5);
	pq.add(10);
	pq.add(11);
	pq.add(12);
	pq.add(13);
	pq.add(14);
	pq.add(15);
	pq.add(16);
	pq.add(2);
	pq.add(1);
	pq.remove(2);

	return 0;
}
