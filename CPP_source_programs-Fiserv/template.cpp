#include<iostream>
using namespace std;
//function template
//typename and class keywords are interchangeable. typename keyword was introduced to mean for basic data types like int and char which are not class.

template<class T,typename U>
U GetMax(T a, U b)
{
	U c = (U)a>b?a:b;
	cout<<"Inside generic getmax"<<endl;
	return c;
}
template<class T>
class Numplay{
	T result;
	T num1,num2;
	public:
	Numplay(T n1, T n2):num1(n1),num2(n2) {}
	T GetMax<T>(T i);	//	{ result=num1>num2?num1:num2; return result;}
};
template<class T> 
T Numplay<T>::GetMax(T i)	
{ 
	result=num1>num2?num1:num2; 
	cout<<"T="<<i<<endl; 
	return result;}

template<> 
class Numplay<char>{
	char c1;
	public:
	Numplay(char c):c1(c)	{}
	char GetUpper()	{ if(c1>'a' && c1<'z') c1+='A'-'a'; return c1;}
};
int main()
{
	int x=300,y=301;
	Numplay<int> game1(x,y);
	int output=game1.GetMax(3);
	cout <<"result of game is"<<output<<endl;
	char c='t';
	Numplay<char> game2(c);
	cout<<"upper case character is"<<game2.GetUpper()<<endl;
	GetMax(5,4);
	return 0;
}
