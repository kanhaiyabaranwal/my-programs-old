/*
https://www.youtube.com/watch?v=yCQN096CwWM
http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/

Maximum Sum Rectangular Submatrix in Matrix dynamic programming/2D kadane
Dynamic Programming | Set 27 (Maximum sum rectangle in a 2D matrix)
*/
#include<iostream>
using namespace std;

namespace NS73
{
#define ROW 4
#define COL 5

	//TODO -- This is not working, but why? 
	// now try kadane formula
	void findMaxSum_WRONG(int M[][COL])
	{
		int dp[ROW][COL];
		int max_sum = INT_MIN; int row = -1; int col = -1;
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				if (i == 0 && j == 0)
					dp[i][j] = M[i][j];
				else if (i == 0)
					dp[i][j] = dp[i][j - 1] + M[i][j];
				else if (j == 0)
					dp[i][j] = dp[i - 1][j] + M[i][j];
				else
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + M[i][j];
				if (dp[i][j] > max_sum)
				{
					max_sum = dp[i][j];
					row = i; col = j;
				}
			}
		}
		//print the DP array
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				cout << "\t" << dp[i][j];
			}
			cout << endl;
		}
		int start_row = 0;
		int start_col = 0;
		//cout << "Max sum from (0,0) to (" << row << "," << col << ") = " << max_sum << endl;
		cout << "Max sum from (" << start_row << "," << start_col << ") to (" << row << "," << col << ") = " << max_sum << endl;
		//now lets improve by lowering row
		for (int i = 0; i <= row; i++)
		{
			int new_sum = max_sum - dp[i][col];
			if (new_sum > max_sum)
			{
				max_sum = new_sum;
				start_row = i;
			}
		}
		cout << "Max sum from (" << start_row << "," << start_col << ") to (" << row << "," << col << ") = " << max_sum << endl;
		//now lets improve by moving right
		for (int i = 0; i <= col; i++)
		{
			int new_sum = max_sum - dp[row][i];
			if (new_sum > max_sum)
			{
				max_sum = new_sum;
				start_col = i;
			}
		}
		cout << "Max sum from (" << start_row << "," << start_col << ") to (" << row << "," << col << ") = " << max_sum << endl;
	}

	void findMaxSum(int M[][COL])
	{
		int dp[ROW];
		int maxSum = INT_MIN;
		int mLeft = -1, mRight = -1, mTop = -1, mButtom = -1;
		for (int left = 0; left < COL; left++)
		{
			for (int i = 0; i < ROW; i++)
				dp[i] = 0;
			for (int right = left; right < COL; right++)
			{
				for (int i = 0; i < ROW; i++)
					dp[i] += M[i][right];
				//kadane formula start
				int maxSumLocal = INT_MIN, maxStart = -1, maxEnd = -1;
				int sum = 0, start = 0;
				for (int i = 0; i < ROW; i++)
				{
					if (sum <= 0)
					{
						sum = 0;
						start = i;
					}
					sum += dp[i];
					if (sum > maxSumLocal)
					{
						maxSumLocal = sum;
						maxStart = start; maxEnd = i;
					}
				}
				//kadane formula end
				if (maxSumLocal > maxSum)
				{
					maxSum = maxSumLocal;
					mLeft = left; mRight = right;
					mTop = maxStart; mButtom = maxEnd;
				}
			}
		}
		cout << "Max sum from (" << mLeft << "," << mTop << ") to (" << mRight << "," << mButtom << ") = " << maxSum << endl;
	}
	void test()
	{
		/*
				int M[ROW][COL] = {
					{1, 2, -1, -4, -20},
					{-8, -3, 4, 2, 1},
					{3, 8, 10, 1, 3},
					{-4, -1, 1, 7, -6}
				};
		*/
		int M[ROW][COL] = {
			{ 2, 1, -3, -4, 5 },
			{ 0, 6, 3, 4, 1 },
			{ 2, -2, -1, 4, -5 },
			{ -3, 3, 1, 0, 3 }
		};

		//findMaxSum_WRONG(M);
		findMaxSum(M);
	}
}

int main_73()
{
	NS73::test();
	return 0;
}
