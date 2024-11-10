#include<iostream>
using namespace std;

struct node{
	char ch;
	node* next;
	node(char ch,node* next=NULL):ch(ch),next(next){
	}
};

bool CheckPalindrom(node* &root,node* end, bool& found)
{
	if(!end)
		return true;
	
	if(end->next && !CheckPalindrom(root,end->next,found))
		return false;
	if(root->next==end || root==end)
	{
		found=1;
		return true;
	}
	else if(root->ch==end->ch)
	{
		root=root->next;
		
		return true;
	}
	else
		return false;
}

int main()
{
	node* root=new node('a',new node('b',new node('c',new node('b',new node('b')))));
	node* cur=root;
	cout<<"String is:";
	while(cur)
	{
		cout<<cur->ch<<",";
		cur=cur->next;
	}
	cout<<endl;
	bool found=0;
	CheckPalindrom(root,root,found);
	if(found)
		cout<<"It is palindrom"<<endl;
	else
		cout<<"It is not a palindrom"<<endl;
	return 0;
}

