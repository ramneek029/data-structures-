#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Stack
{

    struct node
    {
        int data;
        node* next;
    };
    node* start=NULL;
public:
    int cont=0;
    node* getnode(int value)
    {
        struct node* new_node=new node;
        new_node->data=value;
        new_node->next=NULL;
        return new_node;
    }
    void push();
    int pop();
    int peek();
    void length();
    int isEmpty();
};
void Stack:: push()
{
    int n;
    cout<<"\nEnter the element to be pushed:";
    cin>>n;
    node* newnode=getnode(n);
    newnode->next=start;
    start=newnode;
    cout<<"Element Pushed:"<<newnode->data;
    cont++;
}
int Stack::pop()
{
    if(start==NULL)
        return -1;
    int temp=start->data;
    start=start->next;
    int item=temp;
    cont--;
    return item;
}
int Stack::peek()
{
    if(start==NULL)
        return -1;
    return start->data;
}
void Stack::length()
{
    cout<<"\nLength of stack:"<<cont;
}
int Stack::isEmpty()
{
    if(start==NULL)
        return 1;
    return 0;
}
int main()
{
    Stack s;
    while(1)
    {
        cout<<"\n1.To push an element\n2.To pop an element\n3.To show top element\n4.To find length of stack\n5.IsEmpty\n6.Exit";
        int a;
        cout<<"\nEnter your choice:";
        cin>>a;
        switch(a)
        {
        case 1:
            s.push();
            break;
        case 2:
            int a;
            a=s.pop();
            cout<<"\nPopped element:"<<a;
            break;
        case 3:
             int b;
             b=s.peek();
             cout<<"\nTop element:"<<b;
             break;
        case 4:
            s.length();
            break;
        case 5:
            int x;
            x=s.isEmpty();
            cout<<x;
            break;
        case 6:
            exit(0);
        default:
            cout<<"Wrong Input";
        }
    }
     return 0;
}
