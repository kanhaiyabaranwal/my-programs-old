/*
http://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/
*/

#include<iostream>
using namespace std;


struct Node{
	int data;
	Node* prev;
	Node* next;
	Node(int d) : data(d), prev(NULL), next(NULL){};
};

/* Function to insert a node at the beginging of the Doubly Linked List */
void push(Node* &head_ref, int new_data)
{
	Node* new_node = new Node(new_data);
	/* link the old list off the new node */
	new_node->next = head_ref;
	/* change prev of head node to new node */
	if(head_ref !=  NULL)
		head_ref->prev = new_node ;
	/* move the head to point to the new node */
	head_ref = new_node;
}

int countDLL(Node* head)
{
	int count = 0;
	while(head != NULL) { count++; head = head->next;}
	return count;
}

void inOrderUtil(struct Node* root)
{
	if (root == NULL) return;
	inOrderUtil(root->prev);
	cout << root->data << "  ";
	inOrderUtil(root->next);
}
void printInOrder(struct Node* root)
{
	cout << "\nBST inOrder : ";
	inOrderUtil(root);
	cout << endl;
}
void printDLL(Node* head)
{
	if(head == NULL) return;
	Node* tail = NULL;
	cout << "\nDLL from head->tail : " ;
	while(head != NULL)
	{
		cout << head->data << "  ";
		tail = head;
		head = head->next;
	}
	cout << "\nDLL from tail->head : " ;
	while(tail != NULL)
	{
		cout << tail->data << "  ";
		tail = tail->prev;
	}
	cout << endl;
}

Node* convertDLLtoBSTUtil( Node* &head, int n)
{
	if(n <= 0) return NULL;
	Node* left = convertDLLtoBSTUtil(head, n/2);
	Node* root = head; head = head->next;
	Node* right = convertDLLtoBSTUtil(head, n - n/2 -1);
	root->prev = left;
	root->next = right;
	return root;
}

Node* convertDLLtoBST( Node* head)
{
	int n = countDLL(head);
	//Node* root;
	return convertDLLtoBSTUtil(head,n);
}

int main_39_ConversionSortedDLL_to_BalancedBST()
{
	struct Node* head = NULL;
	//linked list 1 <--> 2 <--> 3 <--> 4 <--> 5 <--> 6 <--> 7 
	push(head, 7);
	push(head, 6);
	push(head, 5);
	push(head, 4);
	push(head, 3);
	push(head, 2);
	push(head, 1);
	printDLL(head);

	Node* bstRoot = convertDLLtoBST(head);
	printInOrder(bstRoot);

	return 0;
}