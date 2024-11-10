//Inorder traversal of a binary tree in O(1) space using Morris traversal algorithm
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int num,Node* l=NULL,Node* r=NULL):data(num),left(l),right(r) {
	}
};

void inorder_traversal_order1(Node *root)
{
	cout<<"Inorder traversal in O(1) using Morris algorithm "<<endl;
	Node* cur=root,*parent;
	while(cur)
	{
		if(!cur->left)
		{
			cout<<cur->data<<" ";
			cur=cur->right;
		}
		else
		{
			parent=cur;
			cur=cur->left;
			while(cur->right && cur->right!=parent)
				cur=cur->right;
			if(cur->right==parent)		//temporary link found,
			{
				cur->right=NULL;				//break temp link
				cout<<parent->data<<" ";			//print this node and go to the parent
				cur=parent->right;
			}
			else						//right most child found, create link to parent
			{
				cur->right=parent;
				cur=parent->left;
			}
		}
	}
}

int main()
{
	
	Node* root=new Node(1,new Node(2,new Node(4,new Node(8)),new Node(5)),new Node(3,new Node(6),new Node(7)));
	inorder_traversal_order1(root);
	return 0;
}
