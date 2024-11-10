/*
https://practice.geeksforgeeks.org/problems/exit-point-in-a-matrix/0
Given a matrix with 0’s and 1’s , you enter the matrix at cell (0,0) in left to right direction.
whenever you encounter a 0 you retain in same direction ,
if you encounter a 1’s you have to change direction to right of current direction and change that 1 value to 0,
you have to find out from which index you will leave the matrix at the end.
*/
#include<iostream>
using namespace std;

namespace NS_78
{
	const int N = 3;
	enum direction
	{
		left, right, up, down
	};

	void right_rotate(direction& d)
	{
		switch (d)
		{
		case left:
			d = up; break;
		case right:
			d = down; break;
		case up:
			d = right; break;
		case down:
			d = left; break;
		default:
			break;
		}
	}

	//void printExitPoint(int** arr, int n, int m)
	void printExitPoint()
	{
		int arr[N][N] =
		{
			{ 0, 0, 1 },
			{ 0, 0, 0 },
			{ 0, 0, 0 }
		};
		int n = N; int m = N;

		int x = 0; int y = 0; direction d = right;
		while (true)
		{
			if (arr[x][y])
			{
				right_rotate(d);
				arr[x][y] = 0;
			}
			int x1 = x; int y1 = y;
			switch (d)
			{
			case left:
				y1--; break;
			case right:
				y1++; break;
			case up:
				x1--; break;
			case down:
				x1++; break;
			default:
				break;
			}
			if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
			{
				cout << x << " " << y << endl;
				return;
			}
			x = x1; y = y1;
		}
	}
}

int main_78()
{
	NS_78::printExitPoint();
	return 0;
}

int main_78_geek4geeks() {
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n; cin >> n;
		int m; cin >> m;
		int** arr = new int*[n];
		for (int i = 0; i < n; i++)
			arr[i] = new int[m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		}
		//NS_78::printExitPoint(arr, n, m);
		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;
	}
	return 0;
}