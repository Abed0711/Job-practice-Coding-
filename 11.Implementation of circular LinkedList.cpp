#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

void display(struct node* head)
{
    struct node*temp;
    if(head==NULL)
        cout<<"EMPTY"<<endl;
    else
    {
        temp=head;

        while(temp->next!=head)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<" ";
    }
}

void create()
{
    struct node* newNode , *head , *temp;

    int choice=1;

    while(choice)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        cout<<"DATA : ";
        cin>>newNode->data;
        if(head==NULL)
        {
            head=temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
        temp->next = head;
        cout<<"0/1 : ";
        cin>>choice;
    }
    display(head);

}


int main()
{
    create();
    return 0;
}
