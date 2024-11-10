#include<iostream>
#include<string>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int d,node* n=NULL):data(d),next(n) {}
};

int get_length(node *head)
{
    int counter=0;
    while(head!=NULL)
    {
        head=head->next;
        counter++;
    }
    return counter;
}

node *creat_ll(string str)
{
    node *temp,*head;
    temp=head=NULL;
    int i=0;
    while(i<str.length())
    {
            if(head==NULL)
            {
                head=new node(str[i]-'0');
                temp=head;
            }
            else
            {
                temp->next=new node(str[i]-'0');
                temp=temp->next;
            }
	    i++;
    }
    return head;
}


void print_linklist(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->next;
    }
    cout<<endl;
}

void include_this(int n1,int n2,node *mid_node1,node *mid_node2,int *carry,node **sum_node)
{
    int sum;
    if(n1==n2)
    {
        if(n1==1)
        {
            sum=mid_node1->data + mid_node2->data + (*carry);
            mid_node2->data=sum%10;
            *carry=sum/10;
            return;
        }
        else
        {
            include_this(n1-1,n2-1,mid_node1->next,mid_node2->next,carry,sum_node);
            sum=mid_node1->data + mid_node2->data + (*carry);
            mid_node2->data=sum%10;
            *carry=sum/10;
            return;
        }
    }
    else if(n1>n2)
    {
        include_this(n1-1,n2,mid_node1->next,mid_node2,carry,sum_node);
        sum=mid_node1->data+(*carry);
        node *temp=new node(sum%10);
        temp->next=(*sum_node);
        (*sum_node)=temp;
        *carry=sum/10;
    }
}

void add_linklist(node *mid_node,node **sum_node)
{
    int len1=get_length(mid_node);
    int len2=get_length(*sum_node);
    int carry=0;
    include_this(len1,len2,mid_node,*sum_node,&carry,sum_node);
    if(carry)
    {
        node *temp=new node(carry);
        temp->next=(*sum_node);
        (*sum_node)=temp;  
    }
}

node *include_temp(node *mid_node,int gap,node **sum_node)
{
    node *dev,*temp;
    if(gap==0)
    {
        while(mid_node!=NULL)
        {
            if((*sum_node)==NULL)
            {
                (*sum_node)=new node(mid_node->data);
                dev=(*sum_node);
            }
            else
            {
                dev->next=new node(mid_node->data);
                dev=dev->next;
            }
            mid_node=mid_node->next;
        }
    }
    else
    {
        int len=get_length(*sum_node);
        int i=0;
        dev=(*sum_node);
        while(i<len-gap-1)
        {
            dev=dev->next;
            i++;
        }
        temp=dev->next;
        dev->next=NULL;
        add_linklist(mid_node,sum_node);
        dev->next=temp;
    }
}

void multiply_node(node *num1,node *num2, node *mid_node,int *carry)
{
    int sume;
    if(num1->next==NULL)
    {
        sume= (num1->data) * (num2->data) + (*carry);
        mid_node->data=sume%10;
        *carry=sume/10;
    }
    else
    {
        multiply_node(num1->next,num2,mid_node->next,carry);
        sume= (num1->data) * (num2->data) + (*carry);
        mid_node->data=sume%10;
        *carry=sume/10;
    }
}

void multiply_linklist(node *num1,node *num2,node *mid_node,int *gap,node **sum_node)
{
    node *temp;
    int carry=0;
    if(num2->next==NULL)
    {
        multiply_node(num1,num2,mid_node->next,&carry);

        if(carry)
            mid_node->data=carry;
        else
            mid_node->data=0;
        if(mid_node->data==0)
        {
            include_temp(mid_node->next,*gap,sum_node);
        }
        else
        {
            include_temp(mid_node,*gap,sum_node);
        }
        (*gap)++;

    }
    else
    {
        multiply_linklist(num1,num2->next,mid_node,gap,sum_node);
        multiply_node(num1,num2,mid_node->next,&carry);
        if(carry)
            mid_node->data=carry;
        else
            mid_node->data=0;
        if(mid_node->data==0)
        {
            include_temp(mid_node->next,*gap,sum_node);
        }
        else
        {
            include_temp(mid_node,*gap,sum_node);
        }
        (*gap)++;   
    }
}
node* creat_blank_ll(node* num)
{
    node* head;
    node* temp;
    while(num!=NULL)
    {
        if(head==NULL)
        {
            temp=new node(0);
            head=temp;
        }
        else
        {
            temp->next=new node(0);
            temp=temp->next;
        }
        num=num->next;
    }
    temp->next=new node(0);
    return head;
}

int main()
{
    node *num1,*num2,*temp,*sum_node,*mid_node,*temp1;
    string str1,str2;
    cout<<"Program to multiply two numbers using LL, can multiply very large numbers also."<<endl;
    cout<<"Assumptions: Numbers are positive integers. No validation will be made."<<endl;
    cout<<"Enter number1:";
    cin>>str1;
    cout<<"Enter number2:";
    cin>>str2;
    num1=creat_ll(str1);
    num2=creat_ll(str2);
    mid_node=NULL;
    sum_node=NULL;

    //create a blank ll for intermediate values when each digit of num2 is multiplied by num1
    mid_node=creat_blank_ll(num1);

    int gap=0;
    cout<<"\nNumber 1:";
    print_linklist(num1);
    cout<<"Number 2:";
    print_linklist(num2);

    multiply_linklist(num1,num2,mid_node,&gap,&sum_node);
    cout<<"Multiplication Result:";
    print_linklist(sum_node);  
    return 0;
}
