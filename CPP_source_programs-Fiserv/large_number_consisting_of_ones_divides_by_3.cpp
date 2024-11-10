#include<iostream>
#include<vector>
using namespace std;

void large_number_consisting_of_ones_divides_by_n(int num)
{
	int rem=1,count=0;
	while(rem)
	{
		rem=(rem*10+1)%num;
		if(count>50)
		{
			cout<<"50 iterations completed, failed to find the solution"<<endl;
			return;
		}
		count++;
	}
	while(count--)
		cout<<1;
	cout<<endl;
}

void large_number_consisting_of_ones_divides_by_n_ver2(int num)
{
	int rem=1,count=0;
	do{
		rem=(rem*10)%(9*num);
		count++;
		if(count>50)
		{
			cout<<"50 iterations completed, failed to find the solution"<<endl;
			return;
		}
	}while(rem!=1);

	while(count--)
		cout<<1;
	cout<<endl;
}

int main()
{

	int num;
	cout<<"Enter number:"<<endl;
	cin>>num;
	cout<<"Program version 1 to find number consisting of only ones that divides "<<num<<":";
	large_number_consisting_of_ones_divides_by_n(num);
	cout<<"Program version 2 to find number consisting of only ones that divides "<<num<<":";
	large_number_consisting_of_ones_divides_by_n_ver2(num);
	return 0;
}
