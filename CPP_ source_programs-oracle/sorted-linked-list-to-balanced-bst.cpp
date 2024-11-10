//sorted-linked-list-to-balanced-bst
#include<iostream>

using namespace std;

struct tnode {
	int val;
	tnode* left;
	tnode* right;
	tnode(int v=0,tnode* l=NULL,tnode* r=NULL):val(v),left(l),right(r){
		
	}
};

struct llnode {
	int val;
	llnode* next;
	llnode(int v,llnode *n=NULL):val(v),next(n){
	}
};


void traverse(llnode * cur)
{
	while(cur)
	{
		cout<<cur->val<<",";
		cur=cur->next;
	}
	cout<<endl;
}

void inorder_traverse(tnode * cur)
{
	if(cur->left)
		inorder_traverse(cur->left);
	cout<<cur->val<<",";
	if(cur->right)
		inorder_traverse(cur->right);
	
}


int count(llnode * head,llnode* &mid)
{
	llnode* fast=head;
	llnode* slow=head;
	int count=0;
	cout<<"counting"<<endl;
	while(fast->next && fast->next->next)
	{
		fast=fast->next->next;
		slow=slow->next;
		count++;
		cout<<"Counter "<<count<<endl;
	}
	cout<<"Outside while"<<endl;
	mid=slow;
	return count;
}

tnode* LL2BSTUtil(llnode* &head,int n)
{
	if(n==0)
		return NULL;
	/*if(n==1)
	{
		tnode* root=new tnode(head->val);
		head=head->next;
		return root;
	}
	if(n==2)
	{
		tnode* root=new tnode(head->val);
		head=head->next;
		root->right= new tnode(head->val);
		head=head->next;
		return root;
	}
	if(n==3)
	{
		tnode* root=new tnode(head->next->val);
		root->left= new tnode(head->val);
		head=head->next->next;
		root->right= new tnode(head->val);
		head=head->next;
		return root;
	}*/
	tnode* mid=new tnode();
	mid->left=LL2BSTUtil(head,n/2);
	mid->val=head->val;
	head=head->next;
	mid->right= LL2BSTUtil(head,n-(n/2+1));
	return mid;
}

tnode* LL2BST(llnode* head)
{
	llnode* mid;
	int n=count(head,mid);
	cout<<"N="<<n<<" , mid="<<mid->val<<endl;
	
	//return LL2BSTUtil(head,n); 
	
	tnode *root=new tnode(mid->val);
	
	root->left=LL2BSTUtil(head,n/2);
	head=head->next;
	root->right=LL2BSTUtil(head,n-(n/2+1));
	return root;

}
int main()
{
	llnode* head=new llnode(1,new llnode(2,new llnode(3,new llnode(4,new llnode(5,new llnode(6,new llnode(7,new llnode(8,new llnode(9)))))))));
	cout<<"Traversing linked list"<<endl;
	traverse(head);
	tnode* root=LL2BST(head);
	cout<<"Inorder traversal"<<endl;
	inorder_traverse(root);
	return 0;
}

