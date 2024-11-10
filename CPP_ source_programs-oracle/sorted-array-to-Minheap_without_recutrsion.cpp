#include<iostream>
#include<vector>
using namespace std;


struct node{
	int val;
	node* left;
	node* right;
	node(int v,node* l=NULL,node* r=NULL): val(v),left(l),right(r){
	}
};

node* createMinHeap(int *arr,int n)
{
	//node* root=new node(arr[0]);
	vector<node*> pvec;
	cout<<"Creating minheap"<<endl;
	for(int i=0;i<n;i++)
	{
		pvec.push_back(new node(arr[i]));
	}
	for(int i=0;2*i+1<n;i++)
	{
		pvec[i]->left=pvec[2*i+1];
		if(2*i+2<n)
			pvec[i]->right=pvec[2*i+2];	
	}
	cout<<"Minheap root:"<<pvec[0]->val<<endl;
	return pvec[0];
	
}

void preorder_traversal(node* root)
{
	if(!root)
		return;
	if(root)
		cout<<root->val<<",";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8};
	node* root=createMinHeap(arr,8);
	preorder_traversal(root);
	return 0;
}
