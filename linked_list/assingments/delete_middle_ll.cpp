#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* creationlist(int n){
    Node* head=NULL,*tail = NULL;
    for(int i =0 ;i<n;i++){
        int data;
        cin>>data;
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = NULL; // imp
        if(head == NULL){
            head = newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode; // imp
            tail=newnode;
        }
    }
    return head;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){ //imp
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

Node* delete_at_middle(Node* head){
    if (head == nullptr || head->next == nullptr) {
        return nullptr; // empty or single node case
    }
    Node* prev = NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){ //imp
        prev = slow;
        slow = slow->next;
        fast = fast->next->next; //imp
    }
    prev->next=slow->next;
    delete slow;
    return head;
}


int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = creationlist(n);

    cout << "Original list: ";
    display(head);

    head = delete_at_middle(head);

    cout << "After deleting middle: ";
    display(head);

    return 0;
}