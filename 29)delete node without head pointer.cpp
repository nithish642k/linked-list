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
void deleteNode(struct Node *node)
{
   if(node==NULL)
     return;
   Node *temp=node;
   temp->data=temp->next->data;
   temp->next=temp->next->next;
}
int main()
{
    struct Node *head=NULL;
    head=getNode(1);
    head->next=getNode(2);
    head->next->next=getNode(3);
    head->next->next->next=getNode(4);

    deleteNode(head->next->next->next);
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
