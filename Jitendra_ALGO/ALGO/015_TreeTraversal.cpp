#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "ExceptionMsg.h"

using namespace std;

template <typename T>
int find_index(const vector<T>& v,const T& data)
{
	return (std::find(v.begin(),v.end(),data) - v.begin());
}

template <typename T> 
class Tree
{
public:
	Tree():root(NULL){}
	void populate_from_inorder_preorder(vector<T> inorder,vector<T> preorder);
	void create_tree();
	void clean() { _clean(root) ; root = NULL;}
	vector<T> preorder() { return _preorder(root);}
	vector<T> inorder() { return _inorder(root);}
	vector<T> inorder_itr_noStack(void);
	vector<T> postorder() { return _postorder(root);}

private:
	struct node
	{
		struct node* left;
		struct node* right;
		T data;
		node(const T& _data) : data(_data),left(NULL),right(NULL){}
	};
	struct point {
		int start;
		int end;
		node* parent;
		bool isleft;
		point(int _start,int _end, node* _parent,bool _isleft) :start(_start),end(_end),parent(_parent),isleft(_isleft){}
	};
	struct node* root;
	void _clean(node* root)
	{
		if(root)
		{
			_clean(root->left); _clean(root->right); delete root;
		}
	}
	vector<T> _preorder(struct node* root)
	{
		vector<T> tmp;
		if (!root)
			return tmp;

		tmp.push_back(root->data);
		if(root->left)
		{
			vector<T> tmpLeft = _preorder(root->left);
			tmp.insert(tmp.end(),tmpLeft.begin(),tmpLeft.end());
		}
		if(root->right)
		{
			vector<T> tmpRight = _preorder(root->right);
			tmp.insert(tmp.end(),tmpRight.begin(),tmpRight.end());
		}
		return tmp;
	}
	vector<T> _inorder(struct node* root)
	{
		vector<T> tmp;
		if (!root)
			return tmp;
		if(root->left)
		{
			vector<T> tmpLeft = _inorder(root->left);
			tmp.insert(tmp.end(),tmpLeft.begin(),tmpLeft.end());
		}
		tmp.push_back(root->data);
		if(root->right)
		{
			vector<T> tmpRight = _inorder(root->right);
			tmp.insert(tmp.end(),tmpRight.begin(),tmpRight.end());
		}
		return tmp;
	}
	vector<T> _postorder(struct node* root)
	{
		vector<T> tmp;
		if (!root)
			return tmp;
		if(root->left)
		{
			vector<T> tmpLeft = _postorder(root->left);
			tmp.insert(tmp.end(),tmpLeft.begin(),tmpLeft.end());
		}
		if(root->right)
		{
			vector<T> tmpRight = _postorder(root->right);
			tmp.insert(tmp.end(),tmpRight.begin(),tmpRight.end());
		}
		tmp.push_back(root->data);
		return tmp;
	}
};

template<typename T>
vector<T> Tree<T>::inorder_itr_noStack(void)
{
	vector<T> result;
	node* current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			result.push_back(current->data);
			current = current->right;
		}
		else
		{
			node* pred = current->left;
			while(pred->right != NULL && pred->right != current)
				pred = pred->right;
			// first time visit i.e. terminating condition above while 
			// loop is  pred->right is NULL, which implies left childs
			// are not visited
			if(pred->right == NULL) 
			{
				pred->right = current;
				current = current->left;
			}
			// here pred->right == current. that means second time
			// i.e. terminating condition on above while loop is 
			// pred->right != current, so we can print corrent node
			// move to right elemnt, and restore back the pred right pointer
			// to it's orginal shape, which is NULL
			else 
			{
				result.push_back(current->data);
				pred->right = NULL;
				current = current->right;
			}
		}
	}
	return result;
}

template<typename T>
void Tree<T>::create_tree()
{ // here logic to create tree for int case      //     Tree looks like   //
	node* a  = new node('A'); root = a;          //                 A      
	node* b  = new node('B');                    //                 |
	node* c  = new node('C');                    //         ----------------  
	a->left  = b;                                //         B              C
	a->right = c;                                //         |              |
	node* d  = new node('D');                    //      --------      ---------
	node* e  = new node('E');                    //      |     |        |      |
	b->left  = d;                                //      D     E        F
	b->right = e;                                //
	node* f  = new node('F');                    //
	c->left  = f;
}
template<typename T>
void Tree<T>::populate_from_inorder_preorder(vector<T> inorder,vector<T> preorder)
{
	this->clean();
	if(inorder.size() == 0 && preorder.size() == 0)
		return;
	if(inorder.size() != preorder.size())
		throw (ExpectionMsg("Invalid input"));

	stack<point> s;
	int index = find_index(inorder,preorder[0]);
	root = new node(inorder[index]);
	s.push(point(0,index-1,root,true));
	s.push(point(index+1,preorder.size()-1,root,false));

	while(!s.empty())
	{
		point p = s.top(); s.pop();
		if(p.start <= p.end)
		{
			vector<T>::iterator it_begin = inorder.begin() + p.start; 
			vector<T>::iterator it_end = inorder.begin() + p.end;
			int pre_first_index = find_index(preorder,*it_begin);
			while(it_begin <= it_end)
			{
				int pre_index = find_index(preorder,*it_begin);
				if(pre_index < pre_first_index)
					pre_first_index = pre_index;
				it_begin++;
			}
			node* tmp = new node(preorder[pre_first_index]);
			if(p.isleft)
				p.parent->left = tmp;
			else
				p.parent->right = tmp;
			//split now
			index = find_index(inorder,preorder[pre_first_index]);
			s.push(point(p.start,index-1,tmp,true));
			s.push(point(index+1,p.end,tmp,false));
		}
	}
}


template <typename T> 
void print (vector<T> v)
{
	for( vector<T>::iterator it = v.begin(); it != v.end() ;it++)
		std::cout << *it << " ";
	std::cout<<std::endl;
}



int main_15_TreeTraversal()
//int main()
{
	Tree<char> tree_org;
	tree_org.create_tree();

	vector<char> preorder_org = tree_org.preorder() ;
	cout << "preorder...: ";	print(preorder_org);

	vector<char> inorder_org = tree_org.inorder();
	cout << "inorder....: ";	print(inorder_org);

	vector<char> postorder_org =tree_org.postorder();
	cout << "postorder..: ";	print(postorder_org);

	cout << "\n=========================================================\n\n";

	Tree<char> tree_new; 
	tree_new.populate_from_inorder_preorder(inorder_org,preorder_org);

	vector<char> preorder_new = tree_new.preorder() ;
	cout << "preorder...: ";	print(preorder_new);

	vector<char> inorder_new = tree_new.inorder();
	cout << "inorder....: ";	print(inorder_new);

	vector<char> inorder_new_itr = tree_new.inorder_itr_noStack();
	cout << "inorder no stack ....: ";	print(inorder_new_itr);

	vector<char> postorder_new =tree_new.postorder();
	cout << "postorder..: ";	print(postorder_new);

	return 0;
}
