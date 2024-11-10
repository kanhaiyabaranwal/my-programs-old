#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct node{
	int val;
	node* left;
	node* right;
	node(int v,node* l=NULL,node* r=NULL):val(v),left(l),right(r){
	}
};

void InorderTraversal(node* root, deque<int> & dq)
{
	if(!root)
		return;
	InorderTraversal(root->left,dq);
	cout<<root->val<<",";
	dq.push_back(root->val);
	InorderTraversal(root->right,dq);
}

void InorderPopulate(node* root, deque<int> & dq)
{
	if(!root)
		return;
	InorderPopulate(root->left,dq);
	if(dq.empty())
	{
		cout<<"Fatal error, deque can't be empty"<<endl;
		return;
	}
	root->val=dq.front();
	dq.pop_front();
	//cout<<root->val<<",";
	InorderPopulate(root->right,dq);
	
}
binary_tree_to_binary_search_tree_conversion(node* root)
{
	deque<int> dq;
	cout<<"Inorder Traversal of BT: ";
	InorderTraversal(root,dq);
	cout<<endl;
	sort(dq.begin(),dq.end());
	InorderPopulate(root,dq);
	cout<<"Inorder Traversal of BST: ";
	InorderTraversal(root,dq);
}



int main()
{
	node* root=new node(10,new node(2,new node(8),new node(4)),new node(7));
	binary_tree_to_binary_search_tree_conversion(root);
	return 0;
}
