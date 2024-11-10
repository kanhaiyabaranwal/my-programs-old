#include<iostream>
#include<vector>
using namespace std;


struct node{
	int val;
	node* next;
	node(int val,node* next=NULL):val(val),next(next) {}
};


void traverse(node* n1)
{
	while(n1)
	{
		cout<<n1->val<<",";
		n1=n1->next;
	}
	cout<<endl;
}

int point_of_intersection(node* n1,node* n2,vector<int>& ivec)
{
	node* n=n1;
	while(n1 && n2)
	{
		if(n1->val==n2->val)
		{
			ivec.push_back(n1->val);
			n1=n1->next;	
			n2=n2->next;	
		}
		else if(n1->val < n2->val)
			n1=n1->next;
		else
			n2=n2->next;
	}
	cout<<"Points of Intersection are:";
	for(int i=0;i<ivec.size();i++)
		cout<<ivec[i]<<",";
	cout<<endl;
	return 0;
}

void max_sum_path(node* n1,node*n2,vector<int>& ivec)
{
	int count=0;
	node* head1=n1, *head2=n2;
	node* head,*n;
	int sum1=0,sum2=0;
	while(head1 && head2 && count<ivec.size())
	{
		n1=head1,n2=head2;
		sum1=sum2=0;
		while(n1->val <= ivec[count])
		{
			sum1+=n1->val;
			n1=n1->next;
		}
		while(n2->val <= ivec[count])
		{
			sum2+=n2->val;
			n2=n2->next;
		}
		if(sum1>sum2)
		{
			head=head1;
			n=n1;
		}
		else
		{
			head=head2;
			n=n2;
		}
		while(head!=n)
		{
			cout<<head->val<<",";
			head=head->next;
			count++;
		}
		head1=n1;
		head2=n2;
	}
	sum1=0,sum2=0;
	n1=head1,n2=head2;
	while(n1)
	{
		sum1+=head1->val;
		n1=n1->next;
	}
	while(n2)
	{
		sum2+=head2->val;
		n2=n2->next;
	}
	if(sum1>=sum2)
	{
		head=head1;
		n=n1;
	}
	else
	{
		head=head2;
		n=n2;
	}
	while(head)
	{
		cout<<head->val<<",";
		head=head->next;
		count++;
	}
			
}

	
int main()
{
	node* n1=new node(1,new node(3,new node(30,new node(90,new node(120,new node(240,new node(511)))))));
	node* n2=new node(0,new node(3,new node(12,new node(32,new node(90,new node(125,new node(240,new node(249))))))));
	cout<<"Linked list1:";
	traverse(n1);
	cout<<"Linked list2:";
	traverse(n2);
	vector<int> ivec;
	point_of_intersection(n1,n2, ivec);
	cout<<"Max sum path is:";
	max_sum_path(n1,n2,ivec);
	cout<<endl;
	return 0;
}	
