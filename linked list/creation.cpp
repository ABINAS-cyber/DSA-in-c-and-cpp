// Why do we need it?
// If you have a pointer to a struct or class, you can’t use the dot (.) operator directly because the pointer doesn’t hold the object itself, it only points to it.

// The arrow operator is shorthand for dereferencing the pointer and then accessing the member.


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
    return 0;
}
