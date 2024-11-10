#include<iostream>
using namespace std;

struct node{
	int val;
	node* next;
	node* prev;
	node(int val,node* prev=NULL,node* next=NULL):val(val),prev(prev),next(next){
	}
};

node* DLL2BalancedBST(node* begin,node* end) 
{
	cout<<"Begin:"<<begin->val<<",End:"<<end->val<<endl;
	if(begin==end)
	{
		begin->prev=begin->next=NULL;
		return begin;
	}
	if(begin->next==end)
	{
		begin->prev=begin->next=NULL;
		end->next=NULL;
		return end;
	}
	node* nbegin=begin,*nend=end;
	while(nbegin!=nend)
	{
		nbegin=nbegin->next;
		if(nbegin==nend)
			break;
		nend=nend->prev;
	}
	node* mid=nbegin;
	node* lnode=DLL2BalancedBST(begin,mid->prev);
	node* rnode=DLL2BalancedBST(mid->next,end);
	mid->prev=lnode;
	mid->next=rnode;
	return mid;
}
void print(node* root)
{
	cout<<"Printing value in forward direction: ";
	while(root->next)
	{
		cout<<root->val<<",";
		root=root->next;
	}
	cout<<root->val<<endl;
	cout<<"Printing value in backward direction: ";
	while(root->prev)
	{
		cout<<root->val<<",";
		root=root->prev;
	}
	cout<<root->val<<endl;
}
void InorderTraversal(node* root)
{
	if(!root)
		return ;
	if(root->prev)
		InorderTraversal(root->prev);
	cout<<root->val<<",";
	if(root->next)
		InorderTraversal(root->next);
}


int main()
{
	node* first=new node(1);
	node* begin=first;
	node* second=new node(2);
	node* third=new node(3);
	first->next=second;
	second->next=third;
	second->prev=first;
	third->prev=second;
	first=new node(4);
	second=new node(5);
	third->next=first;
	first->prev=third;
	first->next=second;
	second->prev=first;
	third=new node(6,second);
	second->next=third;
	first=new node(7,third);
	third->next=first;
	second=new node(8,first);
	first->next=second;
	third=new node(9,second);
	second->next=third;
	node* end=third;
	print(begin);
	cout<<"Creating Balanced BST from DLL"<<endl;
	node* root=DLL2BalancedBST(begin,end);
	cout<<"Inorder Traversal is: ";
	InorderTraversal(root);
	return 0;
}
