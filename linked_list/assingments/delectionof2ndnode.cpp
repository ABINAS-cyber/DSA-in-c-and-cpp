//  Deletion of every 2nd node in a single linked list
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *creationlist(int n){
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

void deletionof2ndnode(Node* head){
    if(head == NULL || head->next == NULL){
        cout<<"The list is too short to delete every 2nd node."<<endl;
        return;
    }
    Node* current = head;
    while(current != NULL && current->next != NULL){
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        current = current->next;
    }
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    Node* head = creationlist(n);
    cout<<"Original list: ";
    display(head);
    deletionof2ndnode(head);
    cout<<"List after deleting every 2nd node: ";
    display(head);
}