#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
#define NUM 13

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
	cout<<n->data<<"\t";
	if(n->right)
		InOrderTraversal(n->right);
	return ;
}
void PreOrderTraversal(Node *n)
{
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


bool path_array(Node* root,int key,vector<char>& cvec)
{
	if(!root)
		return false;
	if(root->data==key)
	{
		copy(cvec.begin(),cvec.end(),ostream_iterator<char>(cout,","));
		return true;
	}
		
	if(root->left)
	{
		cvec.push_back('1');
		if(path_array(root->left,key,cvec))
			return true;
		cvec.pop_back();
	}	
	if(root->right)
	{
		cvec.push_back('0');
		if(path_array(root->right,key,cvec))
			return true;
		cvec.pop_back();
	}	
	return false;
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
	cout<<"calling PreOrderTraversal"<<endl;
	PreOrderTraversal(root);
	cout<<"BFT:";
	BFT(root);
	cout<<endl;
	cout<<"path_array"<<endl;
	vector<char> cvec;
	int key;
	cout<<"Enter key:";
	cin>>key;
	if(path_array(root,key,cvec))
		cout<<"Path found from root to "<<key<<endl;	
	else
		cout<<"Path not found from root to "<<key<<endl;	
	return 0;
}
	
