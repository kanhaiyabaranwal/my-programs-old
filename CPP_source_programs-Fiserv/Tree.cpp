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
	cout<<"Number of elements="<<++NbrOfElements<<endl;
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
	cout<<"HeightOfBinaryTree="<<HeightOfBinaryTree<<endl;
	//cout<<"Inorder Traversal"<<endl;
	//InOrderTraversal(root);
	cout<<"Pre order Traversal"<<endl;
	PreorderTraversal(root);
	cout<<"\nBreadth First Traversal"<<endl;
	BreadthFirstTraversal(root);
	
	
	/*int data1,data2;
	data1=9;
	data2=18;
	cout<<"Are "<<data1<<" and "<<data2<<" cousins?\n";
	bool AreCousins=IfCousins(root,data1,data2);
	cout<<"Answer is-"<<AreCousins<<endl;
	*/
	return 0;
}

