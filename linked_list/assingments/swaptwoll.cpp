#include<bits/stdc++.h>
using namespace std;

struct Node{
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

void swaptwoll(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        swap(temp1->data, temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

int main(){
    int n1, n2;
    cout<<"Enter the number of nodes in first linked list: ";
    cin>>n1;
    Node* head1 = creationlist(n1);
    cout<<"Enter the number of nodes in second linked list: ";
    cin>>n2;
    Node* head2 = creationlist(n2);
    cout<<"First linked list before swapping: ";
    display(head1);
    cout<<"Second linked list before swapping: ";
    display(head2);
    swaptwoll(head1, head2);
    cout<<"First linked list after swapping: ";
    display(head1);
    cout<<"Second linked list after swapping: ";
    display(head2);
    return 0;
}