/*
http://www.geeksforgeeks.org/the-stock-span-problem/
*/
#include<iostream>
#include<stack>

using namespace std;

void calculateSpan(int* stockPrice, int n, int* Result)
{
	stack<int> s;
	for(int i=0; i<n; i++)
	{
		while(!s.empty() && stockPrice[i] > stockPrice[s.top()])
			s.pop();
		if(!s.empty())
			Result[i] = i - s.top();
		else
			Result[i] = i + 1;
		s.push(i);
	}
}

int main27_TheStockSpanProblem()
{
	//int stockPrice[] = {10, 4, 5, 90, 120, 80};
	int stockPrice[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(stockPrice)/sizeof(stockPrice[0]);
	int* Result = new int[n];

	// Fill the span values in array S[]
	calculateSpan(stockPrice, n, Result);

	// print the result
	for(int i=0; i<n; i++)
		cout << Result[i] << " ";
	cout << endl;

	return 0;
}