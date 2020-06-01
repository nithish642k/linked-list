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
Node* reverseList(struct Node *head)
{
    stack<Node*>st;
    Node *node=head;
    while(node->next!=NULL)
    {
        st.push(node);
        node=node->next;
    }
    head=node;
    while(!st.empty())
    {
        node->next=st.top();
        st.pop();
        node=node->next;
    }
    node->next=NULL;
    return head;
}

int main()
{
    struct Node *head=NULL;
    head=getNode(10);
    head->next=getNode(20);
    head->next->next=getNode(30);
    head->next->next->next=getNode(40);
    head->next->next->next->next=getNode(50);

    head=reverseList(head);

    cout<<"Reversed list:";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}
