/*
http://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
http://www.geeksforgeeks.org/iterative-tower-of-hanoi/

Program for Tower of Hanoi
------------------------------
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack
i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.
*/
#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

namespace NS91
{

	inline void move_between(stack<int>& s1, char c1, stack<int>& s2, char c2)
	{
		int top1 = s1.empty() ? INT_MAX : s1.top();
		int top2 = s2.empty() ? INT_MAX : s2.top();
		if (top1 < top2)
		{
			int n = s1.top(); s1.pop();
			s2.push(n);
			cout << "move disc " << n << " from " << c1 << " to " << c2 << endl;
		}
		else
		{
			int n = s2.top(); s2.pop();
			s1.push(n);
			cout << "move disc " << n << " from " << c2 << " to " << c1 << endl;
		}
	}
	//iterative method
	void towerOfHanoi_I(int n, char from_rod, char to_rod, char aux_rod)
	{
		stack<int> from_stack;
		stack<int> to_stack;
		stack<int> aux_stack;

		for (int i = n; i >= 1; i--)
			from_stack.push(i);

		int totalMove = pow(2, n) - 1;
		for (int i = 1; i <= totalMove; i++)
		{
			switch (i % 3)
			{
			case 1: // first move
				move_between(from_stack, from_rod, to_stack, to_rod);
				break;
			case 2: // second move
				move_between(from_stack, from_rod, aux_stack, aux_rod);
				break;
			case 0: // third move
				move_between(aux_stack, aux_rod, to_stack, to_rod);
				break;
			default:
				break;
			}
		}
	}

	void towerOfHanoi_R(int n, char from_rod, char to_rod, char aux_rod)
	{
		if (n == 1)
		{
			cout << "move disc " << n << " from " << from_rod << " to " << to_rod << endl;
			return;
		}
		towerOfHanoi_R(n - 1, from_rod, aux_rod, to_rod);
		cout << "move disc " << n << " from " << from_rod << " to " << to_rod << endl;
		towerOfHanoi_R(n - 1, aux_rod, to_rod, from_rod);
	}
	void test()
	{
		int n = 3;
		cout << "Recursive Method : \n";
		towerOfHanoi_R(n, 'A', 'B', 'C');
		cout << "\n Iterative Method : \n";
		towerOfHanoi_I(n, 'A', 'B', 'C');
		cout << endl;
	}
}

int main_091()
//int main()
{
	NS91::test();
	return 0;
}