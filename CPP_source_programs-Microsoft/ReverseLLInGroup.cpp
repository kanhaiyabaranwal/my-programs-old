#include<iostream>
#include<stack>
using namespace std;
//Reverse a Linked List in groups of given size.

struct node{
	int val;
	node* next;
	node(int v,node* n=NULL):val(v),next(n){
		
	}
};

struct FirstLast{
	node* first;
	node* last;
	node* next;
	FirstLast(node* first=NULL,node* last=NULL,node* next=NULL):first(first),last(last),next(next){
	}
};

FirstLast ReverseKNode(node* root, int k)
{
	FirstLast firstlast;
	firstlast.last=root;
	int count=0;
	node* cur=root, *prev=NULL,*next=NULL;
	while(count<k && cur)
	{
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
		count++;
	}
	firstlast.first=prev;
	firstlast.next=cur;
	return firstlast;
}
node* ReverseLLinGroup(node* root, int k)
{
	FirstLast oldfirstlast;
	FirstLast firstlast;
	node* cur=root, *newroot;
	while(cur)
	{
		firstlast=ReverseKNode(cur,k);
		if(oldfirstlast.first==NULL)
			newroot=firstlast.first;
		else
		{
			oldfirstlast.last->next	=firstlast.first;
			
		}
		cur=firstlast.next;
		oldfirstlast = firstlast;
	}
	return newroot;
}

node* ReverseLLInGroupUsingStack(node* root, int k)
{
	stack<int> stk;
	node* cur=root;
	int count=0;
	while(cur)
	{
		node* first=cur;
		stk.empty();
		count=0;
		while(count<k && cur)
		{
			stk.push(cur->val);
			cur=cur->next;
			count++;
		}
		cur=first;
		count=0;
		while(count<k && cur)
		{
			int top=stk.top();
			cur->val=top;
			stk.pop();
			cur=cur->next;
			count++;
		}
	}
	return root;
}

void printLL(node* root)
{
	while(root)
	{
		cout<<root->val<<",";
		root=root->next;
	}
	cout<<endl;
}
int main()
{
	node* root= new node(1,new node(2,new node(3,new node(4,new node(5,new node(6,new node(7,new node(8,new node(9,new node(10))))))))));
	cout<<"Old root is "<<root->val<<endl;
	printLL(root);
	root = ReverseLLInGroupUsingStack(root,3);
	cout<<"New root is "<<root->val<<endl;
	printLL(root);
	
}
