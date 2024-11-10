/*
https://www.geeksforgeeks.org/dynamic-programming-set-37-boolean-parenthesization-problem/
Dynamic Programming | Set 37 (Boolean Parenthesization Problem)

Given a boolean expression with following symbols.
Symbols
-------
'T' ---> true
'F' ---> false

And following operators filled between symbols
Operators
---------
&   ---> boolean AND
|   ---> boolean OR
^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Let the input be in form of two arrays one contains the symbols (T and F) in order and other contains operators (&, | and ^}

Examples:

Input: symbol[]    = {T, F, T}
operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true in two ways
"((T ^ F) & T)" and "(T ^ (F & T))"

Input: symbol[]    = {T, F, F}
operator[]  = {^, |}
Output: 2
The given expression is "T ^ F | F", it evaluates true in two ways
"( (T ^ F) | F )" and "( T ^ (F | F) )".

Input: symbol[]    = {T, T, F, T}
operator[]  = {|, &, ^}
Output: 4
The given expression is "T | T & F ^ T", it evaluates true in 4 ways
((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))

*/
#include <iostream>

using namespace std;
namespace NS_98
{
	struct Node
	{
		int TrueCount; int FalseCount;
		Node() : TrueCount(0), FalseCount(0) {}
		int getTotal() { return TrueCount + FalseCount; }
	};
	int countNumberofWays_Parenth(char* symbols, char* operators, int n)
	{
		Node** dp = new Node*[n];
		for (int i = 0; i < n; i++)
		{
			dp[i] = new Node[n];
			//below initilize for lenght = 1
			dp[i][i].TrueCount = symbols[i] == 'T' ? 1 : 0;
			dp[i][i].FalseCount = symbols[i] == 'F' ? 1 : 0;
		}

		for (int length = 2; length <= n; length++)
		{
			for (int i = 0; i + length <= n; i++)
			{
				int j = i + length - 1;
				for (int k = i; k < j; k++)
				{
					int trueCount = 0, falseCount = 0;
					int totalCount = dp[i][k].getTotal() * dp[k + 1][j].getTotal();
					switch (operators[k])
					{
					case '&':
						trueCount = dp[i][k].TrueCount * dp[k + 1][j].TrueCount;
						falseCount = totalCount - trueCount;
						break;
					case '^':
						trueCount = dp[i][k].TrueCount * dp[k + 1][j].FalseCount + dp[i][k].FalseCount * dp[k + 1][j].TrueCount;
						falseCount = totalCount - trueCount;
						break;
					case '|':
						falseCount = dp[i][k].FalseCount * dp[k + 1][j].FalseCount;
						trueCount = totalCount - falseCount;
						break;
					default:
						break;
					}
					dp[i][j].TrueCount += trueCount;
					dp[i][j].FalseCount += falseCount;
				}
			}
		}
		int result = dp[0][n - 1].TrueCount;
		for (int i = 0; i < n; i++)
			delete[] dp[i];
		delete[] dp;
		return result;
	}

	void test()
	{
		char symbols[] = "TTFT";
		char operators[] = "|&^";
		int n = strlen(symbols);

		int res = countNumberofWays_Parenth(symbols, operators, n);
		cout << res << endl;
	}
}
int main_98()
{
	NS_98::test();
	return 0;
}
