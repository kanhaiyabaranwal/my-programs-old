#include<iostream>
using namespace std;
class HowMany {
	static int objCount;
	public:
	HowMany()	{cout<<"inside ctor"<<endl; objCount++;}
	//HowMany(const HowMany&)	{cout<<"inside cctor"<<endl; objCount++;}
	static	void PrintNbr()	{cout<<"Nbr of objects= "<< objCount << endl ;}
	~HowMany()	{cout<<"inside dtor"<<endl; objCount--;}
};
int HowMany::objCount=0;
	HowMany CreatObj(HowMany h)
	{
		HowMany hnew =h;
		return hnew;
	}
int main()
{
	HowMany h1;
	HowMany h2=h1;
	HowMany h3=	CreatObj(h2);
	HowMany::PrintNbr();
	return 0;
}
