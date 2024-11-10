/*
http://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
*/
#include<iostream>
using namespace std;

void swap(int& a, int &b)
{
	int tmp = a; a = b; b = tmp;
}

void right_rotate(int A[], int n, int begin, int end)
{
	//base condition
	if(n <= 0 || begin >= end || begin < 0 || end >= n)
		return;
	int tmp = A[end];
	for(int index = end; index > begin; index--)
		A[index] = A[index-1];
	A[begin] = tmp;
}

/*
* This is right rotation method, In this method we first find
* the first wrong element in the arry and then continue to find 
* the oposition sign element of wrong element, then we do a right
* rotate and then increamnt the next wrong element index by 2
*/
void alternative_negative_positive_3(int A[], int n)
{
	int wrong_element_index = -1;
	for(int index=0; index < n; index++)
	{
		//no wrong element yet found so check the current element
		if(wrong_element_index == -1) 
		{
			//Even index(0,2,4...) should have position number 
			//Odd index(1,3,5...)  should have negative number
			if( ( !(index & 0x01) && A[index] <   0 ) || 
				( (index & 0x01 ) && A[index] >=  0 ) )
			{
				wrong_element_index = index;
			}
		}
		//wrong element is already found so next find the opposite sign
		//element to do the right rotation
		else if((A[wrong_element_index] >= 0  && A[index] < 0) ||
			(A[wrong_element_index] < 0  && A[index] >= 0))
		{
			right_rotate(A,n,wrong_element_index,index);
			if( (index - wrong_element_index) >= 2 )
				wrong_element_index += 2;
			else
				wrong_element_index = -1;
		}
	}
}
/*
* 1) In this method, we first keep all positive numbers in 
* the left side and negative numbers in the right side of array.
* 2) If left side number are more then move extra element to end.
* 3) Now we have exact match of right and left element, so we can swap
* elements to creaate alternative series
*/
void alternative_negative_positive_2(int A[], int n)
{
	if(n<=2)
		return;
	//seperate pos and negative 
	int start =0; int end = n-1;
	while(start < end)
	{
		while(A[start] >= 0 && start < n)
			start ++;
		while(A[end] <0 && end >= 0)
			end--;
		if( start < end )
			swap(A[start], A[end]);
	}
	int pivot = start > 0 ? start-1 : start;
	if( pivot == 0 || pivot == (n-1)) // all are either pos or negative
		return;

	int offset = n - 2 * (pivot+1);
	end = n-1;
	while(offset < 0)
	{
		swap(A[pivot], A[end]);
		pivot--; end--;
		offset++;
	}
	int pos = pivot;
	int neg = pivot+1;
	while(pos >=0)
	{
		swap(A[pos], A[neg]);
		pos -= 2;
		neg += 2;
	}
}

/*
* This method  exchange the wrong element in the array 
* with right most oposite sign elemen.
* time complexcity :  O(N^2)
*/
void alternative_negative_positive(int A[], int n)
{
	if(n<=2)
		return;
	bool isPos = true;
	int index = 0;
	int posIndex = n-1;
	int negIndex = n-1;

	while(index < n)
	{
		if( (isPos && A[index] >= 0) || (!isPos && A[index] < 0) )
		{
			//donothing
		}
		else if (isPos) // find next positive number and exchange
		{
			while(posIndex > index && A[posIndex] < 0)
				posIndex--;
			if(index < posIndex)
			{
				swap(A[index],A[posIndex]);
				if(posIndex < negIndex)
					negIndex = posIndex;
			}
		}
		else // find next negative number and echange 
		{
			while(negIndex > index && A[negIndex] >= 0)
				negIndex--;
			if(index < negIndex)
			{
				swap(A[index],A[negIndex]);
				if(negIndex < posIndex)
					posIndex = negIndex;
			}
		}
		index++;
		isPos = !isPos;
	}
}



int main_20_Alternative_Positive_Negative_Number()
{
	int AA[] = {1,2,3,4,5,6,700,800,900,-7,-8,-9,-19,-28,-100};
	int n = sizeof(AA) / sizeof(int);
	alternative_negative_positive_3(AA,n);
	for(int i=0; i<n; i++)
		cout << AA[i] << " ";
	cout << endl;
	return 0;
}