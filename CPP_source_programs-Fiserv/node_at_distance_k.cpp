#include<iostream>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
	node(int val,node* left=NULL,node* right=NULL):val(val),left(left),right(right){
	}
};

void ChildAtDistK(node* root, int dist)
{
	if(dist==0)
		cout<<root->val<<",";
	else
	{
		if(root->left)
			ChildAtDistK(root->left,dist-1);
		if(root->right)	
			ChildAtDistK(root->right,dist-1);
	}
}
int NodeAtDistK(node* root,int req_dist,int val)
{
	if(root->val==val)
	{
		ChildAtDistK(root,req_dist);
		return 1;
	}
	int dist=-1;
	if(root->left)
	{
		dist=NodeAtDistK(root->left,req_dist,val);
		if(dist==req_dist)
			cout<<root->val<<",";
		else if(dist != -1 && dist < req_dist && root->right)
			ChildAtDistK(root->right,req_dist-dist-1);
	}
	if(dist==-1 && root->right)
	{
		dist=NodeAtDistK(root->right,req_dist,val);
		if(dist==req_dist)
			cout<<root->val<<",";
		if(dist!=-1 && dist<req_dist && root->left)
			ChildAtDistK(root->left,req_dist-dist-1);
	}
}

int main()
{
	node* root=new node(1,new node(2,new node(4,new node(8,new node(10)),new node(9,NULL,new node(11))),new node(5)),new node(3,new node(6),new node(7)));
	cout<<"Nodes at distance "<<2<<": ";
	int dist=NodeAtDistK(root,2,4);
	if(dist==-1)
		cout<<"node not found"<<endl;
	return 0;
}
