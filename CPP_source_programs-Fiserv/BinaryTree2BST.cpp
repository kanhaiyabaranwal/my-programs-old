#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<iterator>
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
 
void InOrderTraversal(Node* root,deque<int>& ivec)	//left,self then right
{
	static int NbrOfElements=0;
	if(root->left)
		InOrderTraversal(root->left,ivec);
	ivec.push_back(root->data);
	cout<<root->data<<"\t";
	//cout<<"Number of elements="<<++NbrOfElements<<endl;
	if(root->right)
		InOrderTraversal(root->right,ivec);
}
void CreateBST(Node* root,deque<int>& ivec)	//left,self then right
{
	static int NbrOfElements=0;
	if(root->left)
		CreateBST(root->left,ivec);
	//cout<<root->data<<"\t";
	root->data=ivec.front();
	ivec.pop_front();
	//cout<<"Number of elements="<<++NbrOfElements<<endl;
	if(root->right)
		CreateBST(root->right,ivec);
}

Node* root=NULL;
int main()
{
	cout<<"Creating Node"<<endl;
	root=new Node(17,new Node(12,new Node(16),new Node(15)),new Node(2,new Node(4),new Node(30)));
	cout<<"root="<<root->data<<endl;
	
	cout<<"Pre order Traversal"<<endl;
	PreorderTraversal(root);
	deque<int> ivec;
	cout<<"\nIn order Traversal"<<endl;
	InOrderTraversal(root,ivec);
	cout<<endl<<"Contents of array:";
	
	sort(ivec.begin(),ivec.end());
	cout<<"Elements of deque after sorting"<<endl;
	copy(ivec.begin(),ivec.end(),ostream_iterator<int>(cout,","));
	cout<<endl;
	CreateBST(root,ivec);
	cout<<"\nIn order Traversal after In-place sorting using sorted array"<<endl;
	
	InOrderTraversal(root,ivec);
	//copy(ivec.begin(),ivec.end(),ostream_iterator<int>(cout,","));
	//cout<<endl;
	return 0;
}
