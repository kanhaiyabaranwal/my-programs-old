/*
http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
https://www.youtube.com/watch?v=vgLJZMUfnsU
*/
#include<iostream>
#include<limits>
using namespace std;

namespace NS_56
{
	int MatrixChainOrder_DP(int* arr, int n)
	{
		if (n <= 1) return -1; if (n == 2) return 0; //base case

		int **table = new int*[n - 1];
		for (int i = 0; i < n - 1; i++)
			table[i] = new int[n - 1];

		for (int length = 1; length <= n - 1; length++)
		{
			for (int i = 0; i + length <= n - 1; i++)
			{
				int j = i + length - 1;
				if (i == j) { table[i][j] = 0; continue; }  //length = 1
				int min_cost = INT_MAX;
				for (int k = i; k < j; k++)
				{   // write the formula details here
					int cost = table[i][k] + table[k + 1][j] + (arr[i] * arr[k + 1] * arr[j + 1]);
					min_cost = min_cost > cost ? cost : min_cost;
				}
				table[i][j] = min_cost;
			}
		}
		int res = table[0][n - 2];
		for (int i = 0; i < n - 1; i++)
			delete[] table[i];
		delete[] table;
		return res;
	}
}

// TODO -write recurssive method

int main_56_T_18_MatrixChainMultiplication()
{
	//int arr[] = {1, 2, 3, 4};
	//int arr[] = {1, 2, 3, 4, 3};
	int arr[] = { 2, 3, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//int res = NS_56::MatrixChainOrder_R(arr, 1, n-1));
	int res = NS_56::MatrixChainOrder_DP(arr, n);
	cout << "Minimum number of multiplications is : " << res << endl;
	return 0;
}