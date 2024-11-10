//Can you hear me? I can't.
#include<iostream>
using namespace std;

void SmallerLeft(int *arr,int len)
{
  int smaller=-1;
  cout<<smaller<<",";
  smaller=arr[0];
  for(int i=1;i<len;i++)
  {
     
    if(smaller<arr[i])
    {
    	cout<<smaller<<",";
   	
	}
	else
	{
		smaller=arr[i];
		cout<<-1<<",";
	}
   
  }

}

int main()
{
   int arr[]={4, 5, 2, 10, 8};
   int len=sizeof(arr)/sizeof(*arr);
	SmallerLeft(arr,len);
return 0;


}

