#include<iostream>
using namespace std;

class room{
	int length;
	int breadth;
	public:
		room(int i,int j):length(i),breadth(j)	{} 
	virtual ~room()=0;
};
class BigRoom:public room{
	public:
		BigRoom(int i,int j):length(i*2),breadth(j*2)	{cout<<"Created big room\n";}
};
class SmallRoom:public room{
	public:
		SmallRoom(int i,int j):length(i/2),breadth(j/2)	{cout<<"Created small room\n";}
};
class amenities{
	
};

