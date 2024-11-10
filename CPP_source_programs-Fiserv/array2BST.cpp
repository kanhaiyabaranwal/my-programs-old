#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int d=-1,Node* n1=NULL,Node* n2=NULL):data(d),left(n1),right(n2) { }
};

void PreorderTraversal(Node* root)	//left,self then right
{
	cout<<root->data<<"\t";
	if(root->left)
		PreorderTraversal(root->left);
	if(root->right)
		PreorderTraversal(root->right);
}	

void InOrderTraversal(Node* root)	//left,self then right
{
	static int NbrOfElements=0;
	if(root->left)
		InOrderTraversal(root->left);
	cout<<root->data<<"\t";
	//cout<<"Number of elements="<<++NbrOfElements<<endl;
	if(root->right)
		InOrderTraversal(root->right);
}


Node* createBST(int arr[],int s,int e)
{
	int mid=(s+e+1)/2;			//create the node
	//left subtree will be smaller
	Node* root=new Node(arr[mid]);
	if(mid>s)
		root->left=createBST(arr,s,mid-1);
	if(mid<e)
		root->right=createBST(arr, mid+1,e);
	return root;
}

struct LLNode{
	int num;
	LLNode* next;
	LLNode(int n=-1,LLNode *node=NULL):num(n),next(node) {	}
	
};
LLNode **llarray;		
void PreorderTraversal_LLCreation(Node* root,int l)	//left,self, then right, linked list created/appended at level l
{
	cout<<root->data<<"\t";
	if(llarray[l]->num==-1)
		llarray[l]->num=root->data;		//first node of the linked list created, only replace -1 with data
	else
	{
		LLNode* temp=llarray[l];
		cout<<"traversing to the end of list at level "<<l<<endl;
		while(temp->next)
		{
			cout<<"Found data "<<temp->num<<endl;
			temp=temp->next;
		}
		temp->next=new LLNode(root->data);
	}
	if(root->left)
		PreorderTraversal_LLCreation(root->left,l+1);
	if(root->right)
		PreorderTraversal_LLCreation(root->right,l+1);
}	

int HeightofTree(Node *root)
{
	if(!root)
		return 0;
	int hl=HeightofTree(root->left);
	int hr=HeightofTree(root->right);
	if(hl>hr)
		return hl+1;
	else
		return hr+1;
}


int main()
{
	int arr[]={4,7,12,23,26,35,56,68};
	int sz=sizeof(arr)/sizeof(arr[0]);
	cout<<"size of array="<<sz<<endl;
	
	Node* root=createBST(arr,0,sz-1);
	cout<<"root="<<root->data<<endl;
	cout<<"Pre order Traversal"<<endl;
	PreorderTraversal(root);
	cout<<"\nIn order Traversal"<<endl;
	InOrderTraversal(root);
	int h=HeightofTree(root);
	cout<<"\nHeightofTree="<<h<<endl;
	llarray=new LLNode*[h];					//each node represents head of the linked list at the level l
	for(int i=0;i<h;i++)
	{
		llarray[i]=new LLNode(-1);
	}
	PreorderTraversal_LLCreation(root,0);
	cout<<"Linked list created from preorder traversal for each level --"<<endl;
	for(int i=0;i<h;i++)
	{
		LLNode* temp=llarray[h];
		cout<<"data at level["<<i<<"]->";
		while(temp)
		{
			cout<<temp->num;
			temp=temp->next;
		}
		cout<<endl;
	}

}
