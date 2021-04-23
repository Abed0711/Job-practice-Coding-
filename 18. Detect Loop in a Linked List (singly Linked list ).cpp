#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node * next;
    int flag = 0;
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

bool detectLoop(struct node* h)
{
    while(h!=NULL)
    {
        if(h->flag==1)
            return true;
        h->flag=1;
        h=h->next;
    }
    return false;

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

   /// head->next->next->next=head;

    cout<<"Detect loop -> ";
    if(detectLoop(head))
    {
        cout<<"YES";
    }
    else
        cout<<"NO";


    return 0;
}



