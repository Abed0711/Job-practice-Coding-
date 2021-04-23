#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

void show(struct node* head)
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<endl;
}

struct node* middle (struct node* first)
{
    struct node* slow = first;
    struct node* fast = first->next;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow = slow->next;
            fast=fast->next;
        }
    }

    return slow;

};


int main()
{
    int n ;
    struct node * head, * temp, *newNode;

    cout<<"N --> ";
    cin>>n;
    head = NULL;

    for(int i = 0 ; i<n; i++)
    {
        newNode = (struct node *) malloc(sizeof(struct node));
        cout<<"New node --> ";
        cin>>newNode->data;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }

    show(head);
    cout<<"Middle -> ";
    cout<<middle(head)->data;


    return 0;
}


