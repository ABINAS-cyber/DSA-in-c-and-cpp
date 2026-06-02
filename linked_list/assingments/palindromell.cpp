#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};


Node* creationlist(int n){
    Node* head=NULL,*tail=NULL;
    for(int i=0;i<n;i++){
        Node*  newnode=new Node;
        cout<<"Enter the data of node "<<i+1<<" : ";
        cin>>newnode->data;
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
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* palindrome(Node* head){
    Node* temp=head;
    stack<int> s;
    while(temp!=NULL){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=s.top()){
            return NULL;
        }
        s.pop();
        temp=temp->next;
    }
    return head;
}

int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    Node* head=creationlist(n);
    display(head);
    if(palindrome(head)!=NULL){
        cout<<"The linked list is a palindrome."<<endl;
    }
    else{
        cout<<"The linked list is not a palindrome."<<endl;
    }
    return 0;
}