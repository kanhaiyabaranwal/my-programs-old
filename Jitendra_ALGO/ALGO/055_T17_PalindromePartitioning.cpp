/*
http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
https://www.youtube.com/watch?v=lDYIvtBVmgo
*/
//Palindrome Partitioning
//Palindrome Partition Dynamic Programming

#include <iostream>
#include <limits>
using namespace std;

namespace NS_55
{
	//TODO -- n2 time complexity - refer geeksforgeeks
	// coded after looking the solution, so pratice again
	size_t minPalPartion_DP_optimization (char* str, size_t n)
	{
		bool **table = new bool*[n];
		for(size_t i=0; i<n; i++)
			table[i] = new bool[n];
		size_t *res_table = new size_t[n];
		//pre-compute all possible palindrome
		for(size_t length=1; length <= n; length++)
		{
			for(size_t i=0; (i+length) <= n; i++)
			{
				size_t j= i + length -1;
				if(length==1) 
					table[i][j] = true; // i.e. i==j
				else if(length==2) 
					table[i][j] = (str[i] == str[j]);
				else
					table[i][j] = ((str[i] == str[j]) && table[i+1][j-1]);
			}
		}
		//compute final results
		for(size_t i=0; i<n; i++)
		{
			//check if full sting is palindrom
			if(table[0][i])
				res_table[i] = 0;
			else
			{ // now we have to slipt, how?
				size_t min_split = SIZE_MAX;
				for(size_t j=0; j<i; j++)
				{ 
					// if split right side is palindrom, then split 
					//required = 1 + split required in right side
					if(table[j+1][i] && min_split > (1+res_table[j]))
						min_split = 1 + res_table[j];
				}
				res_table[i] = min_split;
			}
		}
		//clean-up memory
		for(size_t i=0; i<n; i++)
			delete[] table[i];
		delete[] table;
		size_t result = res_table[n-1];
		delete[] res_table;
		return result;
	}

	//this is n3 time complexity
	size_t minPalPartion_DP(char* str, size_t n)
	{
		if(n < 1) return 0; // no partion required
		size_t **table = new size_t*[n];
		for(size_t i=0; i<n; i++)
			table[i] = new size_t[n];
		//length = 1, no partion required as it itself is substring
		for(size_t i=0; i<n; i++)
			table[i][i] = 0;
		//now check for other lengths
		for(size_t length=2; length <= n; length++)
		{
			for(size_t i=0; (i+length) <= n; i++)
			{
				size_t j = i+length-1;
				size_t min_cut = INT_MAX;

				//TODO - Explain logic here in more details --
				//If both char are same then we have two options
				//Case 1 : if excluding i,j others are palindrom then no partion required
				//Case 2 : same as else condition
				//Else if both not same then find where to put the partitation
				if(str[i] == str[j] && (length == 2 || table[i+1][j-1] == 0)) 
					min_cut = 0;
				else 
				{
					min_cut = INT_MAX;
					for(size_t k=i; k<j; k++)
					{
						if(min_cut > (table[i][k] + table[k+1][j]))
							min_cut = table[i][k] + table[k+1][j];
					}
					//increment one for cutting at pos k
					min_cut++;
				}
				//store the result
				table[i][j] = min_cut;
			}
		}
		size_t res = table[0][n-1];
		for(size_t i=0; i<n; i++)
			delete[] table[i];
		delete[] table;
		return res;
	}
	size_t minPalPartion_R(char* str, size_t start, size_t end)
	{
		if(start == end)
			return 0;
		//is palindrom ?
		bool isPalindrom = true;
		int i= start; int j= end;
		while(j > i)
		{
			if(str[i] != str[j]) 
			{ 
				isPalindrom = false; 
				break; 
			}
			i++; j--;
		}
		if(isPalindrom) return 0;

		size_t result = SIZE_MAX;
		for(size_t i=start; i<end; i++)
		{
			size_t tmp_result = 1 + minPalPartion_R(str, start, i) + minPalPartion_R(str, i+1, end);
			result =  tmp_result < result ? tmp_result : result;
		}
		return result; 
	}
}

//TODO - recurssion method giving wrong result

int main_55_T_17_PalindromePartitioning()
{
	//char str[] = "ababbbabbababa";
	char str[] = "abcbm";
	size_t n = strlen(str);

	size_t res = NS_55::minPalPartion_DP(str,n);
	cout << "Min cuts needed for Palindrome Partitioning is : " << res << endl;

	size_t res_optimization = NS_55::minPalPartion_DP_optimization(str,n);
	cout << "Min cuts needed for Palindrome Partitioning is : " << res_optimization << endl;

	size_t res_r = NS_55::minPalPartion_R(str,0,n);
	cout << "Min cuts needed for Palindrome Partitioning is : " << res_r << endl;

	return 0;
}