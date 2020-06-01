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
void insert_at_position(struct Node **head,int data,int pos)
{
    Node *newNode=getNode(data);
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        Node *temp=*head; // temp is the node just before pos
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        Node *temp1=temp->next; // temp1 is the node at pos
        temp->next=newNode;
        newNode->next=temp1;
    }
}
int main()
{
    struct Node *head=NULL;
    insert_at_position(&head,10,0);
    insert_at_position(&head,20,1);
    insert_at_position(&head,30,2);
    insert_at_position(&head,40,3);

    insert_at_position(&head,25,2);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
