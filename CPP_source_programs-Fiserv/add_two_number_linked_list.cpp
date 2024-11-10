#include<iostream>
using namespace std;

struct node{
	int val;
	node* next;
	node(int val,node* next=NULL):val(val),next(next) {}
};

int sum(node* num1, node* num2, int len1,int len2,int& pow)
{
	int res;
	if(!num1 && !num2)
		return 0;
	if(len2>len1)
		return sum(num2,num1,len2,len1,pow);
	else if(len1>len2)
	{
		res=sum(num1->next,num2,len1-1,len2,pow);
		res+=num1->val*pow;
		pow*=10;
	}
	else
	{
		res=sum(num1->next,num2->next,len1-1,len2-1,pow);
		res+=pow*(num1->val+num2->val);
		pow*=10;
	}
	return res;
}
int main()
{
	//node* num1=new node(3,new node(2,new node(9)));
	node* num1=new node(4,new node(3,new node(2,new node(9))));
	node* num2=new node(6,new node(2,new node(3)));
	int pow=1;
	int res=sum(num1,num2,4,3,pow);
	cout<<"Sum is:"<<res<<endl;
	return 0;
}
		
		
