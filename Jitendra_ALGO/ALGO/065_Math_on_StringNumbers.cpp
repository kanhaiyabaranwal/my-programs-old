/*
http://www.geeksforgeeks.org/divide-large-number-represented-string/

Divide large number represented as string
-------------------------------------------
Given a large number (represented as string) which has to divided by 
another number (represented as int data type). 
The large number can be very large which does not even fit in long long in C++. 
The task is to find division of these numbers.

http://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/

Multiply Large Numbers represented as Strings
---------------------------------------------
Given two numbers as strings. The numbers may be very large (may not fit in long long int),
the task is to find sum of these two numbers.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace NS65
{
	typedef int digit;

	// this will convert single char to int
	inline digit ctod(char c) { return c - '0'; }

	// this will convert single digit in to char
	inline char dtoc(digit  d) { return d + '0'; }

	//convert string to int
	inline int stoi(string s)
	{
		int res = 0;
		int n = s.length();
		while(n>0)
		{
			res = res * 10 + s.at(n-1) - '0';
		}
		return res;
	}

	string longDivision(string number, int divisor)
	{
		string quotient ="";
		bool canAppendZero = false;
		int n = number.length(); 
		if(n <= 0) return quotient;

		int i =0;
		int dividend = 0; 
		while(i < n)
		{
			dividend = (dividend * 10) + number.at(i++) - '0';
			int div = dividend / divisor;
			dividend = dividend % divisor;
			if(div != 0 || canAppendZero)
			{
				quotient += '0' + div;
				canAppendZero = true;
			}
		}
		return quotient;
	}

	//TODO --
	string longMultiply(string num, digit d)
	{		
		string res = ""; return res;
	}
	//TODO
	string longAdd(string num1, string num2)
	{
		string res = num1; return res;
	}

	string longMultiply(string num1, string num2)
	{
		int n1 = num1.length(); int n2 = num2.length();
		if(!n1 || !n2) return "0";

		string digits; digits.resize(n1+n2);
		for(int i=0; i<n1+n2; i++) digits[i] = '0';

		for(int i=n2-1; i>=0; i--) // num2
		{
			digit carry = 0;
			for(int j=n1-1; j>=0; j--) // num1
			{
				int mult = (ctod(num2[i]) * ctod(num1[j])) + carry + ctod(digits[i+j+1]);
				carry = mult / 10;
				digits[i+j+1] = dtoc(mult % 10);
			}
			digits[i] = dtoc(carry + ctod(digits[i]));
		}
		
		int index;
		for(index=0; index<n1+n2 && digits[index] == '0'; index++); //ignore starting zeros
		if(index == n1+n2-1) return "0" ;// either num1 or num2 are zero so result is zero
		
		return digits.substr(index,n1+n2-index);
	}
}


int main_65()
{
	string number = "1248163264128256512";
	number = "125";
	int divisor = 125;
	string res_div = NS65::longDivision(number, divisor);
	cout << res_div << endl;

	string str1 = "1235421415454545454545454544";
	string str2 = "1714546546546545454544548544544545";
	//str1 = "12345";	str2 = "123";
	str1 = "23958233";	str2 = "5830";
	string res_mult = NS65::longMultiply(str1, str2);
	cout << res_mult << endl;

	return 0;
} 