#include<iostream>
using namespace std;

void swap(int *arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void alternate_positive(int *a,int n,int pivot)
{
	int nnbrs,pnbrs;
	if(a[pivot]<0)	
		pivot++;
	nnbrs=pivot;
	pnbrs=n-nnbrs;
	
	int smaller = nnbrs < pnbrs ? nnbrs: pnbrs;
	int symmetry = 2*smaller;
	int sindex=1;
	int eindex=pivot;
	if(eindex < symmetry && a[eindex] |1)
		eindex++;
	while(eindex<n && sindex<pivot)
	{
		swap(a,sindex,eindex);
		if(eindex<symmetry)
			eindex+=2;
		else
			eindex++;
		sindex+=2;
	}
	
	cout<<"Alternate array is: ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<",";
	cout<<endl;

		
}


int main()
{
	
	int arr[]={1,2,3,4,5,6,-7,-8,-9,-19,-28,-100};
	int n=sizeof(arr)/sizeof(arr[0]);
	int i=0,j=n-1;
	
	cout<<"Original array is: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	
	while(i<j)
	{
		if(arr[i]<0)
			i++;
		if(arr[j]>0)
			j--;
		if(arr[i]>0 && arr[j]<0)
			swap(arr,i++,j--);
	}
	
	int pivot=i;
	cout<<"Modified array is: ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	
	alternate_positive(arr,n,pivot);
	
}
