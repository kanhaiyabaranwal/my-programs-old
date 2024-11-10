#include<iostream>
using namespace std;

struct node{
	int val;
	node* next;
	node(int val,node* next=NULL):val(val),next(next){
	}
};

int IsPalindrom(node* root,int n)
{
	static node* next_half;
	if(n==1)
	{
		next_half=root->next->next;
		if(root->val==next_half->val)
			return true;
		else
			return false;
	}
	if(IsPalindrom(root->next,n-1))
	{
		next_half=next_half->next;
		if(root->val==next_half->val)
			return true;
		else 
			return false;
	}	
	else
		return false;
}
int main()
{
	node *head=new node(3,new node(2,new node(7,new node(6,new node(7,new node(2,new node(3)))))));
	int len=3;
	node* cur=head;
	cout<<"String is :";
	while(cur)
	{
		cout<<cur->val;
		cur=cur->next;
	}
	cout<<endl;
	if(IsPalindrom(head,3))
		cout<<"This is a palindrom"<<endl;
	else	
		cout<<"Not a palindrom"<<endl;
	return 0;
}
