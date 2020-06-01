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
bool detectLoop(Node *head) {

   Node *fast=head;
   Node *slow=head;
   while(fast!=NULL&&fast->next!=NULL)
   {
       slow=slow->next;
       fast=fast->next->next;
        if(slow==fast)
         return true;
   }
   return false;
}
void removeLoop(Node *head) {

   Node *fast=head;
   Node *slow=head;
   while(fast!=NULL&&fast->next!=NULL)
   {
       slow=slow->next;
       fast=fast->next->next;
        if(slow==fast)
         break;
   }
   if(slow==fast)
   {
       if(fast==head) // sepcial case:when loop starts from first node
          {
              while(slow->next!=fast)
              {
                  slow=slow->next;
              }
              slow->next=NULL;
          }
          else
          {
          slow=head; // initialize slow as head,do one more iteration,the node where they both meet again is the node that makes the loop
          while(slow->next!=fast->next)
          {
             slow=slow->next;
             fast=fast->next;
          }
          fast->next=NULL;
       }
   }
}
int main()
{
    struct Node *head=NULL;
    head=getNode(10);
    head->next=getNode(20);
    head->next->next=getNode(30);
    head->next->next->next=getNode(40);
    head->next->next->next->next=getNode(50);

    head->next->next->next->next->next=head->next; // loop from 50 to 20

      if(detectLoop(head))
        cout<<"Loop exists";
    else
        cout<<"No loop";

    removeLoop(head);

    cout<<endl;

    if(detectLoop(head))
        cout<<"Loop exists";
    else
        cout<<"No loop";

    return 0;
}
