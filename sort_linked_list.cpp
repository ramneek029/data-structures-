#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};
node* start;
node* getnode(int value)
{
    struct node* new_node=new node;
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
int printList()
{
    cout<<"Linked list:\n";
    node* ptr= start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"\n";
        ptr=ptr->next;
    }
}
int insert_beg(int value)
{
    struct node* new_node= new node;
    new_node=getnode(value);
    new_node->next= start;
    start= new_node;
    return 0;
}
int sort_ll(int n)
{
    node* save,*ptr;
    for(int i=0;i<n;i++)
    {
        save=start;
        ptr=start->next;
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
int main()
{
    int n;
    cout<<"Enter the number of nodes you want to enter:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int info;
        cout<<"\nEnter the value of node:";
        cin>>info;
        insert_beg(info);
    }
    printList();
    sort_ll(n);
    printList();
}
