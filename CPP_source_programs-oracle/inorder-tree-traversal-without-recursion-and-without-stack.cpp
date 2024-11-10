#include<iostream>

using namespace std;

struct node{
	int val;
	node* left;
	node* right;
	node(int v,node* l=NULL,node* r=NULL): val(v),left(l),right(r){
	}
};

void inorder_tree_traversal_without_recursion_and_without_stack(node* root)
{
	node* cur=root;
	while(cur)
	{
		if(!cur->left)
		{
			cout<<cur->val<<",";
			cur=cur->right;
		}
		else
		{
			node* pre=cur->left;
			while(pre->right!=NULL && pre->right!=cur)
			{
				pre=pre->right;
			}
			if(pre->right==NULL)
			{
				pre->right=cur;
				cur=cur->left;
			}
			else 	//pre->right==cur
			{
				pre->right=NULL;
				cout<<cur->val<<",";
				cur=cur->right;
			}
		}
	}
}

int main()
{
	node* root=new node(20,new node(8,new node(4,new node(1),new node(5)),new node(12)),new node(22,new node(21),new node(25)));
	inorder_tree_traversal_without_recursion_and_without_stack(root);
	return 0;
}
