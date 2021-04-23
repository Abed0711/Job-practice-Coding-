#include<bits/stdc++.h>
using namespace std;
void removeLoop(struct node*loopNode, struct node*head);
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

int detectAndRemoveLoop(struct node* list)
{
    struct node* slow = list , * fast=list;

    while(slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow)
        {
            removeLoop(slow,list);
            return 1;
        }
    }
    return 0;
}

void removeLoop(struct node* loopNode , struct node* head)
{
    struct node* ptr1 ;
    struct node* ptr2 ;

    ptr1=head;

    while(1)
    {
        ptr2=loopNode;
        while(ptr2->next!=loopNode&& ptr2->next!=ptr1)
        {
            ptr2=ptr2->next;
        }
        if(ptr2->next==ptr1)
            break;
        ptr1=ptr1->next;

    }
    ptr2->next=NULL;

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
    head->next->next->next->next->next = head;

    cout<<"Detect loop -> ";
    if(detectAndRemoveLoop(head))
    {
        cout<<"YES"<<endl;
        show(head);
    }
    else
    {
        cout<<"NO"<<endl;
        show(head);
    }

    return 0;
}




