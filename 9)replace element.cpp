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
Node* replace_element(struct Node *head,int oldval,int newval)
{
    if(head==NULL)
    {
        cout<<"Empty list!";
        return head;
    }
    else
    {
        bool found=0;
        for(Node *temp=head;temp!=NULL;temp=temp->next)
        {
            if(temp->data==oldval)
            {
                found=1;
                temp->data=newval;
            }
        }
        if(found)
            cout<<"Update success";
        else
            cout<<"Element not found,update failed";
    }
    return head;
}
int main()
{
    struct Node *head=NULL;
    head=getNode(10);
    head->next=getNode(20);
    head->next->next=getNode(30);
    head->next->next->next=getNode(40);

    head=replace_element(head,20,2);

    cout<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
