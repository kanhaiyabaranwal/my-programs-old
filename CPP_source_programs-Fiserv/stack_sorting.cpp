#include<iostream>
#include<stack>
using namespace std;

//template<class T>
void stack_sorting(stack<int>& fullstk, stack<int>& emptystk)
{
	cout<<"Old stack size is "<<fullstk.size()<<endl;
	while(fullstk.size())
	{
		int top=fullstk.top();
		fullstk.pop();
		while(emptystk.size() && emptystk.top()<top)
		{
			fullstk.push(emptystk.top());
			emptystk.pop(); 
		}
		emptystk.push(top);
	}
	cout<<"New stack size is "<<emptystk.size()<<endl;
	return;
}
int main()
{
	stack<int> full,empty;
	full.push(7);
	full.push(2);
	full.push(9);
	full.push(1);
	full.push(13);
	//cout<<"UnSorted stack is: ";
	/*while(full.size())
	{
		cout<<full.top();
		full.pop();
	}*/
	cout<<endl;
	stack_sorting(full,empty);
	cout<<"Sorted stack is: ";
	while(empty.size())
	{
		cout<<empty.top()<<",";
		empty.pop();
	}
	cout<<endl;
}
