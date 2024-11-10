#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int dat,Node* lef=NULL,Node* righ=NULL):data(dat),left(lef),right(righ) {}
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

//Inplace tree mirroring using queue and stack, at the end of the function mirror is created and original tree is gone
void TreeMirror(Node* root)
{
	queue<Node*> q;
	stack<Node*> stk;
	q.push(root);
	Node *dummyNode=new Node(-1);
	q.push(dummyNode);	//dummy node in the queue to identify end of current level
	Node *temp,*left,*right;
	cout<<"inside TreeMirror"<<endl;
	while(q.size()>1)
	{
		temp=q.front();
		if(temp->data==-1)	//end of level, create mirror
		{
			q.push(new Node(-1));		//push dummy node to mark end of level
			while(stk.size())
			{
		
				//swap nodes
				left=stk.top()->left;
				right=stk.top()->right;
				stk.top()->left=right;
				stk.top()->right=left;
				stk.pop();
			}
			//delete temp node
			q.pop();
			delete temp;
		}
		else
		{
			//cout<<temp->data<<",";
			if(temp->left)
			{
				q.push(temp->left);
			}
			if(temp->right)
			{
				q.push(temp->right);
			}
			stk.push(temp);
			q.pop();
		}
	}
	return ;
}
//Inplace tree mirroring using queue only, at the end of the function mirror is created and original tree is gone
void TreeMirror_usingQ(Node* root)
{
	queue<Node*> q;
	stack<Node*> stk;
	q.push(root);
	Node *dummyNode=new Node(-1);
	q.push(dummyNode);	//dummy node in the queue to identify end of current level
	Node *temp,*left,*right;
	cout<<"inside TreeMirror"<<endl;
	while(q.size()>1)
	{
		temp=q.front();
		if(temp->data==-1)	//end of level, create mirror
		{
			q.push(new Node(-1));		//push dummy node to mark end of level
			while(stk.size())
			{
		
				//swap nodes
				left=stk.top()->left;
				right=stk.top()->right;
				stk.top()->left=right;
				stk.top()->right=left;
				stk.pop();
			}
			//delete temp node
			q.pop();
			delete temp;
		}
		else
		{
			//cout<<temp->data<<",";
			if(temp->left)
			{
				q.push(temp->left);
			}
			if(temp->right)
			{
				q.push(temp->right);
			}
			stk.push(temp);
			q.pop();
		}
	}
	return ;
}
 void TreeMirror_DFT(Node* root)
{
	if(!root)
		return;
	Node* left=NULL,*right=NULL;
	if(root->left)
		left=root->left;	
	if(root->right)
		right=root->right;	
	root->left=right;
	root->right=left;
	TreeMirror_DFT(root->left);
	TreeMirror_DFT(root->right);
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
	cout<<"Doing Tree Mirroring"<<endl;
	TreeMirror(root);
	cout<<endl;
	cout<<"calling BFT after Tree Mirroring"<<endl;
	BFT(root);
	cout<<endl;
	cout<<"Second Tree Mirroring to bring back to original tree"<<endl;
	TreeMirror(root);
	cout<<endl;
	cout<<"calling BFT after Tree Mirroring"<<endl;
	BFT(root);
	cout<<endl;
	cout<<"Tree Mirroring to using TreeMirror_DFT"<<endl;
	TreeMirror_DFT(root);
	cout<<endl;
	cout<<"calling BFT after Tree Mirroring"<<endl;
	BFT(root);
	cout<<endl;
	return 0;
}
	