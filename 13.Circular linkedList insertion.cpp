#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

void show(struct node* tail)
{
    struct node* temp;
    temp=tail->next;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);
    cout<<endl;
}

int countL(struct node* tail)
{
    struct node* temp;
    temp=tail->next;
    int count=1;
    while(temp->next!=tail->next)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

void insertAtBeg(struct node * tail)
{
    struct node* newNode ;
    int choice =1;

    while(choice)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        cout<<"Insert at Begining : ";
        cin>>newNode->data;
        newNode->next=NULL;

        if(tail==NULL)
        {
            tail=newNode;
            tail->next=newNode;
        }
        else
        {
            newNode->next=tail->next;
            tail->next=newNode;
        }
        cout<<"0/1 : ";
        cin>>choice;
    }

    show(tail);

}

void insertAtEnd(struct node * tail)
{
    struct node* newNode ;
    int choice =1;

    while(choice)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        cout<<"Insert at END : ";
        cin>>newNode->data;
        newNode->next=NULL;

        if(tail==NULL)
        {
            tail=newNode;
            tail->next=newNode;
        }
        else
        {
            newNode->next=tail->next;
            tail->next=newNode;
            tail=newNode;
        }
        cout<<"0/1 : ";
        cin>>choice;
    }

    show(tail);

}



void insertAtPos(struct node* tail)
{
    struct node * newnode,*temp;

    int choice=1,i=1;
    int pos;
    while(choice)
    {

        newnode = (struct node*)malloc(sizeof(struct node));
        cout<<"Position : ";
        cin>>pos;
        cout<<countL(tail)<<endl;

        if(countL(tail)<0||pos>countL(tail))
        {
            cout<<"INVALID"<<endl;
        }
        else
        {
            cout<<"Enter At Position Data :";
            cin>>newnode->data;
            newnode->next=NULL;
            temp=tail->next;

            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next=newnode;
        }
        cout<<"0/1 :";
        cin>>choice;
    }
    cout<<endl;
    cout<<"AFTER Insert pos -->";
    show(tail);
}




void cr8()
{
    struct node * tail, *newNode;
    int choice=1;

    while(choice)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        cout<<"Data --> ";
        cin>>newNode->data;
        newNode->next = NULL;

        if(tail==NULL)
        {
            tail = newNode;
            tail->next=newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next=newNode;
            tail=newNode;
        }
        cout<<"0/1 : ";
        cin>>choice;
    }
    show(tail);
   /// insertAtBeg(tail);
   /// insertAtEnd(tail);
    insertAtPos(tail);
}

int main()
{
    cr8();
    return 0;
}


