#include<iostream>
using namespace std;
#define LEFT 0
#define RIGHT 1
struct Node{
	int num;
	Node* left;
	Node* right;
	Node(int n,Node* l=NULL,Node* r=NULL):num(n),left(l),right(r) {}
};

void InorderTraversal(Node *root)
{
	if(root->left)
		InorderTraversal(root->left);
	cout<<root->num<<"\t";
	if(root->right)
		InorderTraversal(root->right);
	return;
}

int longestchain(Node *root,int type)
{
	static int longest=1;
	int lenleft=0,lenright=0;
	if(!root)
		return 0;
	if(root->left)
		lenleft=longestchain(root->left,LEFT);
	if(root->right)
		lenright=longestchain(root->right,RIGHT);
	if(longest < lenleft+lenright+1)
	{
		longest=lenleft+lenright+1;
		cout<<"Longer chain found of length "<<longest<<" with node "<<root->num<<endl;
	}
	if(type==LEFT)
		return lenleft+1;
	else if(type==RIGHT)
		return lenright+1;
	else
		return -1;
}

int main()
{
	Node* root=new Node(1);
	Node* left,*right;
	left=root->left=new Node(2);
	right=left->right=new Node(5);
	right=right->right=new Node(10);
	right=right->right=new Node(11);
	right=right->right=new Node(12);
	
	left=left->left=new Node(4);
	left->left=new Node(8);
	left->right=new Node(9);
	
	right=root->right=new Node(3);
	right->left=new Node(6);
	right->right=new Node(7);
	cout<<"Now inorder traversal"<<endl;
	InorderTraversal(root);
	cout<<endl;
	cout<<"Longest chain node"<<endl;
	longestchain(root, LEFT);
	cout<<endl;

	return 0;
}
	
