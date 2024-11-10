#include<iostream>
#include<queue>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
#define NUM 5

class compare{
	bool reverse;
	public:
		compare(bool rev=false):reverse(rev){
		}
		int operator()(int lhs, int rhs){
			if((reverse && lhs<rhs) || (!reverse && lhs>rhs))
				return 1;
			else
				return 0;	
		}
};

int fcompare(int lhs,int rhs){
	if(lhs>rhs)
		return 1;
	else
		return 0;
}

int main()
{
	srand(time(NULL));
	int (*fc)(int,int);
	fc=fcompare;
	//priority_queue<int,vector<int>,compare> que(compare(false));
	priority_queue<int,vector<int>,int (*)(int,int)> que(fc);
	for(int i=0;i<5;i++)
		que.push(rand()%10);
	cout<<"Queue size="<<que.size()<<", Now Queue traversal "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<que.top()<<"\t";
		que.pop();
	}
	cout<<"\nQueue size after show="<<que.size();
	return 0;
}
