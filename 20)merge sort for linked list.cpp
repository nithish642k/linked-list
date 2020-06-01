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
Node* getMiddleNode(struct Node *head)
{
    if(head==NULL)
        return NULL;
    Node *slow=head,*fast=head->next;
    while(fast!=NULL&&fast->next!=NULL) // at the last node,fast->next will be NULL
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node *merge(Node *left,Node *right)
{
    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    if(left->data<=right->data)
    {
        left->next=merge(left->next,right);
        return left;
    }
    else
    {
        right->next=merge(left,right->next);
        return right;
    }
}
Node* mergeSort(Node *head)
{
    if(head==NULL||head->next==NULL) // if the list is null or contains only one node
        return head;
    Node *middle=getMiddleNode(head);
    Node *secondHalf=middle->next;
    middle->next=NULL;
    return merge(mergeSort(head),mergeSort(secondHalf));
}
int main()
{
    struct Node *head=NULL;
    head=getNode(30);
    head->next=getNode(20);
    head->next->next=getNode(50);
    head->next->next->next=getNode(10);
    head->next->next->next->next=getNode(40);

    head=mergeSort(head);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
