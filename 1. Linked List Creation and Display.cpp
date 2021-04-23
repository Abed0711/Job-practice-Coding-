#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;

};


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

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }


    return 0;
}
