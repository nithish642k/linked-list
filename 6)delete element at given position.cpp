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
Node* delete_at_position(struct Node *head,int pos)
{
    if(head==NULL)
    {
        return head;
    }
    else if(pos==0)
    {
        Node *temp=head;
        head=head->next;
        delete temp;
    }
    else
    {
        Node *temp=head; // temp is the node just before pos
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        Node *temp1=temp->next; // temp1 is the node at pos
        temp->next=temp1->next;
        delete temp1;
    }
    return head;
}
int main()
{
    struct Node *head=NULL;
    head=getNode(10);
    head->next=getNode(20);
    head->next->next=getNode(30);
    head->next->next->next=getNode(40);

    head=delete_at_position(head,2);  // should delete 30

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
