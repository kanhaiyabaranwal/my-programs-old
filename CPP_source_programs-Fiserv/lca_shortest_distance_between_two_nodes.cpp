#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int dat,Node* lef=NULL,Node* righ=NULL):data(dat),left(lef),right(righ) {}
 } ;
void InOrderTraversal(Node *n)
{
	if(n->left)
		InOrderTraversal(n->left);
	if(n)
		cout<<n->data<<"\t";
	if(n->right)
		InOrderTraversal(n->right);
	return ;
}
void PreOrderTraversal(Node *n)
{
	if(n)
		cout<<n->data<<"\t";
	if(n->left)
		PreOrderTraversal(n->left);
	if(n->right)
		PreOrderTraversal(n->right);
	return ;
}
void BFT(Node* n)
{
	queue<Node*> q;
	q.push(n);
	Node *temp;
	while(q.size())
	{
		temp=q.front();
		cout<<temp->data<<",";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
		q.pop();
	}
	return ;
}

Node* FindLCA(Node* root,int d1,int d2)
{
	if(root->data==d1 || root->data==d2)
		return root;
	Node* left=NULL,*right=NULL;
	if(root->left)
		left=FindLCA(root->left,d1,d2);
	if(root->right)
		right=FindLCA(root->right,d1,d2);
	if(left&&right)
		return root;
	if(left)
		return left;
	if(right)
		return right;
	
	return NULL;
}
bool FindNodeDepth(Node* root, int d1,int &depth)
{
	if(!root)
		return false;
	if(root->data==d1)
	{
		return true;
	}
	if(FindNodeDepth(root->left,d1,depth))
	{
		depth++;
		return true;
	}
	else if(FindNodeDepth(root->right,d1,depth))
	{
		depth++;
		return true;
	}
	return false;

}
int main()
{
	Node *n1= new Node(8);
	Node *n2= new Node(9);
	Node* n3=new Node(4,n1,n2);
	n1=new Node(10);
	n2=new Node(11);
	Node* n4=new Node(5,NULL,n1);
	n1=new Node(6,NULL,n2);
	n2=new Node(2,n3,n4);
	n3=new Node(12);
	n4=new Node(13);
	Node *n5=new Node(7,n3,n4);
	Node *n6=new Node(3,n1,n5);
	n3=new Node(1,n2,n6);
	Node *root=n3;
	cout<<"calling InOrderTraversal"<<endl;
	InOrderTraversal(root);
	cout<<endl;
	cout<<"calling PreOrderTraversal"<<endl;
	PreOrderTraversal(root);
	cout<<endl;
	cout<<"calling BFT"<<endl;
	BFT(root);
	cout<<endl;
	int d1=8,d2=7;
	cout<<"Find LCA of data 8 and 7"<<endl;
	Node* lca=FindLCA(root,d1,d2);
	cout<<"LCA is " <<lca->data<<endl;
	int depth1=0,depth2=0;
	FindNodeDepth(lca,d1,depth1);
	FindNodeDepth(lca,d2,depth2);
	cout<<"Distance between 8 and 7 is "<<depth1+depth2<<endl;
	return 0;
}
	
