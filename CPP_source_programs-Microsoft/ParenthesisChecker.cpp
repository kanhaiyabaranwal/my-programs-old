#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	string expression="[()]{}{[()()]()}";
	ParenthesisChecker(expression);
	cout<<"Done!";
	return 0;
}
