/*
TC:O(N)
SC: O(1)
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
Node* reverse(struct Node *head)
{
    Node *curr=head;
    Node *prev=NULL;
    Node *next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}
bool checkPalindrome(Node *head)
{
    if(head==NULL)
        return false;
    if(head->next==NULL)
        return true;
    Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *first=head;
    Node *second=reverse(slow);
    while(second!=NULL)
    {
        if(first->data!=second->data)
         return false;
         first=first->next;
         second=second->next;
    }
    return true;
}
int main()
{

    struct Node *head=NULL;
    head=getNode(1);
    head->next=getNode(2);
    //head->next->next=getNode(3);
    head->next->next=getNode(2);
    head->next->next=getNode(1);

    /*struct Node *head=NULL;
    head=getNode(1);
    head->next=getNode(2);*/


    bool isPalindrome=checkPalindrome(head);

    if(isPalindrome)
        cout<<"Palindrome";
    else
        cout<<"Not a palindrome";
    return 0;
}
