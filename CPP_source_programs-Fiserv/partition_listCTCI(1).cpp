//Rearrange a list such that elements less than X are on the left or it otherwise on the right
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define NUM 10

struct Node{
	int num;
	Node *next;
	Node(int nbr,Node* n=NULL):num(nbr),next(n) {}
};

int main()
{
	srand(time(NULL));
	Node *temp,*cur,*head=NULL;
	cur=head;
	int nbr;
	for(int i=0;i<NUM;i++)
	{
		temp=new Node(rand()%10);
		if(!head)
			head=temp;
		else
			cur->next=temp;
		cur=temp;
	}
	cur=head;
	while(cur)
	{
		cout<<cur->num<<"\t";
		cur=cur->next;
	}
	cout<<endl;
	//pivot element=6
	int pivot=6;
	cout<<"list after partitioning list such that smaller is on the left and larger on the right"<<endl;
	cout<<"Pivot element="<<pivot<<endl;
	Node* prev=head;
	cur=head;
	Node *newhead;
	int flag=0;
	while(cur)
	{
		if(cur->num<=pivot)		//next element is smaller, needs to be moved back
		{
			if(flag)
			{
				prev->next=cur->next;
				cur->next=head;
				head=cur;
				cur=prev->next;
			}
			else
			{
				prev=cur;
				cur=cur->next;
			}
		}
		else
		{
			prev=cur;
			cur=cur->next;
			flag=1;
		}
	}
	cur=head;
	while(cur)
	{
		cout<<cur->num<<"\t";
		cur=cur->next;
	}
	cout<<endl;
	return 0;
}	
