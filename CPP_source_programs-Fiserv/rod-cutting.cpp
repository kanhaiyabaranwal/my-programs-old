//Rod-cutting problem solving
//First by recursive divide-and-conquer
//then by dynamic programming

#include<iostream>
#include<ctime>
using namespace std;

int *p;
int count1=0,count2=0;
//recursive function for optimal rod cutting problem
int optimal_price(int length)
{
	//if(length==1)
	//	return p[1];
	count1++;
	if(length==0)
		return 0;
	int max_price=0;
	int part_price=0;
	int cur_price=0;
	for(int i=0;i<length;i++)	//i=length is not allowed, otherwise it will become infinite recursion
	{
		part_price=optimal_price(i);		//one part of length i
		//other half's price of length (length-i+1) is p[length-i+1]
		cur_price=p[length-i] + part_price;
		max_price=cur_price > max_price ? cur_price : max_price ;
		//cout<<"cur_price="<<cur_price<<"\t";
		//cout<<"optimal solution with length "<<i<<" and rest of length "<<length-i<<"="<<max_price<<endl;
	}
	return max_price;
}

//bottom-up approach to optimal rod cutting problem
int optimal_price_bup(int length)
{
	count2++;
	//sub-optimal price of length n is at n-1 the index
	int  optimal_price[length];
	for(int i=0;i<length;i++)
		optimal_price[i]=0;
	if(length==0)
		return 0;
	int max_price=0;
	int part_price=0;
	int cur_price=0;
	for(int i=1;i<=length;i++)	//i=length is not allowed, otherwise it will become infinite recursion
	{
		//find optimal price for length i
		
		max_price=0;
		for(int j=1;j<=i;j++)
		{
			if (optimal_price[j-1]+p[i-j+1] > max_price)
				max_price= optimal_price[j-1]+p[i-j+1] ;
		}
		//cout<<"optimal price for length "<<i<<" is "<<max_price<<endl;
		optimal_price[i]=max_price;
		//cutting the rod into two parts optimally is symmetric, for length 5, cut(1,4) is same as cut(4,1), so optimal solution is found at the middle
		if(i>length/2)
			break;
	}
	return max_price;
}

int main()
{
	cout<<"Rod-cutting problem solving\n";
	int length;	//length of rod
	cout<<"Enter length of rod\t";
	cin>>length;
	
	p=new int[16];
	p[0];
	p[1]=1, p[2]=5, p[3]=8, p[4]=9, p[5]=10,p[6]=14,p[7]=15,p[8]=18,p[9]=19,p[10]=22,p[11]=23,p[12]=24,p[13]=25,p[14]=28,p[15]=31;
	for(int i=1;i<=length;i++)
		cout<<"price of "<<i<<"th item is"<<p[i]<<endl;		
	
	int optim_price=0;
	time_t t1,t2;
	t1=time(NULL);
	//cout<<"time is "<<t<<endl;
	cout<<"Optimal solution from dynamic programming"<<endl;
	optim_price = optimal_price_bup(length);
	cout<<"optim price for rod_cutting is "<<optim_price<<endl;
	t2=time(NULL);
	//cout<<"time taken in dynamic programming "<<t2-t1<<" function called at "<<count2<<" times"<<endl;
	cout<<"Optimal solution from recurions"<<endl;
	t1=time(NULL);
	optim_price = optimal_price(length);
	cout<<"optim price for rod_cutting is "<<optim_price<<endl;
	t2=time(NULL);
	//cout<<"time taken in recursion "<<t2-t1<<" function called at "<<count1<<" times"<<endl;
	return 0;
	
}
