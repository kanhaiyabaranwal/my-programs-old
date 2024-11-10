//reverse a linked list in-place
#include<iostream>
using namespace std;

struct Node{
	int dat;
	Node* next;
	Node(int dat,Node* n=NULL):dat(dat),next(n) {}
};

Node* reverseUtil(Node* l,Node* &nh)
{
	Node* r;
	if(l->next)
	{
		r=reverseUtil(l->next,nh);
		r->next=l;
	}
	else
		nh=l;
	r=l;
	return r;
}

Node* reverseLL(Node* head)
{
	Node* new_head;
	reverseUtil(head,new_head);
	head->next=NULL;
	return new_head;
}

void printLL(Node *head)
{
	Node* n=head;
	while(n)
	{
		cout<<n->dat<<",";
		n=n->next;
	}
	cout<<endl;
}
		

int main()
{
	Node* head=new Node(4,new Node(5,new Node(6,new Node(7))));
	printLL(head);
	Node* new_head=reverseLL(head);
	printLL(new_head);
	return 0;
}
	
