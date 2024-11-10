#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node1
{
    int data;
    struct node1 *next;
};
typedef struct node1 node;

node * create_node(int data)
{       
    node * head=(node *)malloc(sizeof(node));
    head->data=data;
    head->next=NULL;
    return head;
}

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

node *get_linklist(void)
{
    node *temp,*head;
    head=NULL;
    temp=head;
    int counter=0;
    int data;
    do
    {
        counter++;
        cin>>data;
        if(data!=-1)
        {
            if(head==NULL)
            {
                head=create_node(data);
                temp=head;
            }
            else
            {
                temp->next=create_node(data);
                temp=temp->next;
            }
        }
    }while(data!=-1);
    return head;
}

void print_linklist(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void multiply_node(node *num1,node *num2, node *t_num,int *carry)
{
    int sume;
    if(num1->next==NULL)
    {
        sume= (num1->data) * (num2->data) + (*carry);
        t_num->data=sume%10;
        *carry=sume/10;
    }
    else
    {
        multiply_node(num1->next,num2,t_num->next,carry);
        sume= (num1->data) * (num2->data) + (*carry);
        t_num->data=sume%10;
        *carry=sume/10;
    }
}


void add_me(int n1,int n2,node *t_num1,node *t_num2,int *carry,node **t_sum)
{
    int sum;
    if(n1==n2)
    {
        if(n1==1)
        {
            sum=t_num1->data + t_num2->data + (*carry);
            t_num2->data=sum%10;
            *carry=sum/10;
            return;
        }
        else
        {
            add_me(n1-1,n2-1,t_num1->next,t_num2->next,carry,t_sum);
            sum=t_num1->data + t_num2->data + (*carry);
            t_num2->data=sum%10;
            *carry=sum/10;
            return;
        }
    }
    else if(n1>n2)
    {
        add_me(n1-1,n2,t_num1->next,t_num2,carry,t_sum);
        sum=t_num1->data+(*carry);
        node *temp=create_node(sum%10);
        temp->next=(*t_sum);
        (*t_sum)=temp;
        *carry=sum/10;
    }
}

void add_linklist(node *t_num,node **t_sum)
{
    int len1=get_length(t_num);
    int len2=get_length(*t_sum);
    int carry=0;
    add_me(len1,len2,t_num,*t_sum,&carry,t_sum);
    if(carry)
    {
        node *temp=create_node(carry);
        temp->next=(*t_sum);
        (*t_sum)=temp;  
    }
}

node *add_temp(node *t_num,int gap,node **t_sum)
{
    node *dev,*temp;
    if(gap==0)
    {
        while(t_num!=NULL)
        {
            if((*t_sum)==NULL)
            {
                (*t_sum)=create_node(t_num->data);
                dev=(*t_sum);
            }
            else
            {
                dev->next=create_node(t_num->data);
                dev=dev->next;
            }
            t_num=t_num->next;
        }
    }
    else
    {
        int len=get_length(*t_sum);
        int i=0;
        dev=(*t_sum);
        while(i<len-gap-1)
        {
            dev=dev->next;
            i++;
        }
        temp=dev->next;
        dev->next=NULL;
        add_linklist(t_num,t_sum);
        dev->next=temp;
    }
}

void multiply_linklist(node *num1,node *num2,node *t_num,int *gap,node **t_sum)
{
    node *temp;
    int carry=0;
    if(num2->next==NULL)
    {
        multiply_node(num1,num2,t_num->next,&carry);

        if(carry)
            t_num->data=carry;
        else
            t_num->data=0;
        if(t_num->data==0)
        {
            add_temp(t_num->next,*gap,t_sum);
        }
        else
        {
            add_temp(t_num,*gap,t_sum);
        }
        (*gap)++;

    }
    else
    {
        multiply_linklist(num1,num2->next,t_num,gap,t_sum);
        multiply_node(num1,num2,t_num->next,&carry);
        if(carry)
            t_num->data=carry;
        else
            t_num->data=0;
        if(t_num->data==0)
        {
            add_temp(t_num->next,*gap,t_sum);
        }
        else
        {
            add_temp(t_num,*gap,t_sum);
        }
        (*gap)++;   
    }
}

int main()
{
    node *num1,*num2,*temp,*t_sum,*t_num,*temp1;
    num1=get_linklist();
    num2=get_linklist();
    t_num=NULL;
    t_sum=NULL;
    node *head1=num1;
    while(head1!=NULL)
    {
        if(t_num==NULL)
        {
            t_num=create_node(0);
            temp1=t_num;
        }
        else
        {
            temp1->next=create_node(0);
            temp1=temp1->next;
        }
        head1=head1->next;
    }
    temp1->next=create_node(0);

    int gap=0;
    cout<<"Number 1"<<endl;
    print_linklist(num1);
    cout<<"Number 2"<<endl;
    print_linklist(num2);
    cout<<"Multiplication"<<endl;
    multiply_linklist(num1,num2,t_num,&gap,&t_sum);
    print_linklist(t_sum);  
    return 0;
}
