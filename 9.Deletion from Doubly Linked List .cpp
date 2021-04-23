#include<bits/stdc++.h>
using namespace std;
void deletfromEnd(struct node* head,struct node* tail);
struct node
{
    int data;
    struct node * prev;
    struct node * next;
};

void show(struct node* head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void deletfromBeg(struct node* head)
{
    struct node* temp;
    if(head==NULL)
        cout<<"No Node Available!!"<<endl;

    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    cout<<endl;
    cout<<"After using deletefrombeg func : ";
    show(head);
}


void deletfromEnd(struct node* head,struct node* tail)
{
    struct node* temp;
    if(tail==NULL)
        cout<<"No Node Available!!"<<endl;

    else
    {
        temp=tail;
        tail->prev->next=NULL;
        tail=tail->prev;


    }
    cout<<endl;
    cout<<"After using deletefromEND func : ";
    show(head);
}

void delfrompos(struct node* head)
{
    int pos , i = 1;
    struct node* temp ;temp = head;
    cout<<"Enter pos : ";
    cin>>pos;

    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);

    show(head);

}







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

    show(head);

    ///deletfromBeg(head);
    ///deletfromEnd(head,tail);
    delfrompos(head);
}


int main()
{
    create();
    return 0;
}
