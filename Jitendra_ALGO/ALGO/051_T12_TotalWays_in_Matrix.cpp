/*
https://www.youtube.com/watch?v=GO5QHC_BmvM
http://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
*/
#include<iostream>
using namespace std;

int numberOfPathsR(int n, int m)
{
	if( n== 1 || m == 1) return 1;
	return numberOfPathsR(n-1, m) + numberOfPathsR(n, m-1);
}
int numberOfPathsDP(int n, int m)
{
	if( n== 1 || m == 1) return 1;

	int **table = new int*[n];
	for(int i=0; i<n; i++)
		table[i] = new int[m];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i==0||j==0){table[i][j] = 1; continue;}
			table[i][j] = table[i-1][j] + table[i][j-1];
		}
	}

	int res = table[n-1][m-1];
	for(int i=0; i<n; i++)
		delete[] table[i];
	delete[] table;

	return res;
}

int main_51_T_12_TotalWays_in_Matrix()
{
	int resultRecurssion = numberOfPathsR(3, 3);
	int resultDP = numberOfPathsDP(3, 3);
	cout << resultRecurssion << endl;
	cout << resultDP << endl;
	return 0;
}