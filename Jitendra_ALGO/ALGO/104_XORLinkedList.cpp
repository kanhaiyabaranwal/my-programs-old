/*
https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/
https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-2/
XOR Linked List – A Memory Efficient Doubly Linked List
-------------------------------------------------------
An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes.
A memory efficient version of Doubly Linked List can be created using only one space for address field with every node.
This memory efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bitwise XOR operation to save space for one address.
In the XOR linked list, instead of storing actual memory addresses, every node stores the XOR of addresses of previous and next nodes.
*/
#include <iostream>
using namespace std;

namespace NS104
{
	struct Node; //forward declaration 

	inline Node* XOR(Node* a, Node* b)
	{
		return reinterpret_cast<Node*>(reinterpret_cast<int>(a) ^ reinterpret_cast<int>(b));
	}

	struct Node
	{
		int data;
		Node* xorPtr; // XOR of previous and next pointer
		Node(int v) : data(v), xorPtr(NULL) {}
		Node* nextPtr(Node* prev) { return XOR(xorPtr, prev); }
		Node* prevPtr(Node* next) { return XOR(xorPtr, next); }
	};

	//to-do -- insert and delete at random location

	void insert_front(Node*& head, int value)
	{
		Node* newNode = new Node(value);
		newNode->xorPtr = head;
		if (head != NULL)
			head->xorPtr = XOR(head->xorPtr, newNode);
		head = newNode;
	}

	void print_forward(Node* head)
	{
		Node* prev = NULL;
		Node* next = NULL;
		while (head != NULL)
		{
			cout << head->data << " -> ";
			next = head->nextPtr(prev);
			prev = head;
			head = next;
		}
		cout << "NULL";
	}

	void print_backward(Node* tail)
	{
		Node* prev = NULL;
		Node* next = NULL;
		cout << "NULL";
		while (tail != NULL)
		{
			cout << " <- " << tail->data;
			prev = tail->prevPtr(next);
			next = tail;
			tail = prev;
		}
	}

	void test()
	{
		/* Create following Doubly Linked List
		head-->40<-->30<-->20<-->10   */
		Node *head = NULL;
		insert_front(head, 10);	Node* tail = head;
		insert_front(head, 20);
		insert_front(head, 30);
		insert_front(head, 40);
		// print the created list
		print_forward(head); cout << endl;
		print_backward(tail); cout << endl;
	}
}
int main_104()
//int main()
{
	NS104::test();
	return 0;
}