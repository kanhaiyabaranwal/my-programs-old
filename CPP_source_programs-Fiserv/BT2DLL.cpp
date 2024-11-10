//Binary to DLL conversion
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int nbr,Node *l=NULL,Node* r=NULL):data(nbr),left(l),right(r)	{}
};

Node* DLLConversion(Node *root)
{
	Node* cur,*curright,*rootleft,*rootright;
	if(!root->left && !root->right)
		return root;
	cur=NULL;
	curright=NULL;
	rootleft=NULL;
	rootright=NULL;
	if(root->left)
	{
		cout<<root->data<<"\t";
		cur=DLLConversion(root->left);
		rootleft=root->left;
	}	
	if(root->right)
	{
		rootright=root->right;
		if(cur)
		{
			cur->right=rootright;
			curright=DLLConversion(rootright);
			rootright->left=cur;
			root->right=rootleft;
			rootleft->left=root;
			cur=curright;
		}
		else
		{
			curright=DLLConversion(rootright);
			root->right=rootright;
			rootright->left=root;
			cur=curright;
		}
	}
	return cur;
}

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

int main()
{
	//Binary Tree
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
	cout<<"DLL conversion"<<endl;
	Node* cur=root;
	Node* head=DLLConversion(root);
	//Node* cur=root1;
	while(cur)
	{
		cout<<cur->data<<"\t";
		cur=cur->right;
	}
	return 0;
}
