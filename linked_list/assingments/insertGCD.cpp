#include<bits/stdc++.h>
using namespace std;



struct Node{
    int data;
    Node * next;
};



int calculateGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


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




Node* insertGreatestCommonDivisors(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        // Now it knows what calculateGCD is!
        int gcd_val = calculateGCD(curr->data, curr->next->data);

        Node* newnode = new Node;
        newnode->data = gcd_val;

        newnode->next = curr->next;
        curr->next = newnode;

        curr = newnode->next;
    }

    return head;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node* head = creationlist(n);

    cout << "\nOriginal Linked List:" << endl;
    display(head);

    head = insertGreatestCommonDivisors(head);

    cout << "\nLinked List after inserting GCDs:" << endl;
    display(head);

    return 0;
}