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
int lengthOfLoop(Node *head) {

   Node *fast=head;
   Node *slow=head;
   while(fast!=NULL&&fast->next!=NULL)
   {
       slow=slow->next;
       fast=fast->next->next;
        if(slow==fast)
         break;
   }
   int length=1;
   if(slow==fast)
   {
       Node *temp=slow;
       while(temp->next!=slow)
       {
           temp=temp->next;
           length++;
       }
   }
   return length;
}
int main()
{
    struct Node *head=NULL;
    head=getNode(10);
    head->next=getNode(20);
    head->next->next=getNode(30);
    head->next->next->next=getNode(40);
    head->next->next->next->next=getNode(50);
    //head->next->next->next->next->next=head->next; // loop from 50 to 20

    head->next->next->next->next->next=head;  // loop from 50 to 10

    cout<<"Length of loop:"<<lengthOfLoop(head);

    return 0;
}
