/*
http://www.geeksforgeeks.org/find-next-greater-number-set-digits/
http://www.geeksforgeeks.org/next-higher-palindromic-number-using-set-digits/
http://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
Find next greater number with same set of digits
Next higher palindromic number using the same set of digits
Given a number, find the next smallest palindrome
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string nextGtrNumberUsingSameDigits(string number)
{	
	int n = number.length()-1;
	int i = n;
	//i.e find the is all numbers are decending then no solution
	bool waveFound = false;
	for(; i>0; i--)
	{
		if(number[i] > number[i-1])
		{
			waveFound = true;
			break;
		}
	}
	if(!waveFound) // no solution possiable
		return number;
	//find next number greater than number[i-1]
	char curr = number[i-1];
	int j = i;
	while( j<=n && curr < number[i])  
		j++;
	j--;
	number[i-1] = number[j];
	number[j] = curr;

	//now sort the string from i to end;
	sort(number.begin() +i , number.end());
	return number;
}

/*
Condition:- Here input should be palindrom also
Algo - From begin to mid find the next greater number
and just put reverse of same in the end.
*/
string nextGtrPlandrimUsingSameDigits(string palNumber)
{
	int N = palNumber.length();

	string half= palNumber.substr(0,N/2);
	string center = "";
	if(N%2)
		center = palNumber.substr((N-1)/2,1);
	string nextGrt = nextGtrNumberUsingSameDigits(half);

	string result = "";
	result.append(nextGrt);
	result.append(center);
	reverse(nextGrt.begin(),nextGrt.end());
	result.append(nextGrt);

	return result;
}

inline bool isPalindrom(string palNumber)
{
	bool isPali = true;
	int i=0, j = palNumber.length() -1;
	while(j>i)
	{
		if(palNumber[i] != palNumber[j])
			isPali = false;
		break;
		i++; j--;
	}
	return isPali;
}

inline int addOne(string &number, int pos = -1)
{
	int n = number.length();
	if(pos == -1)
		pos = n -1;
	int last_changed_digit = pos;
	string::reverse_iterator it = number.rbegin() + ( n - pos - 1);

	bool carry = true;
	while(carry && it != number.rend())
	{
		char c = *it;

		if(*it == '9')
		{
			*it = '0';
			carry = true;
		}
		else
		{
			*it =  *it +1;
			carry = false;
		}
		it++;
		last_changed_digit--;
	}
	if(carry)
	{
		string tmp = "1";
		tmp.append(number);
		last_changed_digit--;
		number = tmp;
	}

	return last_changed_digit;
}

/*
Note:- here input can be anything and out put wont have same digits 
like we have in the above example.
Algo:- two pointers(begin/left & end/right), if left side is bigger 
then we can simple put left side digit to right side as we need to  find
next bigger number, but if left side is smaller then we can not just put right
side number to left as it might too big. So we have to add one to left side digit
and put the same number in the right side.
*/
string nextGtrPlandrim(string number)
{
	if(isPalindrom(number))
		addOne(number);
	int i=0; 
	int j = number.length() -1;
	while( i < j)
	{
		int last_changed_digit = j+1;
        if(number[i] > number[j])
		{
			number[j] = number[i];
		}
		else if(number[i] < number[j])
		{
			number[j] = number[i];
			last_changed_digit =  addOne(number,j-1);
		}
		i++;j--;
		while(last_changed_digit < i)
		{
			i--;j++;
		}
	}
	return number;
}
int main_8(void)
{
	string number = "234296313692432";
	string nextGrtP = nextGtrNumberUsingSameDigits(number);
	cout<< nextGrtP << endl;

	string number2 = "4697557964";
	string nextGrtP2 = nextGtrPlandrimUsingSameDigits(number2);
	cout<< nextGrtP2 << endl;
	return 0;
}

