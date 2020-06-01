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
int getSize(Node *node)
{
    if(node==NULL)
        return 0;
    return 1+getSize(node->next);
}
Node* rotateListByK(struct Node *head,int k)
{
    if(head==NULL||k<0)
        return head;
    int sizeOfLL=getSize(head);
    k=k%sizeOfLL;
    if(k==0)
        return head;

    Node *newTail=head;
    int i=1;
    while(i<k)
    {
        newTail=newTail->next;
        i++;
    }
    Node *temp=newTail->next;
    Node *newHead=temp;
    newTail->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    return newHead;
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
    head=rotateListByK(head,k);

    cout<<"Rotated list:";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
