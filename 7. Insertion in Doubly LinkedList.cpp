#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node * prev;
    struct node * next;
};


void create()
{
    struct node* head, *tail, *newnode,*temp;
    int choice=1 ;

    while(choice)
    {
        newnode=(struct node *) malloc(sizeof(struct node));
        cout<<"ENTER : ";
        cin>>newnode->data;
        newnode->prev=NULL;
        newnode->next=NULL;

        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        cout<<"0/1 ? : ";
        cin>>choice;
    }

    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main()
{
    create();
    return 0;
}
