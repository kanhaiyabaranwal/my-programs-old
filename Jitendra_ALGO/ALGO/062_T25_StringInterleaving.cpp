/*

Dynamic Programming | Set 33 (Find if a string is interleaved of two other strings)
String Interleaving Dynamic Programming
Check whether a given string is an interleaving of two other given strings


https://www.youtube.com/watch?v=ih2OZ9-M3OM
http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/
http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings/

*/


#include<iostream>
#include<string>
using namespace std;

namespace NS_62
{
	const char null = '\0';
	bool isInterLeaving_R(const char* A, const char* B, const char* C)
	{	
		//if all null return true, this is terminating condition
		if(*A == null && *B == null && *C == null) return true;

		// if c is null then A and B should null, if not return false
		if(*C == null && (*A != null || *B !=null)) return false; 

		// if c not null then either A or B should not null, if not return false
		if(*C != null && (*A == null && *B == null)) return false;

		//if no match, return false
		if(*C != *A && *C != *B) return false;

		//if both match, try both
		if(*C == *B && *C == *A)
			return (isInterLeaving_R(A, B+1, C+1) || isInterLeaving_R(A+1, B, C+1));

		if(*C == *A)
			return isInterLeaving_R(A+1, B, C+1);

		if(*C == *B)
			return isInterLeaving_R(A, B+1, C+1);

		return false; // dead code
	}

	bool isInterLeaving_DP(string A, string B, string C)
	{
		if((A.size() + A.size()) != C.size()) return false;
		bool** dp = new bool*[A.size()+1];
		for(size_t i=0; i<=A.size(); i++)
			dp[i] = new bool[B.size()+1];

		for(size_t i=0; i<=A.size(); i++)
		{
			for(size_t j=0; j<=B.size(); j++)
			{
				size_t index = i+j-1;
				//for first row and first column
				if(i==0 && j==0){dp[i][j] = true; continue;}
				if(i==0){dp[i][j] = (dp[i][j-1] && C[index] == B[j-1]); continue;}
				if(j==0){dp[i][j] = (dp[i-1][j] && C[index] == A[i-1]); continue;}
				//for rest other rows 
				dp[i][j] = (C[index] == A[i-1] && dp[i-1][j])|| 
					(C[index] == B[j-1] && dp[i][j-1]);
			}
		}

		bool res = dp[A.size()][B.size()];
		for(size_t i=0; i<=A.size(); i++)
			delete[] dp[i];
		delete[] dp;
		return res;
	}

}
int main_62()
{
	string A = "aab";
	string B = "axy";
	//string C = "aaxaby";
	string C = "abaaxy";
	bool res = NS_62::isInterLeaving_R(A.c_str(),B.c_str(),C.c_str());
	bool res_dp = NS_62::isInterLeaving_DP(A,B,C);
	return 0;
}