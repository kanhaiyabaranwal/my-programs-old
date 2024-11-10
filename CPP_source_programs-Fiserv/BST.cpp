#include<iostream>
using namespace std;

struct BSTN {
	BSTN *left;
	BSTN *right;
	int data;
	BSTN(int d):left(NULL),right(NULL),data(d) {}
	
}; 

BSTN* Insert (BSTN *node, int data)
{
	if(!node)
	{
		BSTN *temp=new BSTN(data);
		if(!temp)
		{
			cout<<"Error in creating node\n";
			return 0;	
		}
		cout<<"Node created for data="<<data<<endl;
		return temp;
 	}
	if(node->data > data)
		if(node->left)
			Insert(node->left,data);
		else
			node->left = Insert(node->left,data);
		
	else if(node->data < data)
		if(node->right)
			Insert(node->right,data);
		else
			node->right = Insert(node->right,data);
	else
	{
		cout<<"data already exists"<<endl;
		return NULL;
	}
}

void BSTTraversal(BSTN* root)	//left,self then right
{
	static int NbrOfElements=0;
	if(root->left)
		BSTTraversal(root->left);
	cout<<root->data<<"\t";
	cout<<"Number of elements="<<++NbrOfElements<<endl;
	if(root->right)
		BSTTraversal(root->right);
}

void PreorderTraversal(BSTN* root)	//left,self then right
{
	cout<<root->data<<"\t";
	if(root->left)
		PreorderTraversal(root->left);
	if(root->right)
		PreorderTraversal(root->right);
}	

int main()
{
	cout<<"Creating BSTN"<<endl;
	BSTN* root=Insert(NULL,4);
	Insert(root,10);
	Insert(root,2);
	Insert(root,23);
	Insert(root,13);
	Insert(root,27);
	Insert(root,1);
	Insert(root,7);
	Insert(root,50);
	cout<<"root="<<root->data<<endl;
	cout<<"Inorder Traversal"<<endl;
	BSTTraversal(root);
	cout<<"Pre order Traversal"<<endl;
	PreorderTraversal(root);

}

