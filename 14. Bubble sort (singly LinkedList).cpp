#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data ;
    struct node* next;
};

void show(struct node* head)
{
    struct node* temp;
    temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
        cout<<"->";
    }
    cout<<endl;
}

struct node *swap(struct node* ptr1 , struct node * ptr2)
{
    struct node* temp=ptr2->next;
    ptr2->next=ptr1;
    ptr1->next=temp;

    return ptr2;

};

struct node* bubbleSort(struct node** head,int n)
{
    struct node** h ;
    int swapped=0;

    for(int i = 0 ; i < n ;i++)
    {
        h=head;
        swapped=0;
        for(int j = 0 ; j<n-i-1;j++)
        {
            struct node * ptr1=*h;
            struct node * ptr2=ptr1->next;
            if(ptr1->data>ptr2->data)
            {
                *h=swap(ptr1,ptr2);
                swapped=1;
            }
            h=&(*h)->next;
        }
        if(swapped==0)
            break;
    }



};




int main()
{
    struct node* head, * newNode, *temp;
    int n;
    cout<<"N : ";
    cin>>n;
    head=NULL;
    for(int i = 0 ; i<n; i++)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        cout<<"Data-> ";
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

    cout<<"Before Bubble sort -> "<<endl;
    show(head);
    bubbleSort(&head,n);
    cout<<"After Bubble sort -> "<<endl;
    show(head);



    return 0;
}
