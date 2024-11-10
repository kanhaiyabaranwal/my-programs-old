//Program to connect nodes at same level using 3rd pointer nextRight
#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int num;
	Node* left;
	Node* right;
	Node* nextRight;
	Node(int n,Node *l=NULL,Node* r=NULL):num(n),left(l),right(r) {
	}
};

void InorderTraversal(Node *root)
{
	if(root->left)
		InorderTraversal(root->left);
	//print data
	cout<<root->num<<" ";
	/*if(root->left)
		cout<<", root->left="<<root->left->num;
	else
		cout<<", Left child does not exist";
	if(root->right)
		cout<<", root->right="<<root->right->num;
	else
		cout<<", Right child does not exist";
	if(after)
	{
		if(root->nextRight)
			cout<<", root->nextRight="<<root->nextRight->num;
		else
			cout<<", nextRight does not exist";
	}
	cout<<endl;*/
	if(root->right)
		InorderTraversal(root->right);
}
void PreorderTraversal(Node *root)
{
	cout<<root->num<<" ";
	if(root->left)
		PreorderTraversal(root->left);
	
	if(root->right)
		PreorderTraversal(root->right);
}

void swap(int& a,int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

void createBST(Node * root)
{
	if(root->left)
		createBST(root->left);
	if(root->right)
		createBST(root->right);
	if(root->left && root->left->num > root->num)
		swap(root->left->num,root->num);
	if(root->right && root->right->num < root->num)
		swap(root->right->num,root->num);
	return;
}

int main()
{
	cout<<"Program to connect nodes at same level"<<endl;
	Node *root=new Node(1,new Node(2,new Node(4),new Node(5)),new Node(3,new Node(6),new Node(7)));
	//Node *temp=new Node(2,r)
	cout<<"Inorder traversal: ";
	InorderTraversal(root);
	cout<<endl;
	cout<<"Preorder traversal: ";
	PreorderTraversal(root);
	cout<<endl;
	createBST(root);
	cout<<"Inorder traversal after creating BST: ";
	InorderTraversal(root);
	cout<<endl;
	return 0;
}

