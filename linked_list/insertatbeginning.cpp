#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL, *tail = NULL;

void creation() {
    Node *newnode = new Node;
    cout << "Enter the data: ";
    cin >> newnode->data;
    newnode->next = NULL;

    if (head == NULL) {  // list is empty
        head = newnode;
        tail = newnode;
    } else {             // append at the end
        tail->next = newnode;
        tail = newnode;
    }
}

void insertAtBeginning() {
    Node *newnode = new Node;
    cout << "Enter the beginning  data: ";
    cin >> newnode->data;
    newnode->next = head; // Point new node to the current head
    head = newnode;       // Update head to the new node
}



void display() {
    Node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n;
    cout << "How many nodes? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        creation();
    }
    display();
    insertAtBeginning(); // Insert a new node at the beginning
    display();
    return 0;
}