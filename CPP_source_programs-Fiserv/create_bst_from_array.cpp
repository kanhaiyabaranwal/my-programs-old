#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>

using namespace std;
#define NUM 10	

struct Node{
	int dat;
	Node* left;
	Node* right;
	Node(int num,Node* n1=NULL,Node* n2=NULL):dat(num),left(n1),right(n2) {}
};

Node* create_bst(vector<int>& ivec,int start, int end)
{
	if(start>end)
		return 0;
	int mid=start+((end-start)>>1);
	//int mid=(end+start)/2;
	Node* root=new Node(ivec[mid]);
	root->left=create_bst(ivec,start,mid-1);
	root->right=create_bst(ivec,mid+1,end);
	return root;
}
void path_array(Node* root,int key,vector<char>& svec)
{
	if(!root)
	{
		svec.push_back('-');
		svec.push_back('1');
		return;
	}
	if(root->dat==key)
		return;
	if(key<root->dat)
	{
		svec.push_back('1');
		path_array(root->left,key,svec);
	}
	else
	{
		svec.push_back('0');
		path_array(root->right,key,svec);
	}
}	
	

void inorder_traversal(Node* root)
{
	if(!root)
		return;
	inorder_traversal(root->left);
	cout<<root->dat<<" ";
	inorder_traversal(root->right);
	return;
}


int main()
{
	vector<int> ivec;
	srand(time(NULL));
	for(int i=0;i<NUM;i++)
		ivec.push_back(rand()%50);
	cout<<"Showing integer array"<<endl;
	for(int i=0;i<NUM;i++)
		cout<<ivec[i]<<" ";
	cout<<endl;
	sort(ivec.begin(),ivec.end());
	cout<<"Showing sorted integer array"<<endl;
	for(int i=0;i<NUM;i++)
		cout<<ivec[i]<<" ";
	cout<<endl;
	int sz=ivec.size()-1;
	cout<<"vector size ="<<sz<<endl;
	cout<<"creating BST"<<endl;
	Node* root=create_bst(ivec,0,sz);
	cout<<"inorder traversal"<<endl;
	inorder_traversal(root);
	cout<<"finding path_array:";
	vector<char> svec;
	path_array(root,18,svec); 
	if(svec.size()>1 && svec[svec.size()-2]=='-')
		cout<<"Element does not exist.Path array not found";
	else
		copy(svec.begin(),svec.end(),ostream_iterator<char> (cout," "));
		//for_each(svec.begin(),svec.end(),ostream_iterator(
	//for(int i=0;i<svec.size();i++)
	//	cout<<svec[i]<<" ";
	//cout<<endl;
	cout<<endl;
	return 0;
}
