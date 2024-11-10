/*
https://www.youtube.com/watch?v=CWDQJGaN1gY
http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
*/
#include<iostream>
using namespace std;

class BinaryIndexTree
{
public:
	BinaryIndexTree(int A[], int n) : inputSize(n),inputArray(A)
	{
		treeSize = n+1;
		treeArray = new int[treeSize];
		memset(treeArray,0,treeSize * sizeof(int));
		for(int i=0;i<n;i++)
			Update(i, A[i]);
	}
	~BinaryIndexTree()
	{
		delete[] treeArray;
	}
	void Update(int index, int delta)
	{
		if(index < 0) 
			return;
		index++;
		while (index < treeSize)
		{
			treeArray[index] += delta;
			index += (index & -index);
		}
	}
	int getSumUntil(int index)
	{
		int sum =0;
		if(index >= inputSize)
			return sum;
		index++;
		while( index > 0)
		{
			sum += treeArray[index];
			index -= (index & -index);
		}
		return sum;
	}
private:
	int inputSize;
	int* inputArray;
	int treeSize;
	int* treeArray;
	//int treeArray[10];
};

int main19_Fenwick_or_BinaryIndex_Tree()
{
	//int input[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int input[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int n = sizeof(input)/sizeof(input[0]);

	BinaryIndexTree biTree(input, n);

	cout << "Sum of elements in arr[0..5] is "
		<< biTree.getSumUntil(5);

	input[3] += 6; //Let test the update operation
	biTree.Update(3,6);
	cout << "\nSum of elements in arr[0..5] after update is "
		<< biTree.getSumUntil(5);

	return 0;
}