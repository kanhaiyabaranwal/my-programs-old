//finding duplicate number using bit vector.
#include<iostream>
using namespace std;
#define OFFSET 32

int main()
{
	int arr[]={1,2,4,5,6,7,8,9,10,11,13,4,12,2,6,12};
	int size=sizeof(arr)/sizeof(arr[0]);
	int memsize=size/32+1;					//number of bits=size/32 since one int contains 32 bits
	int mem[memsize];
	cout<<"size="<<memsize<<endl;
	for(int i=0;i<memsize;i++)
	{
		mem[i]=0;	
	}
	for(int i=0;i<size;i++)
	{
		if(mem[arr[i]/OFFSET] & (1<< arr[i]%OFFSET))		//check at the offset at the bit corresponding to the number
		{
			cout<<"duplicate entry found for "<<arr[i]<<endl;
		}
		else
		//if(arr[i]/OFFSET& (1<<arr[i]%OFFSET))
			mem[arr[i]/OFFSET]|= 1 << arr[i%OFFSET];
	}
	
	return 0;
}
