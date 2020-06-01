
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
int main()
{
    int k=3; // number of linked lists
    int n=4; // number of elements in each list;

    Node *arr[k];

    arr[0]=getNode(30);
    arr[0]->next=getNode(32);
    arr[0]->next->next=getNode(35);
    arr[0]->next->next->next=getNode(40);

    arr[1]=getNode(20);
    arr[1]->next=getNode(22);
    arr[1]->next->next=getNode(25);
    arr[1]->next->next->next=getNode(27);

    arr[2]=getNode(0);
    arr[2]->next=getNode(2);
    arr[2]->next->next=getNode(22);
    arr[2]->next->next->next=getNode(23);

    Node *head=mergeKLists(arr,k);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
