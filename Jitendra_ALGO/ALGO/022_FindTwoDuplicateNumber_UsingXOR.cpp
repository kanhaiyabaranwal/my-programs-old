/*
http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
*/
#include<iostream>
using namespace std;

void findTwoDiplucateNumbers_xor(int A[],int n)
{
	if(n<4)
		return;
	int n1 = n-2; // numbers are from 1 to n1

	int xor_A =0, xor_n1 =0;
	for(int i=0; i<n;i++)
		xor_A ^= A[i];

	for(int i=1; i<=n1; i++)
		xor_n1 ^= i;

	//lets say duplicate numbers are x and y
	int x =0, y=0;
	int xor_xy = xor_A ^ xor_n1;

	//find first setbit
	int first_setbit = xor_xy & (~(xor_xy-1));

	//By end of this for loop we will have
	// x = xor of all elements having setbit - x (as x is duplicate, so x^x = 0)
	// y = xor of all elements dont have setbit - y (as y is duplicate, so y^y =0)
	for(int i=0; i< n; i++)
	{
		if( first_setbit & A[i] )
			x ^= A[i];   
		else
			y ^= A[i];
	}
	//By end of this forloop we will have actual x and y. why?
	//becuase - since x have xor of all elements havinf setbit - x, 
	//so if we do x or again with number 1-n1, it will result with x only
	for(int i=1; i<= n1; i++)
	{
		if( first_setbit & A[i] )
			x ^= i;
		else
			y ^= i;
	}
	cout << " duplicate numbers  are : " << x << " and " << y << endl;
}

int main_22_FindTwoDuplicateNumber_UsingXOR()
{
	int A[] = { 1, 2, 3, 3, 4, 4, 5, 6};
	int n = sizeof(A) / sizeof(A[0]);
	findTwoDiplucateNumbers_xor(A,n);
	return 0;
}