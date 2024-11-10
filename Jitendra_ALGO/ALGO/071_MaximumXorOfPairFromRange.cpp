/*
http://www.geeksforgeeks.org/maximum-xor-value-of-a-pair-from-a-range/
Maximum XOR value of a pair from a range
*/
#include<iostream>
using namespace std;
namespace NS71
{
	int maxXORInRange(int l, int r)
	{
		int xor_lr = l ^ r;
		int msb = 0;
		while(xor_lr)
		{
			msb++; xor_lr >>= 1;
		}
		int res = 0;
		int bit = 1;
		while(msb)
		{
			 res |= bit; 
			 bit <<= 1; msb--;
		}
		return res;
	}
}

int main_71()
{
	int L = 19;
	int R = 39;
	int max_xor = NS71::maxXORInRange(L, R);
	cout << max_xor  << endl;
	return 0;
}