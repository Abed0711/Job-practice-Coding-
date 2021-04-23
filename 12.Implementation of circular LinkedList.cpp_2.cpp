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
}

int main()
{
    cr8();
    return 0;
}
