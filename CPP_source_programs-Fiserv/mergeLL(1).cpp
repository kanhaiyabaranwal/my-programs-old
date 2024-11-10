#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int val,Node* n=NULL):data(val),next(n) {}
};

void append_node(Node* &sorted,Node* &tail,Node* node)
{
	if(!sorted)
	{
		sorted=node;
		tail=node;
	}
	else
	{
		tail->next=node;
		tail=tail->next;
	}
}
void mergeLL(Node* first, Node *second, Node* &sorted)
{
	Node* tail=NULL;
	Node *node=NULL;
	while(first and second)
	{
		node=first->data<second->data? first: second;
		append_node(sorted,tail,node);
		first->data<second->data? first=first->next: second=second->next;
	}
	if(first)
		tail->next=first;
	else if(second)
		tail->next=second;
}

int main()
{
	Node* first=new Node(2,new Node(5,new Node(7,new Node(9))));
	Node* second=new Node(1,new Node(3,new Node(11)));
	cout<<"first list:";
	Node* n=first;
	while(n)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
	cout<<"second list:";
	n=second;
	while(n)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
	cout<<endl;
	Node* sorted=NULL;
	mergeLL(first,second,sorted);
	cout<<"Merged and sorted list is "<<endl;
	while(sorted)
	{
		cout<<sorted->data<<" ";
		sorted=sorted->next;
	}
	cout<<endl;
	return 0;
}



