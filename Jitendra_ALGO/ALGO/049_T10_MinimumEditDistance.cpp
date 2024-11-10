/*
https://www.youtube.com/watch?v=We3YDTzNXEk
http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int minEditDistR(string fromStr , string toStr, int n, int m)
{
	if(n==0) return m;
	if(m==0) return n;

	if(fromStr[n] == toStr[m]) return minEditDistR(fromStr, toStr, n-1, m-1);

	int insert = minEditDistR(fromStr, toStr, n, m-1);
	int remove = minEditDistR(fromStr, toStr, n-1, m);
	int modify = minEditDistR(fromStr, toStr, n-1, m-1);

	return 1 + min(min(insert, remove), modify);
}

int minEditDist(string fromStr , string toStr)
{
	int n = fromStr.length();
	int m = toStr.length();

	int **table = new int*[n+1];
	for(int i=0; i<=n; i++)
		table[i] = new int[m+1];
	for(int i=0; i<=n; i++)
		table[0][i] = table[i][0] = i;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			char fromChar = fromStr[i-1];
			char toChar = toStr[j-1];
			//if both char are same then no change required
			if( fromChar == toChar)
				table[i][j] = table[i-1][j-1];
			else // Apply add/delete/modify
			{
				//modify case
				int mod = table[i-1][j-1];
				// delete case
				int remove = table[i-1][j];
				//add case
				int insert = table[i][j-1];
				//min of above three
				table[i][j] = 1 + min(min(mod,remove),insert);
			}
		}
	}

	int res = table[n][m];
	for(int i=0; i<=n; i++)
		delete[] table[i];
	delete[] table;

	return res;
}

int main_49_T_10_MinimumEditDistance()
{
	string str1 = "sunday";
	string str2 = "saturday";

	int editDist = minEditDist( str1 , str2); 
	cout << editDist << endl;

	int editDistR = minEditDistR( str1 , str2, str1.length(),str2.length()); 
	cout << editDistR << endl;

	return 0;
}