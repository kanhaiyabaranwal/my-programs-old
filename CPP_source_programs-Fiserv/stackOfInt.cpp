#include<iostream>
using namespace std;

class stack{
struct LLNode{
	int data;
	LLNode *next;
	LLNode(int i,LLNode *pNext=0): data(i),next(pNext) {}
	};
	LLNode *head;
	public:
	stack():head(0) {}
	int push(int dat);
	int pop();
	int peek();
};
int stack::push(int dat){
		
		head = new LLNode(dat,head);
		if(!head)
		{
			cout<<"failed to push entry data "<<dat<<" into the stack\n";
			return -1;
		}
		return 0;
	}
int stack::pop(){
		int dat=head->data;
		LLNode *temp=head;
		head=head->next;
		delete temp;
		return dat;
	}
int stack::peek(){
		if(head)
			return head->data;
		else
		{
			cout<<"No data in stack\n";
			return 0;
		}
	}

int main(){
	stack stk;
	stk.push(4);
	stk.push(5);
	stk.push(7);
	while(1){
	int i=stk.peek();
		if(!i)
		{
			cout<<"No more data, darling\n";
			break;
		}
		cout<<"data on the top of stack is "<<i<<endl;
		i=stk.pop();
		cout<<"data popped is "<<i<<endl;
	}
	return 0;
}



