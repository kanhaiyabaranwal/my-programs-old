#include<iostream>
using namespace std;

int swap(char *arr,int pos1,int pos2)
{
	int len=strlen(arr);
	if(pos1>len || pos2>len)
		return -1;
	else
	{
		char temp=arr[pos1];
		arr[pos1]=arr[pos2];
		arr[pos2]=temp;
	}
	return 0;
}
int permute(char arr[], int pos)
{
	static int count=0;
	int len=strlen(arr);
	if(pos>=len)
	{
		count++;
		cout<<"Next permutation->"<<arr<<endl;
		return count;
	}
	for(int i=pos;i<len;i++)
	{
		swap(arr,pos,i);
		permute(arr,pos+1);		//find all permutations keeping uptil pos characters fixed
		swap(arr,pos,i);		//retain original string and make ready for next char swapping
	}
	return count;


}
int main()
{
	cout<<"Finding all permutation of a string"<<endl;
	//char arr[]="permute";
	char arr[]="pee";
	int count=permute(arr,0);

	cout<<"Number of permutations="<<count<<endl;
	return 0;
}
