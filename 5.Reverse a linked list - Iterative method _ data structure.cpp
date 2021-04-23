#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;

};

void reverse_list(struct node * head)
{
    struct node * prevnode, * currentnode, * nextnode,*temp;
    prevnode=NULL;

    currentnode= nextnode = head;

    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;

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

    reverse_list(head);



    return 0;
}
