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

struct node* sortedMarge(struct node* a , struct node * b)
{
    struct node* result = NULL;

    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;

    if(a->data<=b->data)
    {
        result=a;
        result->next=sortedMarge(a->next,b);
    }
    else
    {
        result=b;
        result->next=sortedMarge(a,b->next);
    }

    return(result);

};

void frontBacksort(struct node*source , struct node** frontRef , struct node** backRef)
{
    struct node* slow=source;
    struct node* fast = source->next;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *frontRef=source;
    *backRef=slow->next;
    slow->next=NULL;
}


void mergeSort(struct node** headRef)
{
    struct node* h = *headRef;
    struct node* a , *b ;

    if((h==NULL)||(h->next==NULL))
        return;
    frontBacksort(h,&a,&b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef=sortedMarge(a,b);
}




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
    mergeSort(&head);
    show(head);

    return 0;
}
