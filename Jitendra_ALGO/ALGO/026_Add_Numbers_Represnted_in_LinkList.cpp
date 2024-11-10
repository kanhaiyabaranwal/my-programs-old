#include<iostream>
using namespace std;


struct DNode
{
	int disit;
	DNode* next;
	DNode* prev;
	DNode(int d) : disit(d), next(NULL), prev(NULL){}
};


int addDigit( int& carry, int num1, int num2 )
{
	int sum = carry + num1 + num2;
	if(sum < 10)
		carry =0;
	else
	{
		sum = sum - 10;
		carry = 1;
	}
	return sum;
}


DNode* sum( DNode* num1, DNode* num2)   //todo
{
	if(num1 == NULL) return num2; if(num2 == NULL) return num1;
	DNode *end1 = num1, *end2 = num2;
	while(end1->next != NULL) end1 = end1->next;
	while(end2->next != NULL) end2 = end2->next;

	int carry = 0;
	DNode* result = NULL;
	while(end1 != NULL && end2 != NULL)
	{
		int sum  = addDigit(carry, end1->disit, end2->disit);
		DNode *node = new DNode(sum);
		if(result == NULL)
		{
			result = node;
		}
		else
		{
			node->next = result;
			result ->prev = node;
			result = node;
		}
		end1 = end1->prev;
		end2 = end2->prev;
	}
	DNode* leftOver = end1 ? end1 : end2;
	while(leftOver)
	{
		int sum  = addDigit(carry, leftOver->disit, 0);
		DNode *node = new DNode(sum);
		node->next = result;
		result ->prev = node;
		result = node;
		leftOver = leftOver->prev;
	}
	if( carry != 0)
	{
		DNode *node = new DNode(carry);
		node->next = result;
		result ->prev = node;
		result = node;
	}
	return result;
}

void print(DNode* head)
{
	while(head)
	{
		cout << head->disit;
		head = head->next;
	}
	cout << endl;
}

int main_26_Add_Numbers_Represnted_in_LinkList()
{
	// number1 represent 1->9->9->9
	DNode* number1 = new DNode(1);
	number1->next = new DNode(9); number1->next->prev = number1;
	number1->next->next = new DNode(9); number1->next->next->prev = number1->next;
	number1->next->next->next = new DNode(9); number1->next->next->next->prev = number1->next->next;

	//number2 reperent 9->9
	DNode* number2 = new DNode(9);
	number2->next = new DNode(9); number2->next->prev = number2;
	DNode* result = sum(number1, number2);

	cout << "number1 = " ; print(number1);
	cout << "number2 = " ; print(number2);
	cout << "result = " ; print(result);

	return 0;
}