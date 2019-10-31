#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    node* next;
};
node* start;
node* getnode()
{
    struct node* new_node=new node;
    cout<<"Enter the value of node:";
    int value;
    cin>>value;
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
void printList()
{
    node* tnode=start;
    cout<<"\nLinked list:";
    while(tnode!=NULL)
    {
        cout<<tnode->data<<"\t";
        tnode=tnode->next;
    }
}
void insert_beg()
{
    struct node* new_node=new node;
    new_node=getnode();
    new_node->next=start;
    start=new_node;
    cout<<"\nData Inserted!!!";
}
void insert_end()
{
    struct node* new_node=new node;
    new_node=getnode();
    struct node* last=start;
    node* save=NULL;
    while(last!=NULL)
    {   save=last;
        last=last->next;
    }
    save->next=new_node;
    cout<<"\nData Inserted!!!";
}
node* search_item(int value)
{
    node* ptr=start;
    node* save=NULL;
    if(value==start->data){
        cout<<"Found";
        return start;
    }
    while(ptr->next!=NULL)
    {
        if(value==ptr->data)
        {
            cout<<"\nfound";
            return save;
        }
        else
           {
                save=ptr;
                ptr=ptr->next;
           }
    }
    cout<<"\nNot found";
    return NULL;
}
void insert_anywhere()
{
    cout<<"Enter the position at which data to be entered:";
    int a,t=1;
    cin>>a;
    node* ptr=start;
    node* save=NULL;
    node* x=NULL;
    while(ptr!=NULL)
    {
        if(t==a)
        {
            save=ptr;
            break;
        }
        x=ptr;
        t++;
        ptr=ptr->next;
    }
    if(a==1)
        insert_beg();
    else{
        if(save->next==NULL)
            insert_end();
        else
        {
            struct node* new_node=new node;
            new_node=getnode();
            new_node->next=save;
            x->next=new_node;
        }
    }
}
int _delete()
{
    cout<<"Enter the position at which data to be deleted:";
    int a,t=1;
    cin>>a;
    node* ptr=start;
    node* save=NULL;
    node* x=NULL;
    while(ptr!=NULL)
    {
        if(t==a)
        {
            save=ptr;
            break;
        }
        x=ptr;
        t++;
        ptr=ptr->next;
    }
    if(save==start)
    {
        start=start->next;
    }
    else
    {
        if(save->next==NULL)
            x->next=NULL;
        else
            x->next=save->next;
    }
}
void _insert()
{
    cout<<"\nI.Enter 1 to insert at beginning\nII.Enter 2 to insert at last\nIII.Enter 3 to insert anywhere \n ";
    int c;
    cout<<"Enter our choice:";
        cin>>c;
    switch(c)
    {
    case 1:
        {
            insert_beg();
            break;
        }
    case 2:
        {
            insert_end();
            break;
        }
    case 3:
        {
            insert_anywhere();
            break;
        }
    default:
        cout<<"Wrong Choice";
    }
}
int main()
{
    node * head=getnode();
    start=head;
    while(1)
    {
        cout<<"\n(a)Enter 1 to Insert new element\n(b)Enter 2 to Display the List\n(c)Enter 3 to Search an element\n(d)Enter 4 to Delete a element\n(e)Enter 0 to Exit";
        int x;
        cout<<"\nEnter our choice:";
        cin>>x;
        switch(x)
        {
            case 1:
            {
                _insert();
                break;
            }
            case 2:
            {
               printList();
               break;
            }
            case 3:
            {
                cout<<"Enter the node to be searched:";
                int value;
                cin>>value;
                search_item(value);
                break;
            }
            case 4:
            {
                _delete();
                break;
            }
            case 0:
                exit(0);
            default :
                cout<<"Wrong Input";
        }
    }
    return 0;
}
