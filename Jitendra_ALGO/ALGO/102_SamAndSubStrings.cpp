/*
https://www.hackerrank.com/challenges/sam-and-substrings/problem
Sam and sub-strings
amantha and Sam are playing a game. They have 'N' balls in front of them, each ball numbered from 0 to 9, except the first ball which is numbered from 1 to 9. Samantha calculates all the sub-strings of the number thus formed, one by one. If the sub-string is S, Sam has to throw 'S' candies into an initially empty box. At the end of the game, Sam has to find out the total number of candies in the box, T. As T can be large, Samantha asks Sam to tell T % (109+7) instead. If Sam answers correctly, he can keep all the candies. Sam can't take all this Maths and asks for your help.

Help him!

Input Format

A single line containing a string of numbers that appear on the first, second, third ball and so on.

Constraints

Output Format

A single line which is the number of candies in the box,

Sample Input 0

16
Sample Output 0

23
Explanation 0

The substring of number 16 are 16, 1 and 6. Whose sum is 23.

Sample Input 1

123
Sample Output 1

164
Explanation 1

The sub-strings of 123 are 1, 2, 3, 12, 23, 123 which sums to 164.

*/

#include <iostream>
#include <string>

using namespace std;

namespace NS_102 {
	long  substrings(string balls) {
		int n = balls.length();
		long M = std::pow(10, 9) + 7;

		long res = 0;
		long* table = new long[n];
		cout << "Pass 1 \n";

		for (int length = 1; length <= n; length++)
		{
			for (int i = 0; i + length <= n; i++)
			{
				int j = i + length - 1;

				long oldVal2 = (j > i) ? table[j - 1] : 0;
				long oldVal1 = (i > 0) ? table[j - 1] : 0;
				if (oldVal2 < oldVal1)
					oldVal2 = M + oldVal2;
				long oldVal = (oldVal2 - oldVal1) % M;

				string sub_str = balls.substr(j, 1);
				long num = std::stoll(sub_str) % M;

				long val = ((oldVal * 10) % M + num) % M;
				if(i==0)
					table[j] = val;
				res = (res + val) % M;
			}
		}

		//for(int i=0; i < n; i++)
		//    delete[] table[i];
		//delete[] table;
		return res;
	}

	string getInput()
	{
		return string("1234");
	}
	int test() {
		string balls = getInput();
		//cin >> balls;
		long result = substrings(balls);
		cout << result << endl;
		return 0;
	}

}

int main_102()
{
	NS_102::test();
	return 0;
}