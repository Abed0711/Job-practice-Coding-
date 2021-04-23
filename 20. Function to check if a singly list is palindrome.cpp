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

bool isPalindrome(struct node* head)
{
    struct node* slow = head;
    stack<char> s;

    while(slow!=NULL)
    {
        s.push(slow->data);
        cout<<s.top()<<" ";
        slow=slow->next;
    }
    cout<<endl;
    slow=head;

    while(slow!=NULL)
    {
         char i = s.top();
        s.pop();
        if(slow->data!=i)
        {
            return false;
        }
        slow=slow->next;
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

    cout<<"Polindrime -> ";
    if(isPalindrome(head))
    {
        cout<<"YES"<<endl;

    }
    else
    {
        cout<<"NO"<<endl;

    }

    return 0;
}




