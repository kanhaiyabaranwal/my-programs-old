//2.6 CTCI: Given a circular linked list, implement an algorithm which returns the node at the beginning of the loop
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stack>
using namespace std;
#define NUM 11
#define CIRCLE_START 3

struct Node{
	int num;
	Node *next;
	Node(int nbr,Node* n=NULL):num(nbr),next(n) {}
};

int main()
{
	srand(time(NULL));
	Node *temp,*cur,*head,*mid=NULL;
	cur=head=NULL;
	int nbr;
	cout<<"Num1 is ";
	for(int i=0;i<NUM;i++)
	{
		temp=new Node(rand()%10);
		if(!head)
			head=temp;
		else
			cur->next=temp;
		cur=temp;
		cout<<cur->num<<" ";
		if(i==CIRCLE_START)			//keep node to create circular list
			mid=temp;
	}
	cout<<"list created\n";
	cur->next=mid;				//create circule
	cout<<"circle will start at "<<mid->num<<endl;
	cur=head;
	Node *fast=head;
	while(cur)
	{
		cout<<cur->num<<"\t";
		cur=cur->next;
		fast=fast->next->next;
		if(fast==cur)
		{
			cout<<"Circular Linked List collision point "<<cur->num<<" and "<<fast->num<<endl;
			break;
		}
	}
	cur=head;
	int count=0;
	while(true)
	{
		fast=fast->next;
		cur=cur->next;
		if(fast==cur)
		{
			cout<<"Circle starting point is "<<count<<" nodes from start of list at "<<cur->num<<endl;
			break;
		}
		else
			count++;
	}
	

	cout<<"search for beginning of circular  LL over"<<endl;
}
