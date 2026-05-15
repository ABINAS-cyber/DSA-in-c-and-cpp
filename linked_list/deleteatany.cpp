#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* listcreation(int n){
    Node* head = NULL, *tail = NULL;
    for(int i = 0; i < n;i++){
        int data;
        cout<<"Enter the data "<<i+1 <<": ";
        cin>>data;
        Node *newnode = new Node;
        newnode->data=data;
        newnode->next=NULL;
        if(head == NULL){
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
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteatany(Node* &head, int pos){
    if(head == NULL){
        cout<<"Underflow"<<endl;
        return;
    }
    if(pos == 1){ // Deleting the head node
        Node* temp = head;
        head = head->next; // Move head to next node
        delete temp;       // Free memory of old head
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    int count = 1;
    while(temp != NULL && count < pos){
        prev = temp;
        temp = temp->next;
        count++;
    }
    if(temp == NULL){ // Position is out of bounds
        cout<<"Position out of bounds"<<endl;
        return;
    }
    prev->next = temp->next; // Bypass the node to be deleted
    delete temp;             // Free memory of deleted node
}

int main(){
    int n;
    cout<<"How many nodes?";
    cin>>n;
    Node* head = listcreation(n);
    display(head);
    int pos;
    cout<<"Enter the position to delete:";
    cin>>pos;
    deleteatany(head, pos);
    display(head);
    return 0;
}