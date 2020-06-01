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
Node* sortList(struct Node *head)
{
    if(head==NULL)
    {
        return head;
    }
    else
    {
        Node *temp1,*temp2;
        for(temp1=head;temp1!=NULL;temp1=temp1->next)
        {
            for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(temp1->data>temp2->data)
                {
                    int t=temp1->data;
                    temp1->data=temp2->data;
                    temp2->data=t;
                }
            }
        }
    }
    return head;
}
int main()
{
    struct Node *head=NULL;
    head=getNode(20);
    head->next=getNode(10);
    head->next->next=getNode(5);
    head->next->next->next=getNode(10);

    head=sortList(head);

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
