#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define NUM 5


struct Node{
	int data;
	Node* next;
	Node(int num,Node* n=NULL):data(num),next(n) { 	}
};

int main()
{
	Node* root1,*root2,*root,*temp,*cur;
	srand(time(NULL));
	int count=0;
	root1=root2=temp=cur=NULL;
	while(count<2)
	{
		cout<<"Creating LL#"<<count+1<<endl;
		int limit=NUM-count;
		root=NULL;
		for(int i=0;i<limit;i++)
		{
			temp=new Node(rand()%10+i*10);
			if(!root)
				root=temp;
			else
				cur->next=temp;
			cur=temp;
		}
		
		if(count==0)
			root1=root;
		else
			root2=root;
		count++;
		
	}
	cout<<"LL1=";
	cur=root1;
	while(cur)
	{
		cout<<cur->data<<",";
		cur=cur->next;
	}
	cout<<endl;
	cout<<"LL2=";
	cur=root2;
	while(cur)
	{
		cout<<cur->data<<",";
		cur=cur->next;
	}
	//merging 2 LL
	Node* back1=NULL,*cur1=root1,*cur2=root2;
	root=root1;
	cout<<"Mergin 2 LL"<<endl;
	while(cur2 )
	{
		cout<<"cur2->data="<<cur2->data<<",cur1->data="<<cur1->data<<endl;
		if(cur2->data < cur1->data)
		{
			if(!back1)
				root=back1=cur2;
			else
			{
				back1->next=cur2;
				back1=cur2;
			}
			cur2=cur2->next;
			back1->next=cur1;
		}
		else
		{
			if(cur1)
			{
				back1=cur1;
				cur1=cur1->next;
			}
			else
			{
				cur1->next=cur2;
				break;
			}
		}
	}
	cout<<endl;
	cout<<"merged LL=";
	cur=root;
	while(cur)
	{
		cout<<cur->data<<",";
		cur=cur->next;
	}
	cout<<endl;
	return 0;
	
	
}
