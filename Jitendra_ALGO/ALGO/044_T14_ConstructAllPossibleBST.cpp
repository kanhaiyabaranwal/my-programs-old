/*
http://www.geeksforgeeks.org/construct-all-possible-bsts-for-keys-1-to-n/
https://www.youtube.com/watch?v=YDf982Lb84o
*/

#include <iostream>
#include<string>
#include <vector>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	node(int d) : data(d), left(NULL), right(NULL){}
};

#define NO_SPACE_OPTIMIZATION 1
#if NO_SPACE_OPTIMIZATION
node* cloneTree(node* root)
{
	if(root == NULL) return NULL;

	node* newRoot = new node(root->data);
	newRoot->left = cloneTree(root->left);
	newRoot->right = cloneTree(root->right);

	return newRoot;
}
#endif 

vector<node*> constructBinarySearchTrees(int start, int end)
{
	vector<node*> list;
	if(start > end)
	{
		list.push_back(NULL);
		return list;
	}
	for(int i=start; i <= end; i++)
	{
		vector<node*> leftSubTree = constructBinarySearchTrees(start, (i-1));
		vector<node*> rightSubTree = constructBinarySearchTrees((i+1), end);

		for(size_t j=0; j < leftSubTree.size(); j++)
		{
			node* left = leftSubTree[j];
			for(size_t k=0; k < rightSubTree.size(); k++)
			{
				node* root = new node(i);
				node* right = rightSubTree[k];
#if NO_SPACE_OPTIMIZATION
				if( k != 0)
				{
					left = cloneTree(left);
					right = cloneTree(right);
				}
#endif 
				root->left = left;
				root->right = right;
				list.push_back(root);
			}
		}
	}
	return list;
}

int countBinarySearchTreeDP(int size) // total number of trees from 1-N number
{
	if(size <= 0) return 0;
	if(size == 1) return 1;
	int* table = new int[size + 1];
	memset(table,0, sizeof(int) * (size+1));
	table[0] =1; table[1] = 1;
	for(int i=2; i <= size; i++)
	{
		for(int j=1; j<=i; j++)
		{
			table[i] += (table[j-1] * table[i-j]);
		}
	}
	int result = table[size];
	delete[] table;
	return result;
}

void preorder(node* root)
{
	if(root == NULL) return;
	cout << root->data << "  ";
	preorder(root->left);
	preorder(root->right);
}

//int main()
int main44_T_X_ConstructAllPossibleBST()
{
	vector<node*> totalTreesFrom1toN = constructBinarySearchTrees(1, 4); 
	int size = totalTreesFrom1toN.size();
	int size_dp = countBinarySearchTreeDP(4);
	cout << "Preorder traversals of all constructed BSTs are \n";
	for (int i = 0; i < size; i++)
	{
		preorder(totalTreesFrom1toN[i]);
		cout << endl;
	}
	return 0;
}

/*
http://practice.geeksforgeeks.org/problems/given-a-string-find-the-number-of-occurences-of-the-pattern-101
*/
int main_samsung_101()
{
	string s = "1023100100023101";
	int n = s.length();

	bool startOne = false;
	int count =0;
	for(int i=0;i<n;i++)
	{
		switch (s.at(i)) 
		{
		case '1' :
			if(startOne)
				count++;
			startOne = (!startOne);
		case '0':
			break;
		default:
			startOne = false;
			break;
		}
	}
	cout << "count = " << count << endl;
	return 0;
}

