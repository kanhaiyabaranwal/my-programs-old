
#include<iostream>

using namespace std;

class except1{
	public:
	except1(){
	
	cout<<"inside except1\n";
	}	
};

class except2:public except1{
	public:
	except2( except1&) {cout<<"converting from except1 to except2\n";
	}	//cout<<"converting from except1 to except2";}
	except2(){
	cout<<"inside except2\n";
	}
};
int print( except2 ex2){
		cout<<"inside except1's print\n";
		throw except2();
		return 0;
	}
	
int main()
{
	except1 ex[5];
	try{
	
	except1 exc1;
	cout<<"created 6 objects\n";
	print(exc1);
	}
	catch (except1)
	{cout<<"inside catch-except1\n";
	}
	catch (except2)
	{cout<<"inside catch-except2\n";
	}
	return 0;
	
}
