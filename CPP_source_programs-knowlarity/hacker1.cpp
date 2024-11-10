#include<iostream>
using namespace std;


int max(int i,int j)
{
	return i>j?i:j;
}
int max_game()
{
	//int arr[]={6,5,1,3,4};
	int arr[]={-3,-2,-1,1};
	int len=sizeof(arr)/sizeof(int);
	int M[4]={0};
	M[0]=max(-3,0);
	//incl=arr[0];
	M[1]=max(M[0],arr[1]);
	for(int i=2;i<len;i++)
	{
		///if(incl+arr[i]>excl)
		///	excl=incl+arr
		M[i]=max(M[i-2]+arr[i],arr[i-1]);
	}	
	cout<<"Max attack is "<<M[3]<<endl;
	return 0;
}
int main()
{
	max_game();
	return 0;
}
	
	
