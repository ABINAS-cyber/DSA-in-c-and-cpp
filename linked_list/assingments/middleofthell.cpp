#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* next;
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


Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    // Fast pointer moves 2 steps, slow pointer moves 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Slow pointer is now at the middle
    return slow;
}


int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;
    
    // Create the list
    Node* head = creationlist(n);
    
    // Display the list
    cout << "\nYour Linked List: ";
    display(head);
    
    // Find and display the middle node
    Node* middleNode = findMiddle(head);
    
    if (middleNode != NULL) {
        cout << "The middle element is: " << middleNode->data << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }
    
    return 0;
}