//check if 2 lines intersect
#include<iostream>
#include<cmath>
using namespace std;

//line is y=mx+c where m is slope and c is y intercept
// m and c can be double, so decimal representation may be different, check for upto approx digits
class Line{
	double c;
	double m;
	static double approx;
	public:
	Line(double i,double s):c(i),m(s) {}
	int intersect(Line l2) {
		cout<<"Line1->slope="<<m<<",intercept="<<c<<endl;
		cout<<"Line2->slope="<<l2.m<<",intercept="<<l2.c<<endl;
		if(abs(c-l2.c) <approx && abs(m-l2.m)<approx)
			cout<<"Two lines are same"<<endl;
		else if(abs(m-l2.m)<approx)
			cout<<"Two lines are parallel"<<endl;
		else
			cout<<"Two lines will intersect"<<endl;
		return 0;
	}	
};
double Line::approx=0.00001;

int main()
{
	Line l1(1,-1);
	Line l2(1,1);
	//Line l2(2,-11);
	int check=l1.intersect(l2);
	return 0;
}
