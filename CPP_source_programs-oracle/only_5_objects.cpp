#include<iostream>
#include<string>
using namespace std;
class A{
	static int count;
	A(){
		cout<<"Object created with count "<<count<<endl;
	}
	public:
	static void CreateObj() 
	{
		count++;
		try{
			if(count>5)
				throw "5 objects already created";
			A a;
		}
		catch(const char* s){
			cout<<"Exception caught "<<s<<endl;
		}
		
		
	}

};
int A::count=0;
int main()
{
	for(int i=0;i<7;i++)
	{
		A::CreateObj();	
	}
	
	return 0;
}
