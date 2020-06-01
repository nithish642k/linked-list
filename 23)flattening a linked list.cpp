/*
Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which should be sorted
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45

The flattened linked list for the above list should be:
5 7 8 10 19 20 20 22 30 35 40 45 50
*/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next,*bottom;
};
Node *getNode(int data)
{
    Node *newNode=new Node();
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
Node *mergeTwoLists(Node *left,Node *right)
{
    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    if(left->data<=right->data)
    {
        left->next=mergeTwoLists(left->next,right);
        return left;
    }
    else
    {
        right->next=mergeTwoLists(left,right->next);
        return right;
    }
}
Node *mergeKLists(Node *arr[],int N)
{
    Node *result=arr[0];
    for(int i=1;i<N;i++)
    {
        result=mergeTwoLists(result,arr[i]);
    }
    return result;
}
Node *merge(Node *left,Node *right)
{
    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    Node *result;
    if(left->data<right->data)
    {
        result=left;
        result->bottom=merge(left->bottom,right);
    }
    else
    {
        result=right;
        result->bottom=merge(left,right->bottom);
    }
    result->next=NULL;
    return result;
}
Node *flatten(Node *root)
{
    if(root==NULL||root->next==NULL)
     return root;
     return merge(root,flatten(root->next));
}
int main()
{
    Node *head=NULL;
    head=getNode(5);
    head->bottom=getNode(7);
    head->bottom->bottom=getNode(8);
    head->bottom->bottom->bottom=getNode(30);

    head->next=getNode(10);
    head->next->bottom=getNode(20);

    head->next->next=getNode(19);
    head->next->next->bottom=getNode(22);
    head->next->next->bottom->bottom=getNode(50);

    head->next->next->next=getNode(28);
    head->next->next->next->bottom=getNode(35);
    head->next->next->next->bottom->bottom=getNode(40);
    head->next->next->next->bottom->bottom->bottom=getNode(45);


    head=flatten(head);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->bottom;
    }
    return 0;
}
