/*
http://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/
http://www.geeksforgeeks.org/check-whether-binary-tree-complete-not-set-2-recursive-solution/
*/

#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

//todo -- isCompleteBT in recurssive method

//iterative method
bool isCompleteBT_Iterative(node* head)
{
	if(head == NULL) return true;

	queue<node*> Q;
	bool mismatch = false;
	Q.push(head);

	while(!Q.empty())
	{
		node* current = Q.front();Q.pop();
		//basic condition check if left is null then there should no right
		if(current->left == NULL && current->right != NULL)
			return false;
		//if already mismatch happened then there should be no child
		if(mismatch == true && (current->left != NULL || current->right != NULL))
			return false;
		//check if mismatch happended, i.e. one child is null
		if(current->left == NULL || current->right == NULL)
			mismatch = true;
		//push children
		if( current->left != NULL) Q.push(current->left); 
		if(current->right != NULL) Q.push(current->right);
	}
	return true;
}

int main_30_CheckGivenBinaryTree_isComplete()
{
	/* Let us construct the following Binary Tree which
	.     is not a complete Binary Tree
	.            1
	.          /   \
	.         2     3
	.        / \     \
	.       4   5     6
	*/
	struct node *root  = newNode(1);
	root->left         = newNode(2);
	root->right        = newNode(3);
	root->left->left   = newNode(4);
	root->left->right  = newNode(5);
	root->right->right = newNode(6);

	if ( isCompleteBT_Iterative(root) == true )
		printf ("Complete Binary Tree");
	else
		printf ("NOT Complete Binary Tree");

	return 0;
}
