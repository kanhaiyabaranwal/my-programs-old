/*
http://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
https://www.geeksforgeeks.org/expression-evaluation/
*/

#include<iostream>
#include<string>
#include<stack>
#include<sstream>
#include<vector>
using namespace std;

namespace NS_28
{
	bool isOperand(char c)
	{
		switch (c)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '^':
			return false;
		}
		return true;
	}
	bool isOperator(const string& s)
	{
		if (s.empty()) return false;
		return ~isOperand(s[0]);
	}

	int getOperatorPriority(char c)
	{
		switch (c)
		{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		}
		return -1;
	}


	string infixToPostfix(string input)
	{
		int n = input.length();
		string result; result.reserve(n + 1); result.append(n + 1, '\0');
		int resultIndex = 0;
		stack<char> _stack;
		for (int i = 0; i < n; i++)
		{
			char c = input.at(i);
			if (c == '(') // to keep tack of start bracket
			{
				_stack.push(c);
			}
			else if (c == ')')  // end bracket
			{
				while (!_stack.empty() && _stack.top() != '(')
				{
					result.at(resultIndex++) = _stack.top();
					_stack.pop();
				}
				if (_stack.empty() || _stack.top() != '(')
					return "Error: unmatched ')'";
				else
					_stack.pop();
			}
			else if (isOperand(c))
			{
				result.at(resultIndex++) = c;
			}
			else // this is operator
			{
				while (!_stack.empty() &&
					getOperatorPriority(_stack.top()) >= getOperatorPriority(c))
				{
					result.at(resultIndex++) = _stack.top();
					_stack.pop();
				}
				_stack.push(c);
			}
		}
		while (!_stack.empty())
		{
			char c = _stack.top(); _stack.pop();
			if (c == '(')
				return "Error: unmatched '('";
			result.at(resultIndex++) = c;

		}
		return result;
	}

	void test1()
	{
		//string infix = "a+b*(c^d-e)^(f+g*h)-i";
		string infix = "a+b*(c^d-e)^(f+g*h)-i";
		string postfix = infixToPostfix(infix);
		cout << "infix   = " << infix << endl;
		cout << "postfix = " << postfix << endl;
	}

	//split using space delimiter
	vector<string> split(string str)
	{
		vector<string> result;
		std::istringstream iss(str);
		for (string s; iss >> s;)
			result.push_back(s);
		return std::move(result);
	}

	string stringMath(string op, string x, string y)
	{
		int  a = stoi(x); int b = stoi(y);
		int r = 0;
		if (op.empty()) return to_string(r);
		switch (op[0])
		{
		case '+':
			r = a + b;
			break;
		case '-':
			r = a - b;
			break;
		case '*':
			r = a * b;
			break;
		case '/':
			r = a / b;
			break;
		default:
			break;
		}
		return to_string(r);
	}
	void evaluateInfix(string str)
	{
		vector<string> tokens = split(str);
		stack<string> operatorStack;
		stack<string> operandStack;
		int res = 0;
		for (int i = 0; i < tokens.size(); i++)
		{
			string token = tokens[i];
			if (token == "(")
			{

			}
		}
	}
	void test2()
	{
		string infixStr1("10 + 2 * 6");
		evaluateInfix(infixStr1);

		string infixStr2("100 * 2 + 12");
		evaluateInfix(infixStr2);

		string infixStr3("100 * ( 2 + 12 )");
		evaluateInfix(infixStr3);

		string infixStr4("100 * ( 2 + 12 ) / 14");
		evaluateInfix(infixStr4);
	}
}

//int main_28_Expression()
int main()
{
	NS_28::test1();
	return 0;
}