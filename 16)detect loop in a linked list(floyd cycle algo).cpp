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
int main()
{
    struct Node *head=NULL;
    head=getNode(10);
    head->next=getNode(20);
    head->next->next=getNode(30);
    head->next->next->next=getNode(40);
    head->next->next->next->next=getNode(50);

    if(detectLoop(head))
        cout<<"Loop exists";
    else
        cout<<"No loop";

    head->next->next->next->next->next=head->next; // loop from 50 to 20

    cout<<endl;
    if(detectLoop(head))
        cout<<"Loop exists";
    else
        cout<<"No loop";

    return 0;
}
