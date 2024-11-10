#include<iostream>
using namespace std;

struct node{
	int val;
	node* next;
	node(int v,node* n=NULL):val(v),next(n){
		
	}
};

node* RotateLL(node* root,int k)
{
	int count=0;
	node* nodeAhead=root;
	while(count<k && nodeAhead)
	{
		nodeAhead=nodeAhead->next;
		count++;
	}
	if(!nodeAhead)
	{
		cout<<k<<" nodes are not present. rotation not possible"<<endl;
		return NULL;
	}
	node* kthNodeFromEnd = root;
	while(nodeAhead->next)
	{
		kthNodeFromEnd=kthNodeFromEnd->next;
		nodeAhead=nodeAhead->next;
	}
	node* newroot=kthNodeFromEnd->next;
	kthNodeFromEnd->next=NULL;
	nodeAhead->next = root;
	root=newroot;
	return root;
}

int main()
{
	node* root= new node(1,new node(2,new node(3,new node(4,new node(5,new node(6))))));
	cout<<"Old root is "<<root->val<<endl;
	root = RotateLL(root,3);
	cout<<"New root is "<<root->val<<endl;
	
}


