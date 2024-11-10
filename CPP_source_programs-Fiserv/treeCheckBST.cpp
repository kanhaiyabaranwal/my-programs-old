#include<iostream>
using namespace std;

#define LEFT 0
#define RIGHT 1
struct Node {
	Node *left;
	Node *right;
	int data;
	Node(int d,Node* n1=NULL,Node* n2=NULL):left(n1),right(n2),data(d) {}
	
};

void PreorderTraversal(Node* root)	//left,self then right
{
	cout<<root->data<<"\t";
	if(root->left)
		PreorderTraversal(root->left);
	if(root->right)
		PreorderTraversal(root->right);
}	
 
Node* FindNode(Node* node,int data)
{
	static Node *n=NULL;
	if(node==NULL)
		return NULL;
	if(node->data==data)
		return n=node;
	if(node->left && FindNode(node->left,data))
		return n;
	if(node->right && FindNode(node->right,data))
		return n;
	return NULL;
	
}

//Insertion policy, possible left child of parent data
Node* Insert (Node *node, int data, int parentdata=0,int side=0 )		//side, left=0,right=1
{
	if(!node)
	{
		Node *temp=new Node(data);
		if(!temp)
		{
			cout<<"Error in creating node\n";
			return 0;	
		}
		cout<<"Node created for data="<<data<<endl;
		return temp;
 	}
 	Node *parentNode = FindNode(node, parentdata);
 	if(!parentNode)		
		parentNode=node;
 	if(side==LEFT)
 	{
 		 while(parentNode->left)			//left most child
 			parentNode=parentNode->left;
 		parentNode->left=new Node(data);
 		return parentNode;
 	}
 	else	//right most child
 	{
 		 while(parentNode->right)			//left most child
 			parentNode=parentNode->right;
 		parentNode->right=new Node(data);
 		return parentNode;
 	}
 	
}
void InOrderTraversal(Node* root)	//left,self then right
{
	static int NbrOfElements=0;
	if(root->left)
		InOrderTraversal(root->left);
	cout<<root->data<<"\t";
	//cout<<"Number of elements="<<++NbrOfElements<<endl;
	if(root->right)
		InOrderTraversal(root->right);
}

int HeightofTree(Node *root)
{
	if(!root)
		return 0;
	int hl=HeightofTree(root->left);
	int hr=HeightofTree(root->right);
	if(hl>hr)
		return hl+1;
	else
		return hr+1;
}

void BFTUtil(Node* root,int k)
{
	if(k==0)
		cout<<root->data<<" ";
	if(root->left)
		BFTUtil(root->left,k-1);
	if(root->right)
		BFTUtil(root->right,k-1);
}

void BFT_withoutDS(Node *root)
{
	int h=HeightofTree(root)-1;
	for(int i=0;i<=h;i++)
	{
		cout<<"level="<<i<<"-> ";
		BFTUtil(root,i);
		cout<<endl;
	}
}

int CheckBalance(Node* root)
{
	if(!root);
		return 1;
	int h1=HeightofTree(root->left);
	int h2=HeightofTree(root->right);
	cout<<"h1="<<h1<<" and h2="<<h2<<endl;
	if(h1>h2+1 ||h2>h1+1)
		cout<<"Tree is not balanced"<<endl;
	return 0;
}

int CheckBST(Node *root)
{
	if(!root) return true;
	Node* temp;
	if(root->left)
	{
		if(!CheckBST(root->left))
			return false;
		//root data should be greater than right most child of the left subtree
		{
			temp=root->left;
			while(temp->right)
				temp=temp->right;
			if(root->data < temp->data)
				return false;
		}
	}
	if(root->right)
	{
		if(!CheckBST(root->right))
			return false;
		//root data should be less than left most child of the right subtree
		{
			temp=root->right;
			while(temp->left)
				temp=temp->left;
			if(root->data > temp->data)
				return false;
		}
	}
	return true;
}


Node* root=NULL;
int main()
{
	cout<<"Creating Node"<<endl;
	/*root=Insert(NULL,4);
	Insert(root,5,4);
	Insert(root,7,5,LEFT);
	Insert(root,3,5,RIGHT);
	Insert(root,8,7,LEFT);
	Insert(root,11,7,RIGHT);
	Insert(root,6,4,RIGHT);
	Insert(root,2,6,LEFT);
	Insert(root,9,6,RIGHT);
	Insert(root,17,3,LEFT);
	Insert(root,15,3,RIGHT);
	Insert(root,18,15,LEFT);
	*/
	root=new Node(17,new Node(12,new Node(6),new Node(15)),new Node(25,new Node(14),new Node(30)));
	cout<<"root="<<root->data<<endl;
	
	cout<<"Pre order Traversal"<<endl;
	PreorderTraversal(root);
	cout<<"\nIn order Traversal"<<endl;
	InOrderTraversal(root);
	cout<<"\nHeightofTree="<<HeightofTree(root)<<endl;
	cout<<"\nBFT without using Queue or Stack"<<endl;
	BFT_withoutDS(root);
	cout<<"Checking if tree is balanced or not"<<endl;
	CheckBalance(root);
	bool flag=CheckBST(root);
	if(flag)
		cout<<"Tree is a BST"<<endl;
	else
		cout<<"Tree is not a BST"<<endl;
	return 0;
}
