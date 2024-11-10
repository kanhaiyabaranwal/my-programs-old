/*
http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
*/
#include<iostream>
using namespace std;
/* Link list node */
struct LNode
{
	int data;
	struct LNode* next;
	LNode(int d) : data(d), next(NULL){}
};
/* A Binary Tree node */
struct TNode
{
	int data;
	struct TNode* left;
	struct TNode* right;
	TNode(int d) : data(d), left(NULL), right(NULL){}
};

void push(struct LNode** head_ref, int data)
{
	LNode* new_node = new LNode(data);
	/* link the old list off the new node */
	new_node->next = (*head_ref);
	/* move the head to point to the new node */
	(*head_ref)    = new_node;
}

void printList(struct LNode *node)
{
	while(node!=NULL)
	{
		cout <<  node->data << "  ";
		node = node->next;
	}
	cout << endl;
}

int coutLNodes(LNode* head)
{
	int count =0;
	while(head != NULL)
	{
		head = head->next;
		count++;
	}
	return count;
}

void preOrder(struct TNode* root)
{
	if (root == NULL)
		return;
	cout << root->data << "  ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(struct TNode* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->data << "  ";
	inOrder(root->right);
}

TNode* sortedListToBSTUtil(LNode* &head, int n)
{
	if(n<=0)
		return NULL;

	TNode* left = sortedListToBSTUtil(head, n/2);  // process left

	TNode* node = new TNode(head->data); // process current 
	head = head->next;	
	node->left = left;
	node->right = sortedListToBSTUtil(head, n - n/2 -1); // process right

	return node;
}

TNode* sortedListToBST(LNode* head)
{
	if(head == NULL) return NULL;
	int n = coutLNodes(head);
	return sortedListToBSTUtil(head,n);
}



int main_38_SortedSingleLinkedList_to_BalancedBST()
{
	/* Start with the empty list */
	struct LNode* head = NULL;

	/* Let us create a sorted linked list to test the functions
	Created linked list will be 1->2->3->4->5->6->7 */
	/* 
	push(&head, 7);
	push(&head, 6);
	push(&head, 5); 
*/
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout << "Given Linked List \n";
	printList(head);

	/* Convert List to BST */
	TNode *root = sortedListToBST(head);

	cout<< "\n PreOrder Traversal of constructed BST ";
	preOrder(root);

	cout<< "\n InOrder Traversal of constructed BST ";
	inOrder(root);

	cout << endl;
	return 0;
}