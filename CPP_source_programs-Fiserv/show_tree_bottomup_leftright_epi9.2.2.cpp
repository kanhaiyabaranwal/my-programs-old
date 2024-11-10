#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int val,Node* l=NULL,Node* r=NULL):data(val),left(l),right(r) {}
};
void show_tree_bottomup_leftright(Node* root)
{
	queue<Node*> q;
	stack<int> stk;
	q.push(root);
	Node *dummy=new Node(-1);
	q.push(dummy);
	while(q.size()>1)
	{
		if(q.front()->data==-1)
		{
			stk.push(-1);
			q.pop();
			q.push(dummy);
		}
		else
		{
			stk.push(q.front()->data);
			if(q.front()->right)
				q.push(q.front()->right);
			if(q.front()->left)
				q.push(q.front()->left);
			q.pop();
		}
	}
	//now display the stack
	cout<<"Display Tree values bottomup left right"<<endl;
	while(stk.size())
	{
		if(stk.top()==-1)
			cout<<endl;
		else
			cout<<stk.top()<<" ";
		stk.pop();
	}
}
int main()
{
	Node* n=new Node(314,new Node(6,new Node(271,new Node(28),new Node(0)),new Node(561,NULL,new Node(3,new Node(17)))),new Node(6,new Node(2,NULL,new Node(1,new Node(401,NULL,new Node(641)),new Node(257))),new Node(271,NULL,new Node(28))));
	show_tree_bottomup_leftright(n);
	return 0;	
}


