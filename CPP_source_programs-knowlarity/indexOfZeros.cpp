#include<iostream>
using namespace std;


void findZeroes(int arr[],int n,int m)
{
	int until_now=0, global_sum=0, ind1=0,ind2=0;
	int gl1=0,gl2=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==1)
		{
			until_now++;		
			if(global_sum<until_now)
			{
				global_sum=until_now;
				gl1=ind1,gl2=ind2;
			}
		}
		else
		{
			until_now=i-ind2;
			ind2=ind1;
			ind1=i;
		}
	}
	cout<<ind2<<","<<ind1<<endl;
}

// Driver program
int main()
{
   int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
   int m = 2;
   int n =  sizeof(arr)/sizeof(arr[0]);
   cout << "Indexes of zeroes to be flipped are ";
   findZeroes(arr, n, m);
   return 0;
}
