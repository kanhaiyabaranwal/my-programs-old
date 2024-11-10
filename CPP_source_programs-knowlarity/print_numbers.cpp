#include<iostream>
using namespace std;

struct node{
	int val;
	node* next;
	node(int val,node* next=NULL):val(val),next(next) {}
};


void print_numbers ()
{
	char *arr[5]={"one","two","three","four","five"};
	node* root=new node(1,new node(2,new node(3,new node(4,new node(5)))));
	while(root)
	{
		cout<<root->val<<"="<<arr[root->val-1]<<endl;
		root=root->next;
	}
	return;
}
int main()
{

	print_numbers ();
	return 0;
}
