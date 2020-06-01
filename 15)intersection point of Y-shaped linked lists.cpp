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
int getIntersectionPoint(Node* head1, Node* head2)
{
   if(head1==NULL||head2==NULL)
    return -1;
    Node *temp1=head1;
    Node *temp2=head2;
    int count1=0,count2=0;
    while(temp1!=NULL)
    {
        count1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        count2++;
        temp2=temp2->next;
    }
    temp1=head1;
    temp2=head2;
    int diff=abs(count1-count2);
    if(count1>count2)
    {
        while(diff--)
        {
            temp1=temp1->next;
        }
    }
    else
    {
        while(diff--)
        {
            temp2=temp2->next;
        }
    }

    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1==temp2)
         return temp1->data;

        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}
int main()
{
    struct Node *head1=NULL;
    head1=getNode(10);
    head1->next=getNode(20);

    struct Node *head2=NULL;
    head2=getNode(1);
    head2->next=getNode(2);
    head2->next->next=getNode(3);


    Node *mergedNodes=getNode(30);
    mergedNodes->next=getNode(40);
    mergedNodes->next->next=getNode(50);

    head1->next->next=mergedNodes;
    head2->next->next->next=mergedNodes;

    cout<<"Intersection point:"<<getIntersectionPoint(head1,head2);
    return 0;
}
