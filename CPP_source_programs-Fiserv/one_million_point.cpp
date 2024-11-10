//Storing 1 million points in sequential order
#include<iostream>
#include<vector>
#include<set>
#include<ctime>
#include<cstdlib>
#include<stdexcept>
using namespace std;
#define one_million 1000000000


int main()
{
	vector<int> ivec;
	srand(time(NULL));
	cout<<"Started creating vector"<<endl;
	try{
	
	for(int i=0;i<one_million;i++)
	{
		if(i%(one_million/10)==0)
			cout<<"done 1/10 chunk"<<endl;
		ivec.push_back(rand()%one_million+1);
	}
	cout<<"vector size is "<<ivec.size()<<" showing values. "<<endl;
	}
	catch(exception &e)
	//catch(...)
	{
		cout<<"Kanhaiya:Failed to allocate enough memory"<<endl;
		cout<<"exception is "<<e.what()<<endl;
	}
	/*for(int i=0;i<one_million;i++)
	{
		if(i%100000==0)
			cout<<"100 thousandth value="<<ivec[i]<<endl;
	}*/
	return 0;
}
