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
#define M 1000000007
long long  multiplyTwoNumbers(Node* first, Node* second)
{
  long long num1=0,num2=0;
  while(first!=NULL||second!=NULL)
  {
      if(first!=NULL)
      {
          num1=(((num1%M)*10)%M+first->data)%M;
          first=first->next;
      }
      if(second!=NULL)
      {
          num2=(((num2%M)*10)%M+second->data)%M;
          second=second->next;
      }
  }
  return ((num1%M)*(num2%M))%M;
}
int main()
{

    struct Node *head1=NULL; // 342
    head1=getNode(3);
    head1->next=getNode(4);
    head1->next->next=getNode(2);

    struct Node *head2=NULL; // 465
    head2=getNode(4);
    head2->next=getNode(6);
    head2->next->next=getNode(5);

    long long int res=multiplyTwoNumbers(head1,head2);
    cout<<res;
    return 0;
}
