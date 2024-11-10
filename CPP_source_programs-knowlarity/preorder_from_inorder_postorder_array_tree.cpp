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
	
void create_preorder_array(int *pre,int *in,int *post,int ins,int ine,int posts,int poste)
{
	if(ins>ine || posts>poste)
		return;
	static int index=0;
	pre[index++]=post[poste];
	if(ins==ine)
		return;
	int root=post[poste];
	int i=ins;
	while(i<=ine)
	{
		if(in[i]==root)
			break;
		else 
			i++;
	}
	if(i>ine)
	{
		cout<<"Something strange occurred!\n";
		return;
	}
	int len=i-ins;
	create_preorder_array(pre,in,post,ins,i-1,posts,posts+len-1);
	create_preorder_array(pre,in,post,i+1,ine,posts+len,poste-1);
}
	
#define N 13
int main()
{
	int in[]={8,4,9,13,2,5,14,10,1,6,11,3,7,12};	
	int post[]={8,13,9,4,14,10,5,2,11,6,12,7,3,1};
	int n=13;
	int pre[N]={0};
	for(int i=0;i<=n;i++)
		cout<<in[i]<<",";
	cout<<endl;
	create_preorder_array(pre,in,post,0,13,0,13);
	cout<<"in-order traversal: ";
	for(int i=0;i<=n;i++)
		cout<<in[i]<<",";
	cout<<endl;
	cout<<"post-order traversal: ";
	for(int i=0;i<=n;i++)
		cout<<post[i]<<",";
	cout<<endl;
	cout<<"pre-order traversal: ";
	for(int i=0;i<=n;i++)
		cout<<pre[i]<<",";
	cout<<endl;
	return 0;
}
	
