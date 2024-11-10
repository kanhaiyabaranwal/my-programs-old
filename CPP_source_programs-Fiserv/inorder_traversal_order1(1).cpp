#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node* parent;
	Node(int val,Node* l=NULL,Node* r=NULL,Node* p=NULL):data(val),left(l),right(r),parent(p) {}
};

void inorder_traversal_order1(Node* root)
{
	Node* n=root,*cur=root;
	//move=0 - nothing
	//move=1 - go up
	//move=2 - go right
	int move=0;
	cout<<"Inorder traversal in Order(1) where parent node is also provided and node must not be tempered."<<endl;
	while(n)
	{
		if(move==1)
		{
			if(!n->parent)
				break;
			cur=n;
			n=n->parent;
			if(n->left==cur)
			{
				cout<<n->data<<" ";
				move=2;
			}
			else if(n->right==cur)
				move=1;
		}
		else if(n->left)
		{
			if(move==2)
			{
				if(n->right)
					{n=n->right; move=0;}
				else
					n=n->parent;
			}
			else
				n=n->left;
		}
		else if(n->right)
		{
			cout<<n->data<<" ";
			n=n->right;
		}
		else
		{
			cout<<n->data<<" ";
			move=1;
		}
	}
	cout<<endl<<"Inorder Traversal over"<<endl;	

}
void inorder_traversal_recursion(Node* root)
{
	if(!root)
		return;
	inorder_traversal_recursion(root->left);
	cout<<root->data<<" ";
	inorder_traversal_recursion(root->right);
}
int main()
{
	Node* first=new Node(2,new Node(4),new Node(5));
	Node* second=new Node(3,new Node(6),new Node(7));
	Node* root=new Node(1,first,second);
	first->parent=root;
	second->parent=root;
	first->left->parent=first;
	first->right->parent=first;
	second->left->parent=second;
	second->right->parent=second;
	cout<<"inorder_traversal_recursion"<<endl;
	inorder_traversal_recursion(root);	
	cout<<endl;
	cout<<"inorder_traversal_order1"<<endl;
	inorder_traversal_order1(root);
	cout<<endl;
	return 0;
}



