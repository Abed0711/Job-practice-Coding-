#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node * prev;
    struct node* next;
};

void create()
{
    struct node* newnode, *temp , *head;

    int choice=1;
    head=NULL;

    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        cout<<"Enter a data : ";
        cin>>newnode->data;
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;

        }
        cout<<"1/0? : ";
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
