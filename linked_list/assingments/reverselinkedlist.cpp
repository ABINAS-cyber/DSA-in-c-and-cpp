#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node *next;
};


Node* creationlist(int n){
Node* head = NULL , *tail = NULL;
for(int i = 0 ; i < n;i++){
    cout<<"Enter the data "<<i+1<< ": ";
    int data;
    cin>>data;
    Node *newnode = new Node;
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }else{
        tail->next=newnode;
        tail=newnode;
    }
}
return head;
}


void display(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


void reversell(Node* &head){
    Node* prevnode = NULL;
    Node* currentnode = head;
    Node* nextnode= NULL;
    currentnode=nextnode=head;
    while (nextnode != NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}


int main(){
    int n;
    cout<<"How many node ? ";
    cin>>n;
    Node* head = creationlist(n);
    display(head);

    cout<<"After reversing the linked list: "<<endl;
    reversell(head);
    display(head);
    return 0;
}