#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

void show(struct node * temp)
{

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteFromBegining(struct node * head)
{
    struct node * temp;



    temp=head;
    head=head->next;
    free(temp);

    show(head);
}

void deleteFromEnd(struct node * head)
{
    struct node* temp, *prevnode;

    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=NULL;
    }
    else
    {
        prevnode->next=NULL;
    }
    free(temp);
    show(head);
}

void deleteFromPosition(struct node* head)
{
    struct node * temp, *nextnode;
    int pos, i = 0 ;
    temp=head;
    cout<<"Enter the position: ";
    cin>>pos;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;

    temp->next=nextnode->next;

    free(nextnode);

    show(head);

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

    show(temp);
    ///deleteFromBegining(temp);
    ///deleteFromEnd(temp);
    deleteFromPosition(temp);



    return 0;
}
