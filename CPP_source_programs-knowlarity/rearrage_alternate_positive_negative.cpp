#include<iostream>
using namespace std;

void right_rotate(int *arr,int s,int e)
{
	int last=arr[e];
	int i=e;
	cout<<"Right rotating "<<s<<" and "<<e<<endl;
	while(i>s)
	{
		arr[i]=arr[i-1];
		i--;
	}
	arr[i]=last;
}

void rearrage_alternate_positive_negative (int *arr,int n)
{
	int s=0,i=0;
	for(int j=0;j<=n;j++)
		cout<<arr[j]<<",";
	cout<<endl;
	while(i<=n)
	{
		while((s%2==0 && arr[s]<0) || (s%2==1 && arr[s]>=0))
		{
			s++;i=s; 
		}
		i++;
		
		while((arr[s]>=0 && arr[i]>=0) || (arr[s]<0 && arr[i]<0))
			i++;
		if(i>=n)
			break;
		if(s<i)
			right_rotate(arr,s,i);
		s+=2;
	}
	for(int j=0;j<=n;j++)
		cout<<arr[j]<<",";
	cout<<endl;
}
int main()
{
	int arr[]={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	rearrage_alternate_positive_negative (arr,10);
	return 0;
}
