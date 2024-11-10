#include <iostream>
using namespace std;

typedef struct node{
	int dat;
	node* next;
	node(int n):dat(n),next(0) {}
};
int main()
{
	node *first=new node(0);
	int n;
	cout<<"No. of nodes you want\t";
	cin>>n;
	node *cur=first;
	node *prev=first;
	for(int i=1;i<=n;i++)
	{
		node *temp=new node(i);
		cur->next=temp;
		prev=cur;
		cur=temp;
	}		
	//creating a circular list
	cur->next=first;
	cur=first;
	cout<<"values in the linked list are\n";	
	cout<<cur->dat<<"\t";
	do
	{
		cur=cur->next;
		cout<<cur->dat<<"\t";
	}while(cur->next !=NULL && cur->next!=first);
	//evaluate if it's a circular list or not
	node* cur1=first->next->next;	//this node should move two times
	node* cur2=first;	//this node moves one time only
	
	while(cur2 && cur1)
	{
		if (cur2==cur1)
		{
			cout<<"circular list found\n";
			return 0;
		}
		cur1=cur1->next->next;	
		cur2=cur2->next;
	}
	cout<<"No. Circular list does not exist.\n";
	return 0;
}
