/*
https://www.youtube.com/watch?v=4fiDs7CCxkc
http://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
Problem Stattement: 
Given a Binary Tree, write a function that returns the size of the largest 
subtree which is also a Binary Search Tree (BST). 
If the complete Binary Tree is BST, then return the size of whole tree.
*/
#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
	Node(T d) : data(d), left(NULL), right(NULL){}
};
typedef Node<int> node;

struct Result
{
	bool isBST;
	int max;
	int min;
	int size;
	Result(bool _isBST, int _max, int _min, int _size) :
	isBST(_isBST), max(_max), min(_min), size(_size){}
	Result(const Result& o)
	{
		isBST = o.isBST;   max = o.max;
		min = o.min;       size = o.size;
	}
};

Result largestBSTUtil(node* head)
{
	if(head == NULL)
		return Result(true, 0, 0,0);
	Result l = largestBSTUtil(head->left);
	Result r = largestBSTUtil(head->right);

	bool isBSt = l.isBST && r.isBST && 
		(l.size ==0 || l.max <= head->data) && 
		(r.size ==0 || r.min > head->data) ;

	int max = r.size ? r.max : head->data;
	int min = l.size ? l.min : head->data;
	int size = isBSt ? (l.size + r.size +1) : std::max(l.size,r.size);

	return Result(isBSt,max,min,size);
}

int largestBST(node* head)
{
	if(!head)
		return 0;
	return largestBSTUtil(head).size;
}


int main_17_Largest_BST_in_Binary_Tre()
{
	/* Let us construct the following Tree
	.          50
	.       /      \
	.     10        60
	.    /  \       /  \
	.   5   20    55    70
	.            /     /  \
	.          45     65    80
	. */

	node *root = new node(50);
	root->left        = new node(10);
	root->right       = new node(60);
	root->left->left  = new node(5);
	root->left->right = new node(20);
	root->right->left  = new node(55);
	root->right->left->left  = new node(45);
	root->right->right = new node(70);
	root->right->right->left = new node(65);
	root->right->right->right = new node(80);

	/* The complete tree is not BST as 45 is in right subtree of 50.
	.     The following subtree is the largest BST
	.        60
	.      /  \
	.    55    70
	.   /     /  \
	. 45     65    80
	*/
	printf(" Size of the largest BST is %d", largestBST(root));
	return 0;
}
