/*
Subset Sum Problem Dynamic Programming
Perfect Sum Problem (Print all subsets with given sum)
Backtracking | Set 4 (Subset Sum)
Dynamic Programming | Set 25 (Subset Sum Problem)

https://www.youtube.com/watch?v=s6FhG--P7z0
http://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/
http://www.geeksforgeeks.org/backttracking-set-4-subset-sum/
http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

namespace NS_60
{
	//TODO- not completed -- this will print all element with repeating
	void pintAllUtil2(int* A, int n , int sum, vector<int>& path)
	{
		for(int i=0; i<n; i++)
		{
			if(sum < A[i])
				break;
			int mul = sum / A[i] ;
			for(int j=0; j<mul; j++)
				path.push_back(A[i]);  
			int balanceSum = sum % A[i];
			if(balanceSum == 0)
			{
				for(size_t j=0; j < path.size(); j++)
					cout<< path[j] << "  ";
				cout << endl;
			}
			if(balanceSum > 0)
				pintAllUtil2(A+i+1, n-i-1, balanceSum, path);
			for(int j=0; j<mul; j++)
				path.pop_back();

			if(balanceSum < 0)
				break; // since array is sorted
		}
	}
	void pintAllUtil(int* A, int n , int sum, vector<int>& path)
	{
		for(int i=0; i<n; i++)
		{
			path.push_back(A[i]); // check this
			int balanceSum = sum - A[i];
			if(balanceSum == 0)
			{
				for(size_t j=0; j < path.size(); j++)
					cout<< path[j] << "  ";
				cout << endl;
			}
			if(balanceSum > 0)
				pintAllUtil(A+i+1, n-i-1, balanceSum, path);
			path.pop_back();

			if(balanceSum < 0)
				break; // since array is sorted
		}
	}
	void printAll(int* A, int n, int sum)
	{ 
		sort(A,A+n);
		vector<int> path; path.reserve(n);
		pintAllUtil(A,n,sum,path);
	}


	//******** DP Code Start from here *******//
	void printAllDPUtils(int* A, int i, int sum, bool** dp, stack<int>& path)
	{
		if( sum == 0 && !path.empty())
		{
			while(!path.empty())
			{
				int data = path.top();path.pop();
				cout<< data << "  "; 
			}
			cout << endl;
			return;
		}

		if(sum >= A[i] && dp[i+1][sum]) // check with ith coin dp will poit to i+1
		{
			path.push(A[i]);
			printAllDPUtils(A, sum-A[i]-1, sum-A[i], dp, path); 
		}
		//check if we can get resut without ith coin
		if(dp[i][sum])
		{
			stack<int> new_path;
			printAllDPUtils(A, i-1, sum, dp, new_path);
		}
	}
	void printAllDP(int* A, int n, int sum)
	{
		if(sum <= 0) return;
		//populate all
		bool** dp = new bool*[n+1];
		for(int i=0; i<=n;i++)
			dp[i] = new bool[sum+1];
		for(int coinIndx=0; coinIndx<=n; coinIndx++) 
		{ 
			for(int currSum=0; currSum<=sum; currSum++) 
			{
				if(currSum== 0) { dp[coinIndx][currSum] = true; continue;}
				if(coinIndx== 0) { dp[coinIndx][currSum] = false; continue;}

				dp[coinIndx][currSum] = (currSum < A[coinIndx-1] ) ? dp[coinIndx-1][currSum] :  
					dp[coinIndx-1][currSum] || dp[coinIndx-1][currSum-A[coinIndx-1]];
			}
		}		
		//call to print
		if(dp[n][sum])
		{
			stack<int> path;
			printAllDPUtils(A, n-1, sum, dp, path);
		}
		//clean
		for(int i=0; i<=sum;i++)
			delete[] dp[i];
		delete[] dp;
	}



}

int main_60()
{
	//int A[] = {1,1,1,1,1};
	int A[] = {1,2,3,4,5};
	int n = sizeof(A) / sizeof(A[0]);
	int sum = 5;
	cout<< "\n\nVia Recurssion\n=========================\n";
	NS_60::printAll(A, n, sum);
	cout<< "\n\nVia Dynamic Programming\n=========================\n";
	NS_60::printAllDP(A, n, sum);
	return 0;
}