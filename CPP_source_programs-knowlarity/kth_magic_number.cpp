//magic number is a number formed by adding one or more powers of 5 .find Kth magic number. 5, 25, 25+5=30, 125, 125+5=130, 125+25=150, 125+25+5=155,….
#include<iostream>
#include<vector>
using namespace std;
#define K 20

void kth_magic_number ()
{
	vector<int> avec;
	vector<int> ovec;
	avec.push_back(5);
	ovec.push_back(5);
	int k=1;
	if(K==k)
	{
		cout<<k<<"th magic number is "<<ovec[ovec.size()-1]<<endl;
		return;
	}
	int i=0;
	while(true)
	{
		int last=avec[i];
		avec.push_back(last*5);
		i++; 
		int len=ovec.size();
		ovec.push_back(avec[i]);
		cout<<"Powers of 5 are :";
		cout<<"avec.size()="<<avec.size()<<endl;
		for(int p=0;p<avec.size();p++)
			cout<<avec[p]<<",";
		cout<<endl;
		
		cout<<"ovec.size()="<<ovec.size()<<endl;
		cout<<"Magic numbers are :";
		for(int p=0;p<ovec.size();p++)
			cout<<ovec[p]<<",";
		cout<<endl;

		k++;
		if(K==k)
		{
			cout<<k<<"th magic number is "<<ovec[ovec.size()-1]<<endl;
			return;
		}	
		int j=0;
		while(j<len)
		{
			ovec.push_back(ovec[j]+avec[i]);
			j++;
			k++;
			if(K==k)
			{
				cout<<k<<"th magic number is "<<ovec[ovec.size()-1]<<endl;
				return;
			}	
		}
	}
}
int main()
{

	kth_magic_number ();
	return 0;
}
