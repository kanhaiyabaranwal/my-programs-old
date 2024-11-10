#include<iostream>
using namespace std;
#define LEFT 0
#define RIGHT 1
struct Node {
	Node *left;
	Node *right;
	int data;
	Node(int d):left(NULL),right(NULL),data(d) {}
	
}; 
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
//Insertion policy, possible left child of parentdata


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
class Queue{
	struct List{
		Node* nd;
		List* next;
		List* prev;
		List(Node *nod,List* nex=0, List* pre=0): nd(nod),next(nex),prev(pre)	{}
	};
	List *front;
	List *back;
	
	public:
		Queue():front(NULL),back(NULL) { }
		void remove(){		//removes front element
			List *temp=front;
			front=front->prev;
			delete temp;
		}
		int add(Node *nd){
			if(back)
				back=new List(nd,back,NULL);
			else{
				back=new List(nd);
				front=back;
			}
			if(back->next)
				back->next->prev=back;					//reverse linkage is also done.
			if(!back)
				return -1;
			return 0;
		}
		Node* peek(){
			if(front)
				return front->nd;
			else
				return 0;
		}
		int peekdata(){
			if(front)
				return front->nd->data;
			else
				return 0;
		}
		
};
int BreadthFirstTraversal(Node* root){
	Queue q;
	q.add(root);
	cout<<"BFT data="<<"\t";
	Node* n=root;
	while(q.peek()){
		cout<<q.peekdata()<<"\t";
		n=q.peek();
		if(n->left)
			q.add(n->left);
		if(n->right)
			q.add(n->right);
		q.remove();
	}
	cout<<"BFT completed\n";
	return 0;
}
//Find Level of node from root recursively
int FindLevel(Node* nd, int data){
	if(nd==NULL)
		return 0;
	if(nd->left)
		return 	1+FindLevel(nd->left,data);
}
bool IfCousins(Node*root, int data1,int data2){
	int level1=FindLevel(root,data1);
	int level2=FindLevel(root,data2);
}

int BreadthFirstTree(Node* root){
	Node *rootBFT=new Node(root->data);
	Queue q;
	int level=0;
	q.add(root);
	
	cout<<"BFT data="<<"\t";
	const Node* n=root;
	while(q.peek()){
		cout<<q.peekdata()<<"\t";
		if(q.peekdata()==-1)		//dummy node, don't consider this node, but make next node as right child
		{
			q.remove();
		}
		n=q.peek();
		if(n->left)
		{
			q.add(n->left);
			int lev=FindLevel(n->left,n->left->data);
			//if level changes, insert a dummy node to represent change of level into the queue
			if(lev>level)
			{
				Node* temp=new Node(-1);	
				q.add(temp);
			}
			q.add(n->left);
		}
		if(n->right)
			q.add(n->right);
		q.remove();
	}
	cout<<"BFT completed\n";
	return 0;
}

int HeightOfBinaryTree(Node *root)
{
	int heightLeft=0;
	int heightRight=0;
	if(root==NULL)
		return 0;
	heightLeft=HeightOfBinaryTree(root->left);
	heightRight=HeightOfBinaryTree(root->right);
	if(heightLeft>=heightRight)
		return heightLeft+1;
	else
		return heightRight+1;
}

//Least common ancesstor of two nodes
Node* LCA(Node* root, int data1,int data2)
{
	if(root==NULL)
		return 0;
	Node* leftlca=NULL;
	Node* rightlca=NULL;
	if(root->data==data1 || root->data==data2)
		return root;
	leftlca=LCA(root->left,data1,data2);	
	rightlca=LCA(root->right,data1,data2);	
	if(leftlca && rightlca)
		return root;
	else
		return leftlca?leftlca:rightlca;
}

//Distance between two nodes through LCA
Node* LCA_Path(Node* root, int data1,int data2,int &dist)
{
	static int lcafound=0;
	if(root==NULL)
		return 0;
	Node* leftlca=NULL;
	Node* rightlca=NULL;
	if(root->data==data1 || root->data==data2)
	{
		dist=0;				//set distance as zero
		return root;
	}
	int ldist=0,rdist=0;
	leftlca=LCA_Path(root->left,data1,data2,ldist);	
	if(lcafound)			//check if lca was already found, then don't process simply return
	{
		dist=ldist;
		return leftlca;
	}
	rightlca=LCA_Path(root->right,data1,data2,rdist);
	if(lcafound)
	{
		dist=rdist;
		return rightlca;
	}
	if(leftlca && rightlca)
	{
		lcafound=1;
		dist=ldist+rdist+2;			//set total distance as sum of left and right distance
		cout<<"lca found at node "<<root->data<<" distance is "<<dist<<endl;
		return root;
	}
	else
	{
		
		if(leftlca) 
		{
			dist=ldist+1;
			cout<<"Left distance increased due to node pair "<<root->data<<" to "<<leftlca->data<<", dist="<<dist<<endl;
			return leftlca;
		}
		else if(rightlca)
		{
			dist=rdist+1;
			cout<<"Right distance increased due to node pair "<<root->data<<" to "<<rightlca->data<<", dist="<<dist<<endl;
			return rightlca;
		}
	}
	return 0;
}




Node* root=NULL;
int main()
{
	cout<<"Creating Node"<<endl;
	root=Insert(NULL,4);
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
	cout<<"root="<<root->data<<endl;
	int heightOfTree=HeightOfBinaryTree(root);
	cout<<"HeightOfBinaryTree="<<heightOfTree<<endl;
	cout<<"Inorder Traversal"<<endl;
	InOrderTraversal(root);
	cout<<"\nPre order Traversal"<<endl;
	PreorderTraversal(root);
	cout<<"\nBreadth First Traversal"<<endl;
	BreadthFirstTraversal(root);
	cout<<"Finding LCA of nodes 8 and 15"<<endl;
	Node* lca=LCA(root,8,15);
	cout<<"LCA(root,8,15)="<<lca->data<<endl;
	
	//Distance between 2 nodes
	int dist=0;
	Node* lcapath=LCA_Path(root,18,2,dist);
	cout<<"LCA_Path(root,18,2)="<<lcapath->data<<" and distance between them is "<<dist<<endl;
	/*int data1,data2;
	data1=9;
	data2=18;
	cout<<"Are "<<data1<<" and "<<data2<<" cousins?\n";
	bool AreCousins=IfCousins(root,data1,data2);
	cout<<"Answer is-"<<AreCousins<<endl;
	*/
	return 0;
}

