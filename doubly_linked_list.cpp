//Doubly_Linked_List
#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node *prev;
};
node *start=NULL;
node *rear=NULL;
node *create(node *start)
{
    node *new_node;
    int num;
    cout<<"Enter -1 to end:";
    cout<<"Enter the value:";
    cin>>num;
    while(num!=-1)
    {
        new_node=new node;
        new_node->data=num;
        if(start==NULL)
        {
            new_node->next=NULL;
            new_node->prev=NULL;
            start=new_node;
            rear=new_node;
        }
        else
        {
            rear->next=new_node;
            new_node->prev=rear;
            new_node->next=NULL;
            rear=new_node;
        }
        cout<<"Enter the value:";
        cin>>num;
    }
    return start;
}
void display(node *start)
{
    node *ptr;
    ptr=start;
    if(start==NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        while(ptr->next!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<ptr->data<<endl;
    }
}
node *insert_beg(node *start)
{
    node *new_node;
    int num;
    cout<<"Enter the value:";
    cin>>num;
    new_node=new node;
    new_node->data=num;
    new_node->prev=NULL;
    new_node->next=start;
    start=new_node;
    return start;
}
node *insert_end(node *start)
{
    node *new_node,*ptr;
    ptr=start;
    int num;
    cout<<"Enter the value:";
    cin>>num;
    new_node=new node;
    new_node->data=num;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    new_node->next=NULL;
    ptr->next=new_node;
    return start;
}
node *insert_after_node(node *start)
{
    node *new_node,*ptr,*preptr;
    int num,val;
    cout<<"Enter the value:";
    cin>>num;
    cout<<"After which node you want to insert a node?";
    cin>>val;
    new_node=new node;
    new_node->data=num;
    ptr=start;
    preptr=start;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    ptr->prev=new_node;
    new_node->prev=preptr;
    new_node->next=ptr;
    return start;
}
node *delete_beg(node *start)
{
    node *ptr;
    ptr=start;
    if(start==NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        if(start->next==NULL)
        {
            ptr=start;
            free(ptr);
            cout<<"Node is deleted"<<endl;
            start=NULL;
        }
        else
        {
            ptr=start;
            start=start->next;
            start->prev=NULL;
            free(ptr);
            cout<<"Node is deleted"<<endl;
        }
    }
    return start;
}
node *delete_end(node *start)
{
    node *ptr,*preptr;
    ptr=start;
    preptr=start;
    if(start==NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        while(ptr->next!=NULL)
        {
        preptr=ptr;
        ptr=ptr->next;
        }
    preptr->next=NULL;
    free(ptr);
    }
    return start;
}
node *delete_after_node(node *start)
{
    node *ptr,*preptr;
    int val;
    cout<<"After which node you want to delete a node:";
    cin>>val;
    ptr=start;
    preptr=start;
    if(start==NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        while(preptr->data!=val)
        {
        preptr=ptr;
        ptr=ptr->next;
        }
    preptr->next=ptr->next;
    ptr->next->prev=preptr;
    free(ptr);
    }
    return start;
}
int main()
{
    int ch;
    cout<<"1.Creation of linked list"<<endl;
    cout<<"2.Display a List"<<endl;
    cout<<"3.Insert of a node at begining"<<endl;
    cout<<"4.Insert a node at the end"<<endl;
    cout<<"5.Insert a node after a node"<<endl;
    cout<<"6.Delete a node at end"<<endl;
    cout<<"7.Delete a node at end"<<endl;
    cout<<"8.Delete a node after a node"<<endl;
    do
    {
        cout<<"Enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            start=create(start);
            break;
            case 2:
            display(start);
            break;
            case 3:
            start=insert_beg(start);
            break;
            case 4:
            start=insert_end(start);
            break;
            case 5:
            start=insert_after_node(start);
            break;
            case 6:
            start=delete_beg(start);
            break;
            case 7:
            start=delete_end(start);
            break;
            case 8:
            start=delete_after_node(start);
            break;
        }
    }
    while(ch!=9);
    return 0;
}