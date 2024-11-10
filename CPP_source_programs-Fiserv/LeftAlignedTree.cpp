//Convert the structure of the tree like a left aligned tree whose each node contains a down pointer and a right pointer and looks like the below tree.. 
//Input
//					   A
//		            /    \
//		           B	  C
//			       /    \
// 			      D      E
//		             /     /   \
//		            F    G      H
//Output
//			A
//			|
//			B – C
//			|
//			D—E
//			|
//			F—G – H

#include<iostream>
#include<deque>
using namespace std;
#define LEFT 0
#define RIGHT 1

struct Node {
	Node *left;
	Node *right;
	char data;
	Node(char d):left(NULL),right(NULL),data(d) {}
} ; 

Node *root,*LAroot;



Node* FindNode(Node* node,char data)
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


Node* Insert (char data, char parentdata=0,int side=0 )		//side, left=0,right=1
{
	if(!root)
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
 	Node *parentNode = FindNode(root, parentdata);
 	if(!parentNode)		
		parentNode=root;
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
	cout<<root->data<<'\t';
	cout<<"Number of elements="<<++NbrOfElements<<endl;
	if(root->right)
		InOrderTraversal(root->right);
}

int LeftAlignedTraversal(Node *root)
{
	deque<Node*> q;
	q.push_back(root);
	deque<Node*>::iterator travIter=q.begin();
	
	cout<<"q.data="<<q.front()->data<<endl;
	cout<<"travIter->data="<<(*travIter)->data<<endl;
	Node *cur=root;
	Node *temp;
	//cout<<"temp=@"<<temp->data<<"@"<<endl;
	q.push_back(new Node('0'));
	//deque<Node*>::iterator insertIter=q.begin();
	//insertIter++;
	//cout<<"insertIter->data="<<(*insertIter)->data<<endl;
	Node* left,*right;
	LAroot=new Node(root->data);
	Node* LAcur=LAroot;
	int firstChild=1;		//boolean to say if first child after dummy 
	Node* firstNode=LAroot;	//first Node after dummy
	int firstTime=1;
	cout<<"LAcur="<<LAcur->data<<endl;
	while(q.size()>1)
	{
		if(q.front()->data!='0')	//add children to the queue
		{
			cout<<"Non zero data found ="<<q.front()->data<<endl;
			//push left and right child into the queue. Also, make them right children of the LATree
			left=(*travIter)->left;
			if(left)
			{
				cout<<"Left child found="<<left->data<<endl;
				q.push_back(left);
				//If first child after dummy node, make it left child of traversIter
				if(firstChild)
				{
					LAcur->left=new Node(q.back()->data);		//left child is first child of next level
					cout<<"Data inserted on the left of firstChild "<<firstNode->data<<" is "<<firstNode->left->data<<endl;
					LAcur=LAcur->left;
					cout<<"LAcur="<<LAcur->data;
					firstChild=0;
				}
				else
				{
					//Insert to the right most child of LAcur
					temp=LAcur;
					while(temp->right)
						temp=temp->right;
					temp->right=new Node(q.back()->data);
					cout<<"Data inserted on the right of "<<LAcur->data<<" is "<<LAcur->right->data<<endl;
				}
			}
			right=(*travIter)->right;
			if(right)
			{
				cout<<"Right child found="<<right->data<<endl;
				q.push_back(right);
				if(firstChild)
				{
					LAcur->left=new Node(q.back()->data);		//left child is first child of next level
					cout<<"Data inserted on the left of firstChild "<<firstNode->data<<" is "<<firstNode->left->data<<endl;
					LAcur=LAcur->left;
					cout<<"LAcur="<<LAcur->data;
					firstChild=0;
				}
				else
				{
					//Insert to the right most child of LAcur
					temp=LAcur;
					while(temp->right)
						temp=temp->right;
					temp->right=new Node(q.back()->data);
					cout<<"Data inserted on the right of "<<LAcur->data<<" is "<<LAcur->right->data<<endl;
				}
			}
		}
		else		//found 0,add left child as first child of next level. Assign node pointed by Insert iter 
		{			
			firstChild=1;
			q.push_back(new Node('0'));
		}
		travIter++;
		cout<<"travIter->data="<<(*travIter)->data<<endl;
		q.pop_front();
	}
	return 0;
}

//Input
//					   A
//		            /   \
//		           B     C
//			           /    \
// 			         D      E
//		             /     /   \
//		            F    G      H
//Output
//			A
//			|
//			B – C
//			|
//			D—E
//			|
//			F—G – H

int main()
{
	root=Insert('A');
	cout<<"Creating Node"<<endl;
	//Insert(node value,parent node, LEFT/RIGHT)
	Insert('B','A',LEFT);
	Insert('C','A',RIGHT);
	Insert('D','C',LEFT);
	Insert('E','C',RIGHT);
	Insert('F','D',LEFT);
	Insert('G','E',LEFT);
	Insert('H','E',RIGHT);
	cout<<"root="<<root->data<<endl;
	InOrderTraversal(root);
	LeftAlignedTraversal(root);
	cout<<"LAtraversal is\n";
	InOrderTraversal(LAroot);
	/*deque<char> q;
	q.push('A');
	q.push('B');
	cout<<"q1="<<q.front();
	*/
	return 0;
}
