#include<iostream>
#include<set>
#include<ctime>
#include<cstdlib>
using namespace std;

struct Node{
	Node* next;
	int nbr;
	Node(int n,Node* node=0):nbr(n),next(node) {}
};

int main()
{
	Node* root1=0, *root2=0,*cur=0;
	srand(time(NULL));
	//create first LL
	Node* cross;
	for(int i=0;i<6;i++)
	{
		cur=new Node(rand()%10,cur);
		if(i==3)
			cross=cur;
	}
	root1=cur;
	cout<<endl;
	while(cur)
	{
		cout<<"\t"<<cur->nbr<<",";
		cur=cur->next;
	}
	cout<<endl;
	//create second LL
	cur=0;
	Node* end=0;
	for(int i=0;i<6;i++)
	{
		cur=new Node(rand()%10,cur);
		if(!cur->next)
			cur->next=cross;
	}
	root2=cur;
	cout<<"Second Linked List"<<endl;
	while(cur)
	{
		cout<<"\t"<<cur->nbr<<",";
		cur=cur->next;
	}
	cout<<endl;
	set<Node*> nset;
	cur=root1;
	while(cur)
	{
		nset.insert(cur);
		cur=cur->next;
	}
	set<Node*>::const_iterator iter;
	for(cur=root2;cur;cur=cur->next)
	{
		iter=nset.find(cur);
		if(iter!=nset.end())
		{
			cout<<"LL crossing found\n";
			break;
		}
	}
	return 0;
}

	
