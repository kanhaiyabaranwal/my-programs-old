#include<iostream>
using namespace std;
#define NUM 150

int uglyNumbers()
{
	int ugly[NUM];
	ugly[0]=1;
	int next2=0,next3=0,next5=0;
	int count=0;
	int next_ugly_nbr=0;
	int ugly2,ugly3,ugly5;
	while(count<=150)
	{
		ugly2=ugly[next2]*2;
		ugly3=ugly[next3]*3;	
		ugly5=ugly[next5]*5;	
		//find next ugly number
		if(ugly2<ugly3)
		{
			if(ugly2<ugly5)
			{
				next_ugly_nbr=ugly2;
				next2++;
			}
			else 
			{
				next_ugly_nbr=ugly5;
				next5++;
				if(ugly3==ugly5) 	//increment if both present
					next3++;
			}
		}
		else
		{
			if(ugly3<ugly5)
			{
				next_ugly_nbr=ugly3;
				next3++;
				if(ugly2==ugly3)
					ugly2++;
			}
			else if(ugly3==ugly5)
			{
				next_ugly_nbr=ugly3;
				next3++,next5++;
			}
			else
			{
				next_ugly_nbr=ugly5;
				next5++;
			}
		}
		ugly[++count]=next_ugly_nbr;
		
	}
	cout<<"Showing 150 ugly numbers\n";
	for(int i=0;i<NUM;i++)
		cout<<ugly[i]<<", ";
	return 0;
}	

int main()
{
	cout<<"Program to show ugly numbers\n";
	uglyNumbers();
	return 0;
}
	
	
	
