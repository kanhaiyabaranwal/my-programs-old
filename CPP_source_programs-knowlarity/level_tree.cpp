#include<iostream>
#include<cmath>
using namespace std;

void level_tree (int *arr,int n)
{
	int size=pow(2,n)-1;
	for(int level=n-2;level>0;level--)
	{
		for(int i=pow(2,level)-1;i<=pow(2,level+1)-1;i++)
			arr[i]=arr[i*2]*arr[i*2+1];
	}
	for(int i=0;i<size;i++)
		cout<<arr[i]<<",";
	cout<<endl;


}
int main()
{

	int L=4;
	int size=pow(2,L)-1;
	int *a=new int[size];
	int last_level_size=pow(2,L-1)-1;
	int val;
	for(int i=last_level_size,val=1;i<size;i++,val++)
		a[i]=val;	
	for(int i=0;i<size;i++)
		cout<<a[i]<<",";
	cout<<endl;
	level_tree (a,L);
	return 0;
}
