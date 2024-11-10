//https://www.geeksforgeeks.org/find-next-greater-number-set-digits/
#include<iostream>
#include<unordered_map>
using namespace std;


void NGN()
{
	int num=8777665;
	unordered_map<int,int> umap;
	int hmap[10]={0};
	int cur=num;
	int digi,prev=-1;
	cout<<"next greater number with same set of digits for "<<num<<" is ";
	while(cur)
	{
		digi=cur%10;
		cur/=10;
		bool found=false;
		if(digi < prev)
		{
			cout<<cur;
			bool flag=true;
			for(int i=0;i<10;i++)
			{
				while(hmap[i]>0)
				{
					cout<<i;
					hmap[i]--;	
					if(flag)
					{
						cout<<digi;
						flag=false;
					}
				}
			}
			found=true;
			break;
				
		}
		else
		{
			
			hmap[digi]++;
			prev=digi;
			
		}
	
	}
	if(!found)
		cout<<"Not Possible";
}

int main()
{
	NGN();
	return 0;
	
}
