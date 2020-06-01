#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
Node *getNode(int data)
{
    Node *newNode=new Node();
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insert_at_end(struct Node **head,int data)
{
    Node *newNode=getNode(data);
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        Node *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
int main()
{
    struct Node *head=NULL;
    insert_at_end(&head,1);
    insert_at_end(&head,2);
    insert_at_end(&head,3);
    insert_at_end(&head,4);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
