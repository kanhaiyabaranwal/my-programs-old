#include<iostream>
#include<queue>
#include<unordered_map>
#include<map>
#include<iomanip>

using namespace std;
using namespace std::tr1;

struct node{
	int val;
	int hd;
	node* left;
	node* right;
	node(int val,node* left=NULL,node* right=NULL):val(val),left(left),right(right),hd(0) {}
};

typedef map<int,int> MAP;

int bottom_view(node* root)
{
	node* dummy=new node(-1);
	queue<node*> q;
	node* front;
	q.push(root);
	q.push(dummy);
	MAP mmap;
	while(q.size()>1)
	{
		front=q.front();
		if(front->val==-1)
			q.push(dummy);
		else
		{
			if(front->left)
			{
				front->left->hd=front->hd-1;
				q.push(front->left);
			}
			if(front->right)
			{
				front->right->hd=front->hd+1;
				q.push(front->right);
			}
			mmap[front->hd]=front->val;
		}
		q.pop();
	}
	MAP::const_iterator iter=mmap.begin();
	cout<<"Vertical level    node"<<endl;	
	while(iter!=mmap.end())
	{
		cout<<setw(14)<<iter->first<<setw(7)<<iter->second<<endl;
		iter++;
	}
	return 0;
}
int main()
{
	node* root=new node(1,new node(2,new node(4,NULL,new node(8,NULL,new node(9))),new node(5)),new node(3,NULL,new node(6,new node(7))));
	cout<<"Bottom view of the tree"<<endl;
	bottom_view(root);
	return 0;
}
	
			
				
			
