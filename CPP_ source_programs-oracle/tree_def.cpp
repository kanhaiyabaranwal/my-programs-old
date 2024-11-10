#include<iostream>
#include <map>
using namespace std;
//MAP is an efficient balanced BST 

class Tree{
	struct Node{
		int key;
		int value;
		Node* left;
		Node* right;
		Node(int k,int v,Node* l=NULL,Node* r=NULL):key(k),value(v),left(l),right(r){
		}
		void InOrderTraversal();
	};
	Node* root;
public:
	
	bool createNode(int k,int v);
	bool searchKey(int k);
	Tree(int rootKey,int rootValue);
	virtual ~Tree();
	int TreeHeight();
	void InOrderTraversal();
};

bool Tree::createNode(int k,int v){
	Node* temp=root;
	if(!temp)
	{
		root=new Node(k,v);
		if(!root)
			return false;
		else
			return true;
	}
	while(temp->left && temp->value < v)
		temp=temp->left;
	while(temp->right && temp->value > v)
		
	temp->left=new Node(k,v);
	if(temp->left)
		return true;
	return false;
}
Tree::Tree(int rootKey,int rootValue):root(NULL){
	if(createNode(rootKey,rootValue))
		cout<<"Tree created"<<endl;
	else
		cout<<"Failed to create tree"<<endl;
}

bool Tree::searchKey(int k){
}

Tree::~Tree(){
	
}

int Tree::TreeHeight() {
	
}

void Tree::InOrderTraversal(){
	if(root)
		root->InOrderTraversal();
}
void Tree::Node::InOrderTraversal()
{
	cout<<key<<" , "<<value;
	if(left)
		left->InOrderTraversal();
	if(right)
		right->InOrderTraversal();
	cout<<endl<<"End Found"<<endl;
}



int main()
{
	//creates a tree of key,value pair
	Tree t(1,2);
	t.InOrderTraversal();
	
	return 0;
}
