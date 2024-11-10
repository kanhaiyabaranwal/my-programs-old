#include<iostream>
using namespace std;

struct Node{
	int dat;
	Node* left;
	Node* right;
	Node(int num,Node* n1=NULL,Node* n2=NULL):dat(num),left(n1),right(n2) {}
};
int larger_than_key(Node* root,int k)
{
	int key;
	if(!root)
		return -1;
	if(root->dat > k)
	{
		if(root->left)
		{
			key=larger_than_key(root->left,k);
			if(key!=-1 && key>k)		//key found in left tree
				return key;
			else				//key not found in subtree, root has largest value
				return root->dat;
		}
		else
			return root->dat;		//self is the smallest value larger than k	
	}
	else 
	{
		if(root->right)
		{
			key=larger_than_key(root->right,k);
			return key;
		}
		else
			return -1;
	}
	return -1;
}

void InorderTraversal(Node *root)
{
	if(root->left)
		InorderTraversal(root->left);
	cout<<root->dat<<" ";
	if(root->right)
		InorderTraversal(root->right);
}

int main()
{
	Node* root=new Node(19,new Node(7,new Node(3,new Node(2),new Node(5)),new Node(11,NULL,new Node(17,new Node(13)))), new Node(43,new Node(23,NULL,new Node(37,new Node(29,NULL,new Node(31)),new Node(41))),new Node(47,NULL,new Node(53))));
	//Node* root=new Node(1);
	int key;
	cout<<"InorderTraversal: ";
	InorderTraversal(root);
	cout<<"Enter value whose next element is to be found:";
	cin>>key;
	int k=larger_than_key(root,key);
	cout<<"Value larger than "<<key<<": "<<k<<endl;
	return 0;
}
