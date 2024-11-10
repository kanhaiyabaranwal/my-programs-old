#include<iostream>
#include<queue>
using namespace std;

struct node{
	int val;
	node* right;
	node* down;
	node(int v=0,node* d=0,node* r=0):val(v),right(r),down(d) {
	}
	bool operator<(node* a,node* b) const
	{
		return a->val < b->val;
	}
};

priority_queue<node*, vector<node*> pq;

void traverse_linear_list(node * root)
{

	node* temp=root;
	int count=1;
	cout<<"count="<<count<<": ";
	while(temp->down)
	{
		cout<<temp->val<<"\t";
		temp=temp->down;
		
	}
	cout<<temp->val<<"\n";
	
}
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

void convert_to_linear_list(node * root)
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
		temp->down=right;
		temp=right;
	}
	//last down list
	cout<<"count="<<count<<": ";
	while(temp->down)
	{
		cout<<temp->val<<"\t";
		temp=temp->down;
		
	}
	cout<<temp->val<<"\t";
	
}

node* FindTail(node* root)
{
	node* temp=root;
	while(temp->down && !temp->down->right	)
	{
		temp=temp->down;
	}
	cout<<"tail of "<<root->val<<" is "<<temp->val<<endl;
	return temp;
}
void sort_linear_list(node * root)
{
	node* nodeSortedUntil=root;
	node* currentHead=root->right;
	node* cur=root->right;
	node* lastTail=FindTail(root);
	node* prev=lastTail;
	
	while(nodeSortedUntil->down)
	{
		//next head reached while sorting and navigating 
		if(nodeSortedUntil == currentHead)
		{
			currentHead = currentHead->right;
		}
		//move down the list until less than next head or current pointer
		while( nodeSortedUntil->down->val < currentHead->val && nodeSortedUntil->down->val < cur->val )
		{
			nodeSortedUntil = nodeSortedUntil -> down;
		}
		
		//if next val is different, needs to be correctly placed.
		if((currentHead && nodeSortedUntil->down->val > currentHead->val) ||
			(nodeSortedUntil->down->val > cur ->val) )
		{
			
			if(currentHead && currentHead == cur)
			{
				prev=cur;
				cur=cur->down;	
			}
			
			//cur is smaller, so move cur to place after nodeSortedUntil
			if( currentHead->val > cur->val)
			{
				prev->down=cur->down;
				cur->down=nodeSortedUntil->down;
				nodeSortedUntil->down=cur;
				cur=prev->down;
			}
			//current Head is smaller, move it after nodeSortedUntil
			else if( currentHead && nodeSortedUntil->down->val > currentHead->val)
			{
				lastTail->down=currentHead->down;
				
				//Find lastTail of currentHead now.
				lastTail=FindTail(currentHead);
				nodeSortedUntil->down=currentHead;
				currentHead->down = nodeSortedUntil->down;
				node* temp=currentHead;
				//new current Head
				currentHead=currentHead->right;
				temp->right=0;
			}
			else
			{
				cout<<"Something went bad\n";
			}
			
		}
	}
	
}

//sorting in n*m^2 where m is the length of horizontal list. Traversal m horizontal nodes to find smallest, remove the smallest and repeat again for all nodes i.e. n*m nodes.
void sort_original_list(node *root)
{
	vector<int> ivec;
	ivec.push_back(root->val);
	node* temp=root;
	if(root->down)
	{
		root->down->right=root->right;
		root=root->down;
		delete temp;
	}
	else if(root->right)
	{
		root=root->right;
		delete temp;
	}
	else	//only one node, no right, no down. return.
		return;
	cout<<"Sorting original list"<<endl;
	while(root)
	{
		node* temp=root->right;
		node* min=root;
		node* prev=root;
		node* min_prev=NULL;
		while(temp)
		{
			if(temp->val<min->val)
			{
				min_prev=prev;
				min=temp;
			}
			prev=temp;
			temp=temp->right;
		}
		ivec.push_back(min->val);
		//identify next root if min is root.
		if(min==root)
		{
			if(min->down)
			{
				root=min->down;
			}
			else
			{
				root=min->right;
			}
		}
		//remove min from the chain
		if(min->down)
		{
			if(min_prev)
				min_prev->right=min->down;
			min->down->right=min->right;
		}
		else
		{
			if(min_prev)
				min_prev->right=min->right;
		}
		delete min;
	}
	cout<<"Sorted list in n*m^2 order"<<endl;
	cout<<"ivec size is "<<ivec.size()<<endl;
	for( int i=0;i<ivec.size();i++)
		cout<<ivec[i]<<"\t";
	cout<<"\nsorting completed"<<endl;
}


int main()
{
	node* root=new node(5,new node(7,new node(8,new node(30))),new node(10,new node(20),new node(19,new node(22,new node(50)),new node(28,new node(35,new node(40,new node(45)))))));
	cout<<"Traversing entire list before conversion\n";
	traverse_list(root);
	
	//cout<<"Traversing list after sorting\n";
	//sort_original_list(root);
	
	
	cout<<"Traversing linear list before conversion\n";
	traverse_linear_list(root);
	node* temp=FindTail(root);
	convert_to_linear_list(root);
	cout<<"Traversing list after conversion\n";
	traverse_linear_list(root);
	
	cout<<"Sorting...\n";
	//sort_linear_list(root);
	
	
	traverse_linear_list(root);
	return 0;
}
