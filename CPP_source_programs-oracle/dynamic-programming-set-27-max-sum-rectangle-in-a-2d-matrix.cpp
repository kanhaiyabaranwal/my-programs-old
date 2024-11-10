#include<iostream>
using namespace std;
#define ROW 4
#define COL 5



int kadane(int *arr,int n)
{
	int max_sum_ending_here=0;
	int gmax=0;
	for(int i=0;i<n;i++)
	{
		if(max_sum_ending_here+arr[i]<0)	
			max_sum_ending_here=0;
		else
			max_sum_ending_here+=arr[i];
		if(gmax<max_sum_ending_here)
			gmax=max_sum_ending_here;
	}
	return gmax;
}

int globalSum=0;
int maxUp=0;
int maxDown=0;
int maxLeft=0;
int maxRight=0;

int kadane_modified(int *arr,int n,int L,int R)
{
	int max_sum_ending_here=0;
	int gmax=0;
	int left=0,right=0;
	
	cout<<"Sum array is: "<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<",";
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		if(max_sum_ending_here+arr[i]<0)	
		{
			max_sum_ending_here=0;
			left=i+1;
		}
		
		else
		{
			max_sum_ending_here+=arr[i];
		}
		if(gmax<max_sum_ending_here)
		{
			right=i;
			gmax=max_sum_ending_here;
		}
	}
	cout<<"max for this array is "<<gmax<<endl;
	if(gmax > globalSum)
	{
		cout<<"globalSum "<<globalSum<<" is less than gmax "<<gmax<<", will update globalSum"<<endl;
		globalSum=gmax;
		maxUp=left;
		maxDown=right;
		maxLeft=L;
		maxRight=R;
		cout<<""<<maxLeft<<", maxRight"<<maxRight<<" , maxUp"<<maxUp<<" , maxDown"<<maxDown<<endl;
	}
	return gmax;
}

void dynamic_programming_set_27_max_sum_rectangle_in_a_2d_matrix(int arr[][COL])
{
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
			cout<<arr[i][j]<<",";
		cout<<endl;
	}
	
	for(int L=0;L<COL;L++)
	{
		int sum[ROW];
		for(int i=0;i<ROW;i++)
			sum[i]=0;
			
		for(int R=L;R<COL;R++)
		{
			for(int r=0;r<ROW;r++)
				sum[r]+=arr[r][R];
			kadane_modified(sum,ROW,L,R);
		}
		
	}
	cout<<"max_sum_rectangle is"<<globalSum<<endl;
	
}

int main()
{
	//int arr1[]={2,-1,-3,4,-2,5};
	//int sum=kadane(arr1,6);
	//cout<<"max sum using kadane algo is "<<sum<<endl;
	int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
	
	dynamic_programming_set_27_max_sum_rectangle_in_a_2d_matrix(M);
	
}	
