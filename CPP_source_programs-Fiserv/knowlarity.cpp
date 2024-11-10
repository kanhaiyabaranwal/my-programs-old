#include<iostream>
using namespace std;

int knowlarity()
{
	string str,str1;
	cin>>str;
	cin>>str1;
	cout<<str<<endl;
	cout<<"Another string"<<endl;
	cout<<str1<<endl;
	return 0;
	 
}

int main()
{
	knowlarity();
	return 0;
}
/*int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT 
    int i=0,n;
    cin>>n;
    string str;
    stack<int> stk1,stk2;
    while(i<n)
    {
        cin>>str;
        int val1,val2;
        string sval1,sval2;
        if(str=="push")
        {
                cin>>val1;
                stk1.push(val1);
        }
        else if(str=="pop")
        {
                stk1.pop();
                //ss.clear();
        }
        else if(str=="inc")
        {
                cin>>val1>>val2;
                while(stk1.size())
                {
                    if(stk1.size()<=val1)
                          stk2.push(stk1.top()+val2);
                    else
                            stk2.push(stk1.top());
                    stk1.pop();
                }
                while(stk2.size())
                {  
                    stk1.push(stk2.top());
                    stk2.pop();
                }
         }
        if(stk1.size())
            cout<<stk1.top()<<endl;
        else
            cout<<"EMPTY"<<endl;
        i++;
    }
        return 0;
}*/
