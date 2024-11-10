/*Binary tree implementation */
/* Show kth element in the BST */
#include<iostream>

using namespace std;

struct Node {
       int data;
       Node * left;
       Node * right;
       Node(int p): data(p),left(NULL),right(NULL) {}
};
static int k;
int p;

int bin_insert(int num,Node *root )
{
    
    Node *temp=root;
    //23Reach to the right leaf node
    while(temp->left || temp->right)
    {
          while (num <= temp->data && temp->left )
          {
              temp=temp->left;
              continue;
          }
          while (num > temp->data && temp->right )
          {
              temp=temp->right;
              continue;
          }
          break;
    }     
    //if element is smaller than or equal to node data, create left child
    if(num <= temp->data)
           temp->left = new Node(num);
    else
           temp->right = new Node(num);
}
int glb[10];
struct DLLNode{
       int data;
       DLLNode * left;
       DLLNode * right;
       DLLNode(int p): data(p),left(NULL),right(NULL) {}
       };
       
DLLNode * dllroot=NULL;
DLLNode *previous=NULL;
DLLNode *next=NULL;
DLLNode *current=NULL;
int bin_traverse(Node* nd)
{
    if(nd->left)
        bin_traverse(nd->left);
    cout<<nd->data<<'\t';
    glb[k]=nd->data;
    k++;
    if(dllroot==NULL)
    {
         dllroot=new DLLNode(nd->data);
         current=dllroot;
    }
    else
    {
     previous=current;
     current= new DLLNode(nd->data);
     previous->right=current;
     current->left=previous;
     }
     if(nd->right)
        bin_traverse(nd->right);
        
    return 0;
}

int traverseDLL(DLLNode * dllroot)
{
    cout<<"Traversing DLL from left to right...\n";
    DLLNode *temp,*temp1;
    temp=dllroot;
    while(temp)
    {
         cout<<temp->data<<'\t';
         temp1=temp;
         temp=temp->right;
    }
       
    cout<<"\nTraversing DLL from right to left...\n";
    temp=temp1;
    while(temp)
    {
         cout<<temp->data<<'\t';
         temp=temp->left;
    }
    
}

int main()
{
    
    int num;
    int rc=0;
    cout<<"Enter number of Elements\t";
    cin>>rc;
    cout<<"Enter a value:\t";
    cin>>num;
    Node *root = new Node(num);
    for (int i=0; i<rc-1; i++)
    {
        cout<<"Enter a value:\t";
        cin>>num;
        bin_insert(num,root);
    }
    cout<<"Now traversing BST\n";
    bin_traverse(root);
    //kth element
    cout<<"\nWant to find kth element. Enter the value of k\t";
    cin>>p;
    cout<<endl<<p<<"th element is "<<glb[p-1]<<'\n';
    //create doubly linked list
    traverseDLL(dllroot);
    
    cin>>num;
    
    return 0;
}
        
    
