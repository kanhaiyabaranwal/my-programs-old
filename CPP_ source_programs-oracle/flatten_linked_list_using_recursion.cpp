#include<iostream>
#include<queue>
using namespace std;
//Very good algo. 
//Horizontal LL length=m, vertical length=n
//flatten is called m times, merge is called n*m times. Time complexity n*m, Space complexity due to call stack in recursive call is n*m+m.


struct node{
	int val;
	node* right;
	node* down;
	node(int v=0,node* d=0,node* r=0):val(v),right(r),down(d) {
	}
};
node* merge(node* n1,node* n2)
{
	if(!n1)
		return n2;
	if(!n2)
		return n1;
	if(n1->val < n2->val)
	{
		node* result=n1;
		result->down=merge(n1->down,n2);
		return result;
	}
	else			//	if(n1->down->val < n2->val)
	{
		node* result=n2;
		result->down=merge(n1,n2->down);
		return result;
	}
}


node* flatten(node* root)
{
	if(!root || !root->right)
		return root;
	if(root->right)
	{
		return merge(root,flatten(root->right));
	}
}

int main()
{
	node* root=new node(5,new node(7,new node(8,new node(30))),new node(10,new node(20),new node(19,new node(22,new node(50)),new node(28,new node(35,new node(40,new node(45)))))));

	
	node* res=flatten(root);
	cout<<"Sorted list is: ";
	while(res)
	{
		cout<<res->val<<"\t";
		res=res->down;
	}
	return 0;
}
