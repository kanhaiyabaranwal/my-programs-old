//Level order traversal in reverse order
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node{
	int dat;
	node* left;
	node* right;
	node(int dat,node*left=NULL,node* right=NULL):dat(dat),left(left),right(right){
	}
};

void preorder_traversal(node* root)
{
	if(!root)
		return;
	cout<<root->dat<<",";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void inorder_traversal(node* root)
{
	if(!root)
		return;
	inorder_traversal(root->left);
	cout<<root->dat<<",";
	inorder_traversal(root->right);
}

void level_order_traverse_reversed(node* root)
{
	queue<node*> q;
	stack<int> stk;
	node* dummy=new node(-1);
	q.push(root);
	q.push(dummy);
	while(q.size()>1)
	{
		node* temp=q.front();
		if(temp->dat==-1)
			q.push(dummy);
		else
		{
			if(temp->right)
				q.push(temp->right);
			if(temp->left)
				q.push(temp->left);
			stk.push(temp->dat);
		}
		q.pop();
	}
	cout<<"Showing elements of tree in level order data in reversed order"<<endl;
	while(stk.size())
	{
		cout<<stk.top()<<",";
		stk.pop();
	}
}

int main()
{
	node* root=new node(1,new node(2,new node(4),new node(5)),new node(3,new node(6),new node(7)));
	cout<<"Pre-order traversal is: ";
	preorder_traversal(root);
	cout<<endl<<"In-order traversal is: ";
	inorder_traversal(root);
	cout<<endl;
	level_order_traverse_reversed(root);
	return 0;
}
