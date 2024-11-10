/*

https://www.youtube.com/watch?v=a9-NtLIs1Kk
http://www.techiedelight.com/find-n-digit-binary-strings-without-consecutive-1s/
http://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
http://www.geeksforgeeks.org/1-to-n-bit-numbers-with-no-consecutive-1s-in-binary-representation/

Numbers WIthout Consecutive 1s in binary representation
Count number of binary strings without consecutive 1’s
1 to n bit numbers with no consecutive 1s in binary representation.

*/

#include<iostream>
using namespace std;
namespace NS67
{
	int countStrings(int n)
	{
		if(n <= 0) return -1;
		if(n == 1) return 2;
		if(n == 2) return 3;

		int prev1 = 3;
		int prev2 = 2;
		int res = 0;
		for(int i=3; i<=n; i++)
		{
			//with one it is n-2, with zero its n-1, total is sum
			res = prev1 + prev2;
			prev2 = prev1;
			prev1 = res;
		}
		return res;
	}
}
int main_67()
{
	int n = 10;
	int res = NS67::countStrings(n);
	cout << "Number of " << n <<
		"-digit binary strings without any consecutive 1s are " 
		<< res << endl;

	return 0;
}