#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	bool travelled;
	Node(int dat,Node* lef=NULL,Node* righ=NULL):data(dat),left(lef),right(righ),travelled(0) {}
 } ;
void InOrderTraversal(Node *n)
{
	if(n->left)
		InOrderTraversal(n->left);
	if(n)
		cout<<n->data<<"\t";
	if(n->right)
		InOrderTraversal(n->right);
	return ;
}
void PreOrderTraversal(Node *n)
{
	if(n)
		cout<<n->data<<"\t";
	if(n->left)
		PreOrderTraversal(n->left);
	if(n->right)
		PreOrderTraversal(n->right);
	return ;
}
void BFT(Node* n)
{
	queue<Node*> q;
	q.push(n);
	Node *temp;
	while(q.size())
	{
		temp=q.front();
		cout<<temp->data<<",";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
		q.pop();
	}
	return ;
}

void preorder_tree_traversal_without_recursion(Node* root)
{
	stack<Node*> stk;
	stk.push(root);
	Node* top;
	while(stk.size())
	{
		top=stk.top();
		stk.pop();
		if(top->right)
			stk.push(top->right);
		if(top->left)
			stk.push(top->left);
		cout<<top->data<<",";
	}
}
void inorder_tree_traversal_without_recursion(Node* root)
{
	stack<Node*> stk;
	stk.push(root);
	Node* top;
	while(stk.size())
	{
		top=stk.top();
		stk.pop();
		if(top->travelled)
		{
			cout<<top->data<<",";
			continue;
		}
		if(top->right)
			stk.push(top->right);
		stk.push(top);
		if(top->left)
			stk.push(top->left);
		top->travelled=1;
		//cout<<top->data<<",";
	}
}
void postorder_tree_traversal_without_recursion(Node* root)
{
	stack<Node*> stk;
	stk.push(root);	
	while(stk.size())
	{
		root=stk.top();
		stk.pop();
		if(root->left && !root->left->travelled)
		{
			stk.push(root->left);
			root=root->left;
			continue;
		}
		if(root->right && !root->right->travelled)
		{
			stk.push(root);
			stk.push(root->right);
			continue;
		}
		if(!root->travelled)
		{
			root->travelled=1;
			cout<<root->data<<",";
		}
	}
}

int main()
{
	Node *n1= new Node(8);
	Node *n2= new Node(9);
	Node* n3=new Node(4,n1,n2);
	n1=new Node(10);
	n2=new Node(11);
	Node* n4=new Node(5,NULL,n1);
	n1=new Node(6,NULL,n2);
	n2=new Node(2,n3,n4);
	n3=new Node(12);
	n4=new Node(13);
	Node *n5=new Node(7,n3,n4);
	Node *n6=new Node(3,n1,n5);
	n3=new Node(1,n2,n6);
	Node *root=n3;
	cout<<"calling InOrderTraversal"<<endl;
	InOrderTraversal(root);
	cout<<endl;
	cout<<"calling PreOrderTraversal"<<endl;
	PreOrderTraversal(root);
	cout<<endl;
	cout<<"calling BFT"<<endl;
	BFT(root);
	cout<<endl;
	cout<<"Calling preorder tree traversal without recursion"<<endl;
	preorder_tree_traversal_without_recursion(root);
	cout<<endl;
	//cout<<"Calling inorder tree traversal without recursion"<<endl;
	//inorder_tree_traversal_without_recursion(root);
	cout<<"Calling postorder tree traversal without recursion"<<endl;
	postorder_tree_traversal_without_recursion(root);
	cout<<endl;
	return 0;
}
	
