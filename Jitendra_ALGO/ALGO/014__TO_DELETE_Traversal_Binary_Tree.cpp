#if 0
/*
referance: https://www.youtube.com/watch?v=PQKkr036wRc
*/

#include<iostream>
#include<queue>

using namespace std;

template<typename T>
struct TreeNode{
	T value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(const T& data) : value(data), left(NULL), right(NULL){}
};
typedef TreeNode<char> node; 

/*
...............A...................
............./....\................
............/.......\..............
............B........C.............
........../...\..../...\...........
.........D.....E...F....G..........
......../.\.../.\....../..\........
......H...I...J..K....L....M.......
*/
node* createTree()
{
	node* A = new node('A');
	node* B = new node('B');
	node* C = new node('C');
	node* D = new node('D');
	node* E = new node('E');
	node* F = new node('F');
	node* G = new node('G');
	node* H = new node('H');
	node* I = new node('I');
	node* J = new node('J');
	node* K = new node('K');
	node* L = new node('L');
	node* M = new node('M');

	A->left = B; A->right=C;
	B->left = D; B->right=E;
	C->left = F; C->right=G;
	D->left = H; D->right=I;
	E->left = J; E->right=K;
	G->left = L; G->right=M;

	return A;
}

void print_level_order(node* head)
{
	if(!head)
		return;
	queue<node*> q;
	q.push(head);
	while(!q.empty())
	{
		node* tmp = q.front(); q.pop();
		cout << tmp->value << " ";
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
	}
	cout << endl;
}


void print_vertical_order(node* head)
{
	if(!head)
		return;
	typedef pair<node*,int> vd_pair;
	queue<vd_pair> q;
	q.push(vd_pair(head,0));

	priority_queue<int,node*,greater<int>> pq;

	while(!q.empty())
	{
		vd_pair tmp = q.front(); q.pop();
		cout << tmp.first->value << "(" <<  tmp.second  << ") ";
		pq.push(tmp);
		if(tmp.first->left)
			q.push(vd_pair(tmp.first->left,(tmp.second-1)));
		if(tmp.first->right)
			q.push(vd_pair(tmp.first->right,(tmp.second+1)));
	}
	cout << endl;
}



int main_14_Traversal_Binary_Tree ()
{
	node* head = createTree();
	print_level_order(head);
	print_vertical_order(head);

	return 0;
}
#endif 