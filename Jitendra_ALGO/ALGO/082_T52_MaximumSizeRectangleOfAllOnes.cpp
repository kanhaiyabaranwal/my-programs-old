/*
https://www.youtube.com/watch?v=g8bSdXCG-lA
http://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/

Maximum Size Rectangle of All 1's Dynamic Programming

Maximum size rectangle binary sub-matrix with all 1s
Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.

*/
#include<iostream>
#include<stack>
using namespace std;

namespace NS82 {
	const int N = 4;
	const int M = 4;

	int getMaxSizeRectangle(int arr[N][M])
	{
		int res = 0;
		stack<int> S;

		int* histogram = new int[M];
		for (int i = 0; i < M; i++)
			histogram[i] = 0;
		int* left = new int[M];
		int* right = new int[M];

		//process each row
		for (int r = 0; r < N; r++)
		{
			//create the histogram
			for (int c = 0; c < M; c++)
				histogram[c] = arr[r][c] == 0 ? 0 : histogram[c] + 1;
			//clear the stack
			while (!S.empty()) S.pop();
			//calculate the left
			for (int c = 0; c < M; c++)
			{
				//pop the elements which are bigger
				while (!S.empty() && histogram[S.top()] >= histogram[c])
					S.pop();
				left[c] = S.empty() ? 0 : S.top() + 1;
					//push the index
				S.push(c);
			}
			//clear the stack
			while (!S.empty()) S.pop();
			//calculate the right
			for (int c = M-1; c >=0; c--)
			{
				//pop the elements which are bigger
				while (!S.empty() && histogram[S.top()] >= histogram[c])
					S.pop();
				right[c] = S.empty() ? M-1 : S.top() - 1;
				//push the index
				S.push(c);
			}
			//calculate histogram max rectangle
			for (int i = 0; i < M; i++)
			{
				int area = histogram[i] * (right[i] - left[i] + 1);
				res = res < area ? area : res;
			}
		}
		//cleanup
		delete[] histogram;
		delete[] left;
		delete[] right;
		return res;
	}

	void test()
	{
		int arr[N][M] =
		{
			{ 0, 1, 1, 0 },
			{ 1, 1, 1, 1 },
			{ 1, 1, 1, 1 },
			{ 1, 1, 0, 0 }
		};
		int res = getMaxSizeRectangle(arr);
		cout << "Maximum Size Rectangle of All 1's = " << res << endl;
	}
}

int main_82()
{
	NS82::test();
	return 0;
}