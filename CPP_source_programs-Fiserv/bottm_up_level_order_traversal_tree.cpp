#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define NUM 13

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int dat,Node* lef=NULL,Node* righ=NULL):data(dat),left(lef),right(righ) {}
 } ;
int in[NUM*2];
int pre[NUM*2];
void InOrderTraversal(Node *n)
{
	static int count=0;
	if(n->left)
		InOrderTraversal(n->left);
	if(n)
	{
		in[count++]=n->data;
		cout<<n->data<<"\t";
	}
	if(n->right)
		InOrderTraversal(n->right);
	return ;
}
void PreOrderTraversal(Node *n)
{
	static int count=0;
	if(n)
	{
		pre[count++]=n->data;
		cout<<n->data<<"\t";
	}
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

int search(int data,int start,int end)			//returns position of pre[] datain inorder array
{
	while(start<=end)
		if(in[start]==data)
			return start;
		else
			start++;
	return -1;
}

Node* BuildTree(int start,int end)
{
	static int preIndex=0;
	Node* n=new Node(pre[preIndex++]);
	if(start==end)
	{
		cout<<"start==end at "<<start<<endl;
		return n;
	}
	cout<<"Searching "<<n->data<<" between "<<start<<" and "<<end<<" in in[]"<<endl;
	int inIndex=search(n->data,start,end);
	cout<<"Found at "<<inIndex<<endl;	
	if(inIndex!=-1 && start<inIndex)
		n->left=BuildTree(start,inIndex-1);
	if(inIndex!=-1 && inIndex<end)
		n->right=BuildTree(inIndex+1,end);
	return n;
}
	
void bottm_up_level_order_traversal(Node* root)
{
	queue<Node*> q;
	stack<Node*> stk;
	q.push(root);
	q.push(new Node(-1));
	Node* front;
	while(q.size()>1)
	{
		front=q.front();
		if(front->data==-1)
		{
			q.push(front);
		}
		else
		{
			if(front->right)
				q.push(front->right);
			if(front->left)
				q.push(front->left);
			stk.push(front);
		}
		q.pop();
	}
	while(stk.size())
	{
		cout<<stk.top()->data<<",";
		stk.pop();
	}
	cout<<endl;
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
	cout<<"Inorder Traversal:";
	for(int i=0;i<NUM;i++)
		cout<<in[i]<<",";
	cout<<endl;
	cout<<"calling PreOrderTraversal"<<endl;
	PreOrderTraversal(root);
	cout<<"BFT:";
	BFT(root);
	cout<<"bottm_up_level_order_traversal"<<endl;
	bottm_up_level_order_traversal(root);
	
	return 0;
}
	
