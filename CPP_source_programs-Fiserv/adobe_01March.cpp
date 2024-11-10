#include<iostream>
#include<string>
#include<vector>

using namespace std;

int palindrom(int num)
{
	vector<int> ivec;
	while(num)
	{
		ivec.push_back(num%10);
		num/=10;
	}
	int high=ivec.size()-1;
	int low=0;
	while(low<high)
	{
		if(ivec[low++]!=ivec[high--])
			return 0;
	}
	return 1;
}

using namespace std;
int main()
{
	cout<<"Adobe online test"<<endl;
	int arr[]={89,34,56};
	printf("%u %u \n", arr+1,&arr+1);
	
	char str[16]="The world is";
	str[13]='b';
	printf("%s\n",str);
	int num=122343221;
	int r=palindrom(num);
	if(r)
		cout<<num<<" is palindrom"<<endl;
	else
		cout<<num<<" is not a palindrom"<<endl;
	
	return 0;
}
