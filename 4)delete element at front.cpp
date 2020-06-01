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
Node* delete_at_front(struct Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        delete temp;
    }
    return head;
}
int main()
{
    struct Node *head=NULL;
    head=getNode(1);
    head->next=getNode(2);
    head->next->next=getNode(3);
    head->next->next->next=getNode(4);

    head=delete_at_front(head);
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
