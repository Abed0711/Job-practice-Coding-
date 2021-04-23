#include<bits/stdc++.h>
using namespace std;

void insertatbeg(struct node* head);
void insertatEnd(struct node* head,struct node* tail);
void insertatPos(struct node* head);
void insertafterPos(struct node* head);

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

void show(struct node* head)
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int position(struct node* head)
{
    struct node* temp = head;
    int count=1;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}


void create()
{
    struct node* head, *newnode,*tail;
    int choice =1;
    head=NULL;
    while(choice)
    {
        newnode = (struct node*) malloc(sizeof(struct node));

        cout<<"ENTER DATA : ";
        cin>>newnode->data;
        newnode->prev=NULL;
        newnode->next= NULL;


        if(head==NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=head;
            tail=newnode;
        }
        cout<<"1/0 : ";
        cin>>choice;
    }
    cout<<endl;
    cout<<"MY Linked List -->";

    show(head);
    cout<<endl;
    ///insertatbeg(head);
    ///insertatEnd(head,tail);
    ///insertatPos(head);
    insertafterPos(head);

}



void insertatbeg(struct node* head)
{
    struct node * newnode;
    int choice=1;
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        cout<<"Enter At begging :";
        cin>>newnode->data;
        newnode->next=NULL;
        newnode->prev=NULL;

        head->prev=newnode;
        newnode->next=head;
        head=newnode;
        cout<<"0/1 :";
        cin>>choice;
    }
    cout<<endl;
    cout<<"AFTER Insert Begining -->";
    show(head);


}

void insertatEnd(struct node* head,struct node* tail)
{
    struct node * newnode;
    int choice=1;
    while(choice)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        cout<<"Enter At End :";
        cin>>newnode->data;
        newnode->next=NULL;
        newnode->prev=NULL;


        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;

        cout<<"0/1 :";
        cin>>choice;
    }
    cout<<endl;
    cout<<"AFTER Insert END -->";
    show(head);


}

void insertatPos(struct node* head)
{
    struct node * newnode,*temp;
    temp=head;
    int choice=1,i=1;
    int pos;
    while(choice)
    {

        newnode = (struct node*)malloc(sizeof(struct node));
        cout<<"Position : ";
        cin>>pos;

        if(position(head)<pos)
        {
            cout<<"INVALID"<<endl;
        }
        else if(pos==1)
        {
            insertatbeg(head);
            cout<<endl;
        }
        else
        {
            cout<<"Enter At Position Data :";
            cin>>newnode->data;

            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }

            newnode->prev=temp;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->next->prev=newnode;
        }
        cout<<"0/1 :";
        cin>>choice;
    }
    cout<<endl;
    cout<<"AFTER Insert pos -->";
    show(head);
}

void insertafterPos(struct node* head)
{
    struct node * newnode,*temp;
    temp=head;
    int choice=1,i=1;
    int pos;
    while(choice)
    {

        newnode = (struct node*)malloc(sizeof(struct node));
        cout<<"Position : ";
        cin>>pos;

        if(position(head)<pos)
        {
            cout<<"INVALID"<<endl;
        }
        else
        {
            cout<<"Enter At Position Data :";
            cin>>newnode->data;

            while(i<pos)
            {
                temp=temp->next;
                i++;
            }

            newnode->prev=temp;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->next->prev=newnode;
        }
        cout<<"0/1 :";
        cin>>choice;
    }
    cout<<endl;
    cout<<"AFTER pos -->";
    show(head);
}


int main()
{
    create();

    return 0 ;

}
