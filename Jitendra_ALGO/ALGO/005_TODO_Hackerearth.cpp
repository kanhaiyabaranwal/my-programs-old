/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/faizu-on-a-space-war/description/
*/

#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

const int INT_MIN_1 = -9999999;

inline int hash_5(string s)
{
	int n = s.length();
	int res = 0;
	for(int i=0; i<n;i++)
	{
		res += (s[i] - 'a') + 1 ;
	}
	return res;
}

int calculateXor(int* A, int n)
{
	int res = 0;
	if(n <= 1) return 0;
	if(n == 2) return A[0] ^ A[1];
	for(int i=0; i<n-1; i++)
	{
		res += A[i] ^ A[i+1];
	}
	return res += A[0] ^ A[n-1]; // last element with first
}

inline void swap_5(int& a, int&b)
{
	int tmp =a; a=b; b=tmp;
}

void maxXorRec(int* A, int n, int index, int& res)
{
	if(index >= n-1) return;
	for(int i=index+1; i<n;i++)
	{
		swap_5(A[index], A[i]);
		int tmpRes = calculateXor(A,n);
		res = max(tmpRes,res);
		maxXorRec(A, n, index+1,res);
		swap_5(A[index], A[i]); //swapback
	}
}
bool allSelected(bool* selectedArray, int n)
{
	for(int i=0; i<n; i++)
	{
		if(!selectedArray[i]) return false;
	}
	return true;
}
int maxXor_2(int* A, int n)
{
	if(n <=1) return 0;
	if(n == 2) return A[0] ^ A[1];

	bool* selected = new bool[n];
	for(int i=0; i<n; i++)
		selected[i] = false;

	int max_xor = INT_MIN_1;
	int index1, index2;
	for(int i=0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			int _xor = A[i] ^ A[j];
			if(_xor > max_xor)
			{
				index1 = i; index2 = j; max_xor = _xor;
			}
		}
	}
	int res = max_xor; 
	int first_xor = INT_MIN_1; int second_xor = INT_MIN_1; 
	selected[index1] = true; selected[index2] = true;
	for(int i=0; i<n; i++)
	{
		if(!selected[i])
		{
			int xor1 = A[index1] ^ A[i]; first_xor = max(first_xor, xor1);
			int xor2 = A[index2] ^ A[i]; second_xor = max(second_xor, xor2);
		}
	}
	int first = index1; int index = index2;
	if( second_xor < first_xor)
	{
		first = index2; index = index1;
	}
	while(!allSelected(selected,n))
	{
		int nexInxed = -1;
		max_xor = INT_MIN_1;
		for(int i=0; i<n; i++)
		{
			if(!selected[i])
			{
				int _xor = A[index] ^ A[i];
				if(_xor > max_xor)
				{
					nexInxed = i; max_xor = _xor;
				}
			}
		}
		res += max_xor;
		index = nexInxed;
		selected[index] = true;
	}
	res += A[first] ^ A[index];
	delete[] selected;
	return res;
}

int main_5()
{
	//freopen( "C:\\Users\\jisamal.ORADEV\\Documents\\Visual Studio 2008\\Projects\\InterviewQuestions\\Algo\\input_1.txt", "r", stdin );
	int n;
	cin >> n;
	int* input = new int[n];
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		input[i] = hash_5(s);
	}
	int res = calculateXor(input,n);
	maxXorRec(input,n,0,res);
	//int res = maxXor_2(input, n);
	cout << res << endl;
	delete[] input;
	return 0;
}
