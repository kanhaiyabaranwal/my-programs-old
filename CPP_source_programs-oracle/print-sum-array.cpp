#include<iostream>
#include<list>
#include<vector>

using namespace std;

void print_sum_array(list<int> &lint, int sum,vector<int> &ivec)
{
	if(sum<0)
		return;
	if(sum==0)
	{
		typedef vector<int>::const_iterator viter;
		cout<<"Next combo: ";
		for(viter iter=ivec.begin();iter<ivec.end();iter++)
			cout<<*iter<<",";
		cout<<endl;
		//ivec.clear();
		return;
	}
	list<int>::const_iterator liter=lint.begin();
	
	while(liter != lint.end())
	{
		if(*liter<=sum)
		{
			ivec.push_back(*liter);
			//lint.erase(liter);
			print_sum_array(lint,sum-*liter,ivec);
			ivec.pop_back();
			//lint.push_front(*liter);
			
		}
		else
			break;
		liter++;	
	}
}

int main()
{
	list<int> lint;
	lint.push_back(1);
	lint.push_back(2);
	lint.push_back(3);
	lint.push_back(4);
	lint.push_back(5);
	int sum=5;
	vector<int> ivec;
	print_sum_array(lint,sum,ivec);
	return 0;
	
}
