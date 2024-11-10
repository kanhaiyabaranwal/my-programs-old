/*
http://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/
*/


#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
struct node* newNode_ (int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int countNodes( node* root)
{
	if(root == NULL) return 0;
	return 1 + countNodes(root->left) + countNodes(root->right); 
}

void populateTempArry(int* A, node* root, int& index)
{
	if(root == NULL) return;
	populateTempArry(A, root->left,index);
	A[index++] = root->data;
	populateTempArry(A, root->right,index);
}
void assignFromTempArray(int* A, node* root, int& index)
{
	if(root == NULL) return;
	assignFromTempArray(A, root->left,index);
	root->data = A[index++];
	assignFromTempArray(A, root->right,index);
}

void binaryTreeToBST (node* root)
{
	if(root == NULL) return;
	int n = countNodes(root);

	//int* tempArray = new int[n];
	int tempArray[5];
	int index=0;
	populateTempArry(tempArray, root, index);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if( tempArray[i] < tempArray[j])
			{
				int tmp = tempArray[i];
				tempArray[i] = tempArray[j];
				tempArray[j] = tmp;
			}
		}
	}
	index = 0;
	assignFromTempArray(tempArray, root, index);
}

void printInorder (node* root)
{
	if(root == NULL) return;
	printInorder(root->left);
	cout << root->data << "  ";
	printInorder(root->right);
}

int main_37_Convert_BinaryTree_to_BST()
{
	struct node *root = NULL;
	/* Constructing tree given in the above figure
	.          10
	.        /  \
	.        30   15
	.       /      \
	.      20       5   
	*/
	root = newNode_(10);
	root->left = newNode_(30);
	root->right = newNode_(15);
	root->left->left = newNode_(20);
	root->right->right = newNode_(5);

	printInorder (root);
	cout << endl;

	// convert Binary Tree to BST
	binaryTreeToBST (root);

	cout << "Following is Inorder Traversal of the converted BST: \n";
	printInorder (root);

	return 0;
}