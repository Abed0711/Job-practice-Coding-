#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

void InsertAtBegining(struct node *head)
{
    struct node * temp, *newnode;



    newnode=(struct node*)malloc(sizeof(struct node));

    cout<<"Enter a new int : ";
    cin>>newnode->data;
    newnode->next=head;
    head=newnode;

    temp=head;

    cout<<"After INSERT " ;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void InsertAtEnd(struct node* head)
{
    struct node * temp, *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    cout<<"Enter anything for Insert at end : ";
    cin>>newnode->data;
    newnode->next=NULL;

    temp = head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newnode;

    temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}


void InsertAfterGivenPosition(struct node* head)
{
    struct node * temp, *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    int count,pos,i=0;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    cout<<"Give position where you want to enter a value : ";
    cin>>pos;

    if(pos>count)
        cout<<"INVALID";
    else
    {
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        cout<<"Enter a data: ";
        cin>>newnode->data;

        newnode->next=temp->next;
        temp->next=newnode;
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
    struct node* head, * temp, * newnode;
    int choice=1;
    head=NULL;

    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        cout<<"Enter data -->";
        cin>>newnode->data;
        newnode->next=NULL;

        if(head==NULL)
            head = temp = newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        cout<<"DO YOU WANT TO ENTER ? 0/1 : ";
        cin>>choice;
    }

    temp=head;

    cout<<"BEFORE INSERT " ;


    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    ///InsertAtBegining(head);
    ///InsertAtEnd(head);
    ///InsertAfterGivenPosition(head);


    return 0;
}
