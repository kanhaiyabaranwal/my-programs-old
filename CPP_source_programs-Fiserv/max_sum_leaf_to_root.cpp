#include<iostream>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
	node(int val,node* l=NULL,node* r=NULL):val(val),left(l),right(r) {}
};

node* max_path(node* root, int &max_val)
{
	node* lnode,*rnode;
	int lval=0,rval=0;
	
	if(!root)
		return NULL;
	if(root)
		max_val=root->val;
	if(root->left)
		lnode=max_path(root->left,lval);
	if(root->right)
		rnode=max_path(root->right,rval);
	if(!lval && !rval)
		return root;	
	if(lval>rval)
	{
		max_val+=lval;
		return lnode;
	}
	else
	{
		max_val+=rval;
		return rnode;
	}
}

void preorder_traversal(node* root)
{
	if(!root)
		return;
	if(root)
		cout<<root->val<<",";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
	return;
}


int main()
{
	node* root=new node(10,new node(-2,new node(8,new node(4),new node(-1)),new node(-4,new node(6),new node(17))),new node(7,new node(5,NULL,new node(16)),new node(-1,NULL,new node(11))));
	cout<<"Pre order traversal of the tree is:";
	preorder_traversal(root);
	cout<<endl;
	int max_val=0;
	node* leaf=max_path(root,max_val);
	cout<<"leaf node with max path is "<<leaf->val<<", and max value is "<<max_val<<endl;
	return 0;
}	
	
