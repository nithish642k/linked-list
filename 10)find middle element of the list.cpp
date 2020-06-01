/*
idea:Traverse linked list using two pointers:slow and fast
Move slow by one node at a time
Move fast by two nodes at a time
When the fast pointer reaches end slow pointer will reach middle of the linked list.
*/
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
int get_middle_element(struct Node *head)
{
    if(head==NULL)
    {
        return -1;
    }
    Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL) // at the last node,fast->next will be NULL
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main()
{
    /*struct Node *head=NULL;
    head=getNode(10);
    head->next=getNode(20);
    head->next->next=getNode(30);
    head->next->next->next=getNode(40);*/

    struct Node *head=NULL;
    head=getNode(10);
    head->next=getNode(20);
    head->next->next=getNode(30);
    head->next->next->next=getNode(40);
    head->next->next->next->next=getNode(50);

    int res=get_middle_element(head);
    cout<<"Middle element:"<<res;
    return 0;
}
