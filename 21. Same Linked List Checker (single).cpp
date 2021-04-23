#include<bits/stdc++.h>
using namespace std;
void removeLoop(struct node*loopNode, struct node*head);
struct node
{
    char data;
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

bool sameCheck(struct node* ptr1 , struct node* ptr2)
{
    while(ptr1!=NULL)
    {
        if(ptr1->data!=ptr2->data)
        {
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return true;
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

    int m ;
    struct node * headTwo, * tempTwo, *newNodeTwo;

    cout<<"N --> ";
    cin>>m;
    headTwo = NULL;

    for(int i = 0 ; i<n; i++)
    {
        newNodeTwo = (struct node *) malloc(sizeof(struct node));
        cout<<"New node --> ";
        cin>>newNodeTwo->data;
        newNodeTwo->next=NULL;

        if(headTwo==NULL)
        {
            headTwo=tempTwo=newNodeTwo;
        }
        else
        {
            tempTwo->next=newNodeTwo;
            tempTwo=newNodeTwo;
        }
    }
    cout<<"first ->";
    show(head);
    cout<<endl<<"second->";
    show(headTwo);

      cout<<"check -> ";
    if(sameCheck(head,headTwo))
    {
        cout<<"YES"<<endl;

    }
    else
    {
        cout<<"NO"<<endl;

    }

    return 0;
}





