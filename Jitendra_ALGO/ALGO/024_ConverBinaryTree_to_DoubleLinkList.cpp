/*
http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
https://www.youtube.com/watch?v=Dte6EF1nHNo
http://www.techiedelight.com/place-convert-given-binary-tree-to-doubly-linked-list/
*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	node(int d) : data(d), left(NULL), right(NULL){}
};
void printList(node* head, node* terminater=NULL)
{
	if(head == NULL) return;
	cout << "\n\n" << head->data <<  " --> ";
	head= head->right;
	while(head != terminater)
	{
		cout << head->data <<  " --> ";
		head = head->right;
	}
	if(terminater)
		cout << terminater->data << "\n\n";
	else
		cout << "NULL \n\n";
}
/*
Convert binary tree to level order double link list
*/
node* convertLevelOrder(node* root)
{
	if(root == NULL) return root;
	queue<node*> q;
	q.push(root);
	node* prev=NULL;
	while(!q.empty())
	{
		node* current = q.front();q.pop();
		if(current->left)
			q.push(current->left);
		if(current->right)
			q.push(current->right);
		node* next = NULL;
		if(!q.empty())
			next = q.front();
		current->left = prev;
		current->right = next;
		prev = current;
	}
	return root;
}
/*
Convert binary tree to in-order link list : itretive method
left - visit - right
*/
node* convertInOrder_iterative(node* root)
{	
	if(root == NULL) return root;
	stack<node*> S;
	node *head = NULL, *prev = NULL, *current = root;
	while(true)
	{
		/* keep track left node path in the stack*/
		while(current != NULL)
		{
			S.push(current);
			current = current ->left;
		}
		if(S.empty())
			break;

		/* visit current node which is in the top of the stack */
		current = S.top(); S.pop();
		if(head == NULL) //first left most node is head
			head = current; 
		//adjust left, right pointer
		//prev right pointer is enough as last node will have right null
		current->left = prev;
		if(prev != NULL) 
			prev->right = current;

		/* now process right node */
		prev = current;
		current = current->right;;
	}
	return head;
}


// convert binary tree to in-order link list
// http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
void convertInOrder_recurssive(node* root, node* head) // --> TODO IMP
{

}

/*
Convert binary tree toreverse in-order link list : itretive method
right - visit - left
*/
node* convertReverseInOrder_iterative(node* root)
{	
	if(root == NULL) return root;
	stack<node*> S;
	node *head = NULL, *prev = NULL, *current = root;
	while(true)
	{
		/* keep track right node path in the stack*/
		while(current != NULL)
		{
			S.push(current);
			current = current ->right;
		}
		if(S.empty())
			break;

		/* visit current node which is in the top of the stack */
		current = S.top(); S.pop();
		if(head == NULL) //first right most node is head
			head = current; 
		//adjust left, right pointer
		node* left = current->left;
		current->left = prev;
		if(prev != NULL) 
			prev->right = current;

		/* now process left node */
		prev = current;
		current = left;
	}
	return head;
}


/*
* this method will merge two circular linklist to a single
* curcualr list : https://www.youtube.com/watch?v=Dte6EF1nHN
*/
node* mergeTwoCircularLists(node* a, node* b)
{
	if(!a) return b;
	if(!b) return a;

	node* aEnd = a->left;
	node* bEnd = b->left;

	a->left = bEnd; b->left = aEnd;
	aEnd->right =b; bEnd->right = a;

	return a;
}
//https://www.youtube.com/watch?v=Dte6EF1nHN
node* convertPreOrder_usingCircularMethod(node* root)
{
	if(!root) return root;
	//process left and right first
	node* leftList = convertPreOrder_usingCircularMethod(root->left);
	node* rightList = convertPreOrder_usingCircularMethod(root->right);
	//convert single node to double linklist
	root->left = root;
	root->right = root;
	//merge left, center and right in below order
	node* head = mergeTwoCircularLists(leftList, root);
	head = mergeTwoCircularLists(root, rightList);
	return head;
}



void post_order_traverse_iterative(node* root)
{

}

int main_24_ConverBinaryTree_to_DoubleLinkList()
{
	/*           10
	*         /      \
	*        12        15
	*      /   \      /   
	*     25   30    36
	*/
	// Create the tree shown in above diagram
	node *root        = new node(10);
	root->left        = new node(12);
	root->right       = new node(15);
	root->left->left  = new node(25);
	root->left->right = new node(30);
	root->right->left = new node(36);
	node *head = NULL;

	/* Convert to DLL in level order */
	//head = convertLevelOrder(root);
	//printList(head);

	/* Convert to DLL in-order traverse */
	//convertInOrder_noCircular(root, head);

	/* Convert to DLL pre-order traverse using circual merge method */
	//head = convertPreOrder_usingCircularMethod(root);
	//printList(head, head);

	/* Convert to DLL in-order traverse itretively*/
	//head = convertInOrder_iterative(root);
	//printList(head);

	/* Convert to DLL post-order traverse itretively*/
	head = convertReverseInOrder_iterative(root);
	printList(head);

	return 0;
}
