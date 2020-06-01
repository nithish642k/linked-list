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
Node *addTwoNumbers(Node *first,Node *second)
{
    Node *n1=first,*n2=second;
    Node *res=getNode(0); // res->dummy head
    Node *curr=res;
    int carry=0;
    while(n1!=NULL||n2!=NULL)
    {
        int v1=(n1!=NULL)?n1->data:0;
        int v2=(n2!=NULL)?n2->data:0;
        int sum=v1+v2+carry;
        carry=sum/10;
        curr->next=getNode(sum%10);
        if(n1!=NULL)
            n1=n1->next;
        if(n2!=NULL)
            n2=n2->next;
        curr=curr->next;
    }
    if(carry>0)
        curr->next=getNode(carry);
    return res->next;
}
int main()
{

    struct Node *head1=NULL; // 342
    head1=getNode(2);
    head1->next=getNode(4);
    head1->next->next=getNode(3);

    struct Node *head2=NULL; // 465
    head2=getNode(5);
    head2->next=getNode(6);
    head2->next->next=getNode(4);

    /*struct Node *head1=NULL;
    head1=getNode(2);
    head1->next=getNode(4);

    struct Node *head2=NULL;
    head2=getNode(5);
    head2->next=getNode(6);
    head2->next->next=getNode(4);*/


    Node *head=addTwoNumbers(head1,head2);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
