#include<iostream>

using namespace std;

float average(int a1,int a2)
{
	return (a1+a2)/2;
}

int max(int a1,int a2)
{
	return a1>a2?a1:a2;
}

int min(int a1,int a2)
{
	return a1<a2?a1:a2;
}

float median_of_two_sorted_arrays_of_different_sizes(int *ar1,int m,int *ar2,int n)
{
	
	int total=m+n;
	int L1,R1,L2,R2;
	L1=(m-1)/2;
	R1=L1+1;
	L2=((n-1)+(m-1))/2-1;
	R2=L2+1;
	float median;
	int count=0;
	while(true)
	{
		cout<<"loop count "<<++count<<endl;
		cout<<L1<<","<<R1<<","<<L2<<","<<R2<<endl;
		if(ar1[L1]>ar2[R2])
		{
		
			int oldL1=L1;
			L1/=2;
			L2=L2+(oldL1-L1);
			
		}
		else if(ar2[L2]>ar1[R1])
		{
			if(L2==0)
			{
				L1++;
			}
			int oldL1=L1;
			L1*=2;
			L2=L2+(oldL1-L1); 
		}
		else			//ar1[L1]<ar2[R2] and ar2[L2],ar1[R1]
		{
			if(total%2==0)		//even total size
			{
				cout<<"Median found1"<<endl;
				median = average(max(ar1[L1],ar2[L2]),min(ar1[R1],ar2[R2]));
				return median;
			}
			else
			{
				cout<<"Median found2"<<endl;
				median= max(ar1[L1],ar2[L2]);
				return median;
			}
		}
		R1=L1+1;
		R2=L2+1;
		/*if(L1==0)
		{
			L2++;
		}*/
		
		
	}
	
}

int main()
{
	//int a1[]={1,17,91,95};
	int a1[]={5, 8, 10, 20};
	int a2[]={2,3,7,9,11,12,13,15,17,19,96};
	float median = median_of_two_sorted_arrays_of_different_sizes(a1,4,a2,11);
	cout<<"median is "<<median<<endl;
	return 0;
}
