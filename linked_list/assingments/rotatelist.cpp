#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node * next;
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

Node* rotatelist(Node* head, int k) {
    if (!head || k == 0) return head;

    // Find length and tail
    Node* tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    // Make it circular
    tail->next = head;

    // Effective rotations
    k = k % len;
    int stepsToNewHead = len - k;

    // Find new head
    Node* newTail = tail;
    while (stepsToNewHead--) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}


int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    Node* head = creationlist(n);

    cout << "Original list: ";
    display(head);

    int k;
    cout << "Enter the no.of rotation: ";
    cin >> k;

    head = rotatelist(head, k);

    cout << "List after rotation: ";
    display(head);

    return 0;
}
