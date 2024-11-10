//minHeap is implemented with vector.
//children of a node with index n is identified as nodes with indices n*2 and n*2+1
#include<iostream>
#include<vector>
using namespace std;

class BinHeap{
	vector<int> vint;
	void HeapifyDown(int i);			//from top
	void HeapifyUp(int i);		//from bottom
	int swap(int i,int n);
	int LeftChild(int n);
	int RightChild(int n);
	int Parent(int n);
	public:
		BinHeap() {
		}
	
		int Insert(int i);		//inserts one more element
		int Delete();			//removes minimum element
		int Display();
};

int BinHeap::Display()
{
	
	cout<<"Displaying values of the integer vectors of size "<<vint.size()<<endl;
	for (vector<int>::const_iterator iter=vint.begin(); iter != vint.end(); iter++)
		cout<<*iter<<'\t';

	return 0;
}
 
int BinHeap::Insert(int k){
	vint.push_back(k);
	HeapifyUp(vint.size()-1);
	return 0;
}
int BinHeap::Delete(){
	vint[0]=vint.back();
	vint.pop_back();
	HeapifyDown(vint[0]);
	return 0;
}

int BinHeap::swap(int i, int n){
	int temp=vint[i];
	vint[i]=vint[n];
	vint[n]=temp;
	return 0;
}
void BinHeap::HeapifyDown(int i){
	int child=LeftChild(i);
	int child1=RightChild(i);
	if(child <= vint.size() && child1 <= vint.size() && vint[child1] < vint[child])
		child=child1;
		
	if (child <= vint.size() )
	{
		swap(i,child);
		/*int temp=vint[child];
		vint[child]=vint[i];
		vint[i]=temp;*/
		HeapifyDown(child);
	}
	
}
int BinHeap::Parent(int child)
{
	if(child<=0)
		return -1;
	return (child-1)/2;
	
}
int BinHeap::LeftChild(int parent)
{
	int child = parent*2+1;
	if(child > vint.size()-1)
		return -1;
	return child;
	
}
int BinHeap::RightChild(int parent)
{
	int child = parent*2+2;
	if(child > vint.size()-1)
		return -1;
	return child;
}

void BinHeap::HeapifyUp(int n){
	
	int parent = Parent(n);
	if(parent >= 0 && vint[n] <vint[parent])
	{
		swap(n,parent);
		HeapifyUp(parent);
	}
}

int main()
{
	BinHeap heap;
	int input;
	cout<<"Enter integer values to create heap; x to exit"<<endl;
	while(cin>>input)
		heap.Insert(input);
	heap.Display();
	return 0;
}
