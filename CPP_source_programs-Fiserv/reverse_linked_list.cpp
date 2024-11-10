#include<iostream>
using namespace std;

struct node{
        int n;
        node* next;
        node(int n,node* next=NULL):n(n),next(next) {}
};

node* reverse_linked_list(node* head)
{
        if(!head || !head->next)
                return head;
        node* cur=head->next,*prev=head;
	prev->next=NULL;
	int count=1;
	node* curhead=head;
        while(cur)
        {
		if(count%4!=0)
		{
	                node* next=cur->next;
	                cur->next=prev;
	                prev=cur;
	                cur=next;
	        }
		else	//
		{
			prevhead=curhead;
			curhead=cur;
		}
	}
        return prev;
}
int main()
{
        node *head=new node(1,new node(2,new node(3,new node(4,new node(5)))));
        node* cur=head;
	cout<<"Linked List is :";
        while(cur)
        {
                cout<<cur->n<<",";
                cur=cur->next;
        }
        cur=reverse_linked_list(head);
	cout<<"Reversed linked List is :";
        while(cur)
        {
                cout<<cur->n<<",";
                cur=cur->next;
        }
	cout<<endl;
        return 0;
}
