//Check if a tree is balanced or not
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	int h;		//height
	Node(int dat,Node* lef=NULL,Node* righ=NULL):data(dat),left(lef),right(righ),h(1) {}
 } ;
void InOrderTraversal(Node *n)
{
	if(n)
		cout<<n->data<<"\t";
	if(n->left)
		InOrderTraversal(n->left);
	if(n->right)
		InOrderTraversal(n->right);
	return ;
}
void BFT(Node* n)
{
	queue<Node*> q;
	q.push(n);
	Node* dummy=new Node(-1);
	q.push(dummy);
	Node *temp;
	int level=1;
	cout<<"Level "<<level<<": ";
	while(q.size()>1)
	{
		temp=q.front();
		if(temp->data==-1)
		{
			level++;
			cout<<endl<<"Level "<<level<<": ";
			q.push(dummy);
		}
		else
		{
			cout<<temp->data<<",";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
		}
		q.pop();
	}
	return ;
}

int height(Node* root)
{
	if(!root)
		return 0;
	return root->h;
}	

Node* left_case(Node* root,Node* parent)
{
	//do right rotation if left-right case
	if(height(root->left->right) > height(root->left->left))
	{
		Node* newroot=root->left->right;
		root->left->right=root->left->right->left;
		newroot->left=root->left;
		root->left=newroot;
		//right_case(root->left,root);
	}
	//now do left rotation
	Node* newroot=root->left;
	root->left=newroot->right;
	newroot->right=root;
	if(parent)
	{
		parent->left=newroot;
		return parent;
	}
	else
		return newroot;
}
Node* right_case(Node* root,Node* parent)
{
	//do left rotation of right child if right-left case
	if(height(root->right->left) > height(root->right->right))
	{
		Node* newroot=root->right->left;
		root->right->left=root->right->left->right;
		newroot->right=root->right;
		root->right=newroot;
	}	
	//left_case(root->right,root);
	//now do right rotation
	Node* newroot=root->right;
	root->right=newroot->left;
	newroot->left=root;
	if(parent)
	{
		parent->right=newroot;
		return parent;
	}
	else
		return newroot;
}
	

Node* DoBalance(Node* root,Node* parent=NULL)
{
	int h1=height(root->left);
	int h2=height(root->right);
	if(h1>h2+1)
		root=left_case(root,parent);
	if(h1+1<h2)
		root=right_case(root,parent);
	return root;
}
int max(int h1,int h2)
{
	return h1>h2?h1:h2;
}
Node* insert(Node* root,int data)
{
	if(root->data > data)
	{
		if(root->left)
			insert(root->left,data);
		else
			root->left=new Node(data);
	}
	else
	{
		if(root->right)
			insert(root->right,data);
		else
			root->right=new Node(data);
	}
	//update height
	root->h=max(height(root->left),height(root->right))+1;
	//Now Balance,get new root if changed
	root=DoBalance(root);
	return root;
}
	

int main()
{
	Node *root=new Node(10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,40);
	root=insert(root,50);
	root=insert(root,25);
	
	cout<<"calling InOrderTraversal"<<endl;
	InOrderTraversal(root);
	cout<<endl;
	cout<<"calling BFT"<<endl;
	BFT(root);
	cout<<endl;
	return 0;
}
	
