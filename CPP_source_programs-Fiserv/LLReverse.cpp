#include<iostream>
using namespace std;

struct Node{
       int data;
       Node * next;
       Node(int p): data(p),next(NULL) {}
       };
       
int main()
{
    int i=1;
    Node *first=new Node(i);
    cout<<i<<"th node is "<< first->data<<endl;
    
    Node *temp,*temp1,*temp2;
    temp=first;
    //create Linked List
    for(i=2;i<6;i++)
    {
     temp->next=new Node(i);
     temp=temp->next;
     }
     temp=first;
     i=1;
     while(temp)
     {
      cout<<i++<<"th node is"<<temp->data<<endl;
      temp=temp->next;
      
      }
      //Reverse Linked List
      temp=first;
      temp1=first->next;
      temp2=temp1->next;
      first->next=NULL;
      while(temp2->next)
      {
       temp1->next=temp;
       temp=temp1;
       temp1=temp2;
       temp2=temp2->next;     
           
       }
       temp2->next= temp1;
       temp1->next = temp;
       first=temp2;
       i=1;
       cout<<"Reversed Linked List is"<<endl;
       while(temp2)
       {
       cout<<i<<"th node is"<<temp2->data<<endl;
       temp2=temp2->next;
       }
         
    cin>>i;
    return 0;
}
