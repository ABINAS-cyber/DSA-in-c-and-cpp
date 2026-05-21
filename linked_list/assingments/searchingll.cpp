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

void searchingofll(Node* head, int key){
    Node* temp = head;
    int position = 1;
    while(temp != NULL){
        if(temp->data == key){
            cout<<"Element found at position: "<<position<<endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout<<"Element not found in the linked list."<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    Node* head = creationlist(n);
    display(head);
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    searchingofll(head, key);
    return 0;
}