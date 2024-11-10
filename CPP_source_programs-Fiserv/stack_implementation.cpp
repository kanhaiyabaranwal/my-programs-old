#include<iostream>
using namespace std;
//stack of integers first, then generalize it
class stack{
	int *arr;
	int index;
	public:
	stack(int size=100):index(0) {
		arr=new int[size];
	}
	void push(int i)
