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
Node* Sort012(Node *head)
{
    if(head==NULL||head->next==NULL)
       return head;
    Node *temp=head;
    int zeros=0,ones=0,twos=0;
    while(temp!=NULL)
    {
        if(temp->data==0)
           zeros++;
        if(temp->data==1)
           ones++;
        if(temp->data==2)
           twos++;
        temp=temp->next;
    }
    temp=head;
    while(zeros--)
    {
        temp->data=0;
        temp=temp->next;
    }
    while(ones--)
    {
        temp->data=1;
        temp=temp->next;
    }
    while(twos--)
    {
        temp->data=2;
        temp=temp->next;
    }
    return head;
}
int main()
{
    struct Node *head=NULL;
    head=getNode(2);
    head->next=getNode(1);
    head->next->next=getNode(0);
    head->next->next->next=getNode(1);
    head->next->next->next->next=getNode(2);
    head->next->next->next->next->next=getNode(1);

    head=Sort012(head);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
