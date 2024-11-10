/*
http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
https://www.youtube.com/watch?v=_Lf1looyJMU
*/
#include<iostream>
#include<algorithm>
using namespace std;

#define R 6
#define C 5

void printMaxSubSquare(bool M[R][C])
{
	int table[R+1][C+1];
	int maxSize = 0;
	int rEnd = 0; int cEnd =0;
	for(int i=0; i<=R; i++) 
	{
		for(int j=0; j<=C; j++) 
		{
			if(i==0 || j==0) {table[i][j]=0; continue;}		
			int size = 0;
			if(M[i-1][j-1] == 1)
			{
				size = 1 + min(min(table[i-1][j], table[i-1][j-1]), table[i][j-1]);
			}
			table[i][j] = size;
			if(size > maxSize)
			{
				maxSize = size; 
				rEnd = i-1; 
				cEnd = j-1;
			}
		}
	}
	cout << "Max sub matrix size = " << maxSize << endl;
	cout << "row end = " << rEnd << endl;
	cout << "col end = " << cEnd << endl;
}

int main50_T_11_MaximumSizeSquareSub_matrix()
{
	bool M[R][C] =  {
		{0, 1, 1, 0, 1}, 
		{1, 1, 0, 1, 0}, 
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0}};

		printMaxSubSquare(M);
		return 0; 
}  