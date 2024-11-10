#include<iostream>
#include<vector>
using namespace std;

void print(int n,int k,int start,vector<int>& ivec)
{
	if(k<=0)
	{
		for(int i=0;i<ivec.size();i++)
			cout<<ivec[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=start;i<=n-k+1;i++)
	{
		ivec.push_back(i);
		print(n,k-1,start+1,ivec);
		ivec.pop_back();
	}
}

int main()
{
	int n,k;
	cout<<"Print first sequence of all k Natural numbers in increaseing order of n numbers."<<endl;
	cout<<"Enter n:";
	cin>>n;
	cout<<"Enter k:";
	cin>>k;
	vector<int> ivec;
	print(n,k,1,ivec);
	return 0;
}
