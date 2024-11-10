/*
https://www.geeksforgeeks.org/wildcard-pattern-matching/
Wildcard Pattern Matching
4
Given a text and a wildcard pattern, implement wildcard pattern matching algorithm that finds if wildcard pattern is matched with text.
The matching should cover the entire text (not partial text).

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

For example,

Text = "baaabab",
Pattern = “*****ba*****ab", output : true
Pattern = "baaa?ab", output : true
Pattern = "ba*a?", output : true
Pattern = "a*ab", output : false

*/

#include <iostream>
using namespace std;


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define DEBUG 1

namespace NS_101
{
	bool strmatch(char* str, char* pattern, int strLenght, int patternLength)
	{
		bool** dpTable = new bool*[patternLength + 1];
		for (int i = 0; i <= patternLength; i++)
		{
			dpTable[i] = new bool[strLenght + 1];
			for (int j = 0; j <= strLenght; j++)
				dpTable[i][j] = false;
		}
		dpTable[0][0] = true; // null str can match with null pattern
		for (int i = 1; i <= patternLength; i++)
		{
			if (pattern[i - 1] == '*')
				dpTable[i][0] = dpTable[i-1][0]; // Only * can match with empty string --> this is corner case
		}

		for (int i = 1; i <= patternLength; i++)
		{
			for (int j = 1; j <= strLenght; j++)
			{
				bool diag = dpTable[i - 1][j - 1];
				bool left = dpTable[i - 1][j];
				bool top = dpTable[i][j - 1];
				switch (pattern[i - 1])
				{
				case '*':
					dpTable[i][j] = top || left;
					break;
				case '?':
					dpTable[i][j] = diag;
					break;
				default:
					dpTable[i][j] = diag && (pattern[i - 1] == str[j - 1]);
					break;
				}
			}
		}
#if DEBUG
		const char gap[] = "  ";
		const char nullChar = ' ';
		cout << nullChar << gap << nullChar << gap;
		for (int i = 0; i < strLenght; i++)
			cout << str[i] << gap;
		cout << endl;
		for (int i = 0; i <= patternLength; i++)
		{
			if (i > 0)
				cout << pattern[i - 1] << gap;
			else
				cout << nullChar << gap;
			for (int j = 0; j <= strLenght; j++)
			{
				cout << dpTable[i][j] << gap;
			}
			cout << endl;
		}
#endif

		bool isMatch = dpTable[patternLength][strLenght];
		//cleanup
		for (int i = 0; i <= patternLength; i++)
			delete[] dpTable[i];
		delete[] dpTable;
		return isMatch;
	}
	void test()
	{
		char str[] = "baaabab";
		//char pattern[] = "*****ba*****ab";
		// char pattern[] = "ba*****ab";
		// char pattern[] = "ba*ab";
		 char pattern[] = "a*ab";
		// char pattern[] = "a*****ab";
		// char pattern[] = "*a*****ab";
		// char pattern[] = "ba*ab****";
		// char pattern[] = "****";
		// char pattern[] = "*";
		// char pattern[] = "aa?ab";
		// char pattern[] = "b*b";
		// char pattern[] = "a*a";
		// char pattern[] = "baaabab";
		// char pattern[] = "?baaabab";
		// char pattern[] = "*baaaba*";

		// char pattern[] = "ba*ab";

		int strLenght = strlen(str);
		int patternLenght = strlen(pattern);
		bool match = strmatch(str, pattern, strLenght, patternLenght);

		if (match)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}


namespace NS_JITENDRA
{
	struct point
	{
		long int x; long int y;
		point(long int _x = 0, long int _y = 0) : x(_x), y(_y) {}
	};
	void run()
	{
		long int n; cin >> n;
		vector<point> points;
		unordered_map<long int, long int> sumMap;
		unordered_map<long int, long int> diffMap;
		for (long int i = 0; i<n; i++)
		{
			long int x; long int y;
			cin >> x; cin >> y;
			points.push_back(point(x, y));

			long int sum = x + y;
			long int countSum = 0;
			if (sumMap.find(sum) != sumMap.end())
			{
				countSum = sumMap[sum];
			}
			countSum++;
			sumMap[sum] = countSum;

			long int diff = x - y;
			long int countDiff = 0;
			if (diffMap.find(diff) != diffMap.end())
			{
				countDiff = diffMap[diff];
			}
			countDiff++;
			diffMap[diff] = countDiff;
		}

		long int res = 0;
		for (long int i = 0; i < n; i++)
		{
			point p = points[i];
			long int sum = p.x + p.y;
			long int diff = p.x - p.y;

			long int countDiff = diffMap[diff];
			long int countSum = sumMap[sum];

			if (countDiff > 1 || countSum > 1)
				res++;
		}
		cout << res << endl;
	}
}


int main_101()
{
	NS_101::test();
	return 0;
}