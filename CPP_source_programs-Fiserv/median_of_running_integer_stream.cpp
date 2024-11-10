//Program to find median_of_running_integer_stream
#include<iostream>
#include<queue>
#include<fstream>
#include<cmath>
#include<cstdlib>
using namespace std;

void median_of_running_integer_stream()
{
	ifstream in("integers.txt");
	int num;
	priority_queue<int,vector<int>,less<int> > maxHeap; 
	priority_queue<int,vector<int>,greater<int> > minHeap; 
	cout<<"Numbers are ";
	while(in>>num)
	{
		//push elements into one of the heaps
		if( minHeap.size() && num < minHeap.top())
			maxHeap.push(num);
		else
			minHeap.push(num);
		//int size_diff=const_cast<int&>(abs(minHeap.size()-maxHeap.size()));
		cout<<"size of minHeap="<<minHeap.size()<<", size of maxHeap="<<maxHeap.size()<<endl;
		int max=maxHeap.size();
		int min=minHeap.size();
		int diff=max-min;
		while((min-max)>1 || (max-min)>1)
		{
			if(minHeap.size()>maxHeap.size())
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}
			else
			{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
			max=maxHeap.size();
			min=minHeap.size();
			//size_diff=const_cast<int&>(abs(minHeap.size()-maxHeap.size()));
		}
		
		if(minHeap.size()==maxHeap.size())
			cout<<"Heaps are same size. Next element is "<<num<<", median is "<<(minHeap.top()+maxHeap.top())/2.0<<endl;
		else if(minHeap.size()>maxHeap.size())
			cout<<"Min Heap larger. Next element is "<<num<<", median is "<<minHeap.top()<<endl;
		else
			cout<<"Max Heap larger. Next element is "<<num<<", median is "<<maxHeap.top()<<endl;
		
	}
	cout<<endl<<"Elements in minHeap are "<<endl;
	while(minHeap.size())
	{
		cout<<minHeap.top()<<" ";
		minHeap.pop();
	}
	cout<<endl<<"Elements in maxHeap are "<<endl;
	while(maxHeap.size())
	{
		cout<<maxHeap.top()<<" ";
		maxHeap.pop();
	}
}

int main()
{
	cout<<"Program to find median_of_running_integer_stream"<<endl;
	median_of_running_integer_stream();
	return 0;
}
