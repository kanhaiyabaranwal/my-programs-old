#include<iostream>
#include<queue>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
	node(int v,node* l=0,node* r=0):val(v),left(l),right(r){
	}
};

bool check_if_a_given_binary_tree_is_complete_tree_or_not(node * root)
{
	node *dummy=0;
	queue<node*> q;
	q.push(root);
	q.push(dummy);
	node *front=q.front();
	bool levelChanged=false;
	bool endOfCompleteBinaryTree=false;
	while(q.size()>1)
	{
		front=q.front();
		q.pop();
		if(front==0)
		{
			levelChanged=true;
			front=q.front();
			q.pop();
			q.push(dummy);
		}
		else
		{
			if(endOfCompleteBinaryTree && (front->left || front->right))
				return false;
			levelChanged=false;
		}
			
		if(front->left)
		{
			if(endOfCompleteBinaryTree==true)
				return false;
			q.push(front->left);
		}
		else
			endOfCompleteBinaryTree=true;
		if(front->right)
		{
			if(endOfCompleteBinaryTree==true)
				return false;
			q.push(front->right);
		}
	}
	return true;
}

int main()
{
	node *root=new node(1,new node(2,new node(4),new node(5)),new node(3,new node(7),new node(6)));
	bool res=check_if_a_given_binary_tree_is_complete_tree_or_not(root);
	cout<<"check-if-a-given-binary-tree-is-complete-tree-or-not: "<<res<<endl;
}
