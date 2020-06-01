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
void search(struct Node *head,int key)
{
    if(head==NULL)
    {
        cout<<"Empty list!";
    }
    else
    {
        int pos=0;
        bool found=0;
        Node *temp=head;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                found=1;
                cout<<"Element found at position "<<pos;
                break;
            }
            pos++;
            temp=temp->next;
        }
        if(!found)
        {
            cout<<"Element not found";
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

    search(head,20);

    return 0;
}
