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

template<class T>
struct Node {
	Node *left;
	Node *right;
	T data;
	Node(T d):left(NULL),right(NULL),data(d) {}
} ; 

Node<char> *root;

template<class T>
Node<T>* FindNode(Node<T>* node,T data)
{
	static Node<T> *n=NULL;
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

template<class T> 
Node<T>* Insert (T data, T parentdata=0,int side=0 )		//side, left=0,right=1
{
	if(!root)
	{
		Node<T> *temp=new Node<T>(data);
		if(!temp)
		{
			cout<<"Error in creating node\n";
			return 0;	
		}
		cout<<"Node created for data="<<data<<endl;
		return temp;
 	}
 	Node<T> *parentNode = FindNode(root, parentdata);
 	if(!parentNode)		
		parentNode=root;
 	if(side==LEFT)
 	{
 		 while(parentNode->left)			//left most child
 			parentNode=parentNode->left;
 		parentNode->left=new Node<T>(data);
 		return parentNode;
 	}
 	else	//right most child
 	{
 		 while(parentNode->right)			//left most child
 			parentNode=parentNode->right;
 		parentNode->right=new Node<T>(data);
 		return parentNode;
 	}
 	
}


template<class T>
void InOrderTraversal(Node<T>* root)	//left,self then right
{
	static int NbrOfElements=0;
	if(root->left)
		InOrderTraversal(root->left);
	cout<<root->data<<"\t";
	cout<<"Number of elements="<<++NbrOfElements<<endl;
	if(root->right)
		InOrderTraversal(root->right);
}

template<class T>
int LeftAlignedTraversal(Node<T> *root)
{
	deque<Node<T>* > q;
	q.push_back(root);
	deque<Node<T>* >::iterator travIter=q.begin();
	
	cout<<"q.data="<<q.front()<<endl;
	cout<<"travIter->data="<<(*travIter)->data<<endl;
	Node<T> *cur=root;
	Node<T> *temp=new Node<T>('0');
	//cout<<"temp=@"<<temp->data<<"@"<<endl;
	q.push_back('0');
	deque<<T>* >::iterator insertIter=q.begin();
	insertIter++;
	cout<<"insertIter->data="<<(*insertIter)->data<<endl;
	/*while(q.size()!=0)
	{
		if(q.front()=='0')	//end of siblings
		{
			traversIter
		}
		q.pop_front();
	}*/
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
	/*deque<char> q;
	q.push('A');
	q.push('B');
	cout<<"q1="<<q.front();
	*/
	return 0;
}
