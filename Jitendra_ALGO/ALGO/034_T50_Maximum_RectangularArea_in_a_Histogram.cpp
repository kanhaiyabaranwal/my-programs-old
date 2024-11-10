/*
https://www.youtube.com/watch?v=ZmnqCZp9bBs
http://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0
http://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/
http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
*/

#include<iostream>
#include<stack>
using namespace std;

//TODO-- Set1

int getMaxArea_set2( int* hist, int n)
{
	int* leftIndex = new int[n];
	stack<int> leftStack;
	for(int i=0; i<n ; i++)
	{
		while(!leftStack.empty() && hist[leftStack.top()] >= hist[i])
			leftStack.pop();
		leftIndex[i] = leftStack.empty() ? -1 : leftStack.top();
		leftStack.push(i);
	}
	int* rightIndex = new int[n];
	stack<int> rightStack;
	for(int i=n-1; i>=0 ; i--)
	{
		while(!rightStack.empty() && hist[rightStack.top()] >= hist[i])
			rightStack.pop();
		rightIndex[i] = rightStack.empty() ? n : rightStack.top();
		rightStack.push(i);
	}

	int maxArea = 0;
	for(int i=0; i<n; i++)
	{
		int width = rightIndex[i] - leftIndex[i] -1;
		int area = width * hist[i];
		if(area > maxArea)
			maxArea = area;
	}
	return maxArea;
}

// Driver program to test above functions
int main_34_Maximum_RectangularArea_in_a_Histogram()
{
	int hist[] =  {6, 1, 5, 4, 5, 2, 6};
	int n = sizeof(hist)/sizeof(hist[0]);
	cout << "Maximum area is " << getMaxArea_set2(hist, n);
	return 0;
}