
#include<iostream>
using namespace std;

struct node{
	char val;
	node* next;
	node(int val,node*next=NULL):val(val),next(next) {}
};
void traverse(node* root)
{
	cout<<"Traversing LL:";
	while(root)
	{
		cout<<root->val<<",";
		root=root->next;
	}
	cout<<endl;
}


int palindrom_length(node* back,node* forward)
{
	int len=0;
	while(back && forward && (back->val==forward->val))
	{
		len+=2;
		back=back->next;
		forward=forward->next;
	}
	return len;
}
int largest_palindrom(node* root)
{
	if(!root)
		return 0;
	node* cur=root;
	node* prev=NULL;
	node* next;
	int gl=1;
	while(cur->next)
	{
		next=cur->next;
		int l1=1+palindrom_length(prev,next);
		if(cur->val==next->val)
		{
			int l2=2+palindrom_length(prev,next->next);
			if(l2>l1)
				l1=l2;
		}
		if(l1>gl)
		{
			gl=l1;
			cout<<"Largest Palindrom until now starts from "<<cur->val<<" and length is "<<gl<<endl;
		}
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	cur->next=prev;
	traverse(cur);
	cout<<"Largest Palindrom until now starts from "<<cur->val<<" and length is "<<gl<<endl;
	return gl;
	
}

int main()
{
	//node* root=new node('e',new node('b',new node('a',new node('d',new node('d',new node('a',new node('b',new node('a'))))))));
	node* root=new node('e',new node('a',new node('d',new node('d',new node('a',new node('d'))))));
	traverse(root);
	int l=largest_palindrom(root);
	return 0;
}		
	
