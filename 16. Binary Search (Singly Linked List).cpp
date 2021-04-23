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

struct node * middle(struct node* start , struct node * last)
{
    if(start==NULL)
        return NULL;
    struct node* slow = start;
    struct node* fast = start->next;

    while(fast!=last)
    {
        fast = fast->next;

        if(fast!=last)
        {
            slow=slow->next;
            fast=fast->next;
        }

    }
    return slow;
};

struct node* binarySearch(struct node* head, int search)
{
    struct node* first = head;
    struct node* last = NULL;

    do
    {
        struct node * mid = middle(first,last);
        if(first==NULL)
            return NULL;
        if(mid->data==search)
            return mid;
        else if (mid->data<search)
            first = mid->next;
        else
            last = mid;
    }while(first==NULL||last!=first);
    return NULL;
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
    int search;
    cout<<"Search->";
    cin>>search;

    if (binarySearch(head, search) == NULL)
        printf("Value not present\n");
    else
        printf("Present");

    return 0;
}

