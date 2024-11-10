#include<iostream>
#include<queue>
using namespace std;

struct node{
	int val;
	node* right;
	node* down;
	node(int v=0,node* d=0,node* r=0):val(v),right(r),down(d) {
	}
	bool operator < (node * a) const
	{
		return val < a->val;
	}
};

void traverse_list(node * root)
{
	node* right;
	node* temp=root;
	int count=1;
	while(temp->right)
	{
		right=temp->right;
		
		cout<<"count="<<count<<": ";
		while(temp->down)
		{
			cout<<temp->val<<"\t";
			temp=temp->down;
			
		}
		cout<<temp->val<<"\t";
		cout<<endl;
		count++;
		//temp->down=right;
		temp=right;
	}
	//last down list
	cout<<"count="<<count<<": ";
	while(temp->down)
	{
		cout<<temp->val<<"\t";
		temp=temp->down;
		
	}
	cout<<temp->val<<"\n";
	
}

class Compare
{
public:
    bool operator() (node* a, node* b)
    {
        return a->val > b->val;
    }
};

int main()
{
	node* root=new node(5,new node(7,new node(8,new node(30))),new node(10,new node(20),new node(19,new node(22,new node(50)),new node(28,new node(35,new node(40,new node(45)))))));
	cout<<"Traversing entire list before conversion\n";
	traverse_list(root);

	priority_queue<node*,vector<node*>, Compare> pq;
	
	node* temp=root;
	//pq.push(root);
	while(temp)
	{ 
		pq.push(temp);
		temp=temp->right;
	}
	cout<<"Sorting...\n";
	while(pq.size())
	{
		
		node* n=pq.top();
		cout<<pq.top()->val<<"\t";
		pq.pop();
		//n1->val=n1->down->val;
		if(n->down)
		{
			//cout<<"inserting: "<<n->down->val;
			pq.push(n->down);
		}
		
		
	}
	cout<<"\n Sorting completed"<<endl;	
	
	
	
	//sort_linear_list(root);
	
	
	
	return 0;
}
