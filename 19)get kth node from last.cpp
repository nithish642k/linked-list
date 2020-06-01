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
int getKthNodeFromLast(Node *head,int k)
{
    if(head==NULL)
        return -1;
    Node *ptr1=head,*ptr2=head;
    for(int i=1;i<k;i++)
    {
        ptr2=ptr2->next;
        if(ptr2==NULL)
            return -1; // K is greater than the size of the list
    }
    while(ptr2->next!=NULL)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr1->data; // when ptr2 reaches the end of the list,ptr1 will be at the Kth node from the last
}
int main()
{
    struct Node *head=NULL;
    head=getNode(10);
    head->next=getNode(20);
    head->next->next=getNode(30);
    head->next->next->next=getNode(40);
    head->next->next->next->next=getNode(50);

    int k=2;
    cout<<getKthNodeFromLast(head,k);
    return 0;
}
