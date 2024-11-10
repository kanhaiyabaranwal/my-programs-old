//Remove duplicate node from an unsorted linked list
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<map>
#include<utility>
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
	map<int,Node*> mymap;
	mymap.insert(make_pair(head->num,head));
	cur=head->next;
	Node *prev=head;
	while(cur)
	{
		if(mymap.find(cur->num)!=mymap.end())
		{
			cout<<"duplicate entry for "<<cur->num<<"\n";
			//duplicate entry found,remove it
			prev->next=cur->next;
			temp=cur;
			cur=cur->next;
			delete temp;
		}
		else
		{
			mymap.insert(make_pair(cur->num,cur));
			prev=cur;
			cur=cur->next;
		}
	}
	cur=head;
	cout<<"Linked list after removing duplicates"<<endl;
	while(cur)
	{
		cout<<cur->num<<"\t";
		cur=cur->next;
	}
	cout<<endl;
	
	return 0;
}
		
	
