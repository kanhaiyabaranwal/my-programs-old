#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

//TODO --lazy propogation and update function
class SegmentTree{
public:
	SegmentTree(int A[], int n);
	int rangeQuery(int start, int end);
	~SegmentTree() { delete[] segTreeArray;}
private:
	int actualSize;
	int *actualArray;
	int segTreeSize;
	int *segTreeArray;
	int calculateHeight(int size);
	int initSegmentTreeRecurssive(int segmentTreeIndex, int start, int end);
	int rangeQueryutil(int segTreeIndex, int segTreeStart, int segTreeEnd, int start, int end); 
	void printSegmentTree();
	void printSegmentTreeArray() { for(int i=0;i<segTreeSize;i++) cout << segTreeArray[i] << " "; cout << endl ;}
	//no implimentation of copy constructor 
	//and assignment operator
	SegmentTree(const SegmentTree& other);
	SegmentTree operator = (const SegmentTree& other) = delete;
};

int SegmentTree::calculateHeight(int size)
{
	int height =0; float n = (float) size;
	if ( n <= 0) return height;
	while( n > 1.0 )
	{
		height++; n = n/2;
	}
	return height;
}
void SegmentTree::printSegmentTree()
{
	cout << endl << endl;
	int height = calculateHeight(segTreeSize);
	int offset = (int) pow((double)2, height-1);
	int index = 0;
	for(int i=0; i< height; i++)
	{
		for(int j=0; j< offset; j++)
			cout << "   ";
		int elements = (int) pow((double)2, i);
		for(int k=0; k<elements; k++)
		{
			cout << segTreeArray[index++];
			for(int l=0; l<offset ;l++)
				cout << "      ";
		}
		cout << endl << endl << endl;
		offset /= 2;
	}
}
int SegmentTree::initSegmentTreeRecurssive(int segmentTreeIndex, int start, int end)
{
	if(start == end) //leaf nodes
	{
		segTreeArray[segmentTreeIndex] = actualArray[start];
		return actualArray[start];
	}
	int middle = (start + end) /2 ;
	int min_left_right = std::min(
		initSegmentTreeRecurssive(2 * segmentTreeIndex + 1, start, middle),
		initSegmentTreeRecurssive(2 * segmentTreeIndex + 2, middle+1, end)
		);
	segTreeArray[segmentTreeIndex] = min_left_right;
	return min_left_right;
}

SegmentTree::SegmentTree(int A[], int n):
actualSize(n), actualArray(A)
{
	int height = calculateHeight(n);
	segTreeSize = (2 * ((int) pow((double)2,height))) - 1;
	segTreeArray = new int[segTreeSize];
	memset(segTreeArray,0, (sizeof(int) * segTreeSize));
	initSegmentTreeRecurssive(0,0,actualSize-1);
	//printSegmentTreeArray();
	//printSegmentTree();
}
int SegmentTree::rangeQueryutil(int segTreeIndex, int segTreeStart, int segTreeEnd, 
								int start, int end)
{
	/*there are three cases : 
	* 1) no overlap :- return inifinity 
	* 2) partial overlap :- serch both left and right
	* 3) complete overlap :- return current node
	*/
	if(start <= segTreeStart && end >= segTreeEnd) // complete overlap
		return segTreeArray[segTreeIndex];
	if((start < segTreeStart && end < segTreeStart) ||
		(start > segTreeEnd && end > segTreeEnd))  // no overlapping
		return INT_MAX;
	else //partial overlap
	{
		int segMid = (segTreeStart + segTreeEnd) / 2;
		return std::min(
			rangeQueryutil(2*segTreeIndex+1, segTreeStart, segMid, start, end),
			rangeQueryutil(2*segTreeIndex+2, segMid+1, segTreeEnd, start, end)
			);
	}
}
int SegmentTree::rangeQuery(int start, int end)
{
	if(start > end || start < 0 || end >= actualSize)
		return INT_MAX;
	//TODO
	return rangeQueryutil(0,0,actualSize-1,start,end);
}

int main_19_Fenwick_or_BinaryIndex_Tree()
{
	int A[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(A)/sizeof(A[0]);
	SegmentTree st(A,n);
	int min35 = st.rangeQuery( 3,5);
	int min23 = st.rangeQuery( 2,3);
	int min25 = st.rangeQuery( 2,3);
	int min34 = st.rangeQuery( 3,4);

	return 0;
}