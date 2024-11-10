#include<iostream>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int v,Node* l=NULL,Node* r=NULL):val(v),left(l),right(r){
	
	}
};

void Preorder(Node* root){
	if(root==NULL)
		return;
	cout<<root->val<<"\t";
	Preorder(root->left);
	Preorder(root->right);
}
Node* CreateDLL(Node* root){
	Node* right=root->right;
	root->right=NULL;
	Node* leftend=NULL;
	if(root->left)
	{
		leftend=CreateDLL(root->left);
		root->left->right=root;
		if(right)
		{
			leftend->right=right;
			Node* rightend = CreateDLL(right);
			right->right=leftend;
			return rightend;
		}
		else
			return leftend;
	}
	if(right)
	{
		Node* rightend = CreateDLL(right);
		right->left=root;
		return rightend;
	}
	return root;
}
DLLTraversal(Node* root){
	int in;
	while(root){
		cout<<root->val<<"\t";
		if(root->left)
			cout<<"left is "<<root->left->val<<"\n";
		if(root->right)
			cout<<"right is "<<root->right->val<<"\n";
		root=root->right;
		cin>>in;
	}
	cout<<endl;
}

int main()
{
	Node* root=new Node(10,new Node(12,new Node(25),new Node(30)),new Node (15,new Node(36)));
	Preorder(root);
	cout<<endl;
	Node* DLLRoot= CreateDLL(root);
	DLLTraversal(DLLRoot);
	return 0;
}
