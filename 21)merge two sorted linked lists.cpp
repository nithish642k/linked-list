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
int main()
{
    struct Node *head1=NULL;
    head1=getNode(30);
    head1->next=getNode(32);
    head1->next->next=getNode(35);
    head1->next->next->next=getNode(40);
    head1->next->next->next->next=getNode(42);

    struct Node *head2=NULL;
    head2=getNode(20);
    head2->next=getNode(22);
    head2->next->next=getNode(25);
    head2->next->next->next=getNode(27);

    Node *head=merge(head1,head2);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
