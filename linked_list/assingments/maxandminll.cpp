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

void maxandmin(Node* head){
    if(head == NULL){
        cout<<"The list is empty."<<endl;
        return;
    }
    int max = head->data;
    int min = head->data;
    Node* temp = head->next;
    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }
        if(temp->data < min){
            min = temp->data;
        }
        temp = temp->next;
    }
    cout<<"The maximum value in the linked list is: "<<max<<endl;
    cout<<"The minimum value in the linked list is: "<<min<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    Node* head = creationlist(n);
    display(head);
    maxandmin(head);
    return 0;
}