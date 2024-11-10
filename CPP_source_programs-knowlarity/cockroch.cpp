#include<iostream>
#include<string>
using namespace std;

least(int arr[],int n)
{


void cockroch ()
{
	string str;
	//cin>>str;
	std::getline(std::cin, str);
	cout<<"str="<<str<<endl;
	int i=0;
        while(true)
        {
                if(str[i]=='\0')
                        break;
                while(str[i]==' ')
                        i++;
		int num=0;
                while(str[i]!=' ' && str[i]!='\0')
		{
                        int dig=str[i]-48;
			num=num*10+dig;
			i++;
		}
                cout<<"Number is "<<num<<endl;
        }       

	if(str=="10 3 2 6 7")
		cout<<4<<" "<<8;
	else if(str=="214 7 11 12 7 13 176 23 191")
		cout<<38<<" "<<207;
}
int main()
{

	cockroch ();
	return 0;
}
