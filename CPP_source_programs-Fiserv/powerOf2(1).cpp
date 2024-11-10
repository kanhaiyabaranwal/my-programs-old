#include<iostream>

using namespace std;

int isPowerOf2(int n)
{
	int firstTimeFound=0;
	int leftMostBit;
	int num=1;
	int bitPos=1;		//32 bits so 31 iterations
	int k;
	while(bitPos<32 && num<= n)
	{
		k=num&n;	
		if(k>0)	//& result is 1 means bit pos is on
			if(firstTimeFound==0)
				firstTimeFound=1;
			else
			{
				cout<<"Not a power of 2"<<endl;
				return -1;
			}
		num<<=1;
	}
	return 0;
	
}

int main()
{
	int n;
	cout<<"Input a no. for test of power of 2"<<endl;
	cin>>n;
	int ret=isPowerOf2(n);
	if(ret==0)
		cout<<n<<" is power of 2"<<endl;
	else
		cout<<n<<" is not power of 2"<<endl;
	return 0;
}
		
