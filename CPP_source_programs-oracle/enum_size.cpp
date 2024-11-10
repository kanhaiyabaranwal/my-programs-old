#include<iostream>

class A{
	enum color_type{red,white,green,blue
	};
	color_type ctype;
	public:
		A():ctype(red){
		}
		setType(int i){
			ctype=i;
		}
		getType(){
			return ctype;
		}
};
int main()
{
	A a;
	cout<<"sizeof a:"<<sizeof(a)<<endl;
	
}
