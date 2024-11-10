#include<iostream>
using namespace std;

struct Node{
	int num;
	Node* left;
	Node* right;
	int IsLeaf;
	Node(int n,bool isleaf=false):num(n),IsLeaf(isleaf),left(NULL),right(NULL) {}
};
bool IsSumTree(Node *root)
{
	if(!root->left && !root->right)
		return true;
	int sumleft=0,sumright=0;
	if(root->left)
	{
		if(IsSumTree(root->left))
		{
			if(root->left->IsLeaf)
				sumleft=root->left->num;
			else
				sumleft=2*root->left->num;
		}
		else
			return false;
	}
	if(root->right)
	{
		if(IsSumTree(root->right))
		{
			if(root->right->IsLeaf)
				sumright=root->right->num;
			else
				sumright=2*root->right->num;
		}
		else
			return false;
	}
	int sum=sumleft+sumright;
	if(root->num==sum)
		return true;
	else
		return false;
}
int main()
{
	Node* root=new Node(28);
	root->left=new Node(11);
	root->right=new Node(4);
	root->left->left=new Node(5,true);
	root->left->right=new Node(6,true);
	root->right->right=new Node(2);
	root->right->right->left=new Node(2,true);
	if(IsSumTree(root))
		cout<<"Tree is a sum tree"<<endl;
	else
		cout<<"Tree is not a sum tree"<<endl;
	return 0;

}
	
