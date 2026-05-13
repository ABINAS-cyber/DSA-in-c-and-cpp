#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = NULL, *tail = NULL;

void creation(){
    Node * newnode = new Node;
    cout<<"Enter the data: ";
    cin>>newnode->data;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}

void display(){
    Node *temp=head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deletefirst(){
    if(head==NULL){
        cout<<"Underflow";
    }
    else{
        Node *temp = head; // Store the current head in a temporary pointer
        head = head->next;
        delete temp; // Free the memory of the old head
    }
}

int main(){
    int n;
    cout<<"How many nodes? ";
    cin>>n;
    for(int i = 0 ; i < n; i++){
        creation();
    }
    display();
    deletefirst(); // Delete the first node
    display();
}