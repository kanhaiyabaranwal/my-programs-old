#include<iostream>
using namespace std;


struct Node{
	Node* next;
	char c;
	Node(char ch,Node* n=0):c(ch),next(n)	{}
} ;
	
bool IsPalindrom(Node* root)
{
	static Node* cur=root;
	if(root->next )
		if( !IsPalindrom(root->next))
			return false;
		
	if(cur->c!=root->c)
	{
		cout<<cur->c<<" from beginning didn't match with "<<root->c<<" from the end"<<endl;
		return false;
	}
	else
	{
		cout<<cur->c<<" from beginning matched with "<<root->c<<" from the end"<<endl;
		cur=cur->next;
		return true;
	}
}
int main()
{
	char str[20];
	cout<<"Enter string-> ";
	cin>>str;
	Node* root=new Node(str[0]);
	Node* prev=root;
	Node* cur;
	char *pch=&str[1];
	while(*pch)
	{
		cur=new Node(*pch);
		prev->next=cur;
		prev=cur;
		pch++;
	}
	Node *temp=root;
	cout<<"traversing linked list\n";
	while(temp)
	{
		cout<<temp->c<<",";
		temp=temp->next;
	}
	cout<<"string is "<<str<<endl;
	if(IsPalindrom(root))
		cout<<"It's palindrom"<<endl;
	else
		cout<<"It's not palindrom"<<endl;
	return 0;
}

	

