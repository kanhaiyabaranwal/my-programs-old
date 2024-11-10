#include<iostream>
using namespace std;

struct node{
	int n;
	node* next;
	node(int n,node* next=NULL):n(n),next(next){
	}
};

node* reverse_ll(node* root)
{
	node *cur=root,*prev=NULL,*next=cur->next;
	while(cur)
	{
		cur->next=prev;
		//now go to next node
		prev=cur;
		cur=next;	
		if(cur)
			next=cur->next;
	}
	return prev;
}
node* kblock_reverse_ll(node* root,int k=3)
{
	node *cur=root,*prev=NULL,*next=cur->next;
	node* head1=NULL,*head2=NULL,*newroot=NULL;
	int count=1;
	while(cur)
	{
		if(count==k)
			newroot=cur;
		if(count%k==1)
		{
			if(head2)
				head1=head2;
			else
				head1=cur;
			head2=cur;
		}
		if(count%k==0)
			head1->next=cur;
		
		cur->next=prev;
		//now go to next node
		prev=cur;
		cur=next;
		if(cur)
			next=cur->next;
		count++;
	}
	count--;
	if(count%k!=0)
		head1->next=prev;
	prev->next=NULL;
	return newroot;
}


int main()
{
	node* root=new node(1,new node(2,new node(3,new node(4,new node(5,new node(6,new node(7)))))));
	node* cur=root;
	cout<<"Linked list is :";
	while(cur)
	{
		cout<<cur->n<<",";
		cur=cur->next;
	}
	cout<<endl;
	//cur=reverse_ll(root);
	cur=kblock_reverse_ll(root,3); 
	cout<<"Reversed Linked list in blocks of 3 is :";
	int i;
	while(cur)
	{
		cout<<cur->n<<",";
		cur=cur->next;
		//cin>>i;
	}
	cout<<endl;
	
	return 0;
}
