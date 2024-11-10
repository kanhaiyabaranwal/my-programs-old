/*
Maximum Subsquare With Sides as X
Given a matrix of ‘O’ and ‘X’, find the largest subsquare surrounded by ‘X’


https://www.youtube.com/watch?v=vi_1eHCsR9A
http://www.geeksforgeeks.org/given-matrix-o-x-find-largest-subsquare-surrounded-x/


*/

#include<iostream>
#include<algorithm>
using namespace std;

#define N 6

namespace NS_63
{
	int findSubSquare_DP_WRONG(int mat[][N])
	{
		int** dp = new int*[N];
		for(size_t i=0; i<N; i++)
			dp[i] = new int[N];

		int res = 0;
		for(size_t i=0; i<N; i++)
		{
			for(size_t j=0; j<N; j++)
			{
				if(i==0 || j==0) { dp[i][j] = mat[i][j] == 'X' ? 1 : 0; continue;}
				dp[i][j] = mat[i][j] != 'X' ? 0 : 1 + min(dp[i-1][j],dp[i][j-1]);
				res = res < dp[i][j] ? dp[i][j] : res;
			}
		}
		for(size_t i=0; i<N; i++)
			delete[] dp[i];
		delete[] dp;
		return res;
	}

	int findSubSquare_DP(int mat[][N])
	{
		int** dp_hor = new int*[N];
		int** dp_ver = new int*[N];
		for(size_t i=0; i<N; i++)
		{
			dp_hor[i] = new int[N];	dp_ver[i] = new int[N];
		}

		int res = 0;
		for(size_t i=0; i<N; i++)
		{
			for(size_t j=0; j<N; j++)
			{
				if(i==0 || j==0) 
					dp_ver[i][j] = dp_hor[i][j] = (mat[i][j] == 'X') ? 1 : 0;
				else
				{
					dp_hor[i][j] = mat[i][j] != 'X' ? 0 : 1 + dp_hor[i-1][j];
					dp_ver[i][j] = mat[i][j] != 'X' ? 0 : 1 + dp_hor[i][j-1];
				}
				res = res < min(dp_hor[i][j],dp_ver[i][j]) ? 
					min(dp_hor[i][j],dp_ver[i][j]) : res;
			}
		}
		//todo this is not working re-work on res calculation

		for(size_t i=0; i<N; i++) {delete[] dp_hor[i]; delete[] dp_ver[i];}
		delete[] dp_hor; delete[] dp_ver;
		return res;
	}


}

int main_63()
{
	int mat[][N] =  {
		{'X', 'O', 'X', 'X', 'X', 'X'},
		{'X', 'O', 'X', 'X', 'O', 'X'},
		{'X', 'X', 'X', 'O', 'O', 'X'},
		{'O', 'X', 'X', 'X', 'X', 'X'},
		{'X', 'X', 'X', 'O', 'X', 'O'},
		{'O', 'O', 'X', 'O', 'O', 'O'},
	};
	int res = NS_63::findSubSquare_DP(mat);
	cout << res;
	return 0;
}