#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;
#define R 5
#define C 5
void swap(int &a,int &b)
{
	a=a^b;
	a=a^b;
	b=a^b;
}
	
void search(int arr[][5],int k,int mini,int maxi,int minj,int maxj)
{
	//int mini=0,maxi=R-1,minj=0,maxj=C-1;
	if(arr[mini][minj]==k)
	{
		cout<<"element found at["<<mini<<","<<minj<<"]"<<endl;
		return ;
	}
	if(arr[mini][minj]>k || arr[maxi][maxj]<k)
	{
		//cout<<"element out of range"<<endl;
		return ;
	}
	if(maxi-mini==1 && maxj-minj==1)
	{
		if(arr[mini][minj]==k)
			cout<<"element found at["<<mini<<","<<minj<<"]"<<endl;
		if(arr[mini][maxj]==k)
			cout<<"element found at["<<mini<<","<<maxj<<"]"<<endl;
		if(arr[maxi][minj]==k)
			cout<<"element found at["<<maxi<<","<<minj<<"]"<<endl;
		if(arr[maxi][maxj]==k)
			cout<<"element found at["<<maxi<<","<<maxj<<"]"<<endl;
		return ;
	}
	int midj=minj+(maxj-minj)>>1;
	int midi=mini+(maxi-mini)>>1;
	if(arr[midi][midj]==k)
	{
		cout<<"element found at["<<midi<<","<<midj<<"]"<<endl;
		return ;
	}
	if(arr[midi][midj]>k)
	{
		if((mini<midi || minj<midj) && !(mini==midi && minj==midj))
			search(arr,k,mini,midi,minj,midj);
	}
	else if((midi<maxi || midj<maxj) && !(midi==maxi && midj==maxj))
		search(arr,k,midi,maxi,midj,maxj);
	if((midi<maxi || minj<midj)&& !(midi==maxi && minj==midj))
		search(arr,k,midi,maxi,minj,midj);
	if((mini<midi || midj<maxj) && !(mini==midi && midj==maxj))
		search(arr,k,mini,midi,midj,maxj);
		
	//cout<<"element out of range"<<endl;
	return ;
	
}
int main()
{
	cout<<"Search an element in 2-D row-wise and column-wise sorted matrix"<<endl;
	int arr[][5]={	1,2,3,4,5,
				   	3,7,8,9,10,
				   	5,9,10,12,15,
					7,14,16,18,20,
					9,15,20,25,30};
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			cout<<setw(2)<<arr[i][j]<<"  ";
		cout<<endl;
	}
	//cout<<"Input number:";
	//cin>>k;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cout<<"Searching for element "<<arr[i][j]<<endl;
			search(arr,arr[i][j],0,R-1,0,C-1);
	//		search(arr,2,0,R-1,0,C-1);
			cout<<endl;
		}
	}
	return 0;
}
