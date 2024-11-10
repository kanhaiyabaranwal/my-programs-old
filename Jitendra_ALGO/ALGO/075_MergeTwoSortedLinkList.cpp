/*
http://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
Write a SortedMerge() function that takes two lists, each of which is sorted in increasing order,
and merges the two together into one list which is in increasing order.
SortedMerge() should return the new list. The new list should be made by splicing
together the nodes of the first two lists.

Example :-
First  linked list a is 5->10->15
Second linked list b is 2->3->20,
Result/Merged list 2->3->5->10->15->20.
*/
#include<iostream>
using namespace std;

namespace NS75
{
	struct Node
	{
		int data;
		struct Node* next;
	};
	Node* SortedMerge_R2(Node* a, Node* b)
	{
		if (!a) return b;
		if (!b) return a;

		Node* small = a->data < b->data ? a : b;
		Node* big = small == a ? b : a;

		small->next = SortedMerge_R2(small->next, big);
		return small;
	}
	void SortedMerge_R(Node* a, Node* b, Node* &newHead)
	{
		if (!a) newHead = b;
		if (!b) newHead = a;
		if (!a || !b) return;

		Node* small = a->data < b->data ? a : b;
		Node* big = small == a ? b : a;
		Node* smallNext = small->next;
		newHead = small;
		SortedMerge_R(smallNext, big, newHead->next);
	}
	Node* SortedMerge(Node* a, Node* b)
	{
		if (a == NULL) return b;
		if (b == NULL) return a;

		Node *head, *tail;
		if (a->data < b->data)
		{
			head = tail = a; a = a->next;
		}
		else
		{
			head = tail = b; b = b->next;
		}
		while (a || b)
		{
			if (!a)
			{
				tail->next = b; break;
			}
			if (!b)
			{
				tail->next = a; break;
			}
			if (a->data < b->data)
			{
				tail->next = a; a = a->next;
			 }
			else
			{
				tail->next = b; b = b->next;
			}
			tail = tail->next;
		}
		return head;
	}
	void printList(Node* node)
	{
		while (node != NULL)
		{
			cout << node->data << "  ";
			node = node->next;
		}
		cout << endl;
	}
	void push(struct Node** head_ref, int new_data)
	{
		Node* new_node = new Node();
		new_node->data = new_data;
		new_node->next = (*head_ref);
		/* move the head to point to the new node */
		(*head_ref) = new_node;
	}
	void main()
	{
		/* Start with the empty list */
		struct Node* res = NULL;
		struct Node* a = NULL;
		struct Node* b = NULL;
		/* a: 5->10->15 */
		push(&a, 15);
		push(&a, 10);
		push(&a, 5);
		/* b: 2->3->20 */
		push(&b, 20);
		push(&b, 3);
		push(&b, 2);
		/* Merge list */
		//res = SortedMerge(a, b);
		//SortedMerge_R(a, b, res);
		res = SortedMerge_R2(a, b);
		cout << "Merged Linked List is: \n";
		printList(res);
	}
}

int main_75()
{
	NS75::main();
	return 0;
}
