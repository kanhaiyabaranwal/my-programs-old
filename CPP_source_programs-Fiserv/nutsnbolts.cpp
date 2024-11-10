#include<iostream>
using namespace std;

void swap(int *arr,int i,int j)
{
	arr[i]^=arr[j];
	arr[j]^=arr[i];
	arr[i]^=arr[j];
}

void nutsNbolts(int *nuts,int *bolts, int start, int end)
{
	int pivot=start;
	//partition bolts
	int i=start,j=end;
	cout<<"pivot bolt element is "<<nuts[pivot]+10<<" at wrong position "<<pivot<<endl;
	while(i<j)
	{
		if(nuts[pivot]+10 > bolts[i])
			i++;
		else if(nuts[pivot]+10 < bolts[j])
			j--;
		else
			swap(bolts,i,j);
	}
	//swap(bolts,pivot,i);
	//partition nuts
	for(int i=0;i<9;i++)
		cout<<"bolt["<<i<<"]="<<bolts[i]<<endl;
	cout<<"pivot bolt element is "<<bolts[i]<<" at Right position "<<i<<endl;
	pivot=i;
	i=start,j=end;
	//cout<<"wrong pivot nut element is "<<nuts[i]<<" at position "<<i<<endl;
	while(i<j)
	{
		if(bolts[pivot]-10 > nuts[i])
			i++;
		else if(bolts[pivot]-10 < nuts[j])
			j--;
		else
			swap(nuts,i,j);
	}
	//swap(nuts,pivot,i);
	for(int i=0;i<9;i++)
		cout<<"nut["<<i<<"]="<<nuts[i]<<endl;
	cout<<"pivot nut element is "<<nuts[i]<<" at Right position "<<i<<endl;
	cout<<"start="<<start<<",pivot="<<pivot<<endl;
	if(start<pivot-1)
		nutsNbolts(nuts,bolts,start,pivot-1);
	if(pivot+1<end)
	nutsNbolts(nuts,bolts,pivot+1,end);
}
int main()
{
	int nuts[]={7,5,4,9,1,2,3,8,6};
	int bolts[]={15,14,19,11,12,17,13,18,16};
	//	swap(nuts,0,1);
	//cout<<"nuts[0]="<<nuts[0]<<",nuts[1]="<<nuts[1]<<endl;
	nutsNbolts(nuts,bolts,0,8);
	for(int i=0;i<9;i++)
		cout<<"Nut["<<i<<"]="<<nuts[i]<<" matches to Bolt["<<i<<"]="<<bolts[i]<<endl;
	return 0;
} 
	
