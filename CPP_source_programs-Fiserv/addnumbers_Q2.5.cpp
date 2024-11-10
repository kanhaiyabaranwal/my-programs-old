//CTCI: add numbers where numbers are represented through LL with each digit in one node
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stack>
using namespace std;
#define NUM 4

struct Node{
	int num;
	Node *next;
	Node(int nbr,Node* n=NULL):num(nbr),next(n) {}
};
int sum(Node *l1,Node *l2,stack<int> *s)
{
	if(l1==NULL && l2==NULL)
		return 0;
	if(l1==NULL || l2==NULL)
		return -1;
	int prevcarry=sum(l1->next,l2->next,s);
	int val=(l1->num+l2->num)%10+prevcarry;
	s->push(val);	
	int carry=(l1->num+l2->num)/10;
	//cout<<val;
	return carry;
}

int main()
{
	srand(time(NULL));
	Node *temp,*cur,*head,*head1=NULL,*head2=NULL;
	cur=head=head1;
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
	}
	cur=head1=head;
	while(cur)
	{
		cout<<cur->num<<"\t";
		cur=cur->next;
	}
	cout<<endl;
	
	cur=head=head2;
	cout<<"Num2 is ";
	for(int i=0;i<NUM;i++)
	{
		temp=new Node(rand()%10);
		if(!head)
			head=temp;
		else
			cur->next=temp;
		cur=temp;
	}
	cur=head2=head;
	while(cur)
	{
		cout<<cur->num<<"\t";
		cur=cur->next;
	}
	cout<<endl;
	cout<<"head1="<<head1->num<<",head2="<<head2->num<<endl;
	cout<<"Sum of numbers ->";
	stack<int> *s=new stack<int>;
	int carry=sum(head1,head2,s);
	if(carry)
		s->push(carry);
	while(s->size()>0)
	{
		cout<<s->top();
		s->pop();
	}
	cout<<endl;
	
	
	return 0;
}
