/*
https://www.youtube.com/watch?v=MILxfAbIhrE
http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

Check if Binary Tree is Binary Search Tree
A program to check if a binary tree is BST or not
*/
#include<iostream>
using namespace std;
namespace NS69
{
	struct node
	{
		int data;
		struct node* left;
		struct node* right;
		node(int d) : data(d), left(NULL), right(NULL){}
	};
	bool isBSTUtil(node* root, int left, int right)
	{
		if(root == NULL) return true;
		if(root->data > right || root->data < left) return false;
		return isBSTUtil(root->left, left, root->data) && isBSTUtil(root->right, root->data,right);
	}
	bool isBST(node* root)
	{
		return isBSTUtil(root, INT_MIN, INT_MAX);
	}
	//---------------------------------------------------------------------//
	bool isBSTInorderTravelUtil(node* root, node* &prev)
	{
		bool is_bst = true;
		if(root == NULL) return is_bst;

		is_bst = isBSTInorderTravelUtil(root->left, prev);

		if(is_bst && prev != NULL)
			is_bst = prev->data <= root->data;

		prev = root;
		if(is_bst)
			is_bst = isBSTInorderTravelUtil(root->right, prev);

		return is_bst;
	}
	bool isBSTInorderTravel(node* root)
	{
		node* prev = NULL;
		return isBSTInorderTravelUtil(root, prev);
	}
	void test()
	{
		node *root        = new node(4);
		root->left        = new node(2);
		root->right       = new node(5);
		root->left->left  = new node(1);
		root->left->right = new node(3); 

		if(isBSTInorderTravel(root))
			cout << "Is BST\n" ;
		else
			cout << "Not a BST\n";
	}
	void test2()
	{
		node *root        = new node(3);
		root->left        = new node(2);
		root->right       = new node(5);
		root->left->left  = new node(1);
		root->left->right = new node(4);

		if (isBSTInorderTravel(root))
			cout << "Is BST\n";
		else
			cout << "Not a BST\n";
	}
}

int main_69()
{
	NS69::test();NS69::test2();
	return 0;
}