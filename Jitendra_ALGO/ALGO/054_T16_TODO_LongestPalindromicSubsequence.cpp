/*
https://www.youtube.com/watch?v=_nCsPn7_OgI
http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
*/

//Longest Palindromic Subsequence
#include<iostream>
#include<algorithm>
using namespace std;

namespace NS54
{

	int longestPalindromicSubsequence(char * seq, int n)
	{
		int** dp = new int*[n];
		for (int i = 0; i < n; i++)
			dp[i] = new int[n];
		for (int length = 1; length <= n; length++)
		{
			for (int i = 0; i + length <= n; i++)
			{
				int j = i + length - 1;
				if (length == 1)
				{
					dp[i][j] = 1;
				}
				else if (length == 2)
				{
					dp[i][j] == seq[i] == seq[j] ? 2 : 1;
				}
				else
				{
					int left = dp[i][j - 1];
					int right = dp[i + 1][j];
					int middle = seq[i] == seq[j] ? 2 : 0;
					middle += dp[i + 1][j - 1];
					dp[i][j] = std::max(std::max(left, right), middle);
				}
			}
		}
		int res = dp[0][n - 1];
		for (int i = 0; i < n; i++)
			delete[] dp[i];
		delete[] dp;
		return res;
	}

	void test()
	{
		char seq[] = "GEEKS FOR GEEKS";
		int n = strlen(seq);
		int lps = longestPalindromicSubsequence(seq, n);
		cout << "The lnegth of the LPS  = " << lps << endl;
	}
}

int main_54()
{
	NS54::test();
	return 0;
}