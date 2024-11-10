#include<iostream>
using namespace std;
struct node{
	int val;
	node *next;
};


int main(){
	node *head=NULL;
	node *cur,*prev;
	int j=2,k=0,x=0,i=0;
	for(i=0;i<10;i++)
	{   
		if(!head)
		{
			head = new node();
			cur=head;
			head->val=0;
		}
		else
	 	{  
			if(j%2==0)
	  			k++;
	  		x=j;
	 		prev=cur;
	 		cur= new node();
	 		prev->next=cur;
	 		cur->val=x;
	 		cur->next=NULL;
	 		j++;
	 		if(k>=10)
	 			break;
	 		else 
	 			continue;
	}
	while(cur)
	{    
		int y;
     	y=cur->val;
		cout<<y;
	}
	return 0;
}
}

