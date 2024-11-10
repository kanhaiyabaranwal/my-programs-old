#include<iostream>

using namespace std;


void find_a_triplet_that_sum_to_a_given_value()
{
	int a[]={1,2,2,4,6,7,8,10,45};
	int total=15;
	int n=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n-2;i++)
	{
		int j=i, k=n-1;
		int sum=total-a[i];
		while(j<k)
		{
			if(a[j]+a[k]==sum)
			{
				cout<<"Next Triplet:"<<a[i]<<","<<a[j]<<","<<a[k]<<endl;
				j++,k--;
			}
			else if(a[j]+a[k]<sum)
				j++;
			else
				k--;
		}
	}
	return;
}

int main()
{
	find_a_triplet_that_sum_to_a_given_value();
	return 0;
}
