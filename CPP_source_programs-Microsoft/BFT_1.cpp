#include<iostream>
#include<queue>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
	node(int val,node* left=NULL, node* right=NULL):val(val),left(left),right(right){
	}
};

void BFT(node* root)
{
	node *temp=new node(-1);
	queue<node*> q;
	q.push(root);
	q.push(temp);
	node* top;
	cout<<"Navigating through the Tree Breadth First Traversal:";
	while(q.size()>1)
	{
		top=q.front();
		q.pop();
		if(top->val==-1)
		{
			q.push(temp);
		}
		else
		{
			cout<<top->val<<", ";
			if(top->left)
				q.push(top->left);
			if(top->right)
				q.push(top->right);
		}
	}
	
	
}

void PrintTreeInorder(node* root)
{
	if(root->left)
		PrintTreeInorder(root->left);
	cout<<root->val<<",";
	if(root->right)
		PrintTreeInorder(root->right);
	
}

int main_1()
{
	node* root=new node(1, new node(2,new node(4,new node(8)),new node(5)), new node(3,new node(6, new node(9),new node(10)),new node(7)));
	PrintTreeInorder(root);
	BFT(root);
	cout<<"Hello World\n";
	return 0;
}
