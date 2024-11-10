/*
https://www.youtube.com/watch?v=hgA4xxlVvfQ
http://www.geeksforgeeks.org/dynamic-programming-set-24-optimal-binary-search-tree/

Optimal Binary Search Tree
Dynamic Programming | Set 24 (Optimal Binary Search Tree)
---------------------------------------------------------
Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] 
of frequency counts, where freq[i] is the number of searches to keys[i]. 

Construct a binary search tree of all keys such that the total cost 
of all the searches is as small as possible.

*/
#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;
namespace NS68
{
	//TODO- construct the tree and do recurssive method
	// assumations keys are sorted in asending order,
	// so sorting not required
	int optimalSearchTreeDP(int* keys, int* freq,int n)
	{
		if(n<=0) return -1;

		int** dp = new int*[n];
		for(int i=0; i<n; i++)
			dp[i] = new int[n];

		for(int length=1; length<=n; length++)
		{
			for(int i=0; i+length <=n; i++)
			{
				int j = i+length-1;
				if(i==j) {dp[i][j] = freq[i]; continue;}
				int sum = 0;
				for(int k=i; k<=j;k++)
					sum += freq[k];
				int minCost = INT_MAX;
				int optimalRoot = -1; // this will useful when we create tree, but no use now
				for(int root=i; root<=j; root++)
				{
					int left = i <= root-1 ? dp[i][root-1] : 0;
					int right = j >= root+1 ? dp[root+1][j] : 0;
					minCost = std::min(left+right, minCost);
					if(minCost == left+right) optimalRoot = root;
				}
				dp[i][j] = sum + minCost;
			}
		}
		int res=dp[0][n-1];
		for(int i=0; i<n; i++)
			delete[] dp[i];
		return res;
	}
}
int main_68()
{
	//int keys[] = {10, 12, 20};
	//int freq[] = {34, 8, 50};
	int keys[] = {10, 12, 12, 21};
	int freq[] = {4, 2, 6, 3};
	int n = sizeof(keys)/sizeof(keys[0]);
	int res = NS68::optimalSearchTreeDP(keys, freq, n); 
	cout << "Cost of Optimal BST is : " << res << endl;
	return 0;
}