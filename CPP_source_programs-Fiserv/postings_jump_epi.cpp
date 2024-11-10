#include<iostream>
using namespace std;

struct node{
	char val;
	node* jump;
	node* next;
	node(int val,node* jump=NULL,node* next=NULL):val(val),jump(jump),next(next){
	}
};


node* create_jump_postings(node* head)
{
	node* newhead=NULL;
	node* newcur=newhead,*cur=head;
	//create new list
	while(cur)
	{
		if(newcur)
		{
			newcur->next=new node(cur->val,cur->jump);
			newcur=newcur->next;
		}
		else
		{
			newcur=new node(cur->val,cur->jump);
			newhead=newcur;
		}
		cur->jump=newcur;
		cur=cur->next;
	}
	cur=head,newcur=newhead;
	node* temp;
	while(cur && newcur)
	{
		temp=newcur->jump;
		newcur->jump=newcur->jump->jump;
		cur->jump=temp;
		
		cur=cur->next;
		newcur=newcur->next;
	}
	return newhead;
}
void navigate(node* head)
{
	while(head)
	{
		cout<<"Current node:"<<head->val<<",jumps to"<<head->jump->val;
		if(head->next)
			cout<<",next: "<<head->next->val;
		cout<<endl;
		head=head->next;
	}
	cout<<endl;
}
int main()
{
	node* head=new node('a');
	node* node1=new node('b');
	node* node2=new node('c');
	node* node3=new node('d');
	head->jump=node2;
	head->next=node1;
	node1->jump=node3;
	node1->next=node2;
	node2->jump=node1;
	node2->next=node3;
	node3->jump=node3;
	cout<<"Navigating through the Original postings:"<<endl;
	navigate(head);
	node* newhead=create_jump_postings(head);
	cout<<"Navigating through the New postings:"<<endl;
	navigate(newhead);
	return 0;
}
