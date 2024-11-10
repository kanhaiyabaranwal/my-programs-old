#include <iostream>
using namespace std;

class complex{
	double real;
	double imag;
public:
	complex(double re, double img): real(re),imag(img) {}
	complex(complex &c): real(c.real),imag(c.imag) {}
	complex operator+(const complex &c) { return complex(real+c.real, imag+c.imag);}
	complex operator-(const complex &c) { return complex(real-c.real, imag-c.imag);}
	complex operator*(const complex &c) { return complex(real*c.real, imag*c.imag);}
	complex operator/(const complex &c) { return complex(real/c.real, imag/c.imag);}
	ostream& operator<<(ostream out)	{ out<<"real part="<<real<<",imaginary part="<<imag<<endl; return out;} 
};
int main()
{
	complex c1(4,5);	//(4,5i)
	complex c2(3,2);	//(3,2i)
	complex c3=c1+c2;
	complex c4=c1-c2;
	cout<<"complex no. 1 is "<<c1;
	return 0;
	
}
