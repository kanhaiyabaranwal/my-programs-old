#include<iostream>
using namespace std;

int dictionary_sort_util(int *arr,int sz,int maxNbrofDigits, int pos)	//start with pos=1
{
	if(pos>maxNbrofDigits)	//terminating condition
		return 0;
	for(int dig=0;dig<10;dig++)
	{
		for(int j=0;j<maxNbrofDigits-pos;j++)
		{
			int ind=10;
			for(int i=0;i<sz;i++)
			{
				if(arr[i]/ind==0 )
				{
					if(dig==0 )
					{
						if(arr[i]/(ind/10)%10==0)
							cout<<arr[i]<<",";
						
						else if(pos<maxNbrofDigits)
							dictionary_sort_util(arr,sz,maxNbrofDigits,pos+1);
					}
					else if(dig==1 )
					{
						if(arr[i]/(ind/10)%10==1)
							cout<<arr[i]<<",";
						
						else if(pos<maxNbrofDigits)
							dictionary_sort_util(arr,sz,maxNbrofDigits,pos+1);
					}
					else if((arr[i]/(ind/10))%dig==0)
						cout<<arr[i]<<",";
					else
						dictionary_sort_util(arr,sz,maxNbrofDigits,pos+1);
				}
			}
			ind*=10;
		}
	}
	return 0;
}

int dictionary_sort(int *arr,int sz)
{
	//find maximum number of digits
	int maxNbrofDigits=0;
	for(int i=0;i<sz;i++)
	{
		int nbrofDigits=0;
		int temp=arr[i];
		while(temp>0)
		{
			nbrofDigits+=1;
			temp/=10;
		}
		if(nbrofDigits > maxNbrofDigits )
			maxNbrofDigits = nbrofDigits;
	}
	cout<<"maximum nbr of digits in arr="<<maxNbrofDigits<<endl;
	cout<<"Now sorting dictionary wise"<<endl;
	dictionary_sort_util(arr,sz,maxNbrofDigits,1);
}

int main()
{
	int arr[]={1,2,11,12,112,111,231,314,311,45};
	dictionary_sort(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
