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
void insert_at_front(struct Node **head,int data)
{
    Node *newNode=getNode(data);
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        newNode->next=*head;
        *head=newNode;
    }
}
int main()
{
    struct Node *head=NULL;
    insert_at_front(&head,1);
    insert_at_front(&head,2);
    insert_at_front(&head,3);
    insert_at_front(&head,4);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
