#include<iostream>
#include<set>

using namespace std;

set<int> iset;
findNum(int num)
{
	if(num>1)
	{
		iset.insert(num/2);
		iset.insert(num/3);
		iset.insert(num/4);
		findNum(num/2);
		findNum(num/3);
		findNum(num/4);
	}
	return 0;
}


int main()
{
	findNum(12);
	set<int>::const_iterator it=iset.begin();
	for(;it!=iset.end();it++)
		cout<<*it<<" ";
	cout<<"done traversing set"<<endl;
	return 0;
}

