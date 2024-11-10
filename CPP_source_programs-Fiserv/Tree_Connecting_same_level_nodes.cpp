//Program to connect nodes at same level using 3rd pointer nextRight
#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int num;
	Node* left;
	Node* right;
	Node* nextRight;
	Node(int n,Node *l=NULL,Node* r=NULL):num(n),left(l),right(r) {
	}
};

void InorderTraversal(Node *root,int after=0)
{
	if(root->left)
		InorderTraversal(root->left,after);
	//print data
	cout<<"root="<<root->num;
	if(root->left)
		cout<<", root->left="<<root->left->num;
	else
		cout<<", Left child does not exist";
	if(root->right)
		cout<<", root->right="<<root->right->num;
	else
		cout<<", Right child does not exist";
	if(after)
	{
		if(root->nextRight)
			cout<<", root->nextRight="<<root->nextRight->num;
		else
			cout<<", nextRight does not exist";
	}
	cout<<endl;
	if(root->right)
		InorderTraversal(root->right,after);
}
void PreorderTraversal(Node *root)
{
	cout<<root->num<<" ";
	if(root->left)
		PreorderTraversal(root->left);
	
	if(root->right)
		PreorderTraversal(root->right);
}

void connect_same_level_nodes(Node * root)
{
	queue<Node*> q;
	q.push(root);
	q.push(new Node(-1));
	while(q.size()>1)
	{
		Node* front=q.front();
		if(front->num!=-1)		//this will never occur ideally
		{
			if(front->left)
				q.push(front->left);
			if(front->right)
				q.push(front->right);
		}
		q.pop();
		Node* nextFront=q.front();
		if(nextFront->num==-1)
		{
			front->nextRight=NULL;
			//delete nextFront;
			//q.push(new Node(-1));
			q.push(nextFront);		//reuse dummy node
			q.pop();
		}
		else
		{
			front->nextRight=nextFront;
		}
	}
}

int main()
{
	cout<<"Program to connect nodes at same level"<<endl;
	Node *root=new Node(1,new Node(2,new Node(4),new Node(5)),new Node(3,new Node(6),new Node(7)));
	//Node *temp=new Node(2,r)
	cout<<"Inorder traversal: ";
	InorderTraversal(root);
	cout<<endl;
	cout<<"Preorder traversal: ";
	PreorderTraversal(root);
	cout<<endl;
	cout<<"Connecting same level nodes: "<<endl;
	connect_same_level_nodes(root);
	cout<<"Inorder traversal after connecting same level nodes: ";
	InorderTraversal(root,1);
	return 0;
}

