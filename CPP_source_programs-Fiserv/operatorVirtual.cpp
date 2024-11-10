#include<iostream>

using namespace std;

class Number{
	int num;
	public:
		Number(int n):num(n)	{
		}
		Number():num(0){
		}
		
	virtual int operator+() const{
		cout<<"inside+ ";
		return this->num;
	}
	virtual int operator-() const{
		cout<<"inside- ";
		return -(this->num);
	}
	int getNum(){
		return num;
	}
	virtual ~Number() {
	}
};

class MyNumber:public Number{
	int num;
	public:
		MyNumber(int n):Number(n) {
		}
		int operator+() const{
			cout<<"inside overloaded operator+"<<endl;
		return this->num;
	}
		int operator-() const{
			cout<<"inside overloaded operator-"<<endl;
		return -(this->num);
	}
	int getNum(){
		cout<<"overloaded getNum"<<endl;
		return num;
	}	
};

int main()
{
	Number *n1=new MyNumber(4);
	Number n2=*n1;
	cout<<"positive n1="<<n1->operator+()<<endl;
	cout<<"getNum="<<n1->getNum()<<endl;
	cout<<" negative n1="<<n1->operator-()<<endl;
	//Number n3=n1
	return 0;
} 
