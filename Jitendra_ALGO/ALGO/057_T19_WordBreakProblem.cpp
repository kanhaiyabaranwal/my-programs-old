/*
Word Break Problem using Backtracking
Dynamic Programming | Set 32 (Word Break Problem)
Word Break Problem Dynamic Programming

https://www.youtube.com/watch?v=WepWFGxiwRs

http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/

http://www.geeksforgeeks.org/word-break-problem-using-backtracking/

*/

#include<iostream>
#include<string>

using namespace std;

namespace NS_57
{
	bool dictionaryContains(string word)
	{
		string dictionary[] = {
			"mobile","samsung","sam","sung","man","mango",
			"icecream","and","go","i","like","ice","cream"
		};
		int size = sizeof(dictionary) / sizeof(dictionary[0]);
		for (int i = 0; i < size; i++)
			if (dictionary[i].compare(word) == 0)
				return true;
		return false;
	}
	bool wordBreak_DP(string str)
	{
		int n = str.length();
		if (n == 0) return true;
		bool **table = new bool*[n];
		for (int i = 0; i < n; i++)
			table[i] = new bool[n];

		for (int length = 1; length <= n; length++)
		{
			for (int i = 0; i + length <= n; i++)
			{
				int j = i + length - 1;
				table[i][j] = dictionaryContains(str.substr(i, (j - i + 1)));
				for (int k = i; k < j && !table[i][j]; k++)
				{
					table[i][j] = table[i][k] && table[k + 1][j];
				}
			}
		}

		bool res = table[0][n - 1];
		for (int i = 0; i < n; i++)
			delete[] table[i];
		delete[] table;

		return res;
	}

	bool wordBreak_DP2(string str) // using single dimanson array and order of n2
	{
		int n = str.length();
		if (n == 0) return true;
		bool *table = new bool[n + 1];
		for (int i = 0; i <= n; i++)
			table[i] = false;
		table[0] = true;
		for (int length = 1; length < n; length++)
		{
			string substring1 = str.substr(0, length);
			if (table[length] == false && dictionaryContains(substring1))
				table[length] = true;

			if (table[length] == true)
			{
				for (int i = length, length2 = 1; i + length2 <= n; length2++)
				{
					string substring2 = str.substr(i, length2);
					if (table[i + length2] == false && dictionaryContains(substring2))
						table[i + length2] = true;
				}
			}
		}

		bool res = table[n];
		delete[] table;
		return res;
	}

	//TODO recurssion \ back tracking and print all words
	void test()
	{
		wordBreak_DP("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP("iiiiiiii") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP("") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP("samsungandmango") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP("samsungandmangok") ? cout << "Yes\n" : cout << "No\n";

		cout << "\n\n======================DP2=========================\n\n";

		wordBreak_DP2("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP2("iiiiiiii") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP2("") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP2("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP2("samsungandmango") ? cout << "Yes\n" : cout << "No\n";
		wordBreak_DP2("samsungandmangok") ? cout << "Yes\n" : cout << "No\n";
	}
}

int main_57()
{
	NS_57::test();
	return 0;
}