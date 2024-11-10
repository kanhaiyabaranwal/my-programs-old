#include<iostream>
#include<stack>
using namespace std;


struct node{
	int dat;
	bool visited;
	node* left;
	node* right;
	node(int d,node* left=NULL, node* right=NULL,bool visited=false): dat(d),left(left),right(right) {}
};


void inorder_traversal_with_stack(node* root)
{
	stack<node*> stk;
	stk.push(root);
	root->visited=true;
	while(stk.size())
	{
		node* top=stk.top();
		if(top->left && top->left->visited==false)
		{
			top->left->visited=true;
			stk.push(top->left);
		}
		else
		{
			cout<<top->dat<<",";
			stk.pop();
			if(top->right && top->right->visited==false)
			{
				top->right->visited=true;
				stk.push(top->right);
			}
		}
	}
	cout<<"inorder_traversal_with_stack ended"<<endl;
}

void inorder_traversal_with_recursion(node* root)
{
	if(root->left)
		inorder_traversal_with_recursion(root->left);
	cout<<root->dat<<",";
	if(root->right)
		inorder_traversal_with_recursion(root->right);
}
	

int main()
{
	node* root=new node(15,new node(10,new node(8),new node(12)),new node(20,new node(16),new node(25)));
	cout<<"Inorder traversal without recursion"<<endl;
	inorder_traversal_with_stack(root);
	cout<<endl<<"Inorder traversal with recursion"<<endl;
	inorder_traversal_with_recursion(root);
	return 0;
}

