//calculates sum of each path from root to all leaf nodes
#include<iostream>
using namespace std;

struct Node{
	int num;
	Node* left;
	Node* right;
	int IsLeaf;
	Node(int n,bool isleaf=false):num(n),IsLeaf(isleaf),left(NULL),right(NULL) {}
};
void sumofpath(Node *root,int sum)
{
	if(!root->left && !root->right)
		cout<<"path until leaf "<<root->num<<"="<<sum+root->num<<endl;
	if(root->left)
		sumofpath(root->left,sum+root->num);
	if(root->right)
		sumofpath(root->right,sum+root->num);
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
	int sum=0;
	sumofpath(root,sum);
	return 0;

}
	
