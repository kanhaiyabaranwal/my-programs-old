#include<iostream>
using namespace std;

namespace RedBlackTree
{
	enum RedBlack : unsigned char
	{
		RED = 'R',
		BLACK = 'B'
	};
	template<typename T>
	struct Node
	{
		T data;
		RedBlack flag;
		Node* left;
		Node* right;
		Node* parent;
		Node(const T& d, RedBlack f = BLACK) : data(d), flag(f), left(NULL), right(NULL), parent(NULL) {}
	};

	template<typename T>
	class RedBlackTree
	{
	public:
		typedef Node<T> node;
		RedBlackTree() : root(NULL) {}
		~RedBlackTree() { destroy(root); root = NULL; }

	private:
		node* root;
		void destroy(node* n);
		node* leftRotate(node* n);
		node* rightRotate(node* n);
	};

	template<typename T>
	void RedBlackTree<T>::destroy(typename RedBlackTree<T>::node* root)
	{
		if (root)
		{
			destroy(root->left); destroy(root->right);
			delete root;
		}
	}
	template<typename T>
	typename RedBlackTree<T>::node* RedBlackTree<T>::leftRotate(typename RedBlackTree<T>::node* root)
	{
		typedef typename RedBlackTree<T>::node node;
		if (root == NULL || root->right == NULL) return root;

		node* parent = root->parent;
		node* right = root->right;
		node* rightLeft = root->right->left;
		//adjust the parent
		if (parent)
		{
			if (parent->left == root) parent->left = right;
			else if (parent->right == root) parent->right = right;
		}
		//move rightside  node to left/root node
		right->parent = parent;
		//adjust other pointers
		right->left = root; root->parent = right;
		root->right = rightLeft; rightLeft->parent = root;
		//return the node which replaced n. i.e. right side node
		return right;
	}

	template<typename T>
	typename RedBlackTree<T>::node* RedBlackTree<T>::rightRotate(typename RedBlackTree<T>::node* root)
	{
		//TODO Add comment
		typedef typename RedBlackTree<T>::node node;
		if (root == NULL || root->left == NULL) return root;

		node* parent = root->parent;
		node* left = root->left;
		node* leftRight = root->left->right;
		//adjust the parent
		if (parent)
		{
			if (parent->left == root) parent->left = left;
			else if (parent->right == root) parent->right = left;
		}
		left->parent = parent;
		left->right = root; root->parent = left;
		root->left = leftRight; leftRight->parent = root;
		return left;
	}

}

int main_77()
{
	RedBlackTree::RedBlackTree<int> t;
	RedBlackTree::RedBlack f = RedBlackTree::BLACK;
	int n = sizeof(f);
	char c;
	n = sizeof(c);
	return 0;
}