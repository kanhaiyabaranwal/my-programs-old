#include<iostream>

using namespace std;

struct node{
	int val;
	node* next;
	node(int v,node* n=NULL):val(v),next(n){
	}
};

static node* root= new node(9);
void Add(node* n,bool& carry)
{
	
	if(!n->next)
	{
		if(n->val==9)
		{
			n->val=0;carry=1;
			
		}
		else
		{
			n->val+=1;carry=0;
		}
		return;
	}
	else
		Add(n->next,carry);
	
	if(carry)
	{
		if(n->val==9)
		{
			n->val=0;carry=1;
			if(n==root)
				root=new node(1,n);
		}
		else
		{
			n->val+=1;carry=0;
		}
	}
	//else
	//	return;
	
}

void print(node* n)
{
	cout<<"Number is: ";
	while(n)
	{
		cout<<n->val;
		n=n->next;
	}
	cout<<"\n";
}
int main()
{
	node* n=new node(9,new node(9,new node(9)));
	root->next=n;
	print(root);
	bool carry=false;
	Add(root,carry);
	print(root);
	return 0;
	
}
