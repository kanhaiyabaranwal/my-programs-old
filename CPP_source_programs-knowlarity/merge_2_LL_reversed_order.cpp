#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int key;
    struct Node* next;
};

/* Utility function to create a new node with
   given key */
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 

/* Function to print Nodes in a given linked list */
void printList(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->key << " ";
        Node = Node->next;
    }
}

Node *SortedMerge(Node *root1,Node *root2)
{
	Node* cur=NULL;
	while(root1 && root2)
	{
		if(root1->key <=root2->key)
		{
			Node* temp=root1->next;
			root1->next=cur;
			cur=root1;
			root1=temp;
		}
		else
		{
			Node* temp=root2->next;
			root2->next=cur;
			cur=root2;
			root2=temp;
		}
	}
	while(root1)
	{
		Node* temp=root1->next;
		root1->next=cur;
		cur=root1;
		root1=temp;
	}
	while(root2)
	{
		Node* temp=root2->next;
		root2->next=cur;
		cur=root2;
		root2=temp;
	}
	return cur;
}

 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* res = NULL;
 
    /* Let us create two sorted linked lists to test
       the above functions. Created lists shall be
         a: 5->10->15
         b: 2->3->20  */
    Node *a = newNode(5);
    a->next = newNode(10);
    a->next->next = newNode(15);
 
    Node *b = newNode(2);
    b->next = newNode(3);
    b->next->next = newNode(20);
 
    cout << "List A before merge: \n";
    printList(a);
 
    cout << "\nList B before merge: \n";
    printList(b);
 
    /* merge 2 increasing order LLs in descresing order */
    res = SortedMerge(a, b);
 
    cout << "\nMerged Linked List is: \n";
    printList(res);
 
    return 0;
}
