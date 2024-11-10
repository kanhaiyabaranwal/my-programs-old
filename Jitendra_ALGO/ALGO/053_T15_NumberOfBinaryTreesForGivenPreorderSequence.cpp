/*
https://www.youtube.com/watch?v=RUB5ZPfKcnY
http://www.geeksforgeeks.org/number-of-binary-trees-for-given-preorder-sequence-length/
*/
#include<iostream>
using namespace std;
namespace NS_53
{
	int countTreesR(size_t n)
	{
		if(n <= 1) return 1;

		int result = 0;
		//first element is root, rest of elements 
		//can be either left or right side of root
		for(size_t i=0; i<=n-1; i++) 
		{
			int left = countTreesR(i);
			int right = countTreesR(n-i-1);
			result += (left * right);
		}
		return result;
	}
	int countTreesDP(size_t n)
	{
		if(n <= 1) return 1;

		int* table = new int[n+1]; table[0] = table[1] = 1;

		for(size_t i=2; i<=n; i++) 
		{
			int count = 0;
			for(size_t j=0; j<=i-1; j++) 
			{
				count += table[j] * table[i-j-1];
			}
		}

		int result = table[n];
		delete[] table;

		return result;
	}
}
int main_53_T_15_NumberOfBinaryTreesForGivenPreorderSequence()
{
	int n = 5;
	int result = NS_53::countTreesR(n);
	cout << "(Recursion)Total Possible Binary Tree are: " << result << endl;
	int resultDP = NS_53::countTreesDP(n);
	cout << "(Dynamic Programming)Total Possible Binary Tree are: " << result << endl;
	return 0;
}