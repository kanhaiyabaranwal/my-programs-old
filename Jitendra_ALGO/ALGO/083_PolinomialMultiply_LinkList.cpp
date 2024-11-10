/*

*/
#include<iostream>
using namespace std;

namespace NS83
{
	struct node
	{
		int data;
		node* next;
		node(int d) : data(d), next(NULL) {}
	};

	//TODO
	void testUsingLinkList()
	{

	}

	void testUsingArray()
	{
		int P1[] = { 1, 0, 3, 2 };
		int n1 = sizeof(P1) / sizeof(P1[0]);
		int P2[] = { 2,0,4 };
		int n2 = sizeof(P2) / sizeof(P2[0]);

		int n = (n1 - 1) + (n2 - 1) + 1; // length of result
		int* res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = 0;
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				res[i + j] += P1[i] * P2[j];
			}
		}
		for (int i = 0; i < n; i++)
			cout << res[i] << "  ";
		cout << endl;
		delete[] res;
	}
}

int main_83()
{
	NS83::testUsingArray();
	return 0;
}
