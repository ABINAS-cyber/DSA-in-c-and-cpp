#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = NULL , *tail = NULL;

void creation(){
    Node * newnode = new Node;
    cout<<"Enter the data:";
    cin>>newnode->data;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }else{
        tail->next = newnode;
        tail= newnode;
    }
}

void display(){
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;  
    }
    cout<<"NULL"<<endl;
}

void deletelast() {
    if (head == NULL) {
        cout << "Underflow" << endl;
    }
    else if (head->next == NULL) { // Only one node
        delete head;
        head = NULL;
        tail = NULL;
    }
    else {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        delete temp;        // delete the last node
        tail = prev;        // update tail to second last node
        tail->next = NULL;  // mark new end of list
    }
}


int main(){
    int n;
    cout<<"how mant nodes?";
    cin>>n;
    for(int i =0 ;i<n;i++){
        creation();
    }
    display();
    deletelast(); // Delete the last node
    display();
    return 0;
}