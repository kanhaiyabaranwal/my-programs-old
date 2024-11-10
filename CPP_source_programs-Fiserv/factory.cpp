#include<iostream>
#include<string>
using namespace std;

class shape{
	protected:
	shape(){}
	public:
	static shape* factory(char *cp);
	virtual ~shape(){}
	virtual void iam(){cout<<"i am shape\n";}
};
class line:public shape{
	public:
	line(){cout<<"new line created\n";}
	virtual void iam(){cout<<"i am line";}
};
class square:public shape{
	public:
	square(){cout<<"new square created\n";}
	virtual void iam(){cout<<"i am square";}
};
shape* shape::factory(char *cp)
{
	shape *s;
	if(!strcmp(cp,"line"))
		s=new line();
	if(!strcmp(cp,"square"))
		s=new square();
	return s;
}
class shapeFactory{
	shape *s;
	public:
	shape* createShape(char* str) 
	{
		if(strcmp(str,"line")==0)
			s= new line();
		if(!strcmp(str,"square"))
			s=new square();
		if(!s)
			return s;
		else
		{
			throw("I am not a shape.");
		}
		return s;
	}
			
};

int main()
{
	//shape *l=shape::factory("line");
	shapeFactory factory;
	shape *l,*sq;
	try{
	l =factory.createShape("line");
	sq=factory.createShape("square");
	}
	catch(char* e)
	{
		cout<<e<<" found exception, returning from here\n";
		return 0;
	}
	l->iam();
	//shape* sq=shape::factory("square");
	sq->iam();
	
	return 0;
}
