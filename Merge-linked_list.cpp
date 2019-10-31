#include<iostream>
#include<dos.h>
#include<conio.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* getnode(int value)
{
    struct node* new_node=new node;
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
int printList(node* x)
{
    cout<<"Linked list:\n";
    node* ptr=x;
    if(x==NULL)
        cout<<"NULL";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"\n";
        ptr=ptr->next;
    }
    return 0;
}
node* insert_beg(node* x)
{
    int info;
    cout<<"Enter the value of Node:";
    cin>>info;
    struct node* new_node= getnode(info);
    new_node->next= x;
    x= new_node;
    return x;
}
int sort_ll(int n,node* x)
{
    node* save,*ptr;
    for(int i=0;i<n;i++)
    {
        save=x;
        ptr=x->next;
        while(ptr!=NULL)
        {
            if(save->data>ptr->data)
            {
                int temp;
                temp=save->data;
                save->data=ptr->data;
                ptr->data=temp;
            }
            save=ptr;
            ptr=ptr->next;
        }
    }
}
node* merge_ll(node*a,node*b)
{
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    else
    {
        if(a->data<b->data)
           {
             a->next=merge_ll(a->next,b);
             return a;
           }
        else{
            b->next=merge_ll(a,b->next);
            return b;
        }
    }
}
int main()
{
    node* z=NULL;
    node*a=NULL;
    node*b=NULL;
    int an,bn;
    cout<<"Enter the numbers of nodes you want to enter in first and second linked list:";
    cin>>an>>bn;
    for(int i=0;i<an;i++)
        a=insert_beg(a);
    sort_ll(an,a);
    cout<<"First ";
    printList(a);
    for(int i=0;i<bn;i++)
        b=insert_beg(b);
    sort_ll(bn,b);
    cout<<"Second ";
    printList(b);
    z=merge_ll(a,b);
    cout<<"\nMerge ";
    printList(z);//Print Merge
    return 0;
}
