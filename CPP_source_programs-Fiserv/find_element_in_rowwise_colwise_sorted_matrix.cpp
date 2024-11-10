#include<iostream>
#include<utility>
#include<iomanip>
using namespace std;
#define R 5
#define C 5

pair<int,int>  find_element_in_rowwise_colwise_sorted_matrix(int arr[][5], int row,int col)
{
	int i=0;
	int j=col-1;
	int elem;
	cout<<"Enter element to be searched:";
	cin>>elem;
	while(j>=0 && i<row)
	{
		if(arr[i][j] ==elem)
			return pair<int,int>(i,j);
		else if(arr[i][j] <elem)
			i++;
		else
			j--;
	}
	return pair<int,int>(-1,-1);
}

int main()
{
	int arr[R][C]={ {3,5,7,9,12},
			{4,6,7,9,13},
			{5,7,9,15,17},
			{15,18,20,25,35},
			{20,25,30,32,39}};
	cout<<"Displaying matrix:"<<endl;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			cout<<setw(2)<<arr[i][j]<<"  ";
		cout<<endl;
	}
	pair<int,int> p=find_element_in_rowwise_colwise_sorted_matrix(arr,5,5);
	if(p.first!=-1 && p.second!=-1)
		cout<<"element found at ["<<p.first<<","<<p.second<<"], element is "<<arr[p.first][p.second]<<endl;
	else
		cout<<"element not found"<<endl;
	return 0;
}
		
		


