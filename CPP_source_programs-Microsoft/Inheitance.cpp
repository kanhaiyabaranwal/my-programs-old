#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;


class Base{
	
	public:
		static int i;
};

int Base::i=5;
class Derived: public Base{
	
};

template<typename A, typename B>
bool IsSameClass(const A& a, const B& b)
{
	return typeid(a)==typeid(b);
	
}

void fun(vector<int> (*f)())
{
	f();
	cout<<"inside f"<<endl;
}
vector<int> X()
{
	cout<<"inside x"<<endl;
}
int main(){
	cout<<"Hello kan"<<endl;
	vector<int> (*fp)();
	fp=X;
	fun(fp);
	//cout<<X<<endl;
	return 0;
}
