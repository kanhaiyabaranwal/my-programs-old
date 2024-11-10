/*
https://www.youtube.com/watch?v=RORuwHiblPc
http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/
----------------------------------------------------
Text Justification Dynamic Programming
----------------------------------------------------
Dynamic Programming | Set 19 (Word Wrap Problem)
----------------------------------------------------
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width).
Put line breaks in the given sequence such that the lines are printed neatly. Assume that the length of each word is smaller than the line width.

The word processors like MS Word do task of placing line breaks.
The idea is to have balanced lines. In other words, not have few lines with lots of extra spaces and some lines with small amount of extra spaces.
*/
#include<iostream>
#include<cmath>
using namespace std;
namespace NS81
{
	const int INF = INT_MAX;
	inline int sum(int x, int y)
	{
		if (x == INF || y == INF) return INF;
		return x + y;
	}

	//toto fix in n2 time 
	void solveWordWrap_NOTWORKING(int* lengths, int n, int lineSize)
	{
		int** costTbl = new int*[n];
		for (int i = 0; i < n; i++)
			costTbl[i] = new int[n];

		for (int i = 0; i < n; i++)
		{
			int usedChars = 0;
			for (int j = i; j < n; j++)
			{
				usedChars = usedChars + lengths[j] + (j - i);
				int extraSpace = lineSize - usedChars;
				costTbl[i][j] = extraSpace < 0 ? INF : (int)pow(extraSpace, 2);
			}
		}


		int* costTbl2 = new int[n];

		//cleanup
		for (int i = 0; i < n; i++)
		{
			delete[] costTbl[i];
			//delete[] costTbl2[i];
		}
		delete[] costTbl;
		delete[] costTbl2;
	}

	// order of n ^ 3
	void solveWordWrap_N3(int* lengths, int n, int lineSize)
	{
		int** costTbl = new int*[n];
		for (int i = 0; i < n; i++)
			costTbl[i] = new int[n];

		for (int l = 1; l <= n; l++)
		{
			for (int i = 0; i + l <= n; i++)
			{
				int j = i + l - 1;
				if (i == j)
				{
					costTbl[i][j] = lineSize >= lengths[i] ? (int)pow((lineSize - lengths[i]), 2) : INF;
				}
				else
				{
					//check if all words can come in one line.
					int requiredSpace = l - 1; // gap between words
					for (int k = i; k <= j; k++)
						requiredSpace += lengths[k];
					if (requiredSpace <= lineSize)
					{
						costTbl[i][j] = (int)pow((lineSize - requiredSpace), 2);
					}
					else // split and see where we can get min cost;
					{
						int minCost = INF;
						for (int lineBreak = i; lineBreak < j; lineBreak++)
						{
							int cost = sum(costTbl[i][lineBreak], costTbl[lineBreak + 1][j]);
							if (cost < minCost) minCost = cost;
						}
						costTbl[i][j] = minCost;
					}
				}
			}
		}
		cout << "Text Justification Dynamic Programming : " << costTbl[0][n - 1] << endl;

		//cleanup
		for (int i = 0; i < n; i++)
			delete[] costTbl[i];
		delete[] costTbl;
	}

	void test1()
	{
		//int l[] = { 3, 2, 2, 5 };
		int l[] = { 6, 3, 5, 2,4 };
		int n = sizeof(l) / sizeof(l[0]);
		int M = 10;
		//solveWordWrap(l, n, M);
		solveWordWrap_N3(l, n, M);
	}
}

int main_81()
{
	NS81::test1();
	return 0;
}