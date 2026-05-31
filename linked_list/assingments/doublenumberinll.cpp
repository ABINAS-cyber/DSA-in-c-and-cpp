#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node *next;
};


Node *creationlist(int n){
    Node* head=NULL , *tail=NULL;
    for(int i=0;i<n;i++){
        cout<<"enter the data "<<i+1 <<":";
        int data;
        cin>>data;
        Node* newnode=new Node;
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    return head;
}


void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


Node* doublenumberinll(Node* head) {
    if (!head) return head;

    Node* curr = head;
    int carry = 0;

    // Reverse the list to make addition easier
    Node* prev = NULL;
    Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev; // head now points to reversed list

    // Double each digit with carry
    curr = head;
    while (curr) {
        int val = curr->data * 2 + carry;
        curr->data = val % 10;
        carry = val / 10;
        if (!curr->next && carry) {
            curr->next = new Node{carry, NULL};
            carry = 0;
        }
        curr = curr->next;
    }

    // Reverse back to restore original order
    prev = NULL;
    curr = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    return head;
}




int main(){
    int n;
    cout << "How many digits? ";
    cin >> n;

    Node* head = creationlist(n);

    cout << "Original number: ";
    display(head);

    head = doublenumberinll(head);

    cout << "Doubled number: ";
    display(head);

    return 0;
}