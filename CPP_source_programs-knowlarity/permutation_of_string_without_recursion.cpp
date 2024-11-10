#include<iostream>
#include<string>
using namespace std;


struct node{
	string str;
	int state;
	node* next;
	node(string str,int state,node* next=NULL):str(str),state(state),next(next) {}
};

string swap(string str,int i,int j)
{
	char a=str[i];
	str[i]=str[j];
	str[j]=a;
	return str;
}	
void permute( string str)
{
	node* top=new node(str,0);
	node* cur,*next; 
	int len=str.length();
	while(top)
	{
			
		if(top->state==len-1)
			cout<<top->str<<endl;
		//add new states from cur to end and append to the linked list
		int cur_state=top->state;
		string cur_str=top->str;
		cur=top->next;
		delete top;
		for(int i=cur_state;i<len;i++)
		{
				
			cur=new node(swap(cur_str,cur_state,i),cur_state+1,cur);
		}
		top=cur;
	}
}

int main()
{
	string str="1234";
	permute(str);
	return 0;
}
			
		
